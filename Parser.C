/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "jmm.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Absyn.H"
#include <algorithm>
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  std::cout << "line " << yy_mylinenumber << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}



static Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program* pProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

static GlobalDec* YY_RESULT_GlobalDec_ = 0;
GlobalDec* pGlobalDec(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_GlobalDec_;
  }
}
GlobalDec* pGlobalDec(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_GlobalDec_;
  }
}

static ListStatement* YY_RESULT_ListStatement_ = 0;
ListStatement* pListStatement(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}
ListStatement* pListStatement(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}

static ListGlobalDec* YY_RESULT_ListGlobalDec_ = 0;
ListGlobalDec* pListGlobalDec(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListGlobalDec_;
  }
}
ListGlobalDec* pListGlobalDec(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListGlobalDec_;
  }
}

static ListFormalParam* YY_RESULT_ListFormalParam_ = 0;
ListFormalParam* pListFormalParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFormalParam_;
  }
}
ListFormalParam* pListFormalParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFormalParam_;
  }
}

static ListExpression* YY_RESULT_ListExpression_ = 0;
ListExpression* pListExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpression_;
  }
}
ListExpression* pListExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpression_;
  }
}

static Literal* YY_RESULT_Literal_ = 0;
Literal* pLiteral(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Literal_;
  }
}
Literal* pLiteral(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Literal_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

static Identifier* YY_RESULT_Identifier_ = 0;
Identifier* pIdentifier(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Identifier_;
  }
}
Identifier* pIdentifier(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Identifier_;
  }
}

static FormalParam* YY_RESULT_FormalParam_ = 0;
FormalParam* pFormalParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FormalParam_;
  }
}
FormalParam* pFormalParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FormalParam_;
  }
}

static Block* YY_RESULT_Block_ = 0;
Block* pBlock(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}
Block* pBlock(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}

static Statement* YY_RESULT_Statement_ = 0;
Statement* pStatement(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}
Statement* pStatement(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}

static FunctionInvocation* YY_RESULT_FunctionInvocation_ = 0;
FunctionInvocation* pFunctionInvocation(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FunctionInvocation_;
  }
}
FunctionInvocation* pFunctionInvocation(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FunctionInvocation_;
  }
}

static Primary* YY_RESULT_Primary_ = 0;
Primary* pPrimary(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Primary_;
  }
}
Primary* pPrimary(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Primary_;
  }
}

static PostFixExpression* YY_RESULT_PostFixExpression_ = 0;
PostFixExpression* pPostFixExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PostFixExpression_;
  }
}
PostFixExpression* pPostFixExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PostFixExpression_;
  }
}

static UnaryExpression* YY_RESULT_UnaryExpression_ = 0;
UnaryExpression* pUnaryExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_UnaryExpression_;
  }
}
UnaryExpression* pUnaryExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_UnaryExpression_;
  }
}

static MultiplicativeExpression* YY_RESULT_MultiplicativeExpression_ = 0;
MultiplicativeExpression* pMultiplicativeExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MultiplicativeExpression_;
  }
}
MultiplicativeExpression* pMultiplicativeExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MultiplicativeExpression_;
  }
}

static AdditiveExpression* YY_RESULT_AdditiveExpression_ = 0;
AdditiveExpression* pAdditiveExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AdditiveExpression_;
  }
}
AdditiveExpression* pAdditiveExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AdditiveExpression_;
  }
}

static RelationalExpression* YY_RESULT_RelationalExpression_ = 0;
RelationalExpression* pRelationalExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelationalExpression_;
  }
}
RelationalExpression* pRelationalExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelationalExpression_;
  }
}

static EqualityExpression* YY_RESULT_EqualityExpression_ = 0;
EqualityExpression* pEqualityExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EqualityExpression_;
  }
}
EqualityExpression* pEqualityExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EqualityExpression_;
  }
}

