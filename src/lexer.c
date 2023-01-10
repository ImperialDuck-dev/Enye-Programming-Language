 #include <ctype.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include "include/lexer.h"

   FILE *outputfptr;
// Checks current lexeme if it is an operator
// returns true if true
bool operatorChecker(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '!' || ch == '~' || ch == '=' || 
   ch == '%' || ch == '^')
   return (true);
   return (false);
}

bool bracketsChecker(char ch) {
   if (ch == '(' || ch == ')' || ch == '{' || 
   ch == '}' || ch == '[' || ch == ']')
   return (true);
   return (false);
}

// Checks current lexeme if it is a delimiter 
// if true, returns true
bool delimiterChecker(char ch) {
   if (ch == ' ' || ch == ';' || ch == ',' || 
   ch == '"' || ch == '\n' || ch == '\0' ||
   ch == ':' || operatorChecker(ch) || 
   bracketsChecker(ch))
   return (true);
   return (false);
}


void tokenRoleDelimeterOperator(char ch){
   if(ch == ';')
   fprintf(outputfptr,"\t\t\t:\tSEMI_COLON\n");
   else if (ch == ',')
   fprintf(outputfptr,"\t\t\t:\tCOMMA\n");
   else if (ch == ':')
   fprintf(outputfptr,"\t\t\t:\tCOLON\n");
}

/*
// multi-character type lexeme boolean checkers
// Compares current lexeme with the keywords
bool isEqual(char *str1, char *str2){
   for (; *str1 && *str2 && *str1 == *str2; str1++,str2++);
   return (!(*str1) && !(*str2))? true : false;
}
*/
// Checks if current lexeme is equal with keyword array
// returns true if true 
/*
bool keywordChecker(char* str) {
   char *const keywords[] = {
      "pumunta", "ibalik", "habang", "hinto", "gawin", "lipat", "isama",
      "kakulangan", "bulyan", "case", "kawalan", "edi", "bawat", "kapag", "numero", "punto",
      "lipon", "titik", "ipakita", "basahin" 
   };

   int size = sizeof(keywords) / sizeof(*keywords);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(keywords + i))){
         return true;
      }
   }
   return false;  
}
*/
bool keywordChecker(char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == 'c' && str[1] == 'a' && str[2] == 's' && str[3] == 'e')
         return (true);
      else if (str[0] == 'l' && str[1] == 'i' && str[2] == 'p' && str[3] == 'o' && str[4] == 'n')
         return (true);
      else if (str[0] == 'p' && str[1] == 'u' && str[2] == 'm' && str[3] == 'u' && str[4] == 'n' && str[5] == 't'&& str[6] == 'a')
         return (true);  
      else if (str[0] == 'i' && str[1] == 'b' && str[2] == 'a' && str[3] == 'l' && str[4] == 'i' && str[5] == 'k')
         return (true); 
      else if (str[0] == 'h' && str[1] == 'a' && str[2] == 'b' && str[3] == 'a' && str[4] == 'n' && str[5] == 'g')
         return (true); 
      else if (str[0] == 'h' && str[1] == 'i' && str[2] == 'n' && str[3] == 't' && str[4] == 'o')
         return (true);
      else if (str[0] == 'g' && str[1] == 'a' && str[2] == 'w' && str[3] == 'i' && str[4] == 'n')
         return (true);
      else if (str[0] == 'l' && str[1] == 'i' && str[2] == 'p' && str[3] == 'a' && str[4] == 't')
         return (true); 
      else if (str[0] == 'i' && str[1] == 's' && str[2] == 'a' && str[3] == 'm' && str[4] == 'a')
         return (true);
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'k' && str[3] == 'u' && str[4] == 'l' && str[5] == 'a'&& str[6] == 'n'&& str[7] == 'g'&& str[8] == 'a'&& str[9] == 'n')
         return (true);
      else if (str[0] == 'b' && str[1] == 'u' && str[2] == 'l' && str[3] == 'y' && str[4] == 'a'&& str[5] == 'n')
         return (true);
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'w' && str[3] == 'a' && str[4] == 'l' && str[5] == 'a'&& str[6] == 'n')
         return (true);
      else if (str[0] == 'e' && str[1] == 'd' && str[2] == 'i' )
         return (true);
      else if (str[0] == 'b' && str[1] == 'a' && str[2] == 'w' && str[3] == 'a' && str[4] == 't')
         return (true);
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'p' && str[3] == 'a' && str[4] == 'g')
         return (true);
      else if (str[0] == 'n' && str[1] == 'u' && str[2] == 'm' && str[3] == 'e' && str[4] == 'r' && str[5] == 'o')
         return (true);
      else if (str[0] == 'p' && str[1] == 'u' && str[2] == 'n' && str[3] == 't' && str[4] == 'o')
         return (true);
      else if (str[0] == 't' && str[1] == 'i' && str[2] == 't' && str[3] == 'i' && str[4] == 'k')
         return (true);
      else if (str[0] == 'i' && str[1] == 'p' && str[2] == 'a' && str[3] == 'k' && str[4] == 'i' && str[5] == 't' && str[6] == 'a')
         return (true);
      else if (str[0] == 'b' && str[1] == 'a' && str[2] == 's' && str[3] == 'a' && str[4] == 'h' && str[5] == 'i'&& str[6] == 'n')
         return (true); 
   }
   return (false);
}

