#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 10
#define COL 5
int sum (int t[], int len){
 	int i;
 	int ss = 0.;
  	for (i=0; i<len; ss+=t[i++]);
	return ss;
}
double avg (int t[], int len){
 	double ss = (double)sum(t,len)/len;
 	return ss;
 }
int compare(const void * a, const void * b){            
	int **A = (int **)a;
  	int **B = (int **)b;
  	return (sum(*A,COL)-sum(*B,COL));    
    
}
int main(){
	int TAB[ROW][COL];
	int i,j;
	printf("\n-----------------------------------------\nWylosowane Wartości:\n");
	for(i = 0;i<ROW;i++)
		for(j = 0;j<COL;j++){
			TAB[i][j] = rand()%21 -10;
			printf("\tTAB[%d][%d] = %d\n",i,j,TAB[i][j]);
		}
	qsort(TAB,ROW,sizeof(int**),compare);		
	printf("\n-----------------------------------------\nPosortowana:\n");
	for(i = 0;i<ROW;i++)
		for(j = 0;j<COL;j++)
			printf("\tTAB[%d][%d] = %d\n",i,j,TAB[i][j]);

	return 0;
}
