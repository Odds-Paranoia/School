#include "CodeGen.H"
   
CodeGen::CodeGen() 
{
  topRegister = 1;
  tempInt = 0;

  maxIf = 0;
  maxIfElse = 0;
  maxWhile = 0;
  maxExpr = 0;
  tempType = VOID_T;

  curScope = "global";

  regsInScope = 0;
  curStringNum = 0;

  dontMindMeJustCollectingGlobals = true;
  isFormParam = false;
  isArgument = false;
  isRTS = false;
  DONT_MOVE = false;
  isFCall = false;
  paramNum = 1;
  topGlobal = -1;

  emit("stackStart: .skip 1024*1024 @1MB stack space");
  emit("stackEnd: .byte 0");

  emit(".globl _start");
  //emit("adr \tsp, \tstackEnd \t@@ setup stack pointer, full descending");
  emit(".extern getchar");
  emit(".extern printb");
  emit(".extern printc");
  emit(".extern printi");
  emit(".extern prints");
  emit(".extern halt");
  emit("");
  emit("@@ Compiled by: J-- Compiler by Josh Dyck, UCID 10024728 @@");
  emit("");
  emit(".align 4\n");
  emit(".data\n");
}
CodeGen::~CodeGen(){}

void CodeGen::generate(Visitable* v){
  v->accept(this);
  dontMindMeJustCollectingGlobals = false;
  v->accept(this);
}

void CodeGen::emitCmd(string cmd, int reg) {
  cout << "\t" << cmd << "\tr" << reg << "\n";
}

void CodeGen::emitCmd(string cmd, int reg1, int reg2) {
  string MOV = string("MOV");

  // OVERFLOWED name
  if((MOV.compare(cmd) == 0) && (reg1 > 11)) {   
    cout << "\tSTR\t" << "r" << reg2 << ",\t [SP, #" << getVirtualReg(reg1) <<"]\n";
  }
  else if((MOV.compare(cmd) == 0) && (reg2 > 11)) {    
    cout << "\tLDR\t" << "r" << reg1 << ",\t [SP, #" << getVirtualReg(reg2) <<"]\n";
  }

  // GLOBAL name
  // First arg is global -> STORE.
  else if((MOV.compare(cmd) == 0) && (reg1 < 0)) {
    cout << "\tLDR\t" << "r" << 12 << ",\t =" << getGlobalLabel(reg1) << "\n";
    cout << "\tSTR\t" << "r" << reg2 << ",\t [r" << 12 << "]\n";
  }
  // 2nd arg is global -> LOAD.
  else if((MOV.compare(cmd) == 0) && (reg2 < 0)) {
    cout << "\tLDR\t" << "r" << 12 << ",\t =" << getGlobalLabel(reg2) << "\n";
    cout << "\tLDR\t" << "r" << reg1 << ",\t [r" << 12 << "]\n";
  }  

  // LOCAL name
  else
    cout << "\t" << cmd << "\tr" << reg1 << ",\tr" << reg2 << "\n";
}

 // ADD, SUB, etc
  // r12 is temporary register for arithmetic stuff.
void CodeGen::emitCmd(string cmd, int reg1, int reg2, int reg3) {

  // OVERFLOWED name
  if (reg2 > 11)
  {
    cout << "\tLDR\t" << "r12,\t [SP, #" << getVirtualReg(reg2) << "]\n";
    cout << "\t" << cmd << "\tr" << reg1 << ",\tr12,\tr" << reg3 << "\n";
  }

  // GLOBAL name
  else if (reg2 < 0)
  {
    cout << "\tLDR\t" << "r12,\t =" << getGlobalLabel(reg2) << "\n";
    cout << "\tLDR\t" << "r12" << reg1 << ",\t [r" << 12 << "]\n";
    cout << "\t" << cmd << "\tr" << reg1 << ",\tr12,\tr" << reg3 << "\n";
  }
  // Is this necessary?
  else if (reg1 < 0)
  {
    cout << "\tLDR\t" << "r12,\t =" << getGlobalLabel(reg1) << "\n";
    cout << "\tSTR\t" << "r12" << reg2 << ",\t [r" << 12 << "]\n";
    cout << "\t" << cmd << "\tr" << reg2 << ",\tr12,\tr" << reg3 << "\n";
  }

  // LOCAL name
  else
    cout << "\t" << cmd << "\tr" << reg1 << ",\tr" << reg2 << ",\tr" << reg3 << "\n";
}

void CodeGen::emitCmd(string cmd, int reg, string lit) {
  cout << "\t" << cmd << "\tr" << reg << ",\t" << lit << "\n";  
}

void CodeGen::emitCmd(string cmd, int reg1, int reg2, string lit) {
  cout << "\t" << cmd << "\tr" << reg1 << ",\tr" << reg2 << ",\t" << lit << "\n";  
}