bool reservedWordChecker (char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == 't' && str[1] == 'a' && str[2] == 'm' && str[3] == 'a')
      return (true);
      else if (str[0] == 'm' && str[1] == 'a' && str[2] == 'l' && str[3] == 'i')
      return (true);
      else if (str[0] == 'p' && str[1] == 'r' && str[2] == 'i' && str[3] == 'n' && str[4] == 's' && str[5] == 'i' && str[6] == 'p' && str[7] == 'a' && str[8] == 'l') 
      return (true);
      else if (str[0] == 't' && str[1] == 'u' && str[2] == 'l' && str[3] == 'o' && str[4] == 'y')
      return (true);
      else if (str[0] == 't' && str[1] == 'a' && str[2] == 'n' && str[3] == 'g' && str[4] == 'g' && str[5] == 'a' && str[6] == 'l' && str[7] == 'i' && str[8] == 'n')
      return (true);
   }
   return (false);
}

bool booleanOperatorChecker (char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == '|' && str[1] == '|')
      return (true);
      else if(str[0] == '&' && str[1] == '&')
      return (true);
      else if(str[0] == '!')
      return (true);
   }
   return (false);
}

bool commentChecker(char* str){
int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == '|' && str[1] == 'n' && str[2] == 'y')
         return (true);
      else if(str[0] == 'n' && str[1] == 'y' && str[2] == '|')
      return (true);
   }
   return (false);
}
// Checks if the comment content are all in capital letters
// Returns true if true
bool commentContentChecker(char* str){
   int i, len = strlen(str), flag = 1;
   for (i = 1; i <=len; i++) {
      if (isupper(str[i])){
         flag ++;
      }
   }

   if(flag == len){
       return (true);
   }
  
   return (false);
}


// Checks if the current lexeme is "sa"
// returns true if true
bool noiseWordChecker(char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == 's' && str[1] == 'a')
      return (true);
   }
   return (false);
}

// Identifiers starts at ny_
// Checks if the current lexeme is an identifier
// if not, return true
bool identifierChecker(char* str){
    int i, len = strlen(str);

   for (i = 0; i <=len; i++) {
      if (str[0] == 'n' && str[1] == 'y' && str[2] == '_')
      return (true);
   }
   return (false);
}


// Checks if current lexeme is an int
// Returns false if current lexeme is not equal to any number
// Otherwise returns true
bool integerChecker(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5'
      && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}

