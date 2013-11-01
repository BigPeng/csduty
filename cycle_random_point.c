#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926 

double frand(int s, int t){
	int dist = t - s;
	return s + rand()*dist/(1.0*RAND_MAX);
}
int main(int argc, char *argv[]){
	int R= 10;
	int n = 100;
	int i = 0;
	double r, theta;
	if(argc = 3){
		R = atoi(argv[1]);
		n = atoi(argv[2]);
	}else{
		printf("Usage:srp -R -n\n");
	}
	for(i =0; i < n; i ++){
		r = frand(0,R);
		theta = frand(0,PI);
		printf("%f\t%f\n",r*cos(theta),r*sin(theta));
	}
	return 0;
}

