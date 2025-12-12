#include "player.h"
#include <iostream>

// 任务1：完成玩家属性初始化
void Player::init() {
  std::cin >> _hp >> _attack >> _defense >> _money >> _yellow_key >> _blue_key >> _red_key;
}

// 任务2：完成钥匙拾取
void Player::pick_key(int id) {
  if (id == 11) {
    _yellow_key++;
  }
  else if (id == 12) {
    _blue_key++;
  }
  else if (id == 13) {
    _red_key++;
  }
  print();
  return;
}

// 任务3：完成加成道具拾取
void Player::pick_item(const Item &item) {
  _hp += item.hp;
  _attack += items.attack;
  _defense += item.defense;
  _money += item.money;
  print();
  return;
}

// 任务4：完成开门
bool Player::open_door(int id) {
  // 提示：想好什么时候 return true 不要忘记 print()
  return false;
}

// 任务6：完成战斗
bool Player::fight(const Monster &monster) {

  // 等待完成.....

  int result = 0; // 1 -> 玩家胜 2 -> 怪物胜

  // 等待完成.....

  if (result == 1) {
    // 等待完成.....
    print();
    return true;
  }

  return false;
}

// 任务8：完成NPC交互
bool Player::interact(const NPC &npc) {
  // 提示：想好什么时候 return false
  // 等待完成.....
  print();
  return true;
}

// 打印玩家属性
void Player::print() {
  std::cout << _hp << ' ' << _attack << ' ' << _defense << ' ' << _money << ' ' << _yellow_key << ' ' << _blue_key << ' ' << _red_key << std::endl;
}