void CodeGen::emitCmd(string cmd, string label) {
  cout << "\t" << cmd << "\t" << label << "\n";
}

void CodeGen::emitLabel(string scope, string type, int counter, string modifier) {
  if(type == "na")
    cout << scope << "_" << type << "_" << modifier << ":\n";
  else
    cout << scope << "_" << type << "_" << counter << "_" << modifier << ":\n";
}

void CodeGen::emitLabel(string label) {
  cout << label << ":\n";
}

string CodeGen::getLabel(string scope, string type, int counter, string modifier) {
  //set up buffer for label
  char tempBuf[50]; 
  if(type == "na")
    sprintf(tempBuf, "%s_%s_%s", 
      scope.c_str(), type.c_str(), modifier.c_str());
  else
    sprintf(tempBuf, "%s_%s_%d_%s", 
      scope.c_str(), type.c_str(), counter,  modifier.c_str());
  return string(tempBuf);
}

string CodeGen::getGlobalLabel(int number) {
  char buf[20];
  sprintf(buf, "globalVar%d", (number * -1));
  return string(buf);
}

void CodeGen::emit(string cmd) {
  cout << cmd << "\n";
}

int CodeGen::allocRegs(int numRegs) {
  // TODO: Verify virtual reg
  // TODO: Check compatibility with assocReg
  int temp = topRegister;
  topRegister += numRegs; 
  if(topRegister > 11) {
    cout << "\tSUB\t" << "SP,\t#" << 4*numRegs << "\t @@ allocating space for math on stack\n";
  }
  return temp;
}

int CodeGen::freeRegs(int numRegs) {
  int i = 0;
  while (i < numRegs)
  {
    if(topRegister > 11) {
      cout << "\tADD\t" << "SP,\tSP,\t#4" << "\t @@ freeing math space\n";
    }
    topRegister -= 1;
    i++;
  }
  return topRegister;
}

int CodeGen::assocReg(string name) {
  int temp = topRegister;
  regVarsInScope[name] = topRegister;
  topRegister++;
  regsInScope++;
  if(topRegister > 11) {
    cout << "\tSUB\t" << "SP,\tSP,\t#4 \t @@ allocating space for \"" << name << "\" on stack\n";
  }
  if(!dontMindMeJustCollectingGlobals)
  {
    if(isFCall)
      cout << "@@ \"" << name << "\" in r" << topRegister-1 << " for " << tempName << "\n";
    else
      cout << "@@ \"" << name << "\" in r" << topRegister-1 << " locally\n";
  } 
  // Globals
  else if(!isFormParam)
    cout << "@@ GLOBAL \"" << name << "\" in r" << topRegister-1 << " \n";
  else // Is a formal parameter
    cout << "@@ PARAM \"" << name << "\" in r" << topRegister-1 << " for " << tempName << "\n";
  return temp;
}

int CodeGen::assocParam(string name) {
  return 0;
}

int CodeGen::assocGlobal(string name) {
  regVarsInScope[name] = topGlobal;
  varFormerLocation[name] = topGlobal;
  //paramsForFunction // BOOKMARK
  cout << getGlobalLabel(topGlobal) << ":\t .int " << "0\n";
  topGlobal--;
  emit("\t.align 4");
  return (topGlobal);
}

int CodeGen::assocFree(string name) {
  //globalRegVars.erase(name);
  regVarsInScope.erase(name);
  regsInScope--;
  if(topRegister > 11) {
    cout << "\tADD\t" << "SP,\tSP,\t#4 \t @ freeing var \"" << name << "\" from stack\n";
  } 
  topRegister--;  
  return topRegister;
}

int CodeGen::regAtName(string name) {
  return regVarsInScope[name];
}

void CodeGen::emitStoreStr(string str, int stringNum) {
  emit("");
  cout << "litStr" << "_" << stringNum << ":\n"; 
  cout << ".ascii\t"; emit(str);
  emit("");
}

int CodeGen::getVirtualReg(int reg){
  return ((reg-12) * 4);
}

/*
r1-r11

r1-11

MOV   r0, r14

====>



*/



void CodeGen::freeScopeVars() {
  // JUST TO SEE, lets not do this
  
  map<string, int>::iterator pos;
  for (pos = regVarsInScope.begin(); pos != regVarsInScope.end(); ++pos) {
    // do NOT delete global vars
    printf("@@ Are we freeing register %d containing %s in scope %s?\n",
      pos->second, pos->first.c_str(), curScope.c_str());
    if(pos->second > 0) {
      assocFree(pos->first);
      printf("@@ Yup! aaaaand, it's gone.\n");
      if(varWasFormParam[pos->first])
      {
        //assocGlobal(pos->first);
        printf("@@ Putting %s back in global namespace at reg %d\n", pos->first.c_str(), (pos->second)*-1);
        regVarsInScope[pos->first] = (varFormerLocation[pos->first]);
        //paramsForFunction // BOOKMARK
      }
    }
    else
      printf("@@ Nope. Still there.\n");
  } 
}

