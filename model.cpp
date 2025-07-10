#include "model.h"

// ==================== Num ====================

// 3桁のintから初期化するコンストラクタ
Num::Num(int n)
    : d1(n / 100), d2((n / 10) % 10), d3(n % 10) {}

// 各桁を直接指定するコンストラクタ
Num::Num(int d1_, int d2_, int d3_)
    : d1(d1_), d2(d2_), d3(d3_) {}

// 3桁の数字として有効か判定
bool Num::valid() const {
    // 各桁が0-9の範囲であることを確認
    bool c1 = (0 <= d1 && d1 <= 9);
    bool c2 = (0 <= d2 && d2 <= 9);
    bool c3 = (0 <= d3 && d3 <= 9);

    // それぞれの桁が異なることを確認
    bool c4 = !(d1 == d2 || d2 == d3 || d3 == d1);

    return c1 && c2 && c3 && c4;
}

// guessとの位置一致数（ヒット数）
int Num::hit(const Num &guess) const {
    int cnt = 0;
    if (d1 == guess.d1) cnt++;
    if (d2 == guess.d2) cnt++;
    if (d3 == guess.d3) cnt++;
    return cnt;
}

// guessとの数字一致数（位置違い、ブロー数）
int Num::brow(const Num &guess) const {
    int cnt = 0;
    if (d1 == guess.d2 || d1 == guess.d3) cnt++;
    if (d2 == guess.d1 || d2 == guess.d3) cnt++;
    if (d3 == guess.d1 || d3 == guess.d2) cnt++;
    return cnt;
}

// ==================== Cond ====================

// guess, hit, browを指定するコンストラクタ
Cond::Cond(const Num& guess_, int hit_, int brow_)
    : guess(guess_), hit(hit_), brow(brow_) {}

// 出力用ストリーム演算子
std::ostream& operator<<(std::ostream& out, const Num& num) {
    out << num.d1
        << num.d2
        << num.d3;
    return out;
}

// hit, browが有効範囲か判定
bool Cond::valid() const {
    bool h = (0 <= hit && hit <= 3);
    bool b = (0 <= brow && brow <= 3);
    return h && b;
}

// nがこの条件(guess, hit, brow)を満たすか判定
bool Cond::filter(const Num& n) const {
    if (!guess.valid()) return false;
    bool b1 = (hit == n.hit(guess));
    bool b2 = (brow == n.brow(guess));
    return b1 && b2;
}