static ConditionalAndExpression* YY_RESULT_ConditionalAndExpression_ = 0;
ConditionalAndExpression* pConditionalAndExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ConditionalAndExpression_;
  }
}
ConditionalAndExpression* pConditionalAndExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ConditionalAndExpression_;
  }
}

static ConditionalOrExpression* YY_RESULT_ConditionalOrExpression_ = 0;
ConditionalOrExpression* pConditionalOrExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ConditionalOrExpression_;
  }
}
ConditionalOrExpression* pConditionalOrExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ConditionalOrExpression_;
  }
}

static AssignmentExpression* YY_RESULT_AssignmentExpression_ = 0;
AssignmentExpression* pAssignmentExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AssignmentExpression_;
  }
}
AssignmentExpression* pAssignmentExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AssignmentExpression_;
  }
}

static Assignment* YY_RESULT_Assignment_ = 0;
Assignment* pAssignment(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Assignment_;
  }
}
Assignment* pAssignment(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Assignment_;
  }
}

static Expression* YY_RESULT_Expression_ = 0;
Expression* pExpression(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expression_;
  }
}
Expression* pExpression(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expression_;
  }
}

static PIdentifier* YY_RESULT_PIdentifier_ = 0;
PIdentifier* pPIdentifier(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PIdentifier_;
  }
}
PIdentifier* pPIdentifier(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PIdentifier_;
  }
}





/* Line 268 of yacc.c  */
#line 960 "Parser.C"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     _SYMB_0 = 259,
     _SYMB_1 = 260,
     _SYMB_2 = 261,
     _SYMB_3 = 262,
     _SYMB_4 = 263,
     _SYMB_5 = 264,
     _SYMB_6 = 265,
     _SYMB_7 = 266,
     _SYMB_8 = 267,
     _SYMB_9 = 268,
     _SYMB_10 = 269,
     _SYMB_11 = 270,
     _SYMB_12 = 271,
     _SYMB_13 = 272,
     _SYMB_14 = 273,
     _SYMB_15 = 274,
     _SYMB_16 = 275,
     _SYMB_17 = 276,
     _SYMB_18 = 277,
     _SYMB_19 = 278,
     _SYMB_20 = 279,
     _SYMB_21 = 280,
     _SYMB_22 = 281,
     _SYMB_23 = 282,
     _SYMB_24 = 283,
     _SYMB_25 = 284,
     _SYMB_26 = 285,
     _SYMB_27 = 286,
     _SYMB_28 = 287,
     _SYMB_29 = 288,
     _SYMB_30 = 289,
     _SYMB_31 = 290,
     _STRING_ = 291,
     _INTEGER_ = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 891 "jmm.y"

  int int_;
  char char_;
  double double_;
  char* string_;
  PIdentifier* pidentifier_;
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




