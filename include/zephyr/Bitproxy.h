#ifndef ZEPHYR_BITPROXY_H
#define ZEPHYR_BITPROXY_H

#include <climits>
#include "Bit.h"

namespace zephyr
{

template<typename T, size_t N = CHAR_BIT>
class Bitproxy
{
public:
    Bitproxy(T _value);

    operator T();
          Bit operator [](size_t bit);
    const Bit operator [](size_t bit) const;

    constexpr size_t size() const;
    size_t minsize() const;
    size_t minbytes() const;
    T get() const;

private:
    T value;
};

template<typename T, size_t N>
Bitproxy<T,N>::Bitproxy(T _value) :
    value(_value)
{
}

template<typename T, size_t N>
Bitproxy<T,N>::operator T()
{
    return value;
}

template<typename T, size_t N>
Bit Bitproxy<T,N>::operator [](size_t bit)
{
    return Bit(value & 1 << bit);
}

template<typename T, size_t N>
const Bit Bitproxy<T,N>::operator [](size_t bit) const
{
    return const_cast<const Bit&>(*this[bit]);
}

template<typename T, size_t N>
constexpr size_t Bitproxy<T,N>::size() const
{
    return sizeof(T)*N;
}

template<typename T, size_t N>
T Bitproxy<T,N>::get() const
{
    return value;
}

template<typename T, size_t N>
size_t Bitproxy<T,N>::minsize() const
{
    T v(value);
    size_t r = 0;
    while (v >>= 1) {
        r++;
        if (r == size()) return r;
    }
    return r + 1;
}

template<typename T, size_t N>
size_t Bitproxy<T,N>::minbytes() const
{
    return (minsize() + N - 1) / N;
}

}

#endif
