// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "include/lexer.h"

// single character-type lexeme boolean checker

// Checks current lexeme if it is a delimiter 
// if true, returns true
bool delimiterChecker(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
  // ch == '"' || 
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '(' || ch == ')' || ch == '=' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}')
   return (true);
   return (false);
}

// Checks current lexeme if it is an operator
// returns true if true
bool operatorChecker(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '=' || ch == '%' || ch == '~' || 
   ch == '^')
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
      "pumunta sa", "ibalik", "habang", "hinto", "gawin", "lipat", "lipat", "isama",
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

// Checks if current lexeme is equal with booleanOperators array
// returns true if true
bool booleanOperatorChecker(char* str) {
   char *const booleanOperators[] = {
      //"+=","-=","*=","/=","%=","~=","++","--",
      "~DI","~O","~AT", "!", "&&", "||"}; //,"==",">=","<=","/"};


   int size = sizeof(booleanOperators) / sizeof(*booleanOperators);

   for (int i = 0; i < size; i++){
      if(isEqual(str, *(booleanOperators + i))){
         return true;
      }
   }
   return false;  
}

// Checks current lexeme if it is a comment 
// Comments are all in capital letters
// returns true if true
bool commentContentChecker(char* str){
   int i, len = strlen(str), flag = 0;
   for (i = 0; i <=len; i++) {
      if (isupper(str[i])){
         flag ++;
      }
   }

   if(flag == len){
       return (true);
   }
  
   return (false);
}


// Checks if current lexeme if it is enye
// if true, returns true
bool commentChecker(char* str){
   int i, len = strlen(str);
   for (i = 0; i <=len; i++) {
      if (str[0] == 'e' && str[1] == 'n' && str[2] == 'y' && str[3] == 'e')
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

// Checks if the current lexeme is not a number
// Checks again if it is a delimiter; if yes, return false
// if not, return true
bool identifierChecker(char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
   str[0] == '3' || str[0] == '4' || str[0] == '5' ||
   str[0] == '6' || str[0] == '7' || str[0] == '8' ||
   str[0] == '9' || delimiterChecker(str[0]) == true){
       return (false);
   }else
      return (true);
}

//checks if current lexeme is an int
//returns false if current lexeme is not equal to any number
//else returns true
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

//checks if current lexeme is a real number
//if yes, return false
//if has a decimal point, return false
bool realNumberChecker(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i]       != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
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

//funtion that scans code 
//and takes lexemes as input
//and outputs tokens based on their classification
void outputTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   while (right <= length && left <= right) { //while there is another lexeme next to current lexeme
      if (delimiterChecker(str[right]) == false) //checks if str[0] is a delimiter, if not, increment right
      right++;
      if (delimiterChecker(str[right]) == true && left == right) { //checks if the current lexeme is a single character type 
         if (operatorChecker(str[right]) == true)  //checks if the single character type lexeme is also an operator type one
         printf("Operator : '%c'\n", str[right]);
         right++;
         left = right;
      }else if (delimiterChecker(str[right]) == true && left != right || (right == length && left != right)){ //checks if the current lexemes is a multicharacter lexeme type
             char* subStr = subString(str, left, right - 1);
         if (booleanOperatorChecker(subStr) == true)
            printf("Boolean Operator : '%s'\n", subStr);
         else if (keywordChecker(subStr) == true)
            printf("Keyword : '%s'\n", subStr);
         else if (reservedWordChecker(subStr) == true){
            printf("Reserved Word : '%s'\n", subStr);
         }
         else if (commentChecker(subStr) == true)
            printf("Comment : '%s'\n", subStr);
         else if (commentContentChecker(subStr) == true){
            printf("Comment : '%s'\n", subStr);
         }
         else if (integerChecker(subStr) == true)
            printf("Integer : '%s'\n", subStr);
         else if (noiseWordChecker(subStr) == true)
            printf("Noise Word : '%s'\n", subStr);
         else if (realNumberChecker(subStr) == true)
            printf("Number : '%s'\n", subStr);
         else if (identifierChecker(subStr) == true
            && delimiterChecker(str[right]) == true)
         printf("Identifier : '%s'\n", subStr);
         else if (identifierChecker(subStr) == false
            && delimiterChecker(str[right - 1]) == false)
         printf("Invalid Identifier : '%s'\n", subStr);
         left = right;
      }
   }
   return;
}

