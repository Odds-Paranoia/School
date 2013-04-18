stackStart: .skip 1024*1024 @1MB stack space
stackEnd: .byte 0
.globl _start
.extern getchar
.extern printb
.extern printc
.extern printi
.extern prints
.extern halt

@@ Compiled by: J-- Compiler by Josh Dyck, UCID 10024728 @@

.align 4

.data

globalVar1:	 .int 0
	.align 4
globalVar2:	 .int 0
	.align 4
.text
_start:
adr 	sp, 	stackEnd 	@@ setup stack pointer, full descending
BL rtsinit
PUSH	{ip,	lr}
@@ "j" in r1 locally
	B 	main_intLit_0_after
main_intLit_0_data:
.int	123
.align 4
main_intLit_0_after:
	LDR 	r12,	=main_intLit_0_data
	LDR 	r0,	 [r12]
	LDR	r12,	 =globalVar1
	STR	r0,	 [r12]
	B 	main_intLit_1_after
main_intLit_1_data:
.int	456
.align 4
main_intLit_1_after:
	LDR 	r12,	=main_intLit_1_data
	LDR 	r0,	 [r12]
	MOV	r1,	r0
	B 	main_intLit_2_after
main_intLit_2_data:
.int	789
.align 4
main_intLit_2_after:
	LDR 	r12,	=main_intLit_2_data
	LDR 	r0,	 [r12]
	LDR	r12,	 =globalVar2
	STR	r0,	 [r12]
	B 	main_intLit_3_after
main_intLit_3_data:
.int	42
.align 4
main_intLit_3_after:
	LDR 	r12,	=main_intLit_3_data
	LDR 	r0,	 [r12]
	LDR	r12,	 =globalVar2
	STR	r0,	 [r12]
	MOV	r1,	r0
	LDR	r12,	 =globalVar1
	STR	r0,	 [r12]
@@ "NL" in r2 locally
	B 	main_intLit_4_after
main_intLit_4_data:
.int	10
.align 4
main_intLit_4_after:
	LDR 	r12,	=main_intLit_4_data
	LDR 	r0,	 [r12]
	MOV	r2,	r0
	LDR	r12,	 =globalVar1
	LDR	r0,	 [r12]
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printi
	POP 	 {r1-r12}
	MOV	r0,	r12
	MOV	r0,	r2
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printc
	POP 	 {r1-r12}
	MOV	r0,	r12
	MOV	r0,	r1
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printi
	POP 	 {r1-r12}
	MOV	r0,	r12
	MOV	r0,	r2
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printc
	POP 	 {r1-r12}
	MOV	r0,	r12
	LDR	r12,	 =globalVar2
	LDR	r0,	 [r12]
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printi
	POP 	 {r1-r12}
	MOV	r0,	r12
	MOV	r0,	r2
	MOV	r12,	r0
	PUSH	 {r1-r12}
	BL	printc
	POP 	 {r1-r12}
	MOV	r0,	r12
@@ Are we freeing register 2 containing NL in scope main?
@@ Yup! aaaaand, it's gone.
@@ Are we freeing register -1 containing i in scope main?
@@ Nope. Still there.
@@ Are we freeing register 1 containing j in scope main?
@@ Yup! aaaaand, it's gone.
@@ Are we freeing register -1 containing i in scope main?
@@ Nope. Still there.
@@ Are we freeing register -2 containing k in scope main?
@@ Nope. Still there.
main_end:
	 BL halt

POP 	{ip,	pc}
