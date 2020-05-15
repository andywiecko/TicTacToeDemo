#ifndef SRC_GAMECONTROLLER_GAMECONTROLLER_HPP
#define SRC_GAMECONTROLLER_GAMECONTROLLER_HPP

#include <vector>

#include "../Players/Player.hpp"

enum class GameMode
{
    PvP,
    PvC_EASY,
    PvC_NORMAL,
    CvC
};

class GameController
{
private:
    void DeletePlayers();

public:
    std::vector<IPlayer *> players;
    void PvPMode();
    void PvCMode(Player::Level level);
    void CvCMode();
    void SelectGameMode(GameMode gameMode);
    ~GameController();
};

#endif