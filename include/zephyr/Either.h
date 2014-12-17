#ifndef ZEPHYR_EITHER_H
#define ZEPHYR_EITHER_H

#include <utility>

namespace zephyr
{

template <typename L, typename R>
class Either
{
public:
    bool left(L& x)
    {
        if (isLeft) x = l;
        return isLeft;
    }

    bool right(R& x)
    {
        if (!isLeft) x = r;
        return !isLeft;
    }

private:
    template <typename L_, typename R_>
    friend Either<L_, R_> Left(L_ x);

    template <typename L_, typename R_>
    friend Either<L_, R_> Right(R_ x);

    bool isLeft;
    union
    {
        L l;
        R r;
    };
};

template <typename L, typename R>
Either<L, R> Left(L x)
{
    Either<L, R> e;
    e.isLeft = true;
    e.l = std::move(x);
    return e;
}

template <typename L, typename R>
Either <L, R> Right(R x)
{
    Either<L, R> e;
    e.isLeft = false;
    e.r = std::move(x);
    return e;
}

}

#endif
