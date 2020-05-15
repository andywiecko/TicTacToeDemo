#include "FieldCout.hpp"

std::ostream &operator<<(std::ostream &out, Field field)
{
    std::string outString{FieldConverter::Convert(Field::_)};
    switch (field)
    {
    case Field::O:
        outString = FieldConverter::Convert(Field::O);
        break;
    case Field::X:
        outString = FieldConverter::Convert(Field::X);
        break;
    default:
        break;
    }

    out << outString;
    return out;
}