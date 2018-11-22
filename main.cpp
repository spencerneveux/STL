#include "BigInt.hpp"
#include <iostream>
using namespace std;
BigInt goldRabbits(int);
int fact(int);

int main() {
//  Main tester
    for (int n = 0; n <= 1000; n++) {
        cout << "\nThe GoldRabbit of ("<<n<<") is "<<goldRabbits(n);
   }
    for (int i = 0; i < 100; i++) {
        try {
            cout << "Fact("<<i<<"):"<<fact(i)<<endl;
        }catch(...) {
            cout << "Fact("<<i<<"):"<<"Overflow"<<endl;
        }
    }

}

BigInt goldRabbits(int n) {
    static map<int, BigInt> map;
    if (n == 0 || n == 1)
        return 1;
    std::map<int, BigInt>::iterator mit = map.find(n);
    if (mit == map.end())
        return map[n] = goldRabbits(n-1) + goldRabbits(n-2);
    else
        return mit->second;
}

int fact(int n) {
    if (n == 1)
        return 1;
    else
        return (n*fact(n-1));
}
