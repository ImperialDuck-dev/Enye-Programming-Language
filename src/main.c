
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "include/lexer.h"
// #include "include/main.h"
#include "lexer.c"

int main() {
    FILE *fptr = fopen("example/test.enye", "r");
    if(fptr == NULL){
      perror("Unable to open the file");
    }
    char contents[1000];
    while(fgets(contents,sizeof(contents), fptr)){
      outputTokens(contents);
      }
   
    return 0;
}