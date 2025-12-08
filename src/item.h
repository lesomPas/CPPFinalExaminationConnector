#pragma once

#include <vector>

// 加成道具
struct Item {
  int id;
  int hp;
  int attack;
  int defense;
  int money;
  static bool is_item(int id); // 判断 id 是否为 加成道具对象
};

class ItemList {
public:
  void init();             // 加成道具初始化
  Item find(int id) const; // 通过id查找加成道具

private:
  std::vector<Item> _data; // 加成道具列表内数据
};