#include "LongLong.h"
using namespace std;

    LongLong::LongLong(long bigPart, unsigned long smallPart)
    {
        this->bigPart = bigPart;
        this->smallPart = smallPart;
    }

    LongLong LongLong::operator+(LongLong other)
    {
        LongLong result;
        double first = stod(to_string(this->bigPart) + to_string(this->smallPart));
        double second = stod(to_string(other.bigPart) + to_string(other.smallPart));
        string tmp = to_string(first + second);
        string str = tmp.substr(0, tmp.find('.'));
        string s1 = "";
        string s2 = "";
        if (str.length() == 1)
        {
            result.bigPart = stol(str);
            result.smallPart = 0;
        }
        else
        {
            s1 = str.substr(0, str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2) + 1);
            s2 = str.substr(str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2 + 1), str.length());
            result.bigPart = stol(s1);
            result.smallPart = stol(s2);
        }

        return result;
    }

    LongLong LongLong::operator-(LongLong other)
    {
        LongLong result;
        double first = stod(to_string(this->bigPart) + to_string(this->smallPart));
        double second = stod(to_string(other.bigPart) + to_string(other.smallPart));
        string tmp = to_string(first - second);
        string str = tmp.substr(0, tmp.find('.'));
        string s1 = "";
        string s2 = "";
        if (str.length() == 1)
        {
            result.bigPart = stol(str);
            result.smallPart = 0;
        }
        else
        {
            s1 = str.substr(0, str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2) + 1);
            s2 = str.substr(str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2 + 1), str.length());
            result.bigPart = stol(s1);
            result.smallPart = stol(s2);
        }

        return result;
    }

    LongLong LongLong::operator*(LongLong other)
    {
        LongLong result;
        double first = stod(to_string(this->bigPart) + to_string(this->smallPart));
        double second = stod(to_string(other.bigPart) + to_string(other.smallPart));
        string tmp = to_string(first * second);
        string str = tmp.substr(0, tmp.find('.'));
        string s1 = "";
        string s2 = "";
        if (str.length() == 1)
        {
            result.bigPart = stol(str);
            result.smallPart = 0;
        }
        else
        {
            s1 = str.substr(0, str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2) + 1);
            s2 = str.substr(str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2 + 1), str.length());
            result.bigPart = stol(s1);
            result.smallPart = stol(s2);
        }

        return result;
    }

    LongLong LongLong::operator/(LongLong other)
    {
        LongLong result;
        double first = stod(to_string(this->bigPart) + to_string(this->smallPart));
        double second = stod(to_string(other.bigPart) + to_string(other.smallPart));
        string tmp = to_string(first / second);
        string str = tmp.substr(0, tmp.find('.'));
        string s1 = "";
        string s2 = "";
        if (str.length() == 1)
        {
            result.bigPart = stol(str);
            result.smallPart = 0;
        }
        else
        {
            s1 = str.substr(0, str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2) + 1);
            s2 = str.substr(str.length() % 2 == 0 ? str.length() / 2 : (str.length() / 2 + 1), str.length());
            result.bigPart = stol(s1);
            result.smallPart = stol(s2);
        }

        return result;
    }

    bool LongLong::operator==(LongLong other)
    {
        return this->bigPart == other.bigPart && this->smallPart == other.smallPart;
    }

    bool LongLong::operator!=(LongLong other)
    {
        return !(this->bigPart == other.bigPart && this->smallPart == other.smallPart);
    }

    bool LongLong::operator>(LongLong other)
    {
        bool isOver = false;
        if (this->bigPart > other.bigPart)
            isOver = true;
        if (this->bigPart == other.bigPart && this->smallPart > other.smallPart)
            isOver = true;
        return isOver;
    }

    bool LongLong::operator<(LongLong other)
    {
        bool isUnder = false;
        if (this->bigPart < other.bigPart)
            isUnder = true;
        if (this->bigPart == other.bigPart && this->smallPart < other.smallPart)
            isUnder = true;
        return isUnder;
    }

    string LongLong::toString()
    {
        string result = "";
        result += to_string(bigPart);
        if(smallPart != 0)
            result += to_string(smallPart);
        return result;
    }

long LongLong::getBigPart()
{
    return bigPart;
}

void LongLong::setBigPart(long bigPart)
{
    this->bigPart = bigPart;
}

unsigned long LongLong::getSmallPart()
{
    return smallPart;
}

void LongLong::setSmallPart(unsigned long smallPart)
{
    this->smallPart = smallPart;
}