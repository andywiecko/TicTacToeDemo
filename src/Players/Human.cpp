#include "Human.hpp"

namespace Player
{
    void Human::Move(GameMap &map)
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

    Human::Human(Field _field, std::string _name)
    {
        SetField(_field);
        SetName(_name);
    }

} // namespace Player