// THIS FUNCTION FROM STACK OVERFLOW
// AT http://stackoverflow.com/questions/5878775/how-to-find-and-replace-string
// We're gonna use it for escapes
string CodeGen::strReplace(string &s,
                  string toReplace,
                  string replaceWith) {
    return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}

// NEED TO SUPPORT THESE ESCAPES:
// \b, \f, \t, \r, \n, \', \", 

/*
string CodeGen::replaceEscapes(string &str) {
  string escB = string("\b");  string _escB = string("\\b"); 
  string escF = string("\f");  string _escF = string("\\f"); 
  string escT = string("\t");  string _escT = string("\\t");
  string escR = string("\r");  string _escR = string("\\r");
  string escN = string("\n");  string _escN = string("\\n");
  string escQ1 = string("\'"); string _escQ1 = string("\\'");
  string escQ2 = string("\""); string _escQ2 = string("\\\"");
  string escS = string("\\");  string _escS = string("\\\\");
  string r1 = strReplace(str, escN, _escN);
  return r1;
}  */

// Trying this one instead
// http://stackoverflow.com/questions/5342063/replace-single-quotes-in-string-with
  
string CodeGen::replaceEscapes(string &s)
{
    int n = s.length();
    string escaped;
    escaped.reserve(n * 2);        // pessimistic preallocation

    for (int i = 0; i < n; ++i) {
        switch(s[i])
        {
        case '\n':
          escaped += '\\'; escaped += 'n'; break;
        case '\t':
          escaped += '\\'; escaped += 't'; break;  
        case '\b':
          escaped += '\\'; escaped += 'b'; break;  
        case '\f':
          escaped += '\\'; escaped += 'f'; break;  
        case '\r':
          escaped += '\\'; escaped += 'r'; break;  
        case '\'':
          escaped += '\\'; escaped += '\''; break;  
        case '\"':
          escaped += '\\'; escaped += '"'; break;                                 
        default: escaped += s[i];
      }
    }
    return escaped;
} 

// VISITOR CODE STARTS BELOW
//*********************************************************
//*********************************************************
//*********************************************************

// DND
void CodeGen::visitGMainFuncDec(GMainFuncDec *gmainfuncdec)
{
  if(!dontMindMeJustCollectingGlobals) {
    curScope = string("main");
    emit(".text");
    emitLabel("_start");
    emit("adr \tsp, \tstackEnd \t@@ setup stack pointer, full descending");
    emit("BL rtsinit");
    emit("PUSH\t{ip,\tlr}");
    //gmainfuncdec->identifier_->accept(this);
    //printf("@@ yo, in main regAt(a) and (b) are %d, %d\n",
       //regAtName(string("a")), regAtName(string("b") ));
    //printf("@@ and in the data structure:\n");
    //printf("@@ ...%d, %d\n", 
      //regVarsInScope[paramsForFunction[string("sum")].front()],
        //regVarsInScope[paramsForFunction[string("sum")].back()]);
    gmainfuncdec->liststatement_->accept(this);

    /*freeRegs(regsInScope);
    regsInScope = 0;*/
    freeScopeVars();

    emitLabel("main_end");
    //emit(".end");
    emit("\t BL halt\n");
    emit("POP \t{ip,\tpc}"); // This line *SHOULD* come first, but whatevs.
  }
}

// DND
void CodeGen::visitGFuncDec(GFuncDec *gfuncdec)
{
    gfuncdec->type_->accept(this);
    gfuncdec->identifier_->accept(this);
    curScope = string(tempString);

  if(dontMindMeJustCollectingGlobals) {
    // Empty list
    paramsForFunction[curScope] = list<string>();
    gfuncdec->listformalparam_->accept(this);
  }
 


  if(!dontMindMeJustCollectingGlobals) {
    emitLabel(curScope);
    emit("PUSH\t{r1-r11, lr}");
    int counter = 0;
    int formParamHere;

    gfuncdec->listformalparam_->accept(this);
    paramNum = 1;

    gfuncdec->block_->accept(this);

    freeScopeVars();
    cout << curScope << "_end:\n";

    emit("POP\t{r1-r11, pc}");
  }
}

