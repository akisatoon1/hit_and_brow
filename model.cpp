#include "model.h"

// 3桁のintから初期化
Num::Num(int n) : d1(n / 100), d2((n / 10) % 10), d3(n % 10) {}

// 各桁から初期化
Num::Num(int d1_, int d2_, int d3_) : d1(d1_), d2(d2_), d3(d3_) {}

Cond::Cond(const Num& guess_, int hit_, int brow_) : guess(guess_), hit(hit_), brow(brow_) {}

// Num構造体のメンバ関数定義

bool Num::or_equal() const {
    return (d1 == d2 || d2 == d3 || d3 == d1);
}

bool Num::valid() const {
    bool c1 = (0 <= d1 && d1 <= 9);
    bool c2 = (0 <= d2 && d2 <= 9);
    bool c3 = (0 <= d3 && d3 <= 9);
    return c1 && c2 && c3 && !or_equal();
}

int Num::hit(const Num &guess) const {
    int cnt = 0;
    if (d1 == guess.d1) cnt++;
    if (d2 == guess.d2) cnt++;
    if (d3 == guess.d3) cnt++;
    return cnt;
}

int Num::brow(const Num &guess) const {
    int cnt = 0;
    if (d1 == guess.d2 || d1 == guess.d3) cnt++;
    if (d2 == guess.d1 || d2 == guess.d3) cnt++;
    if (d3 == guess.d1 || d3 == guess.d2) cnt++;
    return cnt;
}

// Cond構造体のメンバ関数定義

bool Cond::valid() const {
    bool h = (0 <= hit && hit <= 3);
    bool b = (0 <= brow && brow <= 3);
    return h && b;
}
