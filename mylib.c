#include "mylib.h"

void swap(dataType *a, dataType *b){
	dataType temp = *a;
	*a = *b;
	*b = temp;
}

void print(dataType *data,int n){
	int i = 0;
	for(i = 0;i < n; i ++){
		printf("%d ",data[i]);
	}
	printf("\n");
}

void sort(dataType * data,int s, int t){
	int i,j;
	for(i = s; i < t; i ++)
		for(j = i+1; j < t; j++)
			if(data[i] > data[j])
				swap(&data[i],&data[j]);
}
