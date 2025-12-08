#pragma once

#include "item.h"
#include "monster.h"
#include "npc.h"
#include <vector>


struct Point {
  int row, col;
};

class Map {
public:
  void init();                             // 每张地图的初始化函数
  int get(int row, int col);               // 获取地图上某一点对应的值
  void erase(int row, int col);            // 擦去地图上某一点的对象
  Point get_upstair();                     // 获取上楼点所在坐标
  Point get_downstair();                   // 获取下楼点所在坐标
  static bool is_in_map(int row, int col); // 判断一点是否在 map 中
private:
  int _data[12][12]; // 地图为 11x11
  Point find(int id);
};

class MapList {
public:
  void init();                             // 地图列表的初始化函数
  Map get_map(int floor);                  // 通过层数获取当前层数的地图
  void erase(int floor, int row, int col); // 擦去某一层地图上某一点的对象

private:
  std::vector<Map> _data;
};