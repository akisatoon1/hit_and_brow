#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

struct Num
{
    int d1, d2, d3;

    bool or_equal() const
    {
        return (d1 == d2 || d2 == d3 || d3 == d1);
    }

    bool valid() const
    {
        bool c1 = (0 <= d1 && d1 <= 9);
        bool c2 = (0 <= d2 && d2 <= 9);
        bool c3 = (0 <= d3 && d3 <= 9);
        return c1 && c2 && c3 && !or_equal();
    }

    int hit(const Num &guess) const
    {
        int cnt = 0;
        if (d1 == guess.d1)
            cnt++;
        if (d2 == guess.d2)
            cnt++;
        if (d3 == guess.d3)
            cnt++;
        return cnt;
    }

    int brow(const Num &guess) const
    {
        int cnt = 0;
        if (d1 == guess.d2 || d1 == guess.d3)
            cnt++;
        if (d2 == guess.d1 || d2 == guess.d3)
            cnt++;
        if (d3 == guess.d1 || d3 == guess.d2)
            cnt++;
        return cnt;
    }
};

Num toNum(int n)
{
    Num num;
    num.d1 = n / 100;
    num.d2 = (n / 10) % 10;
    num.d3 = n % 10;
    return num;
}

int toInt(const Num &num)
{
    return num.d1 * 100 + num.d2 * 10 + num.d3;
}

struct Cond
{
    Num guess;
    int hit, brow;

    bool valid() const
    {
        bool h = (0 <= hit && hit <= 3);
        bool b = (0 <= brow && brow <= 3);
        return h && b;
    }
};

Cond newCond(Num guess, int hit, int brow)
{
    Cond c;
    c.guess = guess;
    c.hit = hit;
    c.brow = brow;
    return c;
}

bool filter(const Num &n, Cond c)
{
    Num g = c.guess;
    if (!g.valid())
        return false;

    bool b1 = (c.hit == n.hit(g));
    bool b2 = (c.brow == n.brow(g));
    return b1 && b2;
}

void print(const vector<Num> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << toInt(nums[i]) << ",";
    }
}

void candidate(const vector<Num> &cand, vector<Num> &newCand)
{
start:

    cout << "please input:\n";
    cout << "format: 'guess hit brow'\n";

    int g, h, b;
    cin >> g >> h >> b;

    Num guess = toNum(g);
    if (!guess.valid())
    {
        cout << "invalid guess format.\n\n";
        goto start;
    }
    Cond c = newCond(guess, h, b);

    // gather candidates
    for (const Num &i : cand)
        if (filter(i, c))
            newCand.push_back(i);

    cout << "Candidates:\n";
    print(newCand);
    cout << "\n\n";
}

/*
int estimate(vector<int> &cands)
{
    int min_e = -1;
    double min = 1000;

    for (int e = 0; e <= MAX; e++)
    {
        if (or_equal(e))
            continue;

        int sum = 0;
        int n = 0;
        for (int h = 0; h <= 3; h++)
            for (int b = 0; b <= 3; b++)
            {
                int cnt = 0;

                Cond c = NewCond(e, h, b);
                for (int i : cands)
                    if (filter(i, c))
                        cnt++;

                if (cnt == 0)
                    continue;
                sum += cnt;
                n++;
            }

        if (n == 0)
            continue;
        double avg = (double)sum / n;
        if (avg < min)
        {
            min = avg;
            min_e = e;
        }
    }

    return min_e;
}
*/

void cp(const vector<Num> &src, vector<Num> &dst)
{
    dst.clear();
    for (const Num &i : src)
    {
        dst.push_back(i);
    }
}

int main()
{
    cout << "Start\n\n";

    // init
    vector<Num> cands;
    for (int i = 0; i <= MAX; i++)
    {
        Num n = toNum(i);
        if (n.valid())
            cands.push_back(n);
    }

    while (true)
    {
        vector<Num> empty;
        candidate(cands, empty);
        cp(empty, cands);
        // cout << "Estimate: " << estimate(cands) << endl;
    }
}
