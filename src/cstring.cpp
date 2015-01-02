#include <zephyr/cstring.h>

#include <cstring>

namespace zephyr
{
namespace cstring
{

char* make_copy(const std::string& s)
{
    auto c = new char[s.size() + 1];
    memcpy(c, s.data(), s.size()*sizeof(char));
    c[s.size()] = '\0';
    return c;
}

void delete_copy(char* c)
{
    delete[] c;
}

}
}
