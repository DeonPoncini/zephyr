#ifndef ZEPHYR_C_STRING_H
#define ZEPHYR_C_STRING_H

#include <string>

namespace zephyr
{
namespace cstring
{

char* make_copy(const std::string& s);
void delete_copy(char* c);

}
}

#endif
