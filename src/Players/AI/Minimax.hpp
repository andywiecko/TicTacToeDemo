#ifndef SRC_PLAYERS_AI_MINIMAX_HPP
#define SRC_PLAYERS_AI_MINIMAX_HPP

#include "../../GameMap/GameMap.hpp"
#include "../../GameController/GameOver.hpp"
#include "../../Misc/Constants.hpp"
#include "PlayersInfo.hpp"

namespace Player
{
    class Minimax
    {
        GameMap &map;
        PlayersInfo &players;
        double Minimizing(int depth);
        double Maximizing(int depth);
        double Layer(int depth, bool isMaximizing);

    public:
        void Move();
        Minimax(GameMap &_map, PlayersInfo &_players);
    };

} // namespace Player

#endif