// DND
void CodeGen::visitGVFuncDec(GVFuncDec *gvfuncdec)
{
    gvfuncdec->identifier_->accept(this);
    curScope = string(tempString);

  if(dontMindMeJustCollectingGlobals) {
    // Empty list
    paramsForFunction[curScope] = list<string>();
    gvfuncdec->listformalparam_->accept(this);
  }

  if(!dontMindMeJustCollectingGlobals) {
    emitLabel(curScope);
    emit("PUSH\t{r1-r11, lr}");
    int counter = 0;
    int formParamHere;

    gvfuncdec->listformalparam_->accept(this);
    paramNum = 1;

    gvfuncdec->block_->accept(this);

    freeScopeVars();
    cout << curScope << "_end:\n";

    emit("POP\t{r1-r11, pc}");
  }
}

void CodeGen::visitGVarDec(GVarDec *gvardec)
{
  if(dontMindMeJustCollectingGlobals) {
    gvardec->type_->accept(this);
    gvardec->identifier_->accept(this);
    assocGlobal(tempString);
  }
}

void CodeGen::visitEInt(EInt *eint)
{
  visitInteger(eint->integer_);
  // BOOKMARK
  // stringstream temp;
  // temp << "#" << tempInt;
  // emitCmd("MOV", 0, temp.str());
  // THIS IS WHAT'S CAUSING ALL THE SHIT. DEAL WITH IT TOMORROW
  string intAfter = getLabel(curScope, "intLit", curDataNum, "after");
  string intLabel = getLabel(curScope, "intLit", curDataNum, "data");
  cout << "\tB \t" << intAfter << "\n";
  emitLabel(intLabel);
  cout << ".int\t" << tempInt << "\n"; 
  printf(".align 4\n");
  //cout << "\"\n .align 4\n";
  emitLabel(intAfter);
  cout << "\tLDR \tr12,\t=" << intLabel <<  "\n";
  cout << "\tLDR \tr0,\t [r12]\n";
  curDataNum++;  
}

void CodeGen::visitEString(EString *estring)
{
  /* Code For EString Goes Here */
  tempType = STR_T;
  visitString(estring->string_);
}

void CodeGen::visitETrue(ETrue *etrue)
{
  emitCmd("MOV", 0, "#1");
}

void CodeGen::visitEFalse(EFalse *efalse)
{
  emitCmd("MOV", 0, "#0");
}



// TODO: Collect names here on global run
void CodeGen::visitFParam(FParam *fparam)
{
  if(dontMindMeJustCollectingGlobals) {
    isFormParam = true;

    fparam->type_->accept(this);
    fparam->identifier_->accept(this);

    paramsForFunction[curScope].push_back(tempString);

    cout << "@@ Successfully put " << tempString << " in list at " << curScope << "!\n";
    assocGlobal(tempString);
    varWasFormParam[tempString] = true;

    isFormParam = false; 
  }
  else if(!dontMindMeJustCollectingGlobals) {

    // // Grab the params, and insert!

    fparam->identifier_->accept(this);

    emitCmd("MOV", paramNum, regAtName(tempString));
    assocReg(tempString);

    //cout << "\t @@ var from " << tempString << " in r" << topRegister-1 << "\n";

    paramNum++; 
  }
}

// STATEMENTS BELOW
// **************************************************
// **************************************************
// **************************************************
// **************************************************
// **************************************************

// DND
void CodeGen::visitSVarDec(SVarDec *svardec)
{
  if(!dontMindMeJustCollectingGlobals) {
    svardec->type_->accept(this);
    svardec->identifier_->accept(this);
    assocReg(tempString);
    varWasFormParam[tempString] = false;
  }
}


// DND
void CodeGen::visitSBreak(SBreak *sbreak)
{
  if(!dontMindMeJustCollectingGlobals) {
    // get current while
    string temp = getLabel(curScope, "while", curWhile.top(), "end");
    emitCmd("B", temp);
  }
}

void CodeGen::visitSRetExpr(SRetExpr *sretexpr)
{
  if(!dontMindMeJustCollectingGlobals) {
    sretexpr->expression_->accept(this);
    printf("\tPOP\t {r1-r11, PC}\n");
  }
}

void CodeGen::visitSRet(SRet *sret)
{
  if(!dontMindMeJustCollectingGlobals) {
    printf("\tPOP\t {r1-r11, PC}\n");
  }
}

// DND
void CodeGen::visitSIfElse(SIfElse *sifelse)
{
  if(!dontMindMeJustCollectingGlobals) {
    curIfElse.push(maxIfElse++);

    string elseBlock = getLabel(curScope, "ifElse", curIfElse.top(), "elseBlock");
    string elseEnd = getLabel(curScope, "ifElse", curIfElse.top(), "end");

    sifelse->expression_->accept(this);
    emitCmd("CMP", 0, "#0");
    emitCmd("BEQ", elseBlock);

    sifelse->statement_1->accept(this);
    emitCmd("B", elseEnd);

    emitLabel(elseBlock);
    sifelse->statement_2->accept(this);

    emitLabel(elseEnd);
    curIfElse.pop();
  }
}

