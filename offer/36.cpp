#include <cstdio>

int arr[100001];
int ret; 
void merge(int s1, int e1, int s2, int e2){
    int size = e1 - s1 + e2 - s2 + 2;
    int *tmp = new int[size];
    int pos = 0, start = s1;
    while(s1 <= e1 && s2 <=e2) {
        if(arr[s1] <= arr[s2])
            tmp[pos++] = arr[s1++];
        else {
            ret += e1-s1+1;
            tmp[pos++] = arr[s2++];
        }
    }
    if(s1 > e1)
        while(s2 <= e2)
            tmp[pos++] = arr[s2++];
    if (s2 > e2)
        while(s1 <= e1)
            tmp[pos++] = arr[s1++];
    pos = 0;
    for(int i = start; i <=e2; ++i )
        arr[i] = tmp[pos++];
    delete[] tmp;

}

void merge_sort(int start, int end) {
    if(start == end)
        return;
    int mid = (start + end)/2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, mid+1, end);
    return;
}

int main(){
    int n;    
    while(scanf("%d", &n) != EOF) {
        ret = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        merge_sort(0,n-1);
        printf("%d\n", ret);
    }
    return 0;
}
