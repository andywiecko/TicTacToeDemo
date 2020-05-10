#ifndef SRC_GAMEMAP_GAMEMAP_HPP
#define SRC_GAMEMAP_GAMEMAP_HPP

#include <array>
#include <vector>
#include <iostream>

#include "../Field/Field.hpp"
#include "../Misc/Misc.hpp"

using Fields = std::array<std::array<Field, 3>, 3>;
using Pair = std::array<int, 2>;
using Pairs = std::vector<Pair>;

class GameMap
{
    friend class GameOver;
    Fields fields;
    static const std::vector<Pairs> victoryConditions;

public:
    GameMap();
    void Print();
    bool SetField(Field field, size_t row, size_t col);
    Field GetField(size_t row, size_t col);
    Field GetField(Pair pair);
};

#endif