#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {

 char *word;
 int flg[3];
}Hash;


char* arr[3][6] = {{"hoge", "piyo", "huge", "hoge", "bar", "baz"}, {"hage", "piyo", "boo", "unko", "mank", "ueda"}, {"funabashi", "ichikawa", "matsudo", "kashiwa", "tudanuma", "narita"}};

Hash H[1046527];





int hash1(char* key){
 int sum = 0, count = 0;

 while(key[count] != '\0'){
  sum += key[count];
  count++;
 }
 return sum % 1046527;
}


int hash2(char* key){
 int sum = 0, count = 0;

 while(key[count] != '\0'){
  sum += key[count];
  count++;
 }
  return 1 + (sum % 1046526);

}

int hash(char* key, int i){

 return  (hash1(key) + i*hash2(key)) % 1046527;

}

void insert(char* w, int index){
int count = 0, h;


 while(1){
   h = hash(w, count);
   if(H[h].word == NULL || (strcmp(H[h].word, w)) == 0)
    break;

  count++;
 }

 H[h].word = w;
 H[h].flg[index] = 1;


}

int main(){
int x = 0, y = 0;


 for(x = 0; x < 3; x++){
  for(y = 0; y < 6; y++){
   insert(arr[x][y], x);
  }
 }

 for(x = 0; x < 1046527; x++){
    if(H[x].word != NULL){
     if(H[x].flg[0] == 1)
      printf("1, ");
     if(H[x].flg[1] == 1)
      printf("2, ");
    if(H[x].flg[2] == 1)
     printf("3 ");

     printf("%s\n", H[x].word);
    }
 }
 return 0;

}
