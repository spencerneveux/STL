//Spencer Neveux
//BigInt
//CECS 282 (STL)
//11/12/18

#ifndef BigInt_hpp
#define BigInt_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class BigInt {
private:
    vector<int> v;
public:
    BigInt();
    BigInt(int);
    BigInt(string);
    BigInt operator+(const BigInt &num);
    BigInt goldRabbits(int);
    friend ostream &operator<<(ostream &out, BigInt);
    
};

#endif /* BigInt_hpp */
