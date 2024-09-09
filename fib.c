#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibRec(int n){
   if (n<2){
      return n;
   }
   else{
      return (fibRec(n-1)+fibRec(n-2));
   }
}
int fibIter(int n){
   int terms[50]={0,1};
   int i=2;
   while (i<=n){
      terms[i]=(terms[i-1]+terms[i-2]);
      i=i+1;
   }
   return terms[n];
}

int main(int argc, char** argv){
  
    FILE *file_ptr;
    char str[50];
    file_ptr = fopen(argv[3], "r");

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }
    fgets(str, 50, file_ptr);
    fclose(file_ptr);
    int num= atoi(argv[1])+atoi(str);
    if (strcmp(argv[2], "r") == 0){
      printf("%d", fibRec(num));
    }
    else {
      printf("%d", fibIter(num));
    }


   return 0;
   }