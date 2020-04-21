#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double fun0(double x) { 
	return log(x);
}
double fun1(double x) { 
	return x*x; 
}
double fun2(double x) { 
	return sin(x); 
}
double fun3(double x) { 
	return cos(x); 
}
double (**find_max (double (**TAB)(double), double n))(double);
int main(void){
	char * nazwy[]={"log", "pow","sin","cos"};
	double (*TAB_FUN[5])(double);
	TAB_FUN[0] = fun0;
	TAB_FUN[1] = fun1;
	TAB_FUN[2] = fun2;
	TAB_FUN[3] = fun3;
	TAB_FUN[4] = NULL;
	double (**wsk_fun)(double) = TAB_FUN;
	double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };
	int str = 0;
	while(*wsk_fun) {
		for (int i = 0; i < 8; i++)
			printf("%s(%.1f)=\t%.4f\n",*(nazwy+str) , *(data+i), (**wsk_fun)(*(data+i)));
		str++;
		*wsk_fun++;
	}
	double var;
	printf("Podaj Liczbę Rzeczywistą: ");
	scanf("%lf",&var);
	double (**wsk_max)(double) = find_max (TAB_FUN, var);
	printf ("dla x= %.3f najwieksza wartosc ma %s, ktora wynosi %.3f\n", var, nazwy[wsk_max-TAB_FUN], (**wsk_max)(var));
	return 0;
}
double (**find_max (double (**TAB)(double), double n))(double){
	double (**max)(double)  = TAB;
	*TAB++;
	while(*TAB){
		if((**TAB)(n)>(**max)(n))
			max = TAB;
		*TAB++;
	}
	return max;
}