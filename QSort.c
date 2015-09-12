#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int A[N];





void QSort(int l, int r){
int m;


 if(l < r){
 m = partition(l, r);
 QSort(l, m-2);
 QSort(m, r);
 }

}

int partition(int l, int r){
int i = l, j = 0, v;



 for(j = l; j <= r; j++){
    if(A[r] <= A[j]){
       v = A[j];
       A[j] = A[i];
       A[i] = v;
       i++;
    }

 }

 return i;

}
int main(){
int count;


  srand(time(NULL));

 for(count = 0; count < N; count++){

  A[count] = rand() % 1000;

 }

  QSort(0, N-1);

 for(count = 0; count < N; count++){
   printf("%d ", A[count]);

   if(count % 50 == 0 && count != 0)
     printf("\n");
 }
 printf("\n");
 return 0;

}