// Checks if current lexeme is a real number
// Always return false
// Check if the lexeme is not a number or contains a negative sign
// If yes, return false
// Check if the lexeme contains a decimal point
// If has a decimal point, return true
bool realNumberChecker(char* str) {
   int i, len = strlen(str), flag = 0;
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
      && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0)){
          return (false);
      }
     
      // flag should always be 1, if not then it is invalid (eg 2.1.1..)
      if (str[i] == '.'){
         flag ++;
      }

      if (flag == 1){
         hasDecimal = true;
      }
   }
   return (hasDecimal);
}

char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2)); //dynamically allocating memory 
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}

void tokenRoleSingleOperator(char ch){
   if(ch == '+')
   fprintf(outputfptr,"\t\t\t:\tADD_OPR\n");
   else if (ch == '-')
   fprintf(outputfptr,"\t\t\t:\tSUBT_OPR\n");
   else if (ch == '*')
   fprintf(outputfptr,"\t\t\t:\tMULT_OPR\n");
   else if (ch == '/')
   fprintf(outputfptr,"\t\t\t:\tDIV_OPR\n");
   else if (ch == '>')
   fprintf(outputfptr,"\t\t\t:\tGREAT_OPR\n");
   else if (ch == '<')
   fprintf(outputfptr,"\t\t\t:\tLESS_OPR\n");
   else if (ch == '!')
   fprintf(outputfptr,"\t\t\t:\tNOT_OPR\n");
   else if (ch == '~')
   fprintf(outputfptr,"\t\t\t:\tINT_DIV_OPR\n");
   else if (ch == '=')
   fprintf(outputfptr,"\t\t\t:\tASS_OPR\n");
   else if (ch == '%')
   fprintf(outputfptr,"\t\t\t:\tMOD_OPR\n");
   else if (ch == '^')
   fprintf(outputfptr,"\t\t\t:\tEXP_OPR\n");
}

void tokenRoleMultiOperator(char ch, char ch2){
   if (ch == '=' && ch2 == '=')
   fprintf(outputfptr,"\t\t\t:\tEQ_TO_OPR\n");
   else if (ch == '>' && ch2 == '=')
   fprintf(outputfptr,"\t\t\t:\tGRTR_THAN_OR_EQ_TO_OPR\n");
   else if (ch == '<' && ch2 == '=')
   fprintf(outputfptr,"\t\t\t:\tLESS_THAN_OR_EQ_TO_OPR\n");
   else if (ch == '!' && ch2 == '=')
   fprintf(outputfptr,"\t\t\t:\tNOT_EQUAL_TO_OPR\n");
}

void tokenRoleBooleanOP(char* str){
   if (str[0] == '&' && str[1] == '&')
   fprintf(outputfptr,"\t\t\t:\tAND_OPR\n");
   else if (str[0] == '|' && str[1] == '|')
   fprintf(outputfptr,"\t\t\t:\tOR_OPR\n");
   else if (str[0] == '!')
   fprintf(outputfptr,"\t\t\t:\tNOT_OPR\n");
}
void tokenRoleBracket(char ch){
   if (ch == '(')
   fprintf(outputfptr,"\t\t\t:\tLEFT_PARENTHESIS\n");
   else if (ch == ')')
   fprintf(outputfptr,"\t\t\t:\tRIGHT_PARENTHESIS\n");
   else if (ch == '{')
   fprintf(outputfptr,"\t\t\t:\tLEFT_CURLY_BRACES\n");
   else if (ch == '}')
   fprintf(outputfptr,"\t\t\t:\tRIGHT_CURLY_BRACES\n");
   else if (ch == '[')
   fprintf(outputfptr,"\t\t\t:\tLEFT_SQUARE_BRACES\n");
   else if (ch == ']')
   fprintf(outputfptr,"\t\t\t:\tRIGHT_SQUARE_BRACES\n");
   // else if (ch == ';')
   // fprintf(outputfptr,"\t\t\t:\tSEMI COLON\n");
   // else if (ch == '"')
   // fprintf(outputfptr,"\t\t\t:\tQUOTATION MARK\n");
}

