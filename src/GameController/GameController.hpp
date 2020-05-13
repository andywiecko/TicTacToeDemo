#ifndef SRC_GAMECONTROLLER_GAMECONTROLLER_HPP
#define SRC_GAMECONTROLLER_GAMECONTROLLER_HPP

#include <vector>

#include "../Players/Player.hpp"

enum class GameMode
{
    PvP,
    PvC
};

class GameController
{
public: // make private
    std::vector<IPlayer *> players;
    void PvPMode();
    void PvCMode();

public:
    void SelectGameMode(GameMode gameMode);
    ~GameController();
};

#endif