#ifndef ZEPHYR_TO_STRING
#define ZEPHYR_TO_STRING

#include <string>
#include <sstream>

namespace zephyr
{

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}

}

#endif
