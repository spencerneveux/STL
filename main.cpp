#include "BigInt.hpp"
#include <iostream>
using namespace std;
BigInt goldRabbits(int);
int fact(int);

int main() {
//    //Testing Null Constructor
//    BigInt b1;
//    cout << b1 << endl;
//
//    //Testing overloaded int constructor
//    BigInt b2(23456);
//    cout << b2 << endl;
//
//    //Testing overloaded string constructor
//    BigInt b3("1234567890123456789123456789");
//    cout << b3 << endl;
//
//    //Testing operator+
//    BigInt b4(1359);
//    BigInt b5(2468);
//    BigInt b6 = b4 + b5;
//    cout << b6  << endl;
//
//    BigInt b7(123);
//    BigInt b8(54289);
//    BigInt b9 = b7 + b8;
//    cout << b9 << endl;
    
    // Main tester
    for (int n = 0; n <= 1000; n++) {
        cout << "\nThe GoldRabbit of ("<<n<<") is "<<goldRabbits(n);
//        for (int i = 0; i < 100; i++) {
//            try {
//                cout << "Fact("<<i<<"):"<<fact(i)<<endl;
//            }catch(...) {
//                cout << "Fact("<<i<<"):"<<"Overflow"<<endl;
//            }
//        }
    }
}

BigInt goldRabbits(int n) {
    static map<int, BigInt> farm;
    if (n == 0 || n == 1) {
        farm[n] = 1;
        return farm[n];
    }else {
        BigInt result = farm[n-1] + farm[n-2];
        farm[n] = result;
        return farm[n];
    }
}

int fact(int n) {
    if (n == 1)
        return 1;
    else
        return (n*fact(n-1));
}
