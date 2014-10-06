#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int size, target, times;
	scanf("%d", &size);
	int *arr = new int[size];
	for(int i = 0; i < size; i++)
		scanf("%d", arr+i);
	scanf("%d", &times);
	for(int i = 0; i < times; i++){
		scanf("%d", &target);
		int l = 0, r = size, mid, left, right;
		while(l < r){
			mid = l + (r- l)/2;
			if(arr[mid] == target && (mid == 0 || arr[mid-1] != target)){
				l = mid;
				break;
			}
			else if (arr[mid] >= target)
				r = mid;
			else 
				l = mid+ 1;
		}
		l = mid, r = size;
		left = mid;
		while(l < r){
			mid = l + (r- l)/2;
			if(arr[mid] == target && (mid == size-1 || arr[mid+1] != target)){
				break;
			}
			else if (arr[mid] >= target)
				r = mid;
			else 
				l = mid+ 1;
		}
		if(mid == left && arr[mid] != target)
			printf("%d\n", 0);
		else printf("%d\n", mid- left+ 1);	

	}
}
				
			
