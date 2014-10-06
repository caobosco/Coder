#include <vector>

using namespace std;

vector<int> multiply(vector<int> A) {
    vector<int> tmp(A.size()), ret(A.size() );
    if (A.size() < 1) return ret;
    tmp[0] = 1;
    for (int i = 1; i < A.size(); i++) {
        tmp[i] = tmp[i - 1]*A[i - 1];
    }

    int length = ret.size();
    ret[length - 1] = tmp[length - 1];
    for (int i = ret.size() - 2, cur = A[length - 1]; i >= 0; i--) {
        ret[i] = tmp[i]*cur;
        cur *= A[i];
    }
    return ret;
}


vector<int> multiplyUsingConstantSpace(vector<int> A) {
    int length = A.size();
    if (length == 0) return vecotr<int>();
    vector<int> ret(length);
    ret[0] = A[0];
    for (int i = 1; i < length; i++)
        ret[i] = ret[i - 1]* A[i]; 
    
    ret[length - 1] = ret[length - 2];
    int cur = A[length - 1];
    for(int i = length - 2; i > 0; i--) {
        ret[i] = ret[i - 1]* cur;
        cur *= A[i];
    }
    ret[0] = cur;
    return ret;
}
