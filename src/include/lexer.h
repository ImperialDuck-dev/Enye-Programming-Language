#ifndef LEXER_H
#define LEXER_H

bool isEqual(char *str1, char *str2);
bool keywordChecker(char* str);
bool reservedWordChecker(char* str);
bool booleanOperatorChecker(char* str);
bool delimiterChecker(char ch);
bool operatorChecker(char ch);
bool commentContentChecker(char* str);
bool commentChecker(char* str);
bool noiseWordChecker(char* str);
bool identifierChecker(char* str);
bool integerChecker(char* str);
bool realNumberChecker(char* str);
char* subString(char* str, int left, int right);
void outputTokens(char* str);


#endif