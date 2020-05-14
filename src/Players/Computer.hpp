#ifndef SRC_PLAYERS_COMPUTER_HPP
#define SRC_PLAYERS_COMPUTER_HPP

#include <iostream>
#include <vector>

#include "IPlayer.hpp"
#include "AI/Minimax.hpp"
#include "AI/PlayersInfo.hpp"
#include "../GameMap/GameMap.hpp"

namespace Player
{
    class Computer : virtual public IPlayer
    {
    private:
        PlayersInfo players;
        std::vector<IPlayer *> &activePlayers; // reference to active players in game
        
        void ReadPlayers()
        {
            std::vector<Field> fields;
            for(auto player : activePlayers)
            {
                Field field = player->GetField();
                if (field != this->GetField())
                {
                    fields.push_back(field);
                }
            }
            players = {GetField(), fields};
        }

    public:
        virtual void Move(GameMap &map)
        {
            ReadPlayers(); // player number may differ during the game
            Minimax minimax{map, players};
            minimax.Move();
        }

        Computer(Field _field, std::vector<IPlayer *> &_activePlayers)
            : activePlayers{_activePlayers}
        {
            SetField(_field);
        }
    };

} // namespace Player

#endif