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

    void PvPMode()
    {
        players = {
            new Player::Human{Field::O, "Player 1"},
            new Player::Human{Field::X, "Player 2"}};
    }

    void PvCMode()
    {
        players = {
            new Player::Human{Field::O, "Player 1"},
            new Player::Computer{Field::X}};
    }

public:
    void SelectGameMode(GameMode gameMode)
    {
        switch (gameMode)
        {
        case GameMode::PvP:
            PvPMode();
            break;

        case GameMode::PvC:
            PvCMode();
            break;

        default:
            break;
        }
    }

    ~GameController()
    {
        for (auto player : players)
            delete player;
    }
};

#endif