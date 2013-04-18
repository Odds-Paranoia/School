#ifndef CODEGEN_HEADER
#define CODEGEN_HEADER

#include "enums.h"

/* NOTES
Gonna stick to an ACCUMULATOR theme. The result of expressions will ALWAYS be in r0.

*/


class CodeGen : public Visitor
{
public:
  CodeGen();
  ~CodeGen();

  // Run on tree
  void generate(Visitable* v);

  // used to pass variables up stack.
  string tempString;
  string tempName;
  int tempInt;

  // starts at 0, increments when reg is allocated
  int topRegister;

  // Stacks of utility labels used for branching.
  stack<int> curIf;
  int maxIf;
  stack<int> curIfElse;
  int maxIfElse;
  stack<int> curWhile;
  int maxWhile;
  stack<int> curExpr;
  int maxExpr;

  string curScope;

  // # of regs allocated in this scope
  int regsInScope;

  // Subset of regVars, NOT including global variables.
  map<string, int> regVarsInScope;
  // Copy of previous, used to clean names when done calling
  map<string, int> tempRegVars;

  // Stores previous namespace for func calls
  stack<map<string, int> > regVarStack;

  map<string, bool> varWasFormParam;
  map<string, int> varFormerLocation;
  stack<map<string, bool> > formParamStack;


  // Pseudo-Stack, keeps track of what's in registers. Globals.
  map<string, int> globalRegVars;


  // String stuff
  map<int, string> literalStrings;
  int curStringNum;

  int curDataNum;

  //THE IDEA HERE IS YOU NEED TO COLLECT THE FORMAL PARAMS
  // ON THE GLOBAL TRAVERSAL IN THE "inner" map. So this reads:
  // map<string FUNCNAME, list <string paramName> >
  // Which you can then store into regVarsInScope upon function call
  map<string, list<string> > paramsForFunction;

  bool dontMindMeJustCollectingGlobals;
  bool isFormParam;
  bool isArgument;
  bool isRTS;
  bool DONT_MOVE;
  bool isFCall;
  int savedTopReg;
  int paramNum;
  int topGlobal;
  int traversalsToGo;

  // Used for loose typechecking
  int tempType;
  /* 

  $ METHODS $

              */

  // Primitive commands.
  void emitCmd(string cmd, int reg);
  void emitCmd(string cmd, int destReg, int reg2);
  void emitCmd(string cmd, int destReg, int reg2, int reg3);

  // For comparing to constants, and maybe memory addresses?
  void emitCmd(string cmd, int reg, string lit);

  // Primitives with literals
  void emitCmd(string cmd, int reg1, int reg2, string lit);

 // For branches 
  void emitCmd(string cmd, string label);

  /* eg. 
    main_ifElse_1_start
    main_ifElse_1_else
    main_ifElse_1_end
    eg.
    main_func_start
    main_func_end
    */
  void emitLabel(string scope, string type, int counter, string modifier);
  void emitLabel(string label);
  
  // for control flow statements
  string getLabel(string scope, string type, int counter, string modifier);
  string getGlobalLabel(int number);

  void emit(string cmd);

  

  // increments register counter, returns BOTTOM available
  // TODO: account for spilling
  int allocRegs(int numRegs);
  int freeRegs(int numRegs);
  
  // Returns register associated with variable, incs reg counter
  int assocReg(string name);
  int assocParam(string name);
  int assocGlobal(string name);
  int regAtName(string name);
  int assocFree(string name);

  void emitStoreStr(string str, int stringNum);
  int getVirtualReg(int reg);

  void freeScopeVars();

  string strReplace(string &s,
                    string toReplace,
                    string replaceWith);

  string replaceEscapes(string &s);

  










  void visitProgram(Program* p);
  void visitGlobalDec(GlobalDec* p);
  void visitLiteral(Literal* p);
  void visitType(Type* p);
  void visitIdentifier(Identifier* p);
  void visitFormalParam(FormalParam* p);
  void visitBlock(Block* p);
  void visitStatement(Statement* p);
  void visitFunctionInvocation(FunctionInvocation* p);
  void visitPrimary(Primary* p);
  void visitPostFixExpression(PostFixExpression* p);
  void visitUnaryExpression(UnaryExpression* p);
  void visitMultiplicativeExpression(MultiplicativeExpression* p);
  void visitAdditiveExpression(AdditiveExpression* p);
  void visitRelationalExpression(RelationalExpression* p);
  void visitEqualityExpression(EqualityExpression* p);
  void visitConditionalAndExpression(ConditionalAndExpression* p);
  void visitConditionalOrExpression(ConditionalOrExpression* p);
  void visitAssignmentExpression(AssignmentExpression* p);
  void visitAssignment(Assignment* p);
  void visitExpression(Expression* p);
  void visitProg(Prog* p);
  void visitGFuncDec(GFuncDec* p);
  void visitGVFuncDec(GVFuncDec* p);
  void visitGMainFuncDec(GMainFuncDec* p);
  void visitGVarDec(GVarDec* p);
  void visitEInt(EInt* p);
  void visitEString(EString* p);
  void visitETrue(ETrue* p);
  void visitEFalse(EFalse* p);
  void visitTBool(TBool* p);
  void visitTInt(TInt* p);
  void visitEId(EId* p);
  void visitFParam(FParam* p);
  void visitBBlock(BBlock* p);
  void visitSVarDec(SVarDec* p);
  void visitSBlock(SBlock* p);
  void visitSEmpty(SEmpty* p);
  void visitSAssign(SAssign* p);
  void visitSCall(SCall* p);
  void visitSBreak(SBreak* p);
  void visitSRetExpr(SRetExpr* p);
  void visitSRet(SRet* p);
  void visitSIfElse(SIfElse* p);
  void visitSIf(SIf* p);
  void visitSWhile(SWhile* p);
  void visitFCall(FCall* p);
  void visitPLiteral(PLiteral* p);
  void visitPExpr(PExpr* p);
  void visitPFuncInv(PFuncInv* p);
  void visitPFExprPrim(PFExprPrim* p);
  void visitPFExprID(PFExprID* p);
  void visitUnExpr(UnExpr* p);
  void visitUnExprMin(UnExprMin* p);
  void visitUnExprNeg(UnExprNeg* p);
  void visitMulExpr(MulExpr* p);
  void visitMulExprMul(MulExprMul* p);
  void visitMulExprDiv(MulExprDiv* p);
  void visitMulExprMod(MulExprMod* p);
  void visitAddExpr(AddExpr* p);
  void visitAddExprAdd(AddExprAdd* p);
  void visitAddExprSub(AddExprSub* p);
  void visitRelExpr(RelExpr* p);
  void visitRelExprLT(RelExprLT* p);
  void visitRelExprGT(RelExprGT* p);
  void visitRelExprLE(RelExprLE* p);
  void visitRelExprGE(RelExprGE* p);
  void visitEqExpr(EqExpr* p);
  void visitEqExprEQ(EqExprEQ* p);
  void visitEqExprNE(EqExprNE* p);
  void visitCAExpr(CAExpr* p);
  void visitCAExprAnd(CAExprAnd* p);
  void visitCOExpr(COExpr* p);
  void visitCOExprOr(COExprOr* p);
  void visitAssExpr(AssExpr* p);
  void visitAssExprAss(AssExprAss* p);
  void visitAssign(Assign* p);
  void visitExpr(Expr* p);
  void visitListStatement(ListStatement* p);
  void visitListGlobalDec(ListGlobalDec* p);
  void visitListFormalParam(ListFormalParam* p);
  void visitListExpression(ListExpression* p);
  void visitPIdentifier(PIdentifier* p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);


};


#endif