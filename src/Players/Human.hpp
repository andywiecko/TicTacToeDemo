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
        virtual void Move(GameMap &map)
        {
            size_t row, col;
            Field field{GetField()};

            Console::Log(Info());
            while (true)
            {
                Console::ReadLine("Select row: ", row);
                Console::ReadLine("Select column: ", col);
                if (map.SetField(field, row, col))
                    break;
            }
        }

        Human(Field _field, std::string _name)
        {
            SetField(_field);
            SetName(_name);
        }

    };

} // namespace Players
#endif