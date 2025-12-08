#include "item.h"
#include <algorithm>
#include <iostream>


// 加成道具初始化
void ItemList::init() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    Item item;
    std::cin >> item.id >> item.hp >> item.attack >> item.defense >> item.money;
    _data.emplace_back(std::move(item));
  }
  return;
}

// 返回 id 相符的 加成道具对象
Item ItemList::find(int id) const {
  return *std::find_if(_data.begin(), _data.end(), [id](const Item &item) { return item.id == id; });
}

// 判断 id 是否为 加成道具对象
bool Item::is_item(int id) { return (14 <= id && id <= 99); }