#include "interface.h"
#include <iostream>
#include <limits>
#include "candidate.h"

using namespace std;

#define MAX 999

// --- 入出力インターフェース ---

// 候補数字のリストをカンマ区切りで出力する
void print_nums(const vector<Num> &nums)
{
    for (const Num &n : nums)
    {
        cout << n << ",";
    }
}

// 推測値・ヒット数・ブロー数の入力受付
Cond input_condition()
{
    while (true)
    {
        cout << "please input:\n";
        cout << "format: 'guess_num hit_num brow_num'\n";

        int g, h, b;
        cin >> g >> h >> b;
        if (cin.fail())
        {
            cin.clear();                                         // 入力エラーをクリア
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 入力バッファをクリア
            cout << "invalid input. Please try again.\n\n";
            continue;
        }

        Num guess(g);
        if (!guess.valid())
        {
            cout << "invalid input: guess_num.\n\n";
            continue;
        }

        Cond c(guess, h, b);
        if (!c.valid())
        {
            cout << "invalid input; hit_num or brow_num.\n\n";
            continue;
        }

        return c;
    }
}

// --- 候補リスト操作 ---

// 入力された条件で候補リストを絞り込む
vector<Num> filter_candidates(const vector<Num> &cand)
{
    Cond c = input_condition();
    return filter(cand, c);
}

// ユーザー入力に基づき候補リストを絞り込み、結果を出力する
void candidate(const vector<Num> &cand, vector<Num> &newCand)
{
    auto filtered = filter_candidates(cand);

    cout << "Candidates:\n";
    print_nums(filtered);
    cout << "\n\n";

    newCand = filtered;
}

// すべての有効な候補数字を返す
vector<Num> init_candidates()
{
    vector<Num> cands;
    for (int i = 0; i <= MAX; i++)
    {
        Num n(i);
        if (n.valid())
            cands.push_back(n);
    }
    return cands;
}

// --- エントリポイント ---

// 候補リストを管理しながら繰り返し処理を行う
void start()
{
    vector<Num> cands = init_candidates();
    while (true)
    {
        vector<Num> filtered = filter_candidates(cands);

        cout << "Candidates:\n";
        print_nums(filtered);
        cout << "\n\n";

        cands = filtered;
    }
}