void tokenRoleNoiseWord(char *str){
   if (str[0] == 's' || str[1] == 'a')
   fprintf(outputfptr,"\t\t\t:\tNOISE WORD\n");
}

void tokenRoleIdentifier(char* str){
   if (str[0] == 'n' || str[1] == 'y' || str[2] == '_')
   fprintf(outputfptr,"\t:\tIDENTIFIER\n");
   else
   fprintf(outputfptr,"\t\t\t:\tINVALID IDENTIFIER\n");
}

void tokenRoleInteger(char* str){
   if (str[0] != '0' || str[1] != '1' || str[2] != '2' || str[3] != '3' || str[4] != '4' || 
   str[5] != '5' || str[6] != '6' || str[7] != '7' || str[8] != '8' || str[9] != '9')
   fprintf(outputfptr,"\t\t\t:\tINTEGER\n");
}
/*
int compare(char a[],char b[])  
{  
   int flag=0,i=0;  // integer variables declaration  
   while(a[i]!='\0' &&b[i]!='\0')  // while loop  
   {  
    if(a[i]!=b[i])  
      {  
        flag=1;  
          break;  
      }  
      i++;  
   }  
   if(flag==0)  
   return 0;  
   else  
   return 1;  
}
*/  
/*
void tokenRoleKeyword(char* str){
   char *const keywords[] = {
      "pumunta", "ibalik", "habang", "hinto", "gawin", "lipat", "isama",
      "kakulangan", "bulyan", "case", "kawalan", "edi", "bawat", "kapag", "numero", "punto",
      "lipon", "titik", "ipakita", "basahin" 
   };
   if(compare(keywords[0], str) == 0)
   fprintf(outputfptr,"\t\t:\tGO_KW\n");
   else if(compare(keywords[1], str) == 0)
   fprintf(outputfptr,"\t\t:\tRETURN_KW\n");
   else if(compare(keywords[2], str) == 0)
   fprintf(outputfptr,"\t\t:\tWHILE_KW\n");
   else if(compare(keywords[3], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tBREAK_KW\n");
   else if(compare(keywords[4], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tDO_KW\n");
   else if(compare(keywords[5], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tSWITCH_KW\n");
   else if(compare(keywords[6], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tINCLUDE_KW\n");
   else if(compare(keywords[7], str) == 0)
   fprintf(outputfptr,"\t\t:\tDEFAULT_KW\n");
   else if(compare(keywords[8], str) == 0)
   fprintf(outputfptr,"\t\t:\tBOOLEAN_KW\n");
   else if(compare(keywords[9], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tCASE_KW\n");
   else if(compare(keywords[10], str) == 0)
   fprintf(outputfptr,"\t\t:\tVOID_KW\n");
   else if(compare(keywords[11], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tELSE_KW\n");
   else if(compare(keywords[12], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tFOR_KW\n");
   else if(compare(keywords[13], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tIF_KW\n");
   else if(compare(keywords[14], str) == 0)
   fprintf(outputfptr,"\t\t:\tINT_KW\n");
   else if(compare(keywords[15], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tFLOAT_KW\n");
   else if(compare(keywords[16], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tSTRING_KW\n");
   else if(compare(keywords[17], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tCHAR_KW\n");
   else if(compare(keywords[18], str) == 0)
   fprintf(outputfptr,"\t\t:\tPRINTF_KW\n");
   else if(compare(keywords[19], str) == 0)
   fprintf(outputfptr,"\t\t:\tSCANF_KW\n");
}

void tokenRoleReservedWords(char* str){
   char *const reservedWords[] = {
      "mali","prinsipal","tuloy","tama","tanggalin" 
   };
   if(compare(reservedWords[0], str) == 0)
   fprintf(outputfptr,"\t\t:\tFALSE_KW\n");
   else if(compare(reservedWords[1], str) == 0)
   fprintf(outputfptr,"\t:\tMAIN_KW\n");
   else if(compare(reservedWords[2], str) == 0)
   fprintf(outputfptr,"\t\t:\tCONTINUE_KW\n");
   else if(compare(reservedWords[3], str) == 0)
   fprintf(outputfptr,"\t\t:\tTRUE_KW\n");
   else if(compare(reservedWords[4], str) == 0)
   fprintf(outputfptr,"\t\t:\tDELETE_KW\n");
}

void tokenRoleCommentChecker(char* str){
   char *const commentChecker[] = {
      "ny|","|ny" 
   };
   if(compare(commentChecker[0], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tCLOSING_CMNT\n");
   else if(compare(commentChecker[1], str) == 0)
   fprintf(outputfptr,"\t\t\t:\tOPENING_CMNT\n");
   
}
*/

