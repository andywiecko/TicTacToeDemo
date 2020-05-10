#include "FieldCout.hpp"

std::ostream &operator<<(std::ostream &out, Field field)
{
    std::string outString{"[ ]"};
    switch (field)
    {
    case Field::O:
        outString = FieldConverter::ConvertWithFrame(Field::O);
        break;
    case Field::X:
        outString = FieldConverter::ConvertWithFrame(Field::X);
        break;
    default:
        break;
    }

    out << outString;
    return out;
}