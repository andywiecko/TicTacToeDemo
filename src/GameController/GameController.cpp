#include "GameController.hpp"

void GameController::PvPMode()
{
    players = {
        new Player::Human{Field::O, "Player 1"},
        new Player::Human{Field::X, "Player 2"}};
}

void GameController::PvCMode(Player::Level level)
{
    players = {
        new Player::Human{Field::O, "Player 1"},
        new Player::Computer{Field::X, players, level}};
}

void GameController::CvCMode()
{
    players = {
        new Player::Computer{Field::O, players},
        new Player::Computer{Field::X, players}};
}

void GameController::SelectGameMode(GameMode gameMode)
{
    DeletePlayers();
    switch (gameMode)
    {
    case GameMode::PvP:
        PvPMode();
        break;

    case GameMode::PvC_EASY:
        PvCMode(Player::Level::Easy);
        break;

    case GameMode::PvC_NORMAL:
        PvCMode(Player::Level::Normal);
        break;

    case GameMode::CvC:
        CvCMode();
        break;

    default:
        Console::Log("Not implemented or invalid GameMode");
        break;
    }
}

void GameController::DeletePlayers()
{
    for (auto player : players)
        delete player;
    players.clear();
}

GameController::~GameController()
{
    DeletePlayers();
}