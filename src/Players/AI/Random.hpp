#ifndef SRC_PLAYERS_AI_RANDOM_HPP
#define SRC_PLAYERS_AI_RANDOM_HPP

#include <cstdlib>

#include "../../GameMap/GameMap.hpp"

namespace Player
{

    class Random
    {
    private:
        GameMap &map;
        Field self;

    public:
        void Move()
        {
            size_t index;
            std::vector<size_t> indices;
            for(auto field : map)
            {
                if (field == Field::_)
                    indices.push_back(index);
                index++;
            }

            size_t N = indices.size(); // number of empty fields
            size_t randomField = std::rand() % N;
            map.SetField(self, randomField);

        }

        Random(GameMap &_map, Field _self) : map{_map}, self{_self}
        {
        }
    };

} // namespace Player

#endif