#ifndef SRC_PLAYERS_HUMAN_HPP
#define SRC_PLAYERS_HUMAN_HPP

#include <iostream>

#include "IPlayer.hpp"
#include "../GameMap/GameMap.hpp"
#include "../Misc/Console.hpp"

namespace Player
{

    class Human : virtual public IPlayer
    {
    public:
        virtual void Move(GameMap &map);
        Human(Field _field, std::string _name);
    };

} // namespace Player
#endif