//Spencer Neveux
//CECS 282 (STL)
// 11/12/18

#include "BigInt.hpp"
#include <iostream>
using namespace std;

//Null Constructor
BigInt::BigInt() {
    v.push_back(0);
}

//Overloaded Int constructor
BigInt::BigInt(int n) {
    while(n != 0) {
        int num = n % 10;
        v.push_back(num);
        n /= 10;
    }
}

//String constructor
BigInt::BigInt(string num) {
    string::reverse_iterator rit;
    for (rit = num.rbegin(); rit != num.rend(); rit++) {
        int number = *rit - 48;
        v.push_back(number);
    }
}

//Operator+
BigInt BigInt::operator+(const BigInt &B) {
    vector<int> vResult;
    if (v.size() >= B.v.size()) {
        // Scan through smaller vector
        int carry = 0;
        for (int i = 0; i < B.v.size(); i++) {
            int sum = v[i] + B.v[i] + carry;
            vResult.push_back(sum%10);
            carry = sum/10;
        }
        // Scan through remaining digits in bigger vector
        for (int j = B.v.size(); j < v.size(); j++) {
            int sum = v[j] + carry;
            vResult.push_back(sum%10);
            carry = sum/10;
        }
        
        if (carry)
            vResult.push_back(carry);
        
        this->v.clear();
        this->v = vResult;
    }else {
        // Scan through smaller vector
        int carry = 0;
        for (int i = 0; i < v.size(); i++) {
            int sum = v[i] + B.v[i] + carry;
            vResult.push_back(sum%10);
            carry = sum/10;
        }
        // Scan through remaining digits in bigger vector
        for (int j = v.size(); j < B.v.size(); j++) {
            int sum = B.v[j] + carry;
            vResult.push_back(sum%10);
            carry = sum/10;
        }
        
        if (carry)
            vResult.push_back(carry);
        
        this->v.clear();
        this->v = vResult;
    }

    return (*this);
}



//Overloading Cout
ostream &operator<<(ostream &out, BigInt B) {
    vector<int>::reverse_iterator it;
    for (it = B.v.rbegin(); it != B.v.rend(); it++) {
        out << *it;
    }
    return out;
}
