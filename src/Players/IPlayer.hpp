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

    std::string GetName()
    {
        return name;
    }

    void SetField(Field _field)
    {
        field = _field;
    }

    Field GetField()
    {
        return field;
    }

    std::string Info()
    {
        return name + " (" + FieldConverter::Convert(field) + ")\n";
    }

    virtual void Move(GameMap &map) = 0;
    virtual ~IPlayer() {}
};

#endif