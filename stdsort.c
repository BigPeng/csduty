/*Sort data on stdlib.c's qsort();*/

#include "mylib.h"
#define MAX 20;
int compare(int *a, int *b){
	if (*a > *b)
		return 1;
	if (*a < *b)
		return -1;
	return 0;
}

void testsort(){
	int i = 0;
	int n = MAX;
	int data[n];
	for(i = 0; i < n; i++) 
		data[i]= rand() % n;
	print(data,n);
	qsort(data,n,sizeof(int),(int (*)(const void *,const void *))compare);
	print(data,n);
	int d = 6;
	i = *(int *)bsearch((const void *)&d,data,n,sizeof(int),(int (*)(const void *,const void *))compare);
	printf("%d\n",i);
	
}
int main(void){
	testsort();
	return 0;
}
