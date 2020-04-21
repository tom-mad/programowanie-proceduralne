#include<stdio.h>
#include<stdlib.h>
void print_tab(int **a,int rows, int columns);
int **mn_tab_1(int p, int columns, int rows, int(*A)[p], int(*B)[columns]) ;
int main(){
    int t_A [2][3] = {1,2,3,4,5,6};
    int t_B [3][4] = {1,1,1,1,2,1,1,4,1,1,1,1};
    int ** t_C = mn_tab_1 (3,4, 2,t_A,t_B);
    print_tab(t_C,2,4);
    free(t_C);
    return 0;
}
int **mn_tab_1(int p, int columns, int rows, int(*A)[p], int(*B)[columns]) {
	int ** array = (int**)calloc(rows,sizeof(int*));
	*array = (int*)calloc(rows*columns,sizeof(int));
	for(int i = 1;i<rows;i++)
		*(array + i) = i*columns+*array;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            for(int k=0; k<p; k++){
                array[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return array;
}
void print_tab(int **a,int rows, int columns){
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf ("%3d", a[i][j]);
		printf ("\n");
	}
return;
}