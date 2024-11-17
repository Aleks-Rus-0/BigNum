#pragma once

#include <string>

class bignum
{
private:
    std::string _value;
public:
    bignum();
    friend std::istream& operator >> (std::istream& in, bignum& x);
    friend std::ostream& operator << (std::ostream& out, const bignum& x);

    friend bignum operator + (const bignum& a, const bignum& b);
    friend bignum operator * (const bignum& a, const bignum& b);

    friend bool operator == (const int& x, const bignum& y);
    friend bool operator == (const bignum& x, const bignum& y);

    friend bool operator > (const bignum& x, const bignum& y);

    
};