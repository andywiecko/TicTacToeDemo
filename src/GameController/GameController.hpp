#ifndef SRC_GAMECONTROLLER_GAMECONTROLLER_HPP
#define SRC_GAMECONTROLLER_GAMECONTROLLER_HPP

#include <vector>

#include "../Players/Player.hpp"

enum class GameMode
{
    PvP,
    PvC,
    CvC
};

class GameController
{
public: // make private
    std::vector<IPlayer *> players;
    void PvPMode();
    void PvCMode();
    void CvCMode();

public:
    void SelectGameMode(GameMode gameMode);
    ~GameController();
};

#endif