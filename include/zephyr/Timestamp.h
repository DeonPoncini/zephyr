#ifndef ZEPHYR_TIMESTAMP_H
#define ZEPHYR_TIMESTAMP_H

#include <ctime>

namespace zephyr
{
namespace timestamp
{

time_t  s();
time_t ms();
time_t us();
time_t ns();

}
}

#endif
