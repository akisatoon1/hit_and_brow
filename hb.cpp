#include <iostream>
#include <vector>

using namespace std;

#define MAX 999

struct Cond
{
    int estimate;
    int hit, brow;
};

Cond NewCond(int e, int h, int b)
{
    Cond c;
    c.estimate = e;
    c.hit = h;
    c.brow = b;
    return c;
}

bool or_equal(int real)
{
    int a, b, c; // 1, 2, 3桁目の数字
    a = real / 100;
    b = (real / 10) % 10;
    c = real % 10;

    return (a == b || b == c || c == a);
}

int hit(int real, int esti)
{
    int a, b, c; // 1, 2, 3桁目の数字
    a = real / 100;
    b = (real / 10) % 10;
    c = real % 10;

    int x, y, z; // 1, 2, 3桁目の数字
    x = esti / 100;
    y = (esti / 10) % 10;
    z = esti % 10;

    int cnt = 0;
    if (a == x)
        cnt++;
    if (b == y)
        cnt++;
    if (c == z)
        cnt++;

    return cnt;
}

int brow(int real, int esti)
{
    int a, b, c; // 1, 2, 3桁目の数字
    a = real / 100;
    b = (real / 10) % 10;
    c = real % 10;

    int x, y, z; // 1, 2, 3桁目の数字
    x = esti / 100;
    y = (esti / 10) % 10;
    z = esti % 10;

    int cnt = 0;
    if (a == y || a == z)
        cnt++;
    if (b == x || b == z)
        cnt++;
    if (c == x || c == y)
        cnt++;

    return cnt;
}

bool filter(int n, Cond c)
{
    bool b1 = hit(n, c.estimate) == c.hit;
    bool b2 = brow(n, c.estimate) == c.brow;
    bool b3 = !or_equal(n);
    return b1 && b2 && b3;
}

void print(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ",";
    }
}

void candidate(vector<int> &cand, vector<int> &newCand)
{
    cout << "please input:\n";
    cout << "format: 'guess hit brow'\n";

    int e, h, b;
    cin >> e >> h >> b;
    Cond c = NewCond(e, h, b);

    // gather candidates
    for (int i : cand)
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

void cp(vector<int> &src, vector<int> &dst)
{
    dst.clear();
    for (int i : src)
    {
        dst.push_back(i);
    }
}

int main()
{
    cout << "Start\n\n";

    // init
    vector<int> cands;
    for (int i = 0; i <= MAX; i++)
        cands.push_back(i);

    while (true)
    {
        vector<int> empty;
        candidate(cands, empty);
        cp(empty, cands);
        // cout << "Estimate: " << estimate(cands) << endl;
    }
}
