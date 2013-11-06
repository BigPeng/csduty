/*Sort data on stdlib.c's quciksort();*/

#include "mylib.h"
#define MAX 20;
#define R_NAME "random.txt"
#define A_NAME "asc.txt"
#define D_NAME "sesc.txt"
typedef int dType;

void quciksort(dType data[],long n);//quick sort
long partion(dType data[],long s, long n);//One partion of Quick sort
dType *randomData(dType data[], long max);//Generate a radom test data of size max

/*One partion of Quick sort*/
long partion(dType data[],long low, long high){
	dType pivotkey = *(data + low);//set the first element as the pivotkey
	while(low < high){
		while(low < high && *(data + high) > pivotkey)
			high --;
		*(data + low) = *(data + high);//Move the small  element to left 
		while(low < high && *(data + low) < pivotkey)
			low ++;
		*(data + high) = *(data + low);//Move the big element to right
	}
	*(data + low) = pivotkey;//insert the pivotkey
	return low; //return position of pivotkey
}

/*quic sort*/
void quciksort(dType data[],long low,long high){
	long pivot;
	while(low < high){
		pivot = partion(data,low,high);
		quciksort(data,low,pivot - 1);
		quciksort(data,pivot + 1,high);
	}
}
/*Generate radom test data*/
dType *randomData(dType data[], long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) = rand();
	return data;
}
/*Generate  asc order test data*/
dType *ascData(dType data[], long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) = i;
	return data;
}
/*Generate  desc order test data*/
dType *descData(dType data[], long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) =max - i;
	return data;
}
/*Save the data as file */
void save(char *fileName, dType data[], long n){
	FILE * fp = fopen(fileName,'w');
	int i;
	for(i = 0;i < n; i ++)
		fprintf(fp,"%d\n",*(data + i));
	fclose(fp);
}
/*Generate test data */
void generateData(){
	dType data[MAX];
	randomData(data,MAX);
	save(R_NAME,data,MAX);
	ascData(data,MAX);
	save(A_NAME,data,MAX);
	descData(data,MAX);
	save(D_NAME,data,MAX);
}
/*Read file to data, the elementsize is save in n */
dType *readData(dType data[], long *n, char *fileName){	
	FILE *fp = fopen(fileName,'r');
	*n = 0;
	while(fscanf(fp,"%d\n",(data + *n)) != EOF)
		*n += 1;
	fclose(fp);
	return data;	
}

int compare(int *a, int *b){
	if (*a > *b)
		return 1;
	if (*a < *b)
		return -1;
	return 0;
}
/*The sort algorithm of stdlib.h */
void stdsort(dType data[], long n){
	qsort(data,n,sizeof(dType),(int (*)(const void *,const void *))compare);
}
/*Test sort*/
void testSort(){
	dType data[MAX];
	long n;
	read(data, &n, R_NAME);
	quciksort(data,0,n);
	print(data,n); 
}
int main(void){
	generateData();
	testsort();
	return 0;
}
