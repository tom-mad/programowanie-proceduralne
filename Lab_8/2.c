#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double square(double x){
	return (-(x*x)+3.0*x+11.0);
}
int zero(double (*f)(double), double a, double b, double* m_z, double eps);
int main(){
	double mz;
	if(zero(sin,-1,1,&mz,0.01) == 1)
		printf("Funkcja Posiada Miejsce Zerowe i Jest Równe : %.2f\n",mz);
	else
		printf("Funkcja Nie posiada Miejsc Zerowych\n");
	if(zero(square,0,8,&mz,0.01) == 1)
		printf("Funkcja Posiada Miejsce Zerowe i Jest Równe : %.2f\n",mz);
	else
		printf("Funkcja Nie posiada Miejsc Zerowych\n");
	if(zero(square,-1,1,&mz,0.01) == 1)
		printf("Funkcja Posiada Miejsce Zerowe i Jest Równe : %.2f\n",mz);
	else
		printf("Funkcja Nie posiada Miejsc Zerowych\n");
	return 0;
}
int zero(double (*f)(double), double a, double b, double* m_z, double eps){
	double fa = f(a);
	double fb = f(b);
	double c;
	if (fa*fb>0){
		return 0;
	}
	while(fabs(a-b)>eps){
		*m_z = (a+b)/2;
		c = f(*m_z);
		if(fabs(c) < eps)
			break;
		if(fa*c < 0)
			b = *m_z;
		else{
			a = *m_z;
			fa = c;
		}
	}
	return 1;
}