// DND
void CodeGen::visitSIf(SIf *sif)
{
  if(!dontMindMeJustCollectingGlobals) {
    curIf.push(maxIf++);

    string endIf = getLabel(curScope, "if", curIf.top(), "end");
    sif->expression_->accept(this);
    emitCmd("CMP", 0, "#0");
    emitCmd("BEQ", endIf);

    sif->statement_->accept(this);
    emitLabel(endIf);

    curIf.pop();
  }
}

// DND
void CodeGen::visitSWhile(SWhile *swhile)
{
  if(!dontMindMeJustCollectingGlobals) {
    curWhile.push(maxWhile++);

    string startWhile = getLabel(curScope, "while", curWhile.top(), "start");
    string endWhile = getLabel(curScope, "while", curWhile.top(), "end");

    emitLabel(startWhile);

    swhile->expression_->accept(this);
    emitCmd("CMP", 0, "#0");
    emitCmd("BEQ", endWhile);  


    swhile->statement_->accept(this);

    emitCmd("B", startWhile);
    emitLabel(endWhile);
    curWhile.pop();
  }
}

void CodeGen::visitFCall(FCall *fcall)
{
  if(!dontMindMeJustCollectingGlobals) {
    isFCall = true;
    // VISIT IDENT, GET FUNCNAME
    fcall->identifier_->accept(this);
    tempName = tempString;
    // Name of func is in tempName

    int reg1 = 0;
    isRTS = true;
    if ((tempName.compare(string("printi")) != 0)
     && (tempName.compare(string("printc")) != 0)
     && (tempName.compare(string("printb")) != 0)
     && (tempName.compare(string("halt")) != 0)
     && (tempName.compare(string("getchar")) != 0)
     && (tempName.compare(string("prints")) != 0))
    {
      isRTS = false;
    }

      

    if(isRTS)
    {
      //reg1 = allocRegs(1); 
      //emitCmd("MOV", reg1, 0);
      DONT_MOVE = true;
    }
  }

  // GET PARAMETERS
  fcall->listexpression_->accept(this);

  if(!dontMindMeJustCollectingGlobals) {
    

    regVarStack.push(regVarsInScope);
    savedTopReg = topRegister;
    topRegister = 1;

    bool isPrintS = (tempName.compare(string("prints")) == 0);
    bool isGetChar = (tempName.compare(string("getchar")) == 0);

    // PRINTS
    // PRINTS SPECIAL CASE
    string printLabel = getLabel(curScope, "prints", curStringNum, "print");
    if(isPrintS) {
      cout << "\tMOV\tr12,\tr0\n";      
      cout << "\tPUSH\t {r1-r12}\n";
      cout << "\tB \t" << printLabel << "\n";
      string stringLabel = getLabel(curScope, "prints", curStringNum, "string");
      emitLabel(stringLabel);
      cout << ".ascii\t\"" << replaceEscapes(tempString); 
      printf("\\0\"\n.align 4\n");
      //cout << "\"\n .align 4\n";
      emitLabel(printLabel);
      cout << "\tLDR \tr0,\t=" << stringLabel <<  "\n";
      curStringNum++; 
      emitCmd("BL", tempName);
      cout << "\tPOP\t {r1-r12}\n"; 
      cout << "\tMOV\tr0,\tr12\n";
    }

     // ********************CALL THE FUNCTION *******************
    else if(isRTS && !isPrintS && !isGetChar) {
      cout << "\tMOV\tr12,\tr0\n";       
      cout << "\tPUSH\t {r1-r12}\n";  
      emitCmd("BL", tempName); 
      cout << "\tPOP \t {r1-r12}\n";
      cout << "\tMOV\tr0,\tr12\n";
    }

    else if(isGetChar) {
      cout << "\tPUSH\t {r1-r12}\n";  
      emitCmd("BL", tempName); 
      cout << "\tPOP \t {r1-r12}\n";
    }

    else if(!isRTS) {
      emitCmd("BL", tempName);
    }
    // CLEANUP


    //if (!isRTS)
    //{
      regVarsInScope = regVarStack.top();
      regVarStack.pop();
      topRegister = savedTopReg;
    // }
    isFCall = false;
  }
}

// R0 = IDENTIFIER
// DND
void CodeGen::visitPFExprID(PFExprID *pfexprid)
{
  pfexprid->identifier_->accept(this);
  if(!DONT_MOVE && isFCall){}
    // We need to move name from OLD namespace to NEW one.
   //emitCmd("MOV", regVarsInScope[tempString], regVarStack.top()[(tempString)]);
  DONT_MOVE = true;
  emitCmd("MOV", 0, regVarsInScope[tempString]);
}


