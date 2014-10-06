#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int max_length(int n) {
    if ( n < 3) return 1;
    vector<int> max_len(n, 0);
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i/2; j++) 
            max_len[i- 1] = max(max_len[i - 1], max(j*(i - j), j*max_len[i - j - 1] ) );
    }
    return max_len[n - 1];
}

int main() {
    int length;
    while( cin >> length) 
        cout << max_length(length) << endl;
    return 0;
}
