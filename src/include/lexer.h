#ifndef LEXER_H
#define LEXER_H

bool isEqual(char *str1, char *str2);
bool isValidKeyword(char* str);
bool isValidReservedWord(char* str);
bool isValidDelimiter(char ch);
bool isValidOperator(char ch);
bool isValidCommentContent(char* str);
bool isValidComment(char* str);
bool isValidNoiseWord(char* str);
bool isvalidIdentifier(char* str);
bool isValidInteger(char* str);
bool isRealNumber(char* str);
char* subString(char* str, int left, int right);
void detectTokens(char* str);


#endif