// 类头文件定义 任务见 player.cpp

#pragma once

#include "item.h"
#include "monster.h"
#include "npc.h"

class Player {
public:
  void init();                        // 玩家属性初始化
  void pick_key(int id);              // 钥匙拾取函数
  void pick_item(const Item &item);   // 道具拾取函数
  bool open_door(int id);             // 开门函数
  bool fight(const Monster &monster); // 战斗函数
  bool interact(const NPC &npc);      // NPC交互函数

private:
  int _hp;
  int _attack;
  int _defense;
  int _money;
  int _yellow_key;
  int _blue_key;
  int _red_key;
  void print(); // 打印玩家属性
};