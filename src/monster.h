#pragma once

#include <vector>

// 怪物
struct Monster {
  int id;
  int hp;
  int attack;
  int defense;
  int money;
  static bool is_monster(int id); // 判断 id 是否为 怪物对象
};

class MonsterList {
public:
  void init();                // 怪物初始化
  Monster find(int id) const; // 通过id查找怪物

private:
  std::vector<Monster> _data; // 怪物列表内数据
};