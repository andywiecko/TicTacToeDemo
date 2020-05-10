#ifndef SRC_PLAYERS_IPLAYER_HPP
#define SRC_PLAYERS_IPLAYER_HPP

#include <string>

#include "../GameMap/GameMap.hpp"

class IPlayer
{
private:
    Field field;
    std::string name;

public:
    void SetName(std::string _name)
    {
        name = _name;
    }

    void SetField(Field _field)
    {
        field = _field;
    }

    Field GetField()
    {
        return field;
    }

    virtual void Move(GameMap &map) = 0;
    virtual ~IPlayer() {}
};

#endif