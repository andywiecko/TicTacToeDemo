#ifndef SRC_PLAYERS_AI_RANDOM_HPP
#define SRC_PLAYERS_AI_RANDOM_HPP

#include <cstdlib>

#include "../../GameMap/GameMap.hpp"

namespace Player
{

    class Random
    {
    private:
        GameMap &map;
        Field self;

    public:
        void Move();
        Random(GameMap &_map, Field _self);
    };

} // namespace Player

#endif