
#include <stdio.h>
#include "Parser.H"
#include "Absyn.H"
#include "CodeGen.H"

int main(int argc, char ** argv)
{
  FILE *input;
  if (argc > 1) 
  {
    input = fopen(argv[1], "r");
    if (!input)
    {
      fprintf(stderr, "Error opening input file.\n");
      exit(1);
    }
  }
  else input = stdin;
  /* The default entry point is used. For other options see Parser.H */
  Program *parse_tree = pProgram(input);
  //SymTable *symbols = new SymTable();
  if (parse_tree)
  {
    //printf("\nParse Succesful!\n");
    //printf("\n[Abstract Syntax]\n");
    //ShowAbsyn *s = new ShowAbsyn();
    //printf("%s\n\n", s->show(parse_tree));
    //printf("[Linearized Tree]\n");
    //PrintAbsyn *p = new PrintAbsyn();
    //printf("%s\n\n", p->print(parse_tree));
    CodeGen *gen = new CodeGen(); 
    gen->generate(parse_tree);
    //cout << gen->curScope << "\n";
    return 0;
  }
  return 1;
}
