#ifndef ZEPHYR_C_STRING_H
#define ZEPHYR_C_STRING_H

#include <string>
#include <vector>

namespace zephyr
{
namespace cstring
{

char* make_copy(const std::string& s);
void delete_copy(char* c);

char** make_copy(const std::vector<std::string>& v, int* count);
void delete_copy(char** v, int count);

}
}

#endif
