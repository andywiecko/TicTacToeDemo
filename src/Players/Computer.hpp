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

        void ReadPlayers();
        void Easy(GameMap &map);
        void Normal(GameMap &map);

    public:
        virtual void Move(GameMap &map);
        Computer(Field _field,
                 std::vector<IPlayer *> &_activePlayers,
                 Level _level = Level::Normal);
    };

} // namespace Player

#endif