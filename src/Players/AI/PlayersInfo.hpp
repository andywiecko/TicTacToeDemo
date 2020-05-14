#ifndef SRC_PLAYERS_AI_PLAYERSINFO_HPP
#define SRC_PLAYERS_AI_PLAYERSINFO_HPP

#include <vector>

#include "../../Field/Field.hpp"

class PlayersInfo
{
private:
    Field self;
    std::vector<Field> others;

public:
    PlayersInfo()
    {

    }

    PlayersInfo(Field _self, std::vector<Field> _others)
        : self{_self}, others{_others}
    {
    }
    Field GetSelf()
    {
        return self;
    }
    std::vector<Field> GetOthers()
    {
        return others;
    }
    Field GetLastOther()
    {
        return others.back();
    }
};

#endif