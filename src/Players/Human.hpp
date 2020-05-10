#ifndef SRC_PLAYERS_HUMAN_HPP
#define SRC_PLAYERS_HUMAN_HPP

#include <iostream>

#include "IPlayer.hpp"
#include "../GameMap/GameMap.hpp"
#include "../Misc/Misc.hpp"

namespace Players
{

    class Human : virtual public IPlayer
    {
    public:
        virtual void Move(GameMap &map)
        {
            size_t row, col;
            Field field{GetField()};

            while (true)
            {
                Console::Clear();
                map.Print();
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

        ~Human()
        {
            std::cout << "say good night!" << std::endl;
        }
    };

} // namespace Players
#endif