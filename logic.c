#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void detectTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   while (right <= length && left <= right) {
      if (isValidDelimiter(str[right]) == false)
      right++;
      if (isValidDelimiter(str[right]) == true && left == right) {
         if (isValidOperator(str[right]) == true)
         printf("Valid operator : '%c'", str[right]);
         right++;
         left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left !=       right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
            printf("Valid keyword : '%s'", subStr);
         else if (isValidInteger(subStr) == true)
            printf("Valid Integer : '%s'", subStr);
         else if (isRealNumber(subStr) == true)
            printf("Real Number : '%s'", subStr);
         else if (isvalidIdentifier(subStr) == true
            && isValidDelimiter(str[right - 1]) == false)
         printf("Valid Identifier : '%s'", subStr);
         else if (isvalidIdentifier(subStr) == false
            && isValidDelimiter(str[right - 1]) == false)
         printf("Invalid Identifier : '%s'", subStr);
         left = right;
      }
   }
   return;
}