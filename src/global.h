#pragma once

#include "map.h"
#include "player.h"
#include <string>

struct GameInfo {
  int current_floor = 1; // 当前层
  int current_row = 1;   // 主角当前行
  int current_col = 1;   // 主角当前列
  void print();
};

class Game {
public:
  void start();

private:
  GameInfo info;
  Player player_data;
  MapList map_data;
  Map current_map;
  MonsterList monster_data;
  ItemList item_data;
  NPCList npc_data;
  std::string user_operations;
  int operation_index = 0;
  char get_next_operation();
  void move(int dir_row, int dir_col);
  void stimulate();
  void map_erase(int row, int col);
};