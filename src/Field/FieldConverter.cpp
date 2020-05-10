#include "FieldConverter.hpp"

std::string FieldConverter::Convert(Field field)
{
    return map.at(field);
}

std::string FieldConverter::ConvertWithFrame(Field field)
{
    return "[" + FieldConverter::Convert(field) + "]";
}

const std::map<Field, std::string> FieldConverter::map{
    {Field::O, "O"},
    {Field::X, "X"},
    {Field::_, " "}};