#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N] = {30, 21, 12, 17, 2, 1, 4, 3, 2, 5, 6, 9, 10, 11, 4, 67, 9, 19, 21, 0};
int tentousuu;

void merge(int l, int r, int *arr){
int mid, lindex = 0, rindex = 0, index;
int L[N], R[N];
mid = (l+r)/2;


  if(l == r){
  arr[0] = a[l]; 
   return; 
  } 
  else{
   merge(l, mid, L);
   merge(mid+1, r, R); 
  }

  for(index = l; index <= r; index++){  
    if(L[lindex] > R[rindex] && rindex <= r-mid-1){ 
      arr[rindex+lindex] = a[index] = R[rindex];
      tentousuu++;
      rindex++;
    }

   else if(L[lindex] <= R[rindex] && lindex <= mid-l){
     arr[rindex+lindex] = a[index] = L[lindex];
     lindex++;
   } 

  } 


  while(lindex <= mid-l){
   arr[rindex+lindex] = L[lindex]; 
   lindex++;
  }
  while(rindex <= r-mid-1){
   arr[rindex+lindex] = R[rindex];
   rindex++;  
 }



}



int main(){
int count;
 merge(0, 19, a);

 for(count = 0; count < N; count++)
  printf("%d ", a[count]);  
  printf("\n");

 printf("%d\n", tentousuu);

 return 0;
}
