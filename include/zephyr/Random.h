#ifndef ZEPHYR_RANDOM_H
#define ZEPHYR_RANDOM_H

#include <random>

namespace zephyr
{
namespace random
{

enum class Coin
{
    HEADS,
    TAILS
};

std::mt19937& device();
int rollDice(int sides);
Coin flipCoin();
int rollD6();

}
}

#endif
