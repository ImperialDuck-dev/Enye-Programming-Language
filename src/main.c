
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "include/lexer.h"
#include "include/main.h"
// #include "lexer.c"

int main() {
  char filepath[100];
  int len;
      printf("Input file path: ");
      scanf("%s",filepath);
      len = strlen(filepath);
      if (len < 1) {
        printf("Invalid file path");
        return 0;
      }
      if(filepath[len-1] != 'y' && filepath[len-2] != 'n' && filepath[len-3] != '.'){
        printf("Invalid file extension\n.\n.\nProgram will now close");
      }else if(inputfptr == NULL){
      perror("Unable to open the file");
      }else{
        inputfptr = fopen(filepath, "r");
      }


    outputfptr = fopen("example/SymbolTable.txt", "w");
    char contents[1000];
    printf("GENERATING SYMBOL TABLE...\n");
    while(fgets(contents,sizeof(contents), inputfptr)){
      outputTokens(contents);
      }
    printf("SYMBOL TABLE GENERATED...\n");  


    fclose(inputfptr);
    fclose(outputfptr);
    return 0;
}