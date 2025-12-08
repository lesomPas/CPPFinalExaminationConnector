#include "map.h"
#include <iostream>

void Map::init() {
  for (int row = 1; row <= 11; ++row) {
    for (int col = 1; col <= 11; ++col) {
      std::cin >> _data[row][col];
    }
  }
  return;
}

int Map::get(int row, int col) { return _data[row][col]; }

void Map::erase(int row, int col) {
  _data[row][col] = 0;
  return;
}

bool Map::is_in_map(int row, int col) {
  return ((1 <= row && row <= 11) && (1 <= col && col <= 11));
}

Point Map::find(int id) {
  for (int row = 1; row <= 11; ++row) {
    for (int col = 1; col <= 11; ++col) {
      if (_data[row][col] == id) {
        return {row, col};
      }
    }
  }
  return {-1, -1};
}

Point Map::get_upstair() { return find(2); }

Point Map::get_downstair() { return find(3); }

void MapList::init() {
  int n;
  std::cin >> n;
  Map map;
  for (int i = 1; i <= n; i++) {
    map.init();
    _data.emplace_back(map);
  }
  return;
}

Map MapList::get_map(int floor) { return _data[floor - 1]; }

void MapList::erase(int floor, int row, int col) {
  _data[floor - 1].erase(row, col);
  return;
}