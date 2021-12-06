#pragma once
#include <iostream>
#include <string>
#include <math.h>

class LongLong
{
    long bigPart;
    unsigned long smallPart;

    public: 
    LongLong(long bigPart = 0, unsigned long smallPart = 0);

    long getBigPart();
    void setBigPart(long bigPart);

    unsigned long getSmallPart();
    void setSmallPart(unsigned long smallPart);

        LongLong operator+(LongLong other);

        LongLong operator-(LongLong other);

        LongLong operator*(LongLong other);

        LongLong operator/(LongLong other);

        bool operator==(LongLong other);

        bool operator!=(LongLong other);

        bool operator>(LongLong other);
        
        bool operator<(LongLong other);

        std::string toString();
};
