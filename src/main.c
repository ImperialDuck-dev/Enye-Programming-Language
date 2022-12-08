#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lexer.c"

int main() {
    FILE *fptr = fopen("files/test.txt", "r");
    if(fptr == NULL){
      perror("Unable to open the file");
    }
    char contents[1000];
    while(fgets(contents,sizeof(contents), fptr)){
      detectTokens(contents);
      }
   
    return 0;
}