// -EXPR
// DND
void CodeGen::visitUnExprMin(UnExprMin *unexprmin)
{
  /* Code For UnExprMin Goes Here */
  unexprmin->unaryexpression_->accept(this);
  cout << "\tMOV\t r12,\t #-1\n";
  cout << "\tMUL\t r0,\t r12,\t r0\n";
}

// !EXPR
// DND
void CodeGen::visitUnExprNeg(UnExprNeg *unexprneg)
{
  unexprneg->unaryexpression_->accept(this);
  int reg1 = allocRegs(1);

  // BOOKMARK
  emitCmd("MOV", reg1, 0);
  emitCmd("MOV", 0, "#0");
  emitCmd("CMP", reg1, 0);
  emitCmd("MOVNE", 0, "#1");

  freeRegs(1);
}

// EXPR1 * EXPR2
// DND
void CodeGen::visitMulExprMul(MulExprMul *mulexprmul)
{
  int reg1 = allocRegs(1);
  mulexprmul->multiplicativeexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  mulexprmul->unaryexpression_->accept(this);
  emitCmd("MUL", 0, reg1, 0);
  freeRegs(1);
}

// EXPR1 / EXPR2
// DND -- T18, T26, T31
// Uses *SIGNED* division
void CodeGen::visitMulExprDiv(MulExprDiv *mulexprdiv)
{
  int reg1 = allocRegs(1);
  mulexprdiv->multiplicativeexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  mulexprdiv->unaryexpression_->accept(this);
  emitCmd("SDIV", 0, reg1, 0);
  freeRegs(1);
}

// EXPR1 % EXPR2
// TODO -- LONGFILES AND T26
void CodeGen::visitMulExprMod(MulExprMod *mulexprmod)
{
  int reg1 = allocRegs(1);
  int reg2 = allocRegs(1);

  mulexprmod->multiplicativeexpression_->accept(this);
  emitCmd("MOV", reg1, 0);  // A is in reg1


  mulexprmod->unaryexpression_->accept(this);
  emitCmd("MOV", reg2, 0);  // B is in reg2
  emitCmd("SDIV", 0, reg1, 0);
  // q(a,b) is in r0
  emitCmd("MUL", 0, reg2, 0);
  emitCmd("SUB", 0, reg1, 0);

  freeRegs(2);
}


// EXPR1 + EXPR2
// DND
void CodeGen::visitAddExprAdd(AddExprAdd *addexpradd)
{
  int reg1 = allocRegs(1);
  addexpradd->additiveexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  addexpradd->multiplicativeexpression_->accept(this);
  emitCmd("ADD", 0, reg1, 0);
  freeRegs(1);
}

//EXPR1 - EXPR2
// DND
void CodeGen::visitAddExprSub(AddExprSub *addexprsub)
{
  int reg1 = allocRegs(1);
  addexprsub->additiveexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  addexprsub->multiplicativeexpression_->accept(this);
  emitCmd("SUB", 0, reg1, 0);
  freeRegs(1);
}

// EXPR1 < EXPR2
// DND
void CodeGen::visitRelExprLT(RelExprLT *relexprlt)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);
  relexprlt->relationalexpression_->accept(this);
  emitCmd("MOV", reg1, 0);
  
  relexprlt->additiveexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVLT", 0, "#1");
  emitCmd("MOVGE", 0, "#0");

  curExpr.pop();
  freeRegs(1);
}

// EXPR1 > EXPR2
// DND
void CodeGen::visitRelExprGT(RelExprGT *relexprgt)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);
  relexprgt->relationalexpression_->accept(this);
  emitCmd("MOV", reg1, 0);
  
  relexprgt->additiveexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVGT", 0, "#1");
  emitCmd("MOVLE", 0, "#0");

  curExpr.pop();
  freeRegs(1);
}

// EXPR1 <= EXPR2 
// DND
void CodeGen::visitRelExprLE(RelExprLE *relexprle)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);
  relexprle->relationalexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  relexprle->additiveexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVLE", 0, "#1");
  emitCmd("MOVGT", 0, "#0");

  curExpr.pop();
  freeRegs(1);  

}

// EXPR1 >= EXPR2
// DND
void CodeGen::visitRelExprGE(RelExprGE *relexprge)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);  
  relexprge->relationalexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  relexprge->additiveexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVGE", 0, "#1");
  emitCmd("MOVLT", 0, "#0");

  curExpr.pop();
  freeRegs(1);  
}

// EXPR1 == EXPR1
// DND
void CodeGen::visitEqExprEQ(EqExprEQ *eqexpreq)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);  
  eqexpreq->equalityexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  eqexpreq->relationalexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVEQ", 0, "#1");
  emitCmd("MOVNE", 0, "#0");

  curExpr.pop();
  freeRegs(1);     
}

