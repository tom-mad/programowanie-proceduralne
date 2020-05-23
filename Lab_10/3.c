#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct number {
	char type ;
	union {
	double d ;
	int i ; 
	};
};
void print_number ( struct number *tmp ,int size) {
	for(int i=0;i<size;i++){
		if ( (tmp+i)->type == 'i' )
			printf ("int =%6.d\n", (tmp+i)->i) ;
		else
			printf ("double =%6.2lf\n", (tmp+i) ->d ) ;      
	}
}
int compare(const void * a, const void * b){            
	struct number A = *(struct number *)a;
  	struct number B = *(struct number *)b;    
    if(A.type==B.type){
    	if(A.type == 'i')
    		return B.i-A.i;
    	else{
    		if (A.d > B.d) 
    			return 1;
    		else if (A.d < B.d) 
    			return -1;
    			else 
    				return 0;
    	}
    }
    	else if(A.type=='i')
    		return -1;
    		else return 1;
}
double d_rand(double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}
int main(){
	struct number tab[20];
	srand(time(0));
	for(int i=0;i<20;i++){
		if(rand()%2){
			tab[i].type = 'i';
			tab[i].i = rand()%200 - 100;
		}
		else{
			tab[i].type = 'd';
			tab[i].d = d_rand(-100,100);
		}
	}
	puts("-----------------------------------------\nPrzed sortowaniem");
	print_number(tab,20);
	qsort(tab,20,sizeof(struct number),compare);
	puts("-----------------------------------------\nPo sortowaniu");
	print_number(tab,20);
	return 0;
}
