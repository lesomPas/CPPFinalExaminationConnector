#include "monster.h"
#include <algorithm>
#include <iostream>

// 怪物初始化
void MonsterList::init() {
  // 任务5：完成MonsterList的初始化
  // 提示：构建 Monster 变量 monster ，对其赋值后，使用 _data.emplace_back(monster) 将其添加至容器
  // 等待完成......
  return;
}

// 返回 id 相符的 怪物对象
Monster MonsterList::find(int id) const {
  return *std::find_if(_data.begin(), _data.end(),[id](const Monster &monster) { return monster.id == id; });
}

// 判断 id 是否为 怪物对象
bool Monster::is_monster(int id) { return (100 <= id && id <= 199); }