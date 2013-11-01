/* merge two segment with space complex of O(1) */
#include "mylib.h"

void merge(dataType *data, int n){
	int middle = n/2;
	int low = 0;
	int high = middle;
	dataType temp;
	int last_high = high;
	while(low < middle && high < n){
		print(data,n);
		high = last_high;
		while(low < middle  && data[low] <= data[high])
			low ++;
		swap(&data[low],&data[high]);
		last_high = high;
		while(high < n-1 && data[high] > data[high+1]){
			swap(&data[high],&data[high+1]);
			high ++;
		}
	}	
}

int main(void){
	dataType data[MAX_NUM];
	int i,j,mid;
	for(i = 0;i < MAX_NUM;i++)
		data[i] = rand() % MAX_NUM;
	mid = MAX_NUM / 2;
	print(data,MAX_NUM);
	sort(data,0,mid );
	sort(data,mid,MAX_NUM);
	print(data,MAX_NUM);
	print(NULL,0);
	merge(data,MAX_NUM);
	print(data,MAX_NUM);
	return 0;
}
