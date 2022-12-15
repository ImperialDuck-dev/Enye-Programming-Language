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
bool bracketsChecker(char ch);
bool isEqual(char *str1, char *str2);

// TOKEN FUNCTIONS
void tokenRoleSingleOperator(char ch);
void tokenRoleBooleanOP(char* str);
void tokenRoleBracket(char ch);
void tokenRoleNoiseWord(char *str);
void tokenRoleIdentifier(char* str);
void tokenRoleInteger(char* str);
int compare(char a[],char b[]);
void tokenRoleKeyword(char* str);
void tokenRoleReservedWords(char* str);
void tokenRoleCommentChecker(char* str);
void tokenRoleContentChecker(char* str);
#endif