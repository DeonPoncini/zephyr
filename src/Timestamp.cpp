#include <zephyr/Timestamp.h>

#include <chrono>

namespace zephyr
{
namespace timestamp
{

template <typename T>
time_t t()
{
    auto t = std::chrono::duration_cast<T>(
           std::chrono::high_resolution_clock::now().time_since_epoch());
    return t.count();
}

time_t s()
{
    return t<std::chrono::seconds>();
}

time_t ms()
{
    return t<std::chrono::milliseconds>();
}

time_t us()
{
    return t<std::chrono::microseconds>();
}

time_t ns()
{
    return t<std::chrono::nanoseconds>();
}

}
}
