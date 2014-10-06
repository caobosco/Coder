#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int len;
    while(cin >> len) {
        vector<int> vec(len);
        for(int i = 0; i < len; i++)
            cin >> vec[i];
        sort(vec.begin(), vec.end(), [](const int &a, const int &b) {
            return a > b;
        });
        for(auto &i:vec)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
