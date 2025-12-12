#include "global.h"
#include <iostream>

// 打印游戏的全局信息
void GameInfo::print() {
  std::cout << current_floor << ' ' << '(' << current_row << ',' << current_col << ')' << std::endl;
}

// 开始游戏
void Game::start() {
  player_data.init();
  monster_data.init();
  item_data.init();
  map_data.init();
  current_map = map_data.get_map(info.current_floor);
  std::cin >> user_operations;
  stimulate();
}

// 获取下一个操作字符
char Game::get_next_operation() {
  if (operation_index < user_operations.length()) {
    ++operation_index;
    return user_operations[operation_index - 1];
  }
  return '\0';
}

// 将地图的指定位置修改为 0 （路）
void Game::map_erase(int row, int col) {
  current_map.erase(row, col);
  map_data.erase(info.current_floor, row, col);
}

void Game::move(int dir_row, int dir_col) {

  bool succeed = false;

  int tar_row = info.current_row + dir_row;
  int tar_col = info.current_col + dir_col;

  if (Map::is_in_map(tar_row, tar_col)) {
    int id = current_map.get(tar_row, tar_col);
    if (id == 0) {
      // 路
      succeed = true;
    } else if (id == 2) {
      // 任务9：完成上楼
      info.current_floor++;
      current_map = map_data.get_map(info.current_floor);
      Point downstair = current_map.get_downstair();

      info.current_row = downstair.row;
      info.current_col = downstair.col;
      info.print();
      return;
    } else if (id == 3) {
      // 任务10：完成下楼
      info.current_floor--;
      current_map = map_data.get_map(info.current_floor);
      Point upstair = current_map.get_upstair();

      info.current_row = upstair.row;
      info.current_col = upstair.col;
      info.print();
      return;
    } else if (4 <= id && id <= 6) {
      // 门
      if (player_data.open_door(id)) {
        succeed = true;
      }
    } else if (11 <= id && id <= 13) {
      // 任务11：完成钥匙
      player_data.pick_key(id);
      map_erase(tar_row, tar_col);
      succeed = true;
    } else if (Item::is_item(id)) {
      // 加成道具
      player_data.pick_item(item_data.find(id));
      map_erase(tar_row, tar_col);
      succeed = true;
    } else if (Monster::is_monster(id)) {
      // 任务12：完成怪物
      Monster monster = monster_data.find(id);
      if (player_data.fight(monster)) {
        map_erase(tar_row, tar_col);
        succeed = true;
      }
    } else if (NPC::is_npc(id)) {
      // NPC
      succeed = true;
    }
  }

  if (succeed) {
    info.current_row = tar_row;
    info.current_col = tar_col;
    std::cout << '(' << info.current_row << ',' << info.current_col << ')' << std::endl;
  } else {
    std::cout << "Move failed!" << std::endl;
  }
}

// 模拟游戏进程
void Game::stimulate() {
  auto opt = get_next_operation();
  while (opt) {
    if (opt == 'W') {
      move(-1, 0);
    } else if (opt == 'A') {
      move(0, -1);
    } else if (opt == 'S') {
      move(1, 0);
    } else if (opt == 'D') {
      move(0, 1);
    } else if (opt == 'Y') {
      if (!player_data.interact(npc_data.find(current_map.get(info.current_row, info.current_col)))) {
        std::cout << "Passed" << std::endl;
      }
    } else if (opt == 'N') {
      std::cout << "Passed" << std::endl;
    }
    opt = get_next_operation();
  }
}