#include <vector>
#include "model.h"

using namespace std;

vector<Num> filter(const vector<Num> &candidates, Cond con)
{
    vector<Num> filtered;
    for (const Num &cand : candidates)
        if (con.match(cand))
            filtered.push_back(cand);
    return filtered;
}
