#include<stdio.h>
#define MAK_1(x) printf(#x" =%d\n",x)
#define MAK_2(x) (x+1)%2
int main(){
	printf("%d\t%d\t%d\n",MAK_2(-1),MAK_2(2),MAK_2(-4));
	int x=5, y=9;
	MAK_1(7*x+2-y/6);
	return 0;
}