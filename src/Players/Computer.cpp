#include "Computer.hpp"

namespace Player
{
    void Computer::ReadPlayers()
    {
        std::vector<Field> fields;
        for (auto player : activePlayers)
        {
            Field field = player->GetField();
            if (field != this->GetField())
            {
                fields.push_back(field);
            }
        }
        players = {GetField(), fields};
    }

    void Computer::Easy(GameMap &map)
    {
        Random random{map, GetField()};
        random.Move();
    }

    void Computer::Normal(GameMap &map)
    {
        ReadPlayers(); // player number may differ during the game
        Minimax minimax{map, players};
        minimax.Move();
    }

    void Computer::Move(GameMap &map)
    {
        switch (level)
        {
        case Level::Normal:
            Normal(map);
            break;
        case Level::Easy:
            Easy(map);
            break;
        default:
            break;
        }
    }

    Computer::Computer(Field _field,
                       std::vector<IPlayer *> &_activePlayers,
                       Level _level)
        : activePlayers{_activePlayers}, level{_level}
    {
        SetField(_field);
        SetName("Computer");
    }
} // namespace Player