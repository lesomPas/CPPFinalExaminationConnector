// checker.cpp

// public all
#define private public
#define protected public
#include "global.h"
#undef private
#undef protected

#include <direct.h>
#include <fstream>
#include <functional>
#include <io.h>
#include <iostream>
#include <vector>

class Test_File_RW
{
  public:
    Test_File_RW(int task_id, int times, std::function<void()> f)
    {
        for (int i = 1; i <= times; ++i)
        {
            std::string in = "./test/Task" + std::to_string(task_id) + "/" + std::to_string(i) + ".in";
            std::string out = "./test/Task" + std::to_string(task_id) + "/" + std::to_string(i) + ".out";
            std::ifstream fin(in);
            std::ofstream fout(out);
            auto cin_buf = std::cin.rdbuf();
            auto cout_buf = std::cout.rdbuf();
            std::cin.rdbuf(fin.rdbuf());
            std::cout.rdbuf(fout.rdbuf());
            f();
            std::cin.rdbuf(cin_buf);
            std::cout.rdbuf(cout_buf);
        }
    }
    static std::string GetOutput(int task_id)
    {
        std::string out = "./test/Task" + std::to_string(task_id) + "/" + std::to_string(1) + ".out";
        return out;
    }
};

void test(const std::string &arg);

std::vector<std::function<void(int)>> tasks;

int main(int argc, char *argv[])
{

    // copy all args
    std::vector<std::string> args;
    for (int i = 1; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    // task 1 player::init
    tasks.emplace_back([](int times) {
        Test_File_RW(1, times, []() {
            Player player;
            player.init();
            player.print();
        });
    });

    // task 2 pick_key
    tasks.emplace_back([](int times) {
        Test_File_RW(2, times, []() {
            Player player;
            player.init();
            int t;
            std::cin >> t;
            for (int j = 1; j <= t; ++j)
            {
                int id;
                std::cin >> id;
                player.pick_key(id);
            }
        });
    });

    // task 3 pick_item
    tasks.emplace_back([](int times) {
        Test_File_RW(3, times, []() {
            Player player;
            player.init();
            int t;
            std::cin >> t;
            for (int j = 1; j <= t; ++j)
            {
                int id, hp, attack, defense, money;
                std::cin >> id >> hp >> attack >> defense >> money;
                player.pick_item({id, hp, attack, defense, money});
            }
        });
    });

    // task 4 open_door
    tasks.emplace_back([](int times) {
        Test_File_RW(4, times, []() {
            Player player;
            player.init();
            int t;
            std::cin >> t;
            for (int j = 1; j <= t; ++j)
            {
                int id;
                std::cin >> id;
                player.open_door(id);
            }
        });
    });

    // task 5 monster::init
    tasks.emplace_back([](int times) {
        Test_File_RW(5, times, []() {
            MonsterList list;
            list.init();
            for (const auto &item : list._data)
            {
                std::cout << item.id << ' ' << item.hp << ' ' << item.attack << ' ' << item.defense << ' ' << item.money
                          << '\n';
            }
        });
    });

    // task 6 fight
    tasks.emplace_back([](int times) {
        Test_File_RW(6, times, []() {
            Player player;
            player.init();
            MonsterList list;
            list.init();
            for (const auto &item : list._data)
            {
                if (!player.fight(item))
                {
                    std::cout << "Lose\n";
                }
            }
        });
    });

    // task 7 npc::init
    tasks.emplace_back([](int times) {
        std::ofstream out(Test_File_RW::GetOutput(7));
        NPCList list;
        list.init();
        for (const auto &item : list._data)
        {
            out << item.id << ' ' << item.hp << ' ' << item.attack << ' ' << item.defense << ' ' << item.money << '\n';
        }
        out.close();
    });

    // task 8 interact
    tasks.emplace_back([](int times) {
        Test_File_RW(8, times, []() {
            Player player;
            player.init();
            NPCList list;
            list.init();
            int t;
            std::cin >> t;
            for (int i = 1; i <= t; ++i)
            {
                int id;
                std::cin >> id;
                if (!player.interact(list.find(id)))
                {
                    std::cout << "Failed\n";
                }
            }
        });
    });

    // task 9 move id = 2
    tasks.emplace_back([](int times) {
        Test_File_RW(9, times, []() {
            Game game;
            game.player_data.init();
            game.map_data.init();
            game.current_map = game.map_data.get_map(1);

            int t;
            std::cin >> t;

            for (int i = 1; i <= t; ++i)
            {
                int a, b;
                std::cin >> a >> b;
                game.move(a, b);
            }
        });
    });

    // task 10 move id = 3
    tasks.emplace_back([](int times) {
        Test_File_RW(10, times, []() {
            Game game;
            game.player_data.init();
            game.map_data.init();
            game.current_map = game.map_data.get_map(1);

            int t;
            std::cin >> t;

            for (int i = 1; i <= t; ++i)
            {
                int a, b;
                std::cin >> a >> b;
                game.move(a, b);
            }
        });
    });

    // task 11 move 11<= id <= 13
    tasks.emplace_back([](int times) {
        Test_File_RW(11, times, []() {
            Game game;
            game.player_data.init();
            game.map_data.init();
            game.current_map = game.map_data.get_map(1);

            int t;
            std::cin >> t;

            for (int i = 1; i <= t; ++i)
            {
                int a, b;
                std::cin >> a >> b;
                game.move(a, b);
            }
        });
    });

    // task 12 move Monster::is_monster(id)
    tasks.emplace_back([](int times) {
        Test_File_RW(12, times, []() {
            Game game;
            game.player_data.init();
            game.monster_data.init();
            game.map_data.init();
            game.current_map = game.map_data.get_map(1);

            int t;
            std::cin >> t;

            for (int i = 1; i <= t; ++i)
            {
                int a, b;
                std::cin >> a >> b;
                game.move(a, b);
            }
        });
    });

    for (const auto &item : args)
    {
        test(item);
    }
}

void test(const std::string &arg)
{
    const char dot = '_';
    int id = std::stoi(arg.substr(0, arg.find(dot)));
    int times = std::stoi(arg.substr(arg.find(dot) + 1));
    tasks[id - 1](times);
    return;
}