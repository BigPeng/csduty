#include <time.h>
#include "sort.h"
#include "mylib.h"
#define MAX 254000
#define R_NAME "random.txt"
#define A_NAME "asc.txt"
#define D_NAME "sesc.txt"
typedef int dType;

void quciksort(dType *data,long n);//quick sort
long partion(dType *data,long s, long n);//One partion of Quick sort
dType *randomData(dType *data, long max);//Generate a radom test data of size max
static int count = 0;

dType *midPointer(dType *p1,dType *p2,dType *p3){
	if(*p1 > *p2 && *p1 < *p3)
		return p1;
	if(*p2 > *p1 && *p2 < *p3)
		return p2;
	return p3;
}
/*One partion of Quick sort*/
long partion(dType *data,long low, long high){
	dType pivotkey;
	dType *midp = midPointer(data+low,data+(low+high)/2,data+high);
	swap(midp,data+low);	
	pivotkey= *(data + low);//set the first element as the pivotkey
	while(low < high){
		while(low < high && *(data + high) >= pivotkey)
			high --;
		*(data + low) = *(data + high);//Move the small  element to left 
		while(low < high && *(data + low) <= pivotkey)
			low ++;
		*(data + high) = *(data + low);//Move the big element to right
	}
	*(data + low) = pivotkey;//insert the pivotkey
	return low; //return position of pivotkey
}

/*quic sort*/
void qSort(dType *data,long low,long high){
	long pivot;
	//printf("(%d:%d,%d) ",count++,low,high);
	if(low < high){
		pivot = partion(data,low,high);
		qSort(data,low,pivot - 1);
		qSort(data,pivot + 1,high);
	}
}
/*wrap the qucick sort algorithm */
void quickSort(dType *data,long n){
	qSort(data,0,n-1);
}
/*Generate radom test data*/
dType *randomData(dType *data, long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) = rand();
	return data;
}
/*Generate  asc order test data*/
dType *ascData(dType *data, long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) = i;
	return data;
}
/*Generate  desc order test data*/
dType *descData(dType *data, long max){
	long i;
	for( i = 0;i < max; i++)
		*(data + i) =max - i;
	return data;
}
/*Save the data as file */
void save(char *fileName, dType *data, long n){
	long i;
	FILE * fp ;
	fp = fopen(fileName,"w");
	if(fp == NULL)
		return;       
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
dType *read(dType *data, long *n, char *fileName){        
	FILE *fp;
	fp= fopen(fileName,"r");
	if(fp == NULL)
		return;
	*n = 0;
	while(fscanf(fp,"%d\n",(data + *n)) != EOF)
		*n += 1;
	fclose(fp);
	return data;        
}

int compare(dType *a, dType *b){
	if (*a > *b)
		return 1;
	if (*a < *b)
		return -1;
	return 0;
}
/*The sort algorithm of stdlib.h */
void stdSort(dType *data, long n){
	qsort(data,n,sizeof(dType),(int (*)(const void *,const void *))compare);
}
/*Test sort*/
void testSort(char *fileName,void(*sort)(dType *,long)){
	dType data[MAX];
	long n = 0;	
	clock_t start,end;
	read(data, &n, fileName);
	start = clock();
	printf("pass\n");
	sort(data,n);
	end = clock();
	printf("%d milliseconds.%d",end - start,CLOCKS_PER_SEC);
	save("sorted.txt",data,n);
	
}
/***��data[s,...)���жѵ�����m��ȡ�������Ͻ�***/
void heapAdjust(int *data,int s,int m){
	int temp = *(data + s);
	int j;
	//�����±��0��ʼ�����飬������2*i+1,�к�����2*i+2�������ǣ�2*i\��
	for(j = 2*s+1;j < m; j = 2*j+1){
		if(j <m-1 && *(data+j)<*(data+j+1))//ѡ��ϴ�ĺ���
			j++;
		if(temp >= *(data+j)) break;//�ҵ���data[s]�Ĳ���λ��,>=�����󶥶�
		*(data+s) =  *(data+j);//��˳��·�����ϴ��Ԫ����������
		s = j;
	}
	*(data+s) = temp;
}

void heapSort(dType * data,long n){	
	long i;
	//����Ϊ��n-1)/2����n/2
	for(i=(n - 1)/2;i>=0;--i){
		heapAdjust(data,i,n);		
	}
	for(i=n-1;i>0;--i){
		swap(&data[0],&data[i]);	
		//����data[0,i)
		heapAdjust(data,0,i);
	}	
}
void sort(){
	int i=1;
	void (*sort)(dType *,long) = heapSort;
	//generateData();	
	//testSort(R_NAME,sort);   
	switch(i){
		printf("%d",i);
	case 1:
		printf("%d",i);
		break;
	}
}


void testHeapSort(){
/*
	int data[MAX];
	int i,j;
	for(j=0;j<10;j++){
		for(i = 0;i<MAX;i++)
			data[i] = rand()%MAX;
		printf("befor:");
		print(data,MAX);
		heapSort(data,MAX);
		printf("after:");
		print(data,MAX);
		printf("\n");
	}
*/
	dType data[] = {87,67,90,50,60,9};
	print(data,6);
	printf("\n");
	heapSort(data,6);
	print(data,6);
	
	
}
