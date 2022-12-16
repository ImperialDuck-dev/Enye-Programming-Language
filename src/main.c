
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
  char filepath[100]; // file path variable
  int len; // length of file path
      printf("Input file path: ");
      scanf("%s",filepath);
      len = strlen(filepath);
      if (len < 1) {    // Checks if file path is invalid
        printf("Invalid file path");
        return 0;
      }
      // Checks if file extension is invalid
      if(filepath[len-1] != 'y' && filepath[len-2] != 'n' && filepath[len-3] != '.'){
        printf("Invalid file extension\n.\n.\nProgram will now close" );
      return 0;}
      else{
        inputfptr = fopen(filepath, "r"); // opens input file
      }


    outputfptr = fopen("example/SymbolTable.txt", "w"); 
    // opens output file

    char contents[1000]; // variable to store contents of input file
    printf("GENERATING SYMBOL TABLE...\n");
    while(fgets(contents,sizeof(contents), inputfptr)){ 
      outputTokens(contents); // Parses input file
      }
    printf("SYMBOL TABLE GENERATED...\n");  


    fclose(inputfptr); // closes input file
    fclose(outputfptr); // closes output file
    return 0;
}