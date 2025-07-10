#ifndef MODEL_H
#define MODEL_H

struct Num
{
    int d1, d2, d3;
    // Num(); // デフォルトコンストラクタは不要
    Num(int n); // 3桁のintから初期化
    Num(int d1, int d2, int d3); // 各桁から初期化
    bool or_equal() const;
    bool valid() const;
    int hit(const Num &guess) const;
    int brow(const Num &guess) const;
};

struct Cond
{
    Num guess;
    int hit, brow;
    // Cond(); // デフォルトコンストラクタは不要
    Cond(const Num& guess, int hit, int brow);
    bool valid() const;
};

#endif // MODEL_H
