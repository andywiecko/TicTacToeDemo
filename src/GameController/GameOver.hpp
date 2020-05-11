#ifndef SRC_GAMECONTROLLER_GAMEOVER_HPP
#define SRC_GAMECONTROLLER_GAMEOVER_HPP

#include <iostream>

#include "../Players/Player.hpp"
#include "../GameMap/GameMap.hpp"
#include "../GameMap/MapViewer.hpp"

class GameOver
{
private:
    static bool CheckCondition(GameMap &map, const Pairs &cond);
    static void Victory(IPlayer *player);
    static void Draw();

public:
    static bool End(GameMap map);
    static bool HasFinished(GameMap map);
    static bool HasFinished(GameMap map, IPlayer *player);
    
};

#endif