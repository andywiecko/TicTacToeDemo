#include "GameMap.hpp"

GameMap::GameMap()
{
    fields = {{{Field::_, Field::_, Field::_},
               {Field::_, Field::_, Field::_},
               {Field::_, Field::_, Field::_}}};
}

void GameMap::Print()
{
    for (auto &fieldsRow : fields)
    {
        for (auto &field : fieldsRow)
            std::cout << field << " ";
        std::cout << std::endl;
    }
}

bool GameMap::IsFull()
{
    for (auto &fieldsRow : fields)
        for (auto &field : fieldsRow)
            if (field == Field::_)
                return false;

    return true; // map does not contain Field::_
}

bool GameMap::SetField(Field field, size_t row, size_t col)
{
    // TODO add bound check
    if (row < 3 and col < 3)
    {
        Field currentField = fields.at(row).at(col);
        if (currentField == Field::_)
        {
            fields.at(row).at(col) = field;
            return true;
        }
        else
        {
            Console::Log("Field is already occupied! Try again.\n");
            return false;
        }
    }
    Console::Log("Out of bounds! Try again!\n");
    return false;
}

Field GameMap::GetField(size_t row, size_t col)
{
    return fields.at(row).at(col);
}

Field GameMap::GetField(Pair pair)
{
    int row = pair.at(0);
    int col = pair.at(1);
    return GetField(row, col);
}

Field &GameMap::GetFirstField()
{
    return *fields.front().begin();
}

Field *GameMap::begin()
{
    return fields.front().begin();
}

Field *GameMap::end()
{
    return fields.back().end();
}

// TODO auto filler
const std::vector<Pairs> GameMap::victoryConditions{
    {{0, 0}, {1, 1}, {2, 2}}, // diagonal
    {{0, 2}, {1, 1}, {2, 0}}, // antidiagonal
    {{0, 0}, {0, 1}, {0, 2}}, // cols (3)
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}}, // rows (3)
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}}};