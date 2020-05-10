#ifndef SRC_GAMECONTROLLER_GAMEOVER_HPP
#define SRC_GAMECONTROLLER_GAMEOVER_HPP

#include <iostream>

#include "../GameMap/GameMap.hpp"

class GameOver
{
private:
    static bool CheckCondition(GameMap &map, const Pairs &cond)
    {
        const Pair pair = cond.at(0);
        Field field = map.GetField(pair);
        if (field == Field::_)
            return false;

        for (auto &_pair : cond)
        {
            if (field != map.GetField(_pair))
                return false;
        }
        return true;
    }

public:
    static bool End(GameMap map)
    {
        for (auto &cond : GameMap::victoryConditions)
        {
            if (CheckCondition(map, cond))
                return true;
        }
        return false;
    }

    static void Victory()
    {
        std::cout << "wygrał aaaa" << std::endl;
    }
};

#endif