void tokenRoleKeyword(char* str){
   if (str[0] == 'c' && str[1] == 'a' && str[2] == 's' && str[3] == 'e')
         fprintf(outputfptr,"\t\t\t:\tCASE_KW\n");
      else if (str[0] == 'l' && str[1] == 'i' && str[2] == 'p' && str[3] == 'o' && str[4] == 'n')
         fprintf(outputfptr,"\t\t\t:\tSTRING_KW\n");
      else if (str[0] == 'p' && str[1] == 'u' && str[2] == 'm' && str[3] == 'u' && str[4] == 'n' && str[5] == 't'&& str[6] == 'a')
         fprintf(outputfptr,"\t\t:\tGO_KW\n");  
      else if (str[0] == 'i' && str[1] == 'b' && str[2] == 'a' && str[3] == 'l' && str[4] == 'i' && str[5] == 'k')
         fprintf(outputfptr,"\t\t:\tRETURN_KW\n"); 
      else if (str[0] == 'h' && str[1] == 'a' && str[2] == 'b' && str[3] == 'a' && str[4] == 'n' && str[5] == 'g')
         fprintf(outputfptr,"\t\t:\tWHILE_KW\n"); 
      else if (str[0] == 'h' && str[1] == 'i' && str[2] == 'n' && str[3] == 't' && str[4] == 'o')
         fprintf(outputfptr,"\t\t\t:\tBREAK_KW\n");
      else if (str[0] == 'g' && str[1] == 'a' && str[2] == 'w' && str[3] == 'i' && str[4] == 'n')
         fprintf(outputfptr,"\t\t\t:\tDO_KW\n");
      else if (str[0] == 'l' && str[1] == 'i' && str[2] == 'p' && str[3] == 'a' && str[4] == 't')
         fprintf(outputfptr,"\t\t\t:\tSWITCH_KW\n"); 
      else if (str[0] == 'i' && str[1] == 's' && str[2] == 'a' && str[3] == 'm' && str[4] == 'a')
         fprintf(outputfptr,"\t\t\t:\tINCLUDE_KW\n");
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'k' && str[3] == 'u' && str[4] == 'l' && str[5] == 'a'&& str[6] == 'n'&& str[7] == 'g'&& str[8] == 'a'&& str[9] == 'n')
         fprintf(outputfptr,"\t\t:\tDEFAULT_KW\n");
      else if (str[0] == 'b' && str[1] == 'u' && str[2] == 'l' && str[3] == 'y' && str[4] == 'a'&& str[5] == 'n')
         fprintf(outputfptr,"\t\t:\tBOOLEAN_KW\n");
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'w' && str[3] == 'a' && str[4] == 'l' && str[5] == 'a'&& str[6] == 'n')
         fprintf(outputfptr,"\t\t:\tVOID_KW\n");
      else if (str[0] == 'e' && str[1] == 'd' && str[2] == 'i' )
         fprintf(outputfptr,"\t\t\t:\tELSE_KW\n");
      else if (str[0] == 'b' && str[1] == 'a' && str[2] == 'w' && str[3] == 'a' && str[4] == 't')
         fprintf(outputfptr,"\t\t\t:\tFOR_KW\n");
      else if (str[0] == 'k' && str[1] == 'a' && str[2] == 'p' && str[3] == 'a' && str[4] == 'g')
         fprintf(outputfptr,"\t\t\t:\tIF_KW\n");
      else if (str[0] == 'n' && str[1] == 'u' && str[2] == 'm' && str[3] == 'e' && str[4] == 'r' && str[5] == 'o')
         fprintf(outputfptr,"\t\t:\tINT_KW\n");
      else if (str[0] == 'p' && str[1] == 'u' && str[2] == 'n' && str[3] == 't' && str[4] == 'o')
         fprintf(outputfptr,"\t\t\t:\tFLOAT_KW\n");
      else if (str[0] == 't' && str[1] == 'i' && str[2] == 't' && str[3] == 'i' && str[4] == 'k')
         fprintf(outputfptr,"\t\t\t:\tCHAR_KW\n");
      else if (str[0] == 'i' && str[1] == 'p' && str[2] == 'a' && str[3] == 'k' && str[4] == 'i' && str[5] == 't' && str[6] == 'a')
         fprintf(outputfptr,"\t\t:\tPRINTF_KW\n");
      else if (str[0] == 'b' && str[1] == 'a' && str[2] == 's' && str[3] == 'a' && str[4] == 'h' && str[5] == 'i'&& str[6] == 'n')
         fprintf(outputfptr,"\t\t:\tSCANF_KW\n");
}

