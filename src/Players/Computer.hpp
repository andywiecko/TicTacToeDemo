#ifndef SRC_PLAYERS_COMPUTER_HPP
#define SRC_PLAYERS_COMPUTER_HPP

#include <iostream>
#include <vector>

#include "IPlayer.hpp"
#include "AI/Minimax.hpp"
#include "AI/Random.hpp"
#include "AI/PlayersInfo.hpp"
#include "../GameMap/GameMap.hpp"

namespace Player
{

    enum class Level
    {
        Easy,
        Normal
    };

    class Computer : virtual public IPlayer
    {
    private:
        PlayersInfo players;
        std::vector<IPlayer *> &activePlayers; // reference to active players in game
        Level level;

        void ReadPlayers()
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

        void Easy(GameMap &map)
        {
            Random random{map, GetField()};
            random.Move();
        }

        void Normal(GameMap &map)
        {
            ReadPlayers(); // player number may differ during the game
            Minimax minimax{map, players};
            minimax.Move();
        }

    public:
        virtual void Move(GameMap &map)
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

        Computer(Field _field, std::vector<IPlayer *> &_activePlayers, Level _level = Level::Normal)
            : activePlayers{_activePlayers}, level{_level}
        {
            SetField(_field);
            SetName("Computer");
        }
    };

} // namespace Player

#endif