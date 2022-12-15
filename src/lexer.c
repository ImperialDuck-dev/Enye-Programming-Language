// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "include/lexer.h"

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
   if (ch == ' ' || ch == ';' || ch == '"' || 
   ch == '\n' || ch == '\0' || 
   operatorChecker(ch) || bracketsChecker(ch))
   return (true);
   return (false);
}


// multi-character type lexeme boolean checkers
// Compares current lexeme with the keywords
bool isEqual(char *str1, char *str2){
   for (; *str1 && *str2 && *str1 == *str2; str1++,str2++);
   return (!(*str1) && !(*str2))? true : false;
}

// Checks if current lexeme is equal with keyword array
// returns true if true 
bool keywordChecker(char* str) {
   char *const keywords[] = {
      "pumunta", "ibalik", "habang", "hinto", "gawin", "lipat", "lipat", "isama",
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

//Checks if current lexeme is equal with reservedWords array
//returns true if true
bool reservedWordChecker(char* str) {
   char *const reservedWords[] = {
      "mali","prinsipal","tuloy","tama"};


   int size = sizeof(reservedWords) / sizeof(*reservedWords);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(reservedWords + i))){
         return true;
      }
   }
   return false;  
}

bool booleanOperatorChecker(char* str){
   char *const boolOperators[] = {
      "||", "&&", "!"
   };

   int size = sizeof(boolOperators) / sizeof(*boolOperators);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(boolOperators + i))){
         return true;
      }
   }
   return false;
}

// Checks current lexeme if it is a comment 
// Comments are all in capital letters
// returns true if true
bool commentChecker(char* str){
   char *const comments[] = {
      "ny|", "|ny"
   };

   int size = sizeof(comments) / sizeof(*comments);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(comments + i))){
         return true;
      }
   }
   return false;
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
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
      && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
         if (str[i] == '.')
      hasDecimal = true;
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
   printf("\t:\tADD_OPR\n");
   else if (ch == '-')
   printf("\t:\tSUBT_OPR\n");
   else if (ch == '*')
   printf("\t:\tMULT_OPR\n");
   else if (ch == '/')
   printf("\t:\tDIV_OPR\n");
   else if (ch == '>')
   printf("\t:\tGREAT_OPR\n");
   else if (ch == '<')
   printf("\t:\tLESS_OPR\n");
   else if (ch == '!')
   printf("\t:\tNOT_OPR\n");
   else if (ch == '~')
   printf("\t:\tINT_DIV_OPR\n");
   else if (ch == '=')
   printf("\t:\tASS_OPR\n");
   else if (ch == '%')
   printf("\t:\tMOD_OPR\n");
   else if (ch == '^')
   printf("\t:\tEXP_OPR\n");
}

void tokenRoleMultiOperator(char ch, char ch2){
   if (ch == '!' && ch2 == '=')
   printf("\t:\tNOT_EQ_TO_OPR\n");
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
      if (delimiterChecker(str[right]) == true && str[right] == ';')
         printf("Delimiter: %c\n",str[right]);
      else if (delimiterChecker(str[right]) && bracketsChecker(str[right]))
         printf("Bracket: %c\n",str[right]);
      else if(operatorChecker(str[right]) == true && operatorChecker(str[right + 1]) == true){
         printf("Operator : %c%c", str[right],str[right+1]);
         tokenRoleMultiOperator(str[right],str[right+1]);
         right++;
         left = right;
      }else if (operatorChecker(str[right]) == true)
         //checks if the single character type lexeme is also an operator type one
         printf("Operator : %c", str[right]);
         tokenRoleSingleOperator(str[right]);
         right++;
         left = right;
      }else if (delimiterChecker(str[right]) == true && left != right || (right == length && left != right)){ //checks if the current lexemes is a multicharacter lexeme type
             char* subStr = subString(str, left, right - 1); //takes the current lexeme as input
         if (keywordChecker(subStr) == true){
            printf("Keyword : %s\n", subStr);
            // Increment flag
            flag++;}
         else if (booleanOperatorChecker(subStr) == true)
            printf("Operator : %s\n", subStr);   
         else if (reservedWordChecker(subStr) == true)
            printf("Reserved Word : %s\n", subStr);
         else if (commentChecker(subStr) == true)
            printf("Comment : %s\n", subStr);
         else if (commentContentChecker(subStr) == true)
            printf("Comment : %s\n", subStr);
         else if (integerChecker(subStr) == true)
            printf("Integer : %s\n", subStr);
         else if (noiseWordChecker(subStr) == true)
            printf("Noise Word : %s\n", subStr);
         else if (realNumberChecker(subStr) == true)
            printf("Number : %s\n", subStr);
         else if (identifierChecker(subStr) == true){
            printf("Identifier : %s\n", subStr);
            // Reset flag counter
         flag = 0;}
         else if(identifierChecker(subStr)== false){
            if(flag != 0){
               // A keyword must have succeeding identifier
               // e.g. keyword ny_identifier (+1 -1 = flag: 0)
               // If a keyword (flag: 1) does not reset, it means that the succeeding lexeme 
               // is an invalid keyword, otherwise it is a syntax error
               printf("Invalid Identifier : %s\n", subStr);
               flag = 0;
            }
            else{
               printf("String : %s\n", subStr);
               flag = 0;
            }
         }
         left = right;
      }
   }
   return;
}

