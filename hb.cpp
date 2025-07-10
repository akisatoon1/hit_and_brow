#include <iostream>
#include <vector>
#include "model.h"

using namespace std;

#define MAX 999

void print(const vector<Num> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i].toInt() << ",";
    }
}

void candidate(const vector<Num> &cand, vector<Num> &newCand)
{
start:

    cout << "please input:\n";
    cout << "format: 'guess hit brow'\n";

    int g, h, b;
    cin >> g >> h >> b;


    Num guess(g);
    if (!guess.valid())
    {
        cout << "invalid guess format.\n\n";
        goto start;
    }
    Cond c(guess, h, b);

    // gather candidates
    for (const Num &i : cand)
        if (c.filter(i))
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
        Num n(i);
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