/* Line 293 of yacc.c  */
#line 1069 "Parser.C"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 1081 "Parser.C"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    12,    19,    26,    30,    31,    34,
      35,    38,    39,    41,    45,    46,    48,    52,    54,    56,
      58,    60,    62,    64,    66,    69,    73,    77,    79,    82,
      85,    88,    91,    97,   103,   105,   107,   111,   119,   124,
     126,   130,   132,   134,   136,   138,   141,   144,   146,   150,
     154,   158,   160,   164,   168,   170,   174,   178,   182,   186,
     188,   192,   196,   198,   202,   204,   208,   210,   212,   216,
     218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    42,    -1,    46,    47,     4,    43,     5,
      49,    -1,    33,    47,     4,    43,     5,    49,    -1,    47,
       4,     5,     6,    41,     7,    -1,    46,    47,     8,    -1,
      -1,    41,    50,    -1,    -1,    42,    40,    -1,    -1,    48,
      -1,    48,     9,    43,    -1,    -1,    64,    -1,    64,     9,
      44,    -1,    37,    -1,    36,    -1,    28,    -1,    32,    -1,
      25,    -1,    30,    -1,    65,    -1,    46,    47,    -1,     6,
      41,     7,    -1,    46,    47,     8,    -1,     8,    -1,    63,
       8,    -1,    52,     8,    -1,    26,     8,    -1,    31,     8,
      -1,    29,     4,    64,     5,    50,    -1,    34,     4,    64,
       5,    50,    -1,    51,    -1,    49,    -1,    31,    64,     8,
      -1,    29,     4,    64,     5,    50,    27,    50,    -1,    47,
       4,    44,     5,    -1,    45,    -1,     4,    64,     5,    -1,
      52,    -1,    53,    -1,    47,    -1,    54,    -1,    10,    55,
      -1,    11,    55,    -1,    55,    -1,    56,    12,    55,    -1,
      56,    13,    55,    -1,    56,    14,    55,    -1,    56,    -1,
      57,    15,    56,    -1,    57,    10,    56,    -1,    57,    -1,
      58,    16,    57,    -1,    58,    17,    57,    -1,    58,    18,
      57,    -1,    58,    19,    57,    -1,    58,    -1,    59,    20,
      58,    -1,    59,    21,    58,    -1,    59,    -1,    60,    22,
      59,    -1,    60,    -1,    61,    23,    60,    -1,    61,    -1,
      63,    -1,    47,    24,    62,    -1,    62,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   992,   992,   994,   995,   996,   997,   999,  1000,  1002,
    1003,  1005,  1006,  1007,  1009,  1010,  1011,  1013,  1014,  1015,
    1016,  1018,  1019,  1021,  1023,  1025,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1037,  1038,  1039,  1041,  1043,
    1044,  1045,  1047,  1048,  1050,  1051,  1052,  1054,  1055,  1056,
    1057,  1059,  1060,  1061,  1063,  1064,  1065,  1066,  1067,  1069,
    1070,  1071,  1073,  1074,  1076,  1077,  1079,  1080,  1082,  1084,
    1086
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_STRING_", "_INTEGER_", "$accept", "Program", "GlobalDec",
  "ListStatement", "ListGlobalDec", "ListFormalParam", "ListExpression",
  "Literal", "Type", "Identifier", "FormalParam", "Block", "Statement",
  "Statement1", "FunctionInvocation", "Primary", "PostFixExpression",
  "UnaryExpression", "MultiplicativeExpression", "AdditiveExpression",
  "RelationalExpression", "EqualityExpression", "ConditionalAndExpression",
  "ConditionalOrExpression", "AssignmentExpression", "Assignment",
  "Expression", "PIdentifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    44,    44,    44,    45,    45,    45,
      45,    46,    46,    47,    48,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    53,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     6,     6,     3,     0,     2,     0,
       2,     0,     1,     3,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     1,     2,     2,
       2,     2,     5,     5,     1,     1,     3,     7,     4,     1,
       3,     1,     1,     1,     1,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     2,     1,    21,    22,     0,    70,    10,     0,
       0,    23,     0,     0,     0,    11,    11,     6,     0,     0,
       0,    12,     0,     7,     0,    24,    11,     0,     0,     7,
       4,    13,     3,     5,    27,     0,     0,     0,     0,     0,
       0,    35,     8,    34,     0,     0,     0,    30,     0,     0,
      31,     0,     0,    19,    20,    18,    17,    39,    43,    41,
      42,    44,    47,    51,    54,    59,    62,    64,    66,    69,
      67,     0,     0,     0,    14,     0,    29,    28,    25,     0,
       0,    43,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    26,
       0,    15,    68,     0,    40,    48,    49,    50,    53,    52,
      55,    56,    57,    58,    60,    61,    63,    65,     0,    38,
      14,    32,    33,    16,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     8,    28,     2,    19,   100,    57,    39,    81,
      21,    41,    42,    43,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   101,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
     -89,    10,    77,   -89,   -89,   -89,   -23,   -89,   -89,   -23,
      13,   -89,    39,    37,    64,   -16,   -16,   -89,    43,    70,
     -23,    78,    81,   -89,    89,   -89,   -16,    89,    59,   -89,
     -89,   -89,   -89,   -89,   -89,    88,    95,    23,    96,   -23,
      -1,   -89,   -89,   -89,   100,   101,    98,   -89,    46,    46,
     -89,    46,    46,   -89,   -89,   -89,   -89,   -89,    -1,   -89,
     -89,   -89,   -89,   107,     1,    45,     8,    92,    80,   -89,
     -89,   109,    46,   117,    46,    46,   -89,   -89,   -89,   110,
     121,   133,   -89,   -89,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,   -89,   140,   -89,
     141,   129,   -89,   105,   -89,   -89,   -89,   -89,   107,   107,
       1,     1,     1,     1,    45,    45,     8,    92,   105,   -89,
      46,   120,   -89,   -89,   105,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   119,   -89,    26,    29,   -89,     6,    -2,
     -89,    44,   -88,   -89,   -27,   -89,   -89,   -46,   -34,    52,
     -14,    55,    56,   -89,    76,   -26,   -24,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      10,    44,    45,    74,    12,    82,    83,    13,     9,     4,
       3,    87,     7,    71,     5,   121,    88,    14,    25,    44,
      45,    20,    20,    75,    79,    80,    40,    49,    93,    94,
     122,    50,    20,    51,    52,    58,   125,    73,   105,   106,
     107,    16,    22,    15,    40,    17,    58,    58,    98,    23,
      49,    53,    31,   108,   109,    54,    51,    52,     7,    55,
      56,    89,    90,    91,    92,    29,    33,    34,    30,    18,
      58,    32,    58,    58,    53,    24,    44,    45,    54,   114,
     115,     7,    55,    56,     4,    35,    27,    26,    36,     5,
      37,    44,    45,    38,     7,    29,    47,    44,    45,    48,
      72,    40,     4,    96,    29,    78,    34,     5,    76,    77,
       6,    29,     7,    34,    95,   103,    40,    97,    58,    84,
      85,    86,    40,     4,    35,    99,   104,    36,     5,    37,
       4,    35,    38,     7,    36,     5,    37,    74,   120,    38,
       7,   110,   111,   112,   113,   118,   119,   124,    46,   123,
     116,   102,   117
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-89))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       2,    28,    28,     4,     6,    51,    52,     9,     2,    25,
       0,    10,    35,    37,    30,   103,    15,     4,    20,    46,
      46,    15,    16,    24,    48,    49,    28,     4,    20,    21,
     118,     8,    26,    10,    11,    37,   124,    39,    84,    85,
      86,     4,    16,     4,    46,     8,    48,    49,    72,     6,
       4,    28,    26,    87,    88,    32,    10,    11,    35,    36,
      37,    16,    17,    18,    19,     6,     7,     8,    24,     5,
      72,    27,    74,    75,    28,     5,   103,   103,    32,    93,
      94,    35,    36,    37,    25,    26,     5,     9,    29,    30,
      31,   118,   118,    34,    35,     6,     8,   124,   124,     4,
       4,   103,    25,    23,     6,     7,     8,    30,     8,     8,
      33,     6,    35,     8,    22,     5,   118,     8,   120,    12,
      13,    14,   124,    25,    26,     8,     5,    29,    30,    31,
      25,    26,    34,    35,    29,    30,    31,     4,     9,    34,
      35,    89,    90,    91,    92,     5,     5,    27,    29,   120,
      95,    75,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    42,     0,    25,    30,    33,    35,    40,    46,
      47,    65,    47,    47,     4,     4,     4,     8,     5,    43,
      46,    48,    43,     6,     5,    47,     9,     5,    41,     6,
      49,    43,    49,     7,     8,    26,    29,    31,    34,    46,
      47,    49,    50,    51,    52,    63,    41,     8,     4,     4,
       8,    10,    11,    28,    32,    36,    37,    45,    47,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     4,    47,     4,    24,     8,     8,     7,    64,
      64,    47,    55,    55,    12,    13,    14,    10,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     8,    64,     8,
      44,    64,    62,     5,     5,    55,    55,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    59,    60,     5,     5,
       9,    50,    50,    44,    27,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 992 "jmm.y"
    {  (yyval.program_) = new Prog((yyvsp[(1) - (1)].listglobaldec_)); YY_RESULT_Program_= (yyval.program_); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 994 "jmm.y"
    {  std::reverse((yyvsp[(4) - (6)].listformalparam_)->begin(),(yyvsp[(4) - (6)].listformalparam_)->end()) ;(yyval.globaldec_) = new GFuncDec((yyvsp[(1) - (6)].type_), (yyvsp[(2) - (6)].identifier_), (yyvsp[(4) - (6)].listformalparam_), (yyvsp[(6) - (6)].block_)); YY_RESULT_GlobalDec_= (yyval.globaldec_); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 995 "jmm.y"
    {  std::reverse((yyvsp[(4) - (6)].listformalparam_)->begin(),(yyvsp[(4) - (6)].listformalparam_)->end()) ;(yyval.globaldec_) = new GVFuncDec((yyvsp[(2) - (6)].identifier_), (yyvsp[(4) - (6)].listformalparam_), (yyvsp[(6) - (6)].block_)); YY_RESULT_GlobalDec_= (yyval.globaldec_); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 996 "jmm.y"
    {  (yyval.globaldec_) = new GMainFuncDec((yyvsp[(1) - (6)].identifier_), (yyvsp[(5) - (6)].liststatement_)); YY_RESULT_GlobalDec_= (yyval.globaldec_); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 997 "jmm.y"
    {  (yyval.globaldec_) = new GVarDec((yyvsp[(1) - (3)].type_), (yyvsp[(2) - (3)].identifier_)); YY_RESULT_GlobalDec_= (yyval.globaldec_); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 999 "jmm.y"
    {  (yyval.liststatement_) = new ListStatement(); YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 1000 "jmm.y"
    {  (yyvsp[(1) - (2)].liststatement_)->push_back((yyvsp[(2) - (2)].statement_)) ; (yyval.liststatement_) = (yyvsp[(1) - (2)].liststatement_) ; YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 1002 "jmm.y"
    {  (yyval.listglobaldec_) = new ListGlobalDec(); YY_RESULT_ListGlobalDec_= (yyval.listglobaldec_); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 1003 "jmm.y"
    {  (yyvsp[(1) - (2)].listglobaldec_)->push_back((yyvsp[(2) - (2)].globaldec_)) ; (yyval.listglobaldec_) = (yyvsp[(1) - (2)].listglobaldec_) ; YY_RESULT_ListGlobalDec_= (yyval.listglobaldec_); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 1005 "jmm.y"
    {  (yyval.listformalparam_) = new ListFormalParam(); YY_RESULT_ListFormalParam_= (yyval.listformalparam_); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 1006 "jmm.y"
    {  (yyval.listformalparam_) = new ListFormalParam() ; (yyval.listformalparam_)->push_back((yyvsp[(1) - (1)].formalparam_)); YY_RESULT_ListFormalParam_= (yyval.listformalparam_); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 1007 "jmm.y"
    {  (yyvsp[(3) - (3)].listformalparam_)->push_back((yyvsp[(1) - (3)].formalparam_)) ; (yyval.listformalparam_) = (yyvsp[(3) - (3)].listformalparam_) ; YY_RESULT_ListFormalParam_= (yyval.listformalparam_); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 1009 "jmm.y"
    {  (yyval.listexpression_) = new ListExpression(); YY_RESULT_ListExpression_= (yyval.listexpression_); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 1010 "jmm.y"
    {  (yyval.listexpression_) = new ListExpression() ; (yyval.listexpression_)->push_back((yyvsp[(1) - (1)].expression_)); YY_RESULT_ListExpression_= (yyval.listexpression_); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 1011 "jmm.y"
    {  (yyvsp[(3) - (3)].listexpression_)->push_back((yyvsp[(1) - (3)].expression_)) ; (yyval.listexpression_) = (yyvsp[(3) - (3)].listexpression_) ; YY_RESULT_ListExpression_= (yyval.listexpression_); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 1013 "jmm.y"
    {  (yyval.literal_) = new EInt((yyvsp[(1) - (1)].int_)); YY_RESULT_Literal_= (yyval.literal_); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 1014 "jmm.y"
    {  (yyval.literal_) = new EString((yyvsp[(1) - (1)].string_)); YY_RESULT_Literal_= (yyval.literal_); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 1015 "jmm.y"
    {  (yyval.literal_) = new ETrue(); YY_RESULT_Literal_= (yyval.literal_); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 1016 "jmm.y"
    {  (yyval.literal_) = new EFalse(); YY_RESULT_Literal_= (yyval.literal_); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 1018 "jmm.y"
    {  (yyval.type_) = new TBool(); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 1019 "jmm.y"
    {  (yyval.type_) = new TInt(); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 1021 "jmm.y"
    {  (yyval.identifier_) = new EId((yyvsp[(1) - (1)].pidentifier_)); YY_RESULT_Identifier_= (yyval.identifier_); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 1023 "jmm.y"
    {  (yyval.formalparam_) = new FParam((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].identifier_)); YY_RESULT_FormalParam_= (yyval.formalparam_); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 1025 "jmm.y"
    {  (yyval.block_) = new BBlock((yyvsp[(2) - (3)].liststatement_)); YY_RESULT_Block_= (yyval.block_); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 1027 "jmm.y"
    {  (yyval.statement_) = new SVarDec((yyvsp[(1) - (3)].type_), (yyvsp[(2) - (3)].identifier_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 1028 "jmm.y"
    {  (yyval.statement_) = new SEmpty(); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 1029 "jmm.y"
    {  (yyval.statement_) = new SAssign((yyvsp[(1) - (2)].assignment_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 1030 "jmm.y"
    {  (yyval.statement_) = new SCall((yyvsp[(1) - (2)].functioninvocation_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 1031 "jmm.y"
    {  (yyval.statement_) = new SBreak(); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 1032 "jmm.y"
    {  (yyval.statement_) = new SRet(); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 1033 "jmm.y"
    {  (yyval.statement_) = new SIf((yyvsp[(3) - (5)].expression_), (yyvsp[(5) - (5)].statement_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 1034 "jmm.y"
    {  (yyval.statement_) = new SWhile((yyvsp[(3) - (5)].expression_), (yyvsp[(5) - (5)].statement_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 1035 "jmm.y"
    {  (yyval.statement_) = (yyvsp[(1) - (1)].statement_); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 1037 "jmm.y"
    {  (yyval.statement_) = new SBlock((yyvsp[(1) - (1)].block_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 1038 "jmm.y"
    {  (yyval.statement_) = new SRetExpr((yyvsp[(2) - (3)].expression_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 1039 "jmm.y"
    {  (yyval.statement_) = new SIfElse((yyvsp[(3) - (7)].expression_), (yyvsp[(5) - (7)].statement_), (yyvsp[(7) - (7)].statement_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 1041 "jmm.y"
    {  std::reverse((yyvsp[(3) - (4)].listexpression_)->begin(),(yyvsp[(3) - (4)].listexpression_)->end()) ;(yyval.functioninvocation_) = new FCall((yyvsp[(1) - (4)].identifier_), (yyvsp[(3) - (4)].listexpression_)); YY_RESULT_FunctionInvocation_= (yyval.functioninvocation_); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 1043 "jmm.y"
    {  (yyval.primary_) = new PLiteral((yyvsp[(1) - (1)].literal_)); YY_RESULT_Primary_= (yyval.primary_); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 1044 "jmm.y"
    {  (yyval.primary_) = new PExpr((yyvsp[(2) - (3)].expression_)); YY_RESULT_Primary_= (yyval.primary_); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 1045 "jmm.y"
    {  (yyval.primary_) = new PFuncInv((yyvsp[(1) - (1)].functioninvocation_)); YY_RESULT_Primary_= (yyval.primary_); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 1047 "jmm.y"
    {  (yyval.postfixexpression_) = new PFExprPrim((yyvsp[(1) - (1)].primary_)); YY_RESULT_PostFixExpression_= (yyval.postfixexpression_); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 1048 "jmm.y"
    {  (yyval.postfixexpression_) = new PFExprID((yyvsp[(1) - (1)].identifier_)); YY_RESULT_PostFixExpression_= (yyval.postfixexpression_); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1050 "jmm.y"
    {  (yyval.unaryexpression_) = new UnExpr((yyvsp[(1) - (1)].postfixexpression_)); YY_RESULT_UnaryExpression_= (yyval.unaryexpression_); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 1051 "jmm.y"
    {  (yyval.unaryexpression_) = new UnExprMin((yyvsp[(2) - (2)].unaryexpression_)); YY_RESULT_UnaryExpression_= (yyval.unaryexpression_); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1052 "jmm.y"
    {  (yyval.unaryexpression_) = new UnExprNeg((yyvsp[(2) - (2)].unaryexpression_)); YY_RESULT_UnaryExpression_= (yyval.unaryexpression_); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 1054 "jmm.y"
    {  (yyval.multiplicativeexpression_) = new MulExpr((yyvsp[(1) - (1)].unaryexpression_)); YY_RESULT_MultiplicativeExpression_= (yyval.multiplicativeexpression_); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 1055 "jmm.y"
    {  (yyval.multiplicativeexpression_) = new MulExprMul((yyvsp[(1) - (3)].multiplicativeexpression_), (yyvsp[(3) - (3)].unaryexpression_)); YY_RESULT_MultiplicativeExpression_= (yyval.multiplicativeexpression_); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 1056 "jmm.y"
    {  (yyval.multiplicativeexpression_) = new MulExprDiv((yyvsp[(1) - (3)].multiplicativeexpression_), (yyvsp[(3) - (3)].unaryexpression_)); YY_RESULT_MultiplicativeExpression_= (yyval.multiplicativeexpression_); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 1057 "jmm.y"
    {  (yyval.multiplicativeexpression_) = new MulExprMod((yyvsp[(1) - (3)].multiplicativeexpression_), (yyvsp[(3) - (3)].unaryexpression_)); YY_RESULT_MultiplicativeExpression_= (yyval.multiplicativeexpression_); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 1059 "jmm.y"
    {  (yyval.additiveexpression_) = new AddExpr((yyvsp[(1) - (1)].multiplicativeexpression_)); YY_RESULT_AdditiveExpression_= (yyval.additiveexpression_); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 1060 "jmm.y"
    {  (yyval.additiveexpression_) = new AddExprAdd((yyvsp[(1) - (3)].additiveexpression_), (yyvsp[(3) - (3)].multiplicativeexpression_)); YY_RESULT_AdditiveExpression_= (yyval.additiveexpression_); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 1061 "jmm.y"
    {  (yyval.additiveexpression_) = new AddExprSub((yyvsp[(1) - (3)].additiveexpression_), (yyvsp[(3) - (3)].multiplicativeexpression_)); YY_RESULT_AdditiveExpression_= (yyval.additiveexpression_); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1063 "jmm.y"
    {  (yyval.relationalexpression_) = new RelExpr((yyvsp[(1) - (1)].additiveexpression_)); YY_RESULT_RelationalExpression_= (yyval.relationalexpression_); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1064 "jmm.y"
    {  (yyval.relationalexpression_) = new RelExprLT((yyvsp[(1) - (3)].relationalexpression_), (yyvsp[(3) - (3)].additiveexpression_)); YY_RESULT_RelationalExpression_= (yyval.relationalexpression_); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1065 "jmm.y"
    {  (yyval.relationalexpression_) = new RelExprGT((yyvsp[(1) - (3)].relationalexpression_), (yyvsp[(3) - (3)].additiveexpression_)); YY_RESULT_RelationalExpression_= (yyval.relationalexpression_); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 1066 "jmm.y"
    {  (yyval.relationalexpression_) = new RelExprLE((yyvsp[(1) - (3)].relationalexpression_), (yyvsp[(3) - (3)].additiveexpression_)); YY_RESULT_RelationalExpression_= (yyval.relationalexpression_); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 1067 "jmm.y"
    {  (yyval.relationalexpression_) = new RelExprGE((yyvsp[(1) - (3)].relationalexpression_), (yyvsp[(3) - (3)].additiveexpression_)); YY_RESULT_RelationalExpression_= (yyval.relationalexpression_); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1069 "jmm.y"
    {  (yyval.equalityexpression_) = new EqExpr((yyvsp[(1) - (1)].relationalexpression_)); YY_RESULT_EqualityExpression_= (yyval.equalityexpression_); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1070 "jmm.y"
    {  (yyval.equalityexpression_) = new EqExprEQ((yyvsp[(1) - (3)].equalityexpression_), (yyvsp[(3) - (3)].relationalexpression_)); YY_RESULT_EqualityExpression_= (yyval.equalityexpression_); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 1071 "jmm.y"
    {  (yyval.equalityexpression_) = new EqExprNE((yyvsp[(1) - (3)].equalityexpression_), (yyvsp[(3) - (3)].relationalexpression_)); YY_RESULT_EqualityExpression_= (yyval.equalityexpression_); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 1073 "jmm.y"
    {  (yyval.conditionalandexpression_) = new CAExpr((yyvsp[(1) - (1)].equalityexpression_)); YY_RESULT_ConditionalAndExpression_= (yyval.conditionalandexpression_); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1074 "jmm.y"
    {  (yyval.conditionalandexpression_) = new CAExprAnd((yyvsp[(1) - (3)].conditionalandexpression_), (yyvsp[(3) - (3)].equalityexpression_)); YY_RESULT_ConditionalAndExpression_= (yyval.conditionalandexpression_); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1076 "jmm.y"
    {  (yyval.conditionalorexpression_) = new COExpr((yyvsp[(1) - (1)].conditionalandexpression_)); YY_RESULT_ConditionalOrExpression_= (yyval.conditionalorexpression_); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 1077 "jmm.y"
    {  (yyval.conditionalorexpression_) = new COExprOr((yyvsp[(1) - (3)].conditionalorexpression_), (yyvsp[(3) - (3)].conditionalandexpression_)); YY_RESULT_ConditionalOrExpression_= (yyval.conditionalorexpression_); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1079 "jmm.y"
    {  (yyval.assignmentexpression_) = new AssExpr((yyvsp[(1) - (1)].conditionalorexpression_)); YY_RESULT_AssignmentExpression_= (yyval.assignmentexpression_); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1080 "jmm.y"
    {  (yyval.assignmentexpression_) = new AssExprAss((yyvsp[(1) - (1)].assignment_)); YY_RESULT_AssignmentExpression_= (yyval.assignmentexpression_); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1082 "jmm.y"
    {  (yyval.assignment_) = new Assign((yyvsp[(1) - (3)].identifier_), (yyvsp[(3) - (3)].assignmentexpression_)); YY_RESULT_Assignment_= (yyval.assignment_); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1084 "jmm.y"
    {  (yyval.expression_) = new Expr((yyvsp[(1) - (1)].assignmentexpression_)); YY_RESULT_Expression_= (yyval.expression_); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1086 "jmm.y"
    {  (yyval.pidentifier_) = new PIdentifier((yyvsp[(1) - (1)].string_),yy_mylinenumber) ; YY_RESULT_PIdentifier_= (yyval.pidentifier_) ; }
    break;



/* Line 1806 of yacc.c  */
#line 2911 "Parser.C"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



