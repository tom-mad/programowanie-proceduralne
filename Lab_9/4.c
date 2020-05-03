#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct vector{
  double x,y,z;
};
struct abc{
  struct vector vect;  
  double length;
};
double d_rand(double min, double max){
  double r = (double) rand()/RAND_MAX;
  return r*(max-min) + min; 
}
double wekt_len(struct vector a){
  return sqrt(pow(a.x,2)+pow(a.y,2)+pow(a.z,2));
}
void f_d(struct abc *t,int n){
  for(int i=0;i<n;i++)
    (t+i)->length = wekt_len(((t+i)->vect));
  return;
}
int compare_l(const void* a, const void* b){
  struct abc vA = *(struct abc*)a;
  struct abc vB = *(struct abc*)b;

  if (vA.length > vB.length) return 1;
    else if (vA.length < vB.length) return -1;
      else return 0;
}
int main(int argc, char *argv[]){
  int x = atoi(argv[1]);
  if(argc == 1||x<=0){
    printf("Brak Argumentów lub podana liczba jest <=0\n");
    return 0; 
  }
  struct abc *vectors = calloc(x,sizeof(struct abc));
  srand(time(0));
  for(int i=0; i<x;i++){
    vectors[i].vect.x = d_rand(-100,100);
    vectors[i].vect.y = d_rand(-100,100);
    vectors[i].vect.z = d_rand(-100,100);
}
  f_d(vectors,x);
  puts("***tablica przed sortowaniem:");
  for(int i=0; i<x;i++){
    printf("Numer Struktury [%d] , x = %.2f   y = %.2f   z = %.2f  length = %.2f\n",i,vectors[i].vect.x,vectors[i].vect.y,vectors[i].vect.z,vectors[i].length);
  }
  puts("***tablica po sortowaniu:");
  qsort(vectors,x, sizeof(vectors[0]), compare_l);
  for(int i=0; i<x;i++){
    printf("Numer Struktury [%d] , x = %.2f   y = %.2f   z = %.2f  length = %.2f\n",i,vectors[i].vect.x,vectors[i].vect.y,vectors[i].vect.z,vectors[i].length);
  }
  free(vectors);
  return 0;
}