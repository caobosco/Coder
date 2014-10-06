#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void reverse(string &in, int l, int r) {
    char tmp;
    r--;
    while(l < r) {
        tmp = in[l];
        in[l] = in[r];
        in[r] = tmp;
        l++, r--;
    }
    return;
}

int main(){
    string in;
    int shift;
    while(cin >> in) {
        cin >> shift;
        reverse(in, 0, shift);
        reverse(in, shift, in.size());
        reverse(in, 0, in.size());
        cout << in << endl;
    }
    return 0;
}
