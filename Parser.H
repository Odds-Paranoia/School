#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Program;
class GlobalDec;
class ListStatement;
class ListGlobalDec;
class ListFormalParam;
class ListExpression;
class Literal;
class Type;
class Identifier;
class FormalParam;
class Block;
class Statement;
class FunctionInvocation;
class Primary;
class PostFixExpression;
class UnaryExpression;
class MultiplicativeExpression;
class AdditiveExpression;
class RelationalExpression;
class EqualityExpression;
class ConditionalAndExpression;
class ConditionalOrExpression;
class AssignmentExpression;
class Assignment;
class Expression;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  GlobalDec* globaldec_;
  ListStatement* liststatement_;
  ListGlobalDec* listglobaldec_;
  ListFormalParam* listformalparam_;
  ListExpression* listexpression_;
  Literal* literal_;
  Type* type_;
  Identifier* identifier_;
  FormalParam* formalparam_;
  Block* block_;
  Statement* statement_;
  FunctionInvocation* functioninvocation_;
  Primary* primary_;
  PostFixExpression* postfixexpression_;
  UnaryExpression* unaryexpression_;
  MultiplicativeExpression* multiplicativeexpression_;
  AdditiveExpression* additiveexpression_;
  RelationalExpression* relationalexpression_;
  EqualityExpression* equalityexpression_;
  ConditionalAndExpression* conditionalandexpression_;
  ConditionalOrExpression* conditionalorexpression_;
  AssignmentExpression* assignmentexpression_;
  Assignment* assignment_;
  Expression* expression_;
} YYSTYPE;

Program* pProgram(FILE *inp);
Program* pProgram(const char *str);
GlobalDec* pGlobalDec(FILE *inp);
GlobalDec* pGlobalDec(const char *str);
ListStatement* pListStatement(FILE *inp);
ListStatement* pListStatement(const char *str);
ListGlobalDec* pListGlobalDec(FILE *inp);
ListGlobalDec* pListGlobalDec(const char *str);
ListFormalParam* pListFormalParam(FILE *inp);
ListFormalParam* pListFormalParam(const char *str);
ListExpression* pListExpression(FILE *inp);
ListExpression* pListExpression(const char *str);
Literal* pLiteral(FILE *inp);
Literal* pLiteral(const char *str);
Type* pType(FILE *inp);
Type* pType(const char *str);
Identifier* pIdentifier(FILE *inp);
Identifier* pIdentifier(const char *str);
FormalParam* pFormalParam(FILE *inp);
FormalParam* pFormalParam(const char *str);
Block* pBlock(FILE *inp);
Block* pBlock(const char *str);
Statement* pStatement(FILE *inp);
Statement* pStatement(const char *str);
FunctionInvocation* pFunctionInvocation(FILE *inp);
FunctionInvocation* pFunctionInvocation(const char *str);
Primary* pPrimary(FILE *inp);
Primary* pPrimary(const char *str);
PostFixExpression* pPostFixExpression(FILE *inp);
PostFixExpression* pPostFixExpression(const char *str);
UnaryExpression* pUnaryExpression(FILE *inp);
UnaryExpression* pUnaryExpression(const char *str);
MultiplicativeExpression* pMultiplicativeExpression(FILE *inp);
MultiplicativeExpression* pMultiplicativeExpression(const char *str);
AdditiveExpression* pAdditiveExpression(FILE *inp);
AdditiveExpression* pAdditiveExpression(const char *str);
RelationalExpression* pRelationalExpression(FILE *inp);
RelationalExpression* pRelationalExpression(const char *str);
EqualityExpression* pEqualityExpression(FILE *inp);
EqualityExpression* pEqualityExpression(const char *str);
ConditionalAndExpression* pConditionalAndExpression(FILE *inp);
ConditionalAndExpression* pConditionalAndExpression(const char *str);
ConditionalOrExpression* pConditionalOrExpression(FILE *inp);
ConditionalOrExpression* pConditionalOrExpression(const char *str);
AssignmentExpression* pAssignmentExpression(FILE *inp);
AssignmentExpression* pAssignmentExpression(const char *str);
Assignment* pAssignment(FILE *inp);
Assignment* pAssignment(const char *str);
Expression* pExpression(FILE *inp);
Expression* pExpression(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _STRING_ 291
#define _INTEGER_ 292

extern YYSTYPE yylval;

#endif
