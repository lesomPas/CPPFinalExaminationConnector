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
  _attack += item.attack;
  _defense += item.defense;
  _money += item.money;
  print();
  return;
}

// 任务4：完成开门
bool Player::open_door(int id) {
  if (id == 4 && _yellow_key > 0) {
    _yellow_key--;
  }
  else if (id == 5 && _blue_key > 0) {
    _blue_key--;
  }
  else if (id == 6 && _red_key > 0) {
    _red_key--;
  }
  else {
    return false;
  }
  print();
  return true;
}

// 任务6：完成战斗
bool Player::fight(const Monster &monster) {
  int origin_hp = _hp;

  int result = 0; // 1 -> 玩家胜 2 -> 怪物胜

  while (true) {
    monster.hp -= std::min(1, _attack - monster.defense);
    if (monster.hp <= 0) {
      results = 1;
      break;
    }
    _hp -= std::min(1, monster.attack - _defense);
    if (_hp <= 0) {
      results = 2;
      break;
    }
  }

  if (result == 1) {
    _money += monster.money;
    print();
    return true;
  }

  _hp = origin_hp;
  return false;
}

// 任务8：完成NPC交互
bool Player::interact(const NPC &npc) {
  if (_hp + npc.hp <= 0 || _money + npc.money < 0) {
    return false;
  }
  _hp += npc.hp;
  _attack += npc.attack;
  _money += npc.money;
  print();
  return true;
}

// 打印玩家属性
void Player::print() {
  std::cout << _hp << ' ' << _attack << ' ' << _defense << ' ' << _money << ' ' << _yellow_key << ' ' << _blue_key << ' ' << _red_key << std::endl;
}