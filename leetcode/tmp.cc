#include <iostream>
#include <cstring>
using namespace std;


int main() {
    long a = 0;
    long long b = 0;
    cout << sizeof(a) << ' ' << sizeof(b) << endl;
    char *str= "a";
    cout << strlen(str) << ' ' << sizeof(str) << endl;
    return 0;
}