// EXPR1 != EXPR2
// DND
void CodeGen::visitEqExprNE(EqExprNE *eqexprne)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);  
  eqexprne->equalityexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  eqexprne->relationalexpression_->accept(this);
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVNE", 0, "#1");
  emitCmd("MOVEQ", 0, "#0");

  curExpr.pop();
  freeRegs(1);  
}

// EXPR1 && EXPR2
// DND
void CodeGen::visitCAExprAnd(CAExprAnd *caexprand)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);  

  string andAfter = getLabel(curScope, "and", maxExpr, "after");


  caexprand->conditionalandexpression_->accept(this);
  emitCmd("MOV", reg1, 0);
  emitCmd("MOV", 0, "#0");
  emitCmd("CMP", reg1, 0);
  emitCmd("BEQ", andAfter);
  emitCmd("MOV", 0, "#1");


  caexprand->equalityexpression_->accept(this);
  emitCmd("MOV", reg1, 0);
  emitCmd("MOV", 0, "#0");
  emitCmd("CMP", reg1, 0);

  emitCmd("MOVNE", 0, "#1");

  emitLabel(andAfter);

  curExpr.pop();
  freeRegs(1);  
}

// EXPR1 || EXPR2
// DND
void CodeGen::visitCOExprOr(COExprOr *coexpror)
{
  curExpr.push(maxExpr++);
  int reg1 = allocRegs(1);  
  coexpror->conditionalorexpression_->accept(this);
  emitCmd("MOV", reg1, 0);

  coexpror->conditionalandexpression_->accept(this);

  // result of this add can only be 0, 1, or 2. 
  emitCmd("ADD", 0, reg1, 0);
  emitCmd("CMP", 0, "#0");

  // if it's not 0, move 1 in there just in case it's 2.
  emitCmd("MOVGT", 0, "#1");

  curExpr.pop();
  freeRegs(1);  
}

// VAR = EXPR
// DND
void CodeGen::visitAssign(Assign *assign)
{
  // Whatever expression happens, the result will be in r0
  assign->assignmentexpression_->accept(this);
  assign->identifier_->accept(this);

  // move r0 into whatever it is being assigned to
  emitCmd("MOV", regAtName(tempString), 0);
}

// We have formal parameters: now attach them to the call stuff
void CodeGen::visitListExpression(ListExpression* listexpression)
{
  int formParamHere;
  isFormParam = true;
  for (ListExpression::iterator i = listexpression->begin() ; 
    i != listexpression->end() ; ++i)
    {
      (*i)->accept(this); 
      if(!isRTS){
        formParamHere = regAtName(paramsForFunction[tempName].front());
        //formParamHere = regVarsInScope[tempName];
        cout << "\t @@ " << paramsForFunction[tempName].front() << " at globalVar" << -formParamHere << "\n";
        emitCmd("MOV", formParamHere, 0);  

        //cycle it 
        paramsForFunction[tempName].push_back(paramsForFunction[tempName].front());
        paramsForFunction[tempName].pop_front();      
      }
    }
  isFormParam = false;

  
}


// DONE
void CodeGen::visitInteger(Integer x)
{
  tempInt = x;
}

// DONE
void CodeGen::visitString(String x)
{
  tempString.clear();
  tempString = string (x);
}

// IRRELEVANT BELOW

// **************************************************
// **************************************************
// **************************************************
// **************************************************
// **************************************************

//LISTS

