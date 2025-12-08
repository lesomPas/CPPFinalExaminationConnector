#include "npc.h"
#include <algorithm>

// NPC初始化
void NPCList::init()
{
    // 任务7：完成NPCList的初始化
    // 提示：构建 NPC 变量 npc ，对其赋值后，使用 _data.emplace_back(npc) 将其添加至容器
    // 等待完成......
    return;
}

// 返回 id 相符的 NPC对象
NPC NPCList::find(int id) const
{
    auto it = std::find_if(_data.begin(), _data.end(), [id](const NPC &npc) { return npc.id == id; });
    if (it != _data.end())
    {
        return *it;
    }
    else
    {
        return NPC{};
    }
}

// 判断 id 是否为 NPC对象
bool NPC::is_npc(int id)
{
    return (200 <= id && id <= 201);
}