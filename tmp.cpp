#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;
void test() {
class A {
public:
    A() {
        cout << "A" << endl;
    }
};

class B{
public:
    B() {
        cout << "B" << endl;
    }
    A a;
};
    B* b = new B();
}

void test1()
{
char string[10];
char* str1 ="0123456789";
strcpy( string, str1 );
}
int main (){
    char *pointer = "what";
    char array[5] = "what";
    int a[][3]={1,2,3,4,5};
    cout << a[0][4] << ' ' << sizeof(a[0]) << endl;
    array[0] = 't';
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    //B* b = new B();
    test1();
    return 0;
}