void tokenRoleReservedWords(char* str){
   if (str[0] == 't' && str[1] == 'a' && str[2] == 'm' && str[3] == 'a')
      fprintf(outputfptr,"\t\t:\tTRUE_KW\n");
      else if (str[0] == 'm' && str[1] == 'a' && str[2] == 'l' && str[3] == 'i')
      fprintf(outputfptr,"\t\t:\tFALSE_KW\n");
      else if (str[0] == 'p' && str[1] == 'r' && str[2] == 'i' && str[3] == 'n' && str[4] == 's' && str[5] == 'i' && str[6] == 'p' && str[7] == 'a' && str[8] == 'l') 
      fprintf(outputfptr,"\t:\tMAIN_KW\n");
      else if (str[0] == 't' && str[1] == 'u' && str[2] == 'l' && str[3] == 'o' && str[4] == 'y')
      fprintf(outputfptr,"\t\t:\tCONTINUE_KW\n");
      else if (str[0] == 't' && str[1] == 'a' && str[2] == 'n' && str[3] == 'g' && str[4] == 'g' && str[5] == 'a' && str[6] == 'l' && str[7] == 'i' && str[8] == 'n')
      fprintf(outputfptr,"\t\t:\tDELETE_KW\n");
}

void tokenRoleCommentChecker(char* str){
   if (str[0] == '|' && str[1] == 'n' && str[2] == 'y')
         fprintf(outputfptr,"\t\t\t:\tOPENING_CMNT\n");
      else if(str[0] == 'n' && str[1] == 'y' && str[2] == '|')
         fprintf(outputfptr,"\t\t\t:\tCLOSING_CMNT\n");
}

void tokenRoleContentChecker(char* str){
   int i, len = strlen(str);
   for (i = 1; i <=len; i++) {
      if (isupper(str[i])){
      }
   }
   fprintf(outputfptr,"\t\t:\tCMNT_CONTENT\n");
}





