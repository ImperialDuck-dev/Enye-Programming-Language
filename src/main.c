
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/lexer.h"
#include "include/main.h"
// #include "lexer.c"

int main() {
    FILE *inputfptr = fopen("example/test.enye", "r");
    FILE *outputfptr = fopen("example/SymbolTable.enye", "w");
    if(inputfptr == NULL){
      perror("Unable to open the file");
    }
    char contents[1000];
    while(fgets(contents,sizeof(contents), inputfptr)){
      outputTokens(contents);
      }
   
    
    fclose(inputfptr);
    fclose(outputfptr);
    return 0;
}