BINDIR	= /usr/bin
AS	= $(BINDIR)/arm-linux-gnueabi-as
LD	= $(BINDIR)/arm-linux-gnueabi-ld
CC = clang++
CCFLAGS = 
FLEX = flex
BISON = bison
LATEX = latex
DVIPS = dvips
KERNEL	= test.exe
OBJS	= test.o rts.o

all:  full runtest

full: compiler test.exe

compiler: clean jmm.exe

test.exe:		$(OBJS)
		$(LD) -o $@ -Ttext 0x10000 $(OBJS)

test:
	$(BINDIR)/arm-linux-gnueabi-as test.s
	$(BINDIR)/arm-linux-gnueabi-ld -Ttext 0x10000 -o test.exe test.o rts.o

rts.o: 
	$(AS) rts.s -o $@

test.o: test.s
	$(AS) test.s -o $@

test.s:
	./jmm.exe test.jmm > test.s

runtest: $(KERNEL)
	$(BINDIR)/qemu-system-arm -nographic -monitor null -serial null -semihosting -kernel $(KERNEL) -cpu any



clean:
	$(RM) Main.o CodeGen.o test.o rts.o test.s test.exe jmm.exe





jmm.exe: Absyn.o Lexer.o Parser.o CodeGen.o Main.o
	@echo "Linking compiler...\n"
	${CC} ${CCFLAGS} Absyn.o Lexer.o Parser.o CodeGen.o Main.o -o jmm.exe

Main.o: Main.C Parser.H Absyn.H CodeGen.H
	${CC} ${CCFLAGS} -c Main.C

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

CodeGen.o: CodeGen.C CodeGen.H
	${CC} ${CCFLAGS} -c CodeGen.C
        


Parser.C: jmm.y
	${BISON} jmm.y -o Parser.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Lexer.C: jmm.l
	${FLEX} -o Lexer.C jmm.l

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C 	

