#ifndef UTIL_RANDOM_H
#define UTIL_RANDOM_H

#include <random>

namespace util
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