void CodeGen::visitListStatement(ListStatement* liststatement)
{
  for (ListStatement::iterator i = liststatement->begin() ; 
    i != liststatement->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CodeGen::visitListGlobalDec(ListGlobalDec* listglobaldec)
{
  for (ListGlobalDec::iterator i = listglobaldec->begin() ; 
    i != listglobaldec->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void CodeGen::visitListFormalParam(ListFormalParam* listformalparam)
{
  for (ListFormalParam::iterator i = listformalparam->begin() ; 
    i != listformalparam->end() ; ++i)
  {
    (*i)->accept(this);
  }
}




// REDUNDANT

void CodeGen::visitSAssign(SAssign *sassign)
{
  /* Code For SAssign Goes Here */

  sassign->assignment_->accept(this);

}

void CodeGen::visitPLiteral(PLiteral *pliteral)
{
  /* Code For PLiteral Goes Here */

  pliteral->literal_->accept(this);
}

void CodeGen::visitPExpr(PExpr *pexpr)
{
  /* Code For PExpr Goes Here */

  pexpr->expression_->accept(this);

}

// Don't need to do anything special here, because all output is in r0 anyway.
void CodeGen::visitPFuncInv(PFuncInv *pfuncinv)
{
  /* Code For PFuncInv Goes Here */

  pfuncinv->functioninvocation_->accept(this);

}


void CodeGen::visitPIdentifier(PIdentifier *pidentifier)
{
  /* Code For PIdentifier Goes Here */
  visitString(pidentifier->string_);
}

void CodeGen::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listglobaldec_->accept(this);

}

void CodeGen::visitSCall(SCall *scall)
{
  /* Code For SCall Goes Here */

  scall->functioninvocation_->accept(this);
}

void CodeGen::visitSBlock(SBlock *sblock)
{
  /* Code For SBlock Goes Here */

  sblock->block_->accept(this);

}

void CodeGen::visitBBlock(BBlock *bblock)
{
  /* Code For BBlock Goes Here */

  bblock->liststatement_->accept(this);
}

// EXPRESSION CONVERSIONS BELOW



void CodeGen::visitPFExprPrim(PFExprPrim *pfexprprim)
{
  /* Code For PFExprPrim Goes Here */

  pfexprprim->primary_->accept(this);

}

void CodeGen::visitUnExpr(UnExpr *unexpr)
{
  /* Code For UnExpr Goes Here */

  unexpr->postfixexpression_->accept(this);

}

void CodeGen::visitMulExpr(MulExpr *mulexpr)
{
  /* Code For MulExpr Goes Here */

  mulexpr->unaryexpression_->accept(this);

}

void CodeGen::visitAddExpr(AddExpr *addexpr)
{
  /* Code For AddExpr Goes Here */

  addexpr->multiplicativeexpression_->accept(this);

}

void CodeGen::visitRelExpr(RelExpr *relexpr)
{
  /* Code For RelExpr Goes Here */

  relexpr->additiveexpression_->accept(this);

}

void CodeGen::visitEqExpr(EqExpr *eqexpr)
{
  /* Code For EqExpr Goes Here */

  eqexpr->relationalexpression_->accept(this);

}

void CodeGen::visitCAExpr(CAExpr *caexpr)
{
  /* Code For CAExpr Goes Here */

  caexpr->equalityexpression_->accept(this);

}

void CodeGen::visitCOExpr(COExpr *coexpr)
{
  /* Code For COExpr Goes Here */

  coexpr->conditionalandexpression_->accept(this);
}

void CodeGen::visitAssExpr(AssExpr *assexpr)
{
  /* Code For AssExpr Goes Here */

  assexpr->conditionalorexpression_->accept(this);

}

void CodeGen::visitAssExprAss(AssExprAss *assexprass)
{
  /* Code For AssExprAss Goes Here */

  assexprass->assignment_->accept(this);
}

void CodeGen::visitExpr(Expr *expr)
{
  /* Code For Expr Goes Here */

  expr->assignmentexpression_->accept(this);
}



// UNUSED BELOW

// Typechecking is for suckers

void CodeGen::visitTBool(TBool *tbool)
{
  /* Code For TBool Goes Here */

  tempType = BOOL_T;
}

void CodeGen::visitTInt(TInt *tint)
{
  /* Code For TInt Goes Here */

  tempType = INT_T;
}

void CodeGen::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  eid->pidentifier_->accept(this);
}

void CodeGen::visitProgram(Program* t) {} //abstract class
void CodeGen::visitGlobalDec(GlobalDec* t) {} //abstract class
void CodeGen::visitLiteral(Literal* t) {} //abstract class
void CodeGen::visitType(Type* t) {} //abstract class
void CodeGen::visitIdentifier(Identifier* t) {} //abstract class
void CodeGen::visitFormalParam(FormalParam* t) {} //abstract class
void CodeGen::visitBlock(Block* t) {} //abstract class
void CodeGen::visitStatement(Statement* t) {} //abstract class
void CodeGen::visitFunctionInvocation(FunctionInvocation* t) {} //abstract 
void CodeGen::visitPrimary(Primary* t) {} //abstract class
void CodeGen::visitPostFixExpression(PostFixExpression* t) {} //abstract c
void CodeGen::visitUnaryExpression(UnaryExpression* t) {} //abstract class
void CodeGen::visitMultiplicativeExpression(MultiplicativeExpression* t) {} 
void CodeGen::visitAdditiveExpression(AdditiveExpression* t) {} //abstract c
void CodeGen::visitRelationalExpression(RelationalExpression* t) {} //abstra
void CodeGen::visitEqualityExpression(EqualityExpression* t) {} //abstract c
void CodeGen::visitConditionalAndExpression(ConditionalAndExpression* t) {} 
void CodeGen::visitConditionalOrExpression(ConditionalOrExpression* t) {} 
void CodeGen::visitAssignmentExpression(AssignmentExpression* t) {} //abstra
void CodeGen::visitAssignment(Assignment* t) {} //abstract class
void CodeGen::visitExpression(Expression* t) {} //abstract class


void CodeGen::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void CodeGen::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}


void CodeGen::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}

void CodeGen::visitSEmpty(SEmpty *sempty)
{
  /* Code For SEmpty Goes Here */
}
