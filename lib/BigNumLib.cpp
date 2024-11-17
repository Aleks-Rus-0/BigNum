#include "BigNumLib.h"
#include <string>
#include <iostream>
#include <algorithm>

bignum::bignum() {
    _value = "0";
}

bignum::bignum(std::string x) {
    _value = x;
}

bignum operator + (const bignum& a, const bignum& b) { 
    std::string ans;
    std::string x = a._value, y = b._value;
    
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    if (x.size() > y.size()) swap(x, y);

    int ost = 0;
    for (int i = 0; i < x.size(); i++) {

        int add = (x[i]- '0') + (y[i] - '0');

        ans.push_back((add + ost) % 10 + '0');

        ost = (add + ost) / 10;
    }

    for (int i = x.size(); i < y.size(); i++) {
        int add = (y[i] - '0');
        ans.push_back((add + ost) % 10 + '0');
        ost = (add + ost) / 10;
    }

    if (ost) ans.push_back(ost + '0');
    reverse(ans.begin(), ans.end());

    return bignum{ans};
}

bignum operator * (const bignum& a, const bignum& b) {
    bignum ans;
    std::string x = a._value;
    std::string y = b._value;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    if (x.size() < y.size()) swap(x, y);
    if (y == "0") return ans;

    for (int i = 0; i < x.size(); i++) {
        int ost = 0; std::string s;
        for (int j = 0; j < y.size(); j++) {
            s.push_back(((x[i] - '0') * (y[j] - '0') + ost) % 10 + '0');
            ost = (((x[i] - '0') * (y[j] - '0') + ost) -  ((x[i] - '0') * (y[j] - '0') + ost) % 10 ) / 10;
        }
        if (ost != 0) s.push_back(ost + '0');
        reverse(s.begin(), s.end());
        for (int l = 0; l < i; l++) s.push_back('0');
        ans = ans + bignum{s};
    }
    return ans;
}


bool operator == (const int& x, const bignum& y) {
    int a = x;
    std::string b = y._value;
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        if (a % 10 != b[i] - '0') {
            std::cout << a % 10 << " " << b[i] - '0' << '\n';
            return false;
        }
        a = (a - a % 10) / 10;
    }
    return b.size() == std::to_string(x).size();
}

bool operator == (const bignum& x, const bignum& y) {
    return x._value == y._value;
}


std::istream& operator >> (std::istream& in, bignum& x) {
    in >> x._value;
    return in;
}

std::ostream& operator << (std::ostream& out, const bignum& x) {
    out << x._value;
    return out;
}

bool operator > (const bignum& x, const bignum& y) {
    if (x._value.size() == y._value.size()) {
        for (int i = 0; i < x._value.size(); i++) {
            if (x._value[i] - '0' < y._value[i] - '0') return true;
        }
        return false;
    }
    return x._value.size() < y._value.size();
}
