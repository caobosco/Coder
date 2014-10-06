#include <algorithm>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *arr = new int(m + n);
        merge(A, A + m, B, B + n, arr);
        if (m == 0 && n == 0)
            return 0.0;
        else return arr[(m + n) >> 1 + (m+n)&0x1];
    }
};

int main() {
    int arr1[] = {};
    int arr2[] = {1,2,3,4,5};
    Solution sol;
    sol.findMedianSortedArrays(arr1, 0, arr2, 5);
    return 0;
}    
