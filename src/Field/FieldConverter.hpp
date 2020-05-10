#ifndef SRC_FIELD_FIELDCONVERTER_HPP
#define SRC_FIELD_FIELDCONVERTER_HPP

#include <map>
#include <string>

#include "FieldEnum.hpp"

class FieldConverter
{
private:
    static const std::map<Field, std::string> map;

public:
    static std::string Convert(Field field);
    static std::string ConvertWithFrame(Field field);

};

#endif