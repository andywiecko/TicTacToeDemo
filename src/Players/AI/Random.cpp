#include "Random.hpp"

namespace Player
{
    void Random::Move()
    {
        size_t index{0};
        std::vector<size_t> indices;
        for (auto field : map)
        {
            if (field == Field::_)
                indices.push_back(index);
            index++;
        }

        size_t N = indices.size(); // number of empty fields
        size_t randomField = indices.at(std::rand() % N);
        std::cout << randomField;
        map.SetField(self, randomField);
    }

    Random::Random(GameMap &_map, Field _self) : map{_map}, self{_self}
    {
    }

} // namespace Player