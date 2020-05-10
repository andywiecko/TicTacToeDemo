#ifndef SRC_PLAYERS_COMPUTER_HPP
#define SRC_PLAYERS_COMPUTER_HPP

#include <iostream>

#include "IPlayer.hpp"
#include "../GameMap/GameMap.hpp"

namespace Players
{

    class Computer : virtual public IPlayer
    {
    public:
        virtual void Move(GameMap &map)
        {
        }

        Computer(Field _field)
        {
            SetField(_field);
        }

    };

} // namespace Players

#endif