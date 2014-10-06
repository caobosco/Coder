#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(int a, int b) {
    string s1, s2;
    stringstream ss;
    ss << a;
    ss << b;
    ss >> s1;
    ss.clear();
    ss << b;
    ss << a;
    ss >> s2;
    return s1 < s2;
}

int main(){
    int m;
    while(scanf("%d", &m) != EOF) {
        int *arr = new int[m];
        for (int i = 0; i < m; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+m, cmp);
        stringstream ss;
        for(int i = 0; i < m; ++i)
            ss<<arr[i];
        string str;
        ss>>str;
        cout << str << endl;
        delete[] arr;
    }
    return 0;
}
