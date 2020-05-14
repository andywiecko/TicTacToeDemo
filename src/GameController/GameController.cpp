#include "GameController.hpp"

void GameController::PvPMode()
{
    players = {
        new Player::Human{Field::O, "Player 1"},
        new Player::Human{Field::X, "Player 2"}};
}

void GameController::PvCMode()
{
    players = {
        new Player::Human{Field::O, "Player 1"},
        new Player::Computer{Field::X, players}};
}

void GameController::CvCMode()
{
    players = {
        new Player::Computer{Field::O, players},
        new Player::Computer{Field::X, players}};
}

void GameController::SelectGameMode(GameMode gameMode)
{
    switch (gameMode)
    {
    case GameMode::PvP:
        PvPMode();
        break;

    case GameMode::PvC:
        PvCMode();
        break;

    case GameMode::CvC:
        CvCMode();
        break;

    default:
        break;
    }
}

GameController::~GameController()
{
    for (auto player : players)
        delete player;
}