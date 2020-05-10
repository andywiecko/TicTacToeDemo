#ifndef SRC_FIELD_FIELDCOUT_HPP
#define SRC_FIELD_FIELDCOUT_HPP

#include <ostream>
#include <string>
#include <iostream>

#include "FieldEnum.hpp"
#include "FieldConverter.hpp"

std::ostream & operator << (std::ostream & out, Field field);

#endif