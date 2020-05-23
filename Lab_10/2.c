#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct fun{
	char namef[10];
	double (*f)(double *,int);
};
double sum (double t[], int len){
 int i;
 double ss = 0.;
  for (i=0; i<len; ss+=t[i++]);
return ss;}

//---------------------------

double avg (double t[], int len){
 double ss = sum(t,len)/len;
 return ss;}

//---------------------------

double min (double t[], int len){
 int i;
 int min = 0;
 for (i=0; i<len; i++)
  if (t[i]<t[min]) min=i;
 return t[min];}

//---------------------------

double max (double t[], int len){
 int i;
 int max = 0;
 for (i=0; i<len; i++)
  if (t[i]>t[max]) max=i;
 return t[max];}
 double *fun_tab(double (*x)(double *,int),char p[],int a){
 	struct fun tab[a];
 	for(int i =0;i<a;i++){
 		strcat(tab[i].namef,p);
 		tab[i].f = x+i;
 	}
 	return tab;
 }
 int main(){
 	char * names[] = {"sum", "avg", "min", "max"};
 	double (*TAB_FUN[])(double *, int) = {sum, avg, min, max};
 	double data[][4] = {{1.3, 1.2, 0.2, 2.3}, {3.4, 1.1, 1.1, 2.1}, {0.4, 0.9, 2.3, 1.3}, {2.3, 0.6, 1.1}};
 	int var = sizeof(names)/sizeof(char*);
 	struct fun *wsk_fun = fun_tab(TAB_FUN,names, var);
 	return 0;
 }
