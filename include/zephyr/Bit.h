#ifndef ZEPHYR_BIT_H
#define ZEPHYR_BIT_H

namespace zephyr
{

class Bit
{
public:
    Bit(bool _value);

    operator bool();

    bool test() const;
    void flip();
    void set();
    void clear();

private:
    bool value;
};

}

#endif
