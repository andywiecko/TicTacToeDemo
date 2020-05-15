#include "FieldCout.hpp"

std::ostream &operator<<(std::ostream &out, Field field)
{
    out << FieldConverter::Convert(field);
    return out;
}