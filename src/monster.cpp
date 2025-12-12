#include "monster.h"
#include <algorithm>
#include <iostream>

// 怪物初始化
void MonsterList::init() {
  // 任务5：完成MonsterList的初始化
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    Monster monster;
    std::cin >> monster.id >> monster.hp >> monster.attack >> monster.defense >> monster.money;
    _data.emplace_back(std::move(monster));
  }
  return;
}

// 返回 id 相符的 怪物对象
Monster MonsterList::find(int id) const {
  return *std::find_if(_data.begin(), _data.end(),[id](const Monster &monster) { return monster.id == id; });
}

// 判断 id 是否为 怪物对象
bool Monster::is_monster(int id) { return (100 <= id && id <= 199); }