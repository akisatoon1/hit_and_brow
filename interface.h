#ifndef GAME_H
#define GAME_H

#include <vector>
#include "model.h"

// 候補数字のリストをカンマ区切りで出力する
void print_nums(const std::vector<Num> &nums);

// ユーザーから推測値・ヒット数・ブロー数を入力させる
void input_guess_and_condition(int &guess, int &hit, int &brow);

// 入力された条件で候補リストを絞り込む
std::vector<Num> filter_candidates(const std::vector<Num> &cand);

// ユーザー入力に基づき候補リストを絞り込み、結果を出力する
void candidate(const std::vector<Num> &cand, std::vector<Num> &newCand);

// vectorのコピー（今後は非推奨、戻り値利用推奨）
std::vector<Num> cp(const std::vector<Num> &src);

// すべての有効な候補数字を返す
std::vector<Num> init_candidates();

// 候補リストを管理しながら繰り返し処理を行う
void start();

#endif // GAME_H