//funtion that scans code 
//and takes lexemes as input
//and outputs tokens based on their classification
void outputTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   int flag = 0;
   
   while (right <= length && left <= right) { //while there is another lexeme next to current lexeme
      if (delimiterChecker(str[right]) == false) //checks if str[0] is a delimiter, if not, increment right
      right++;
      if(delimiterChecker(str[right]) == true && left == right) { //checks if the current lexeme is a single character type    
      if (delimiterChecker(str[right]) == true && str[right] == ';' || str[right] == ':' || str[right] == ','){
      //   fprintf(outputfptr,"Delimiter: %c\t\t:\tSEMI COLON\n",str[right]);
         fprintf(outputfptr,"Lexeme: %c",str[right]);
         tokenRoleDelimeterOperator(str[right]);}
      else if (delimiterChecker(str[right]) && bracketsChecker(str[right])){
      //   fprintf(outputfptr,"Bracket: %c",str[right]);
         fprintf(outputfptr,"Lexeme: %c",str[right]);
         tokenRoleBracket(str[right]);
      }
      else if(operatorChecker(str[right]) == true && operatorChecker(str[right + 1]) == true){
      //   fprintf(outputfptr,"Operator : %c%c", str[right],str[right+1]);
         fprintf(outputfptr,"Lexeme : %c%c", str[right],str[right+1]);
         tokenRoleMultiOperator(str[right],str[right+1]);
         right = right+2;
         left = right;
      }else if (operatorChecker(str[right]) == true)
         //checks if the single character type lexeme is also an operator type one
      //   fprintf(outputfptr,"Operator : %c", str[right]);
         fprintf(outputfptr,"Lexeme : %c", str[right]);
         tokenRoleSingleOperator(str[right]);
         right++;
         left = right;
      }else if (delimiterChecker(str[right]) == true && left != right || (right == length && left != right)){ //checks if the current lexemes is a multicharacter lexeme type
             char* subStr = subString(str, left, right - 1); //takes the current lexeme as input
         if (keywordChecker(subStr) == true){
         //   fprintf(outputfptr,"Keyword : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleKeyword(subStr);
            // Increment flag
            flag++;}
         else if (booleanOperatorChecker(subStr) == true){
         //   fprintf(outputfptr,"Operator : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);   
            tokenRoleBooleanOP(subStr);
         }
         else if (reservedWordChecker(subStr) == true){
         //   fprintf(outputfptr,"Reserved Word : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleReservedWords(subStr);
            }
         else if (integerChecker(subStr) == true){
         //   fprintf(outputfptr,"Integer : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleInteger(subStr);
            }
         else if (realNumberChecker(subStr) == true)
         //   fprintf(outputfptr,"Number : %s\t\t\t:\tREAL_NUMBER\n", subStr);
            fprintf(outputfptr,"Lexeme : %s\t\t\t:\tREAL_NUMBER\n", subStr);

            
         else if (commentChecker(subStr) == true){
         //   fprintf(outputfptr,"Comment : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleCommentChecker(subStr);
            }
         else if (commentContentChecker(subStr) == true){
         //   fprintf(outputfptr,"Comment : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleContentChecker(subStr);
         }
         else if (noiseWordChecker(subStr) == true){
         //   fprintf(outputfptr,"Noise Word : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleNoiseWord(subStr);
            }
         
         else if (identifierChecker(subStr) == true){
         //   fprintf(outputfptr,"Identifier : %s", subStr);
            fprintf(outputfptr,"Lexeme : %s", subStr);
            tokenRoleIdentifier(subStr);
            // Reset flag counter
         flag = 0;}
         else if(identifierChecker(subStr)== false){
            if(flag != 0){
               // A keyword must have succeeding identifier
               // e.g. keyword ny_identifier (+1 -1 = flag: 0)
               // If a keyword (flag: 1) does not reset, it means that the succeeding lexeme 
               // is an invalid keyword, otherwise it is a syntax error
            //   fprintf(outputfptr,"Invalid Lexeme : %s", subStr);
               fprintf(outputfptr,"Lexeme : %s", subStr);
               fprintf(outputfptr,"\t:\tLEXEME NOT RECOGNIZED\n");
               flag = 0;
            }
            else{
            //   fprintf(outputfptr,"String : %s", subStr);
               fprintf(outputfptr,"Lexeme : %s", subStr);
               fprintf(outputfptr,"\t\t\t:\tSTRING LITERAL\n");
               flag = 0;
            }
         }
         left = right;
      }
   }
   return;
}

