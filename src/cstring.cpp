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

char** make_copy(const std::vector<std::string>& v, int* count)
{
    *count = v.size();
    if (*count > 0) {
        char** ret = new char*[*count];
        for (auto i = 0; i < *count; i++) {
            ret[i] = make_copy(v[i]);
        }
        return ret;
    } else {
        return nullptr;
    }
}

void delete_copy(char** v, int count)
{
    for (auto i = 0; i < count; i++) {
        zephyr::cstring::delete_copy(v[i]);
    }
    delete [] v;
}

}
}
