#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "include/lexer.h"
#include "include/main.h"
#include "lexer.c"



int main() {
  char in_filepath[100],out_filepath[100] = "example/SymbolTable.txt",parser_filepath[100] = "example/ParsingInput.txt",symbol_filepath[100] = "example/SymbolTable.txt"; // file path variable
  int len; // length of file path
      printf("Input file path: ");
      scanf("%s",in_filepath);
      len = strlen(in_filepath);
      if (len <= 2) { // Checks if file path is invalid
        printf("Invalid file path");
        return 0;
      }
      // Checks if file extension is invalid
      if(in_filepath[len-1] == 'y' && in_filepath[len-2] == 'n' && in_filepath[len-3] == '.'){
            /* FOR LEXER */
            inputfptr = fopen(in_filepath, "r");
            outputfptr = fopen(out_filepath, "w");
            
            /* FOR PARSING */
            outputfptr2 = fopen("example/SymbolTable.txt", "r");
            outputfptr3 = fopen("example/ParsingInput.txt", "w");
            char lexerContent;
            char lexerData[1000];  // variable to store contents of input file
                fprintf(outputfptr,"LEXEMES\t\t\t\t\tTOKENS\n"); 
                for(int i=0; i<sizeof(lexerData); i++) {
                    lexerContent = fgetc(inputfptr); // reads input file
                    if(lexerContent == EOF) {
                        break;
                        }
                    lexerData[i] = lexerContent;                
    }
            outputTokens(lexerData); // calls outputTokens function
            fclose(inputfptr);
            fclose(outputfptr);

            outputfptr2 = fopen("example/SymbolTable.txt", "r");
            char parsingContent;
            char parsingData[1000];  // variable to store contents of input file
                fprintf(outputfptr,"LEXEMES\t\t\t\t\tTOKENS\n"); 
                for(int i=0; i<sizeof(parsingData); i++) {
                    parsingContent = fgetc(outputfptr2); // reads input file
                    if(parsingContent == EOF) {
                        break;
                        }
                    parsingData[i] = parsingContent;                
    }
                    print_declaration(parsingData);
      }           
      else if(in_filepath[len-1] != 'y' && in_filepath[len-2] != 'n' && in_filepath[len-3] != '.'){
        printf("Invalid file extension\n.\n.\nProgram will now close");
        return 0;
      }else{
        printf("Invalid input!\n.\n.\nProgram will now close");
        return 0;
      }
    
    
    fclose(outputfptr2); // closes output file
    return 0;

}

    
