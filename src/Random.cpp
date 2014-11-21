#include "Random.h"

namespace util
{
namespace random
{

std::mt19937& device()
{
    static std::random_device rd;
    static std::mt19937 engine(rd());
    return engine;
}

int rollDice(int sides)
{
    std::uniform_int_distribution<> die(1,sides);
    return die(device());
}

Coin flipCoin()
{
    auto flip = rollDice(2);
    if (flip == 1) {
        return Coin::HEADS;
    } else {
        return Coin::TAILS;
    }
}

int rollD6()
{
    return rollDice(6);
}

}
}
