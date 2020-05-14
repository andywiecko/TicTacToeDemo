#ifndef SRC_MISC_CONSTANTS
#define SRC_MISC_CONSTANTS

#include <limits>

namespace Constants
{
    // infinity
    const double infty = std::numeric_limits<double>::infinity();
    // negative infinity
    const double m_infty = -std::numeric_limits<double>::infinity();

} // namespace Constants

#endif