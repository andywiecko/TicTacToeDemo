#include "GameOver.hpp"

bool GameOver::CheckCondition(GameMap &map, const Pairs &cond, Field &winner)
{
    const Pair pair = cond.at(0);
    Field field = map.GetField(pair);
    if (field == Field::_)
        return false;

    for (auto &_pair : cond)
    {
        if (field != map.GetField(_pair))
            return false;
    }
    winner = field;
    return true;
}

void GameOver::Victory(IPlayer *player)
{
    Console::Log("\nWinner: " + player->Info());
}

void GameOver::Draw()
{
    Console::Log("\nDraw! There is no winner!\n");
}

bool GameOver::CheckWin(GameMap map, Field &winner)
{
    for (auto &cond : GameMap::victoryConditions)
    {
        if (CheckCondition(map, cond, winner))
            return true;
    }
    return false;
}

bool GameOver::CheckWin(GameMap map)
{
    Field winner;
    return GameOver::CheckWin(map, winner);
}

bool GameOver::HasFinished(GameMap map)
{
    return CheckWin(map) or map.IsFull();
}

bool GameOver::HasFinished(GameMap map, IPlayer *player)
{
    if (GameOver::CheckWin(map))
    {
        MapViewer::View(map);
        Victory(player);
        return true;
    }
    else if (map.IsFull())
    {
        MapViewer::View(map);
        GameOver::Draw();
        return true;
    }
    return false;
}