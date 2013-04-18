.globl _start
.extern getchar
.extern printb
.extern printc
.extern printi
.extern prints
.extern halt

@@ Compiled by: J-- Compiler by Josh Dyck, UCID 10024728 @@

.text
.align 4

_start:
PUSH	{ip,	lr}
	MOV	r0,	r0

	ADR 	r0,	str1
	BL	prints

POP 	{ip,	pc}

s: .ascii	"Hello, world!"
slen = .-s

str1:
	.word 0
	.word s 
	.word slen

