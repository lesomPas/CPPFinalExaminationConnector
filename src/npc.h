#pragma once

#include <vector>

struct NPC {
  int id;
  int hp;
  int attack;
  int defense;
  int money;
  static bool is_npc(int id);
};

class NPCList {
public:
  void init();            // NPC初始化
  NPC find(int id) const; // 通过 id 查找NPC

private:
  std::vector<NPC> _data; // NPC列表内数据
};