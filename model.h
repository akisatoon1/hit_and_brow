#ifndef MODEL_H
#define MODEL_H

#include <iostream>

// ==================== Num ====================
struct Num
{
    int d1, d2, d3; ///< 各桁の数字: d1d2d3で表される

    // コンストラクタ
    Num(int n);                  ///< 3桁のintから初期化
    Num(int d1, int d2, int d3); ///< 各桁から初期化

    // メンバ関数
    bool valid() const;               ///< 有効な3桁か
    int hit(const Num &guess) const;  ///< ヒット数
    int brow(const Num &guess) const; ///< ブロー数
};

// ==================== Cond ====================
struct Cond
{
    Num guess;     ///< 推測値
    int hit, brow; ///< ヒット数・ブロー数

    // コンストラクタ
    Cond(const Num &guess, int hit, int brow);

    // メンバ関数
    bool valid() const;             ///< hit, browが有効範囲か
    bool match(const Num &n) const; ///< この条件でnが成立するか
};

// 出力用ストリーム演算子
std::ostream &operator<<(std::ostream &os, const Num &num);

#endif // MODEL_H
