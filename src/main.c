
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
  char in_filepath[100],out_filepath[100] = "example/SymbolTable.txt"; // file path variable
  int len; // length of file path
      printf("Input file path: ");
      scanf("%s",in_filepath);
      len = strlen(in_filepath);
      if (len <= 1) { // Checks if file path is invalid
        printf("Invalid file path");
        return 0;
      }
      // Checks if file extension is invalid
      if(in_filepath[len-1] == 'y' && in_filepath[len-2] == 'n' && in_filepath[len-3] == '.'){
        inputfptr = fopen(in_filepath, "r"); // opens input file
        outputfptr = fopen(out_filepath, "w"); 
        }
      else{
        printf("Invalid file extension\n.\n.\nProgram will now close");
        return 0;
      }
      
    char contents[1000]; // variable to store contents of input file
    printf("GENERATING SYMBOL TABLE...\n");
    while(fgets(contents,sizeof(contents), inputfptr)){ 
      outputTokens(contents); // Parses input file
      }
    getch();
    getch();
    printf("SYMBOL TABLE GENERATED...\n");  
    printf("Symbol Table can be found at %s",out_filepath);

    fclose(inputfptr); // closes input file
    fclose(outputfptr); // closes output file
    return 0;
}