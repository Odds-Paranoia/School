.global prints
.global printi
.global rtsinit
.global printb
.global halt
.global printc
.global getchar


rtsinit:
	@ get stdin fd
	mov	r0,#0x01	@ SYS_OPEN
	adr	r1,inopenparms
	svc	0x123456
	cmp	r0,#-1
	beq	halt		@ can't do much yet but bail
	str	r0,ifd

	@ get stdout fd
	mov	r0,#0x01	@ SYS_OPEN
	adr	r1,outopenparms
	svc	0x123456
	cmp	r0,#-1
	beq	halt		@ can't do much yet but bail
	str	r0,ofd

	mov	pc,lr		@ leaf rts
	
@ not offically part of the RTS but helpful for debugging
@ loop unrolled to save a register
printx:
	adr	r3,xtab
	adr	r1,xbufend

	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1
	lsr	r0,#4
	and	r2,r0,#0xf; ldrb r2,[r3,+r2]; strb r2,[r1],#-1

	adr	r0,xbuf
	b	prints

xtab:	.byte	'0','1','2','3','4','5','6','7'
	.byte	'8','9','a','b','c','d','e','f'
xbuf:	.byte	'0','x',0,0,0,0,0,0,0,0,0
xbufend = .-2	@ skip NUL byte
	.align	4

@@printb:
	@@adr	r1,tf
	@@ldr	r0,[r1,+r0,lsl #2]
	@@b	prints


printb:
	mov r1, r0
	mov r0, #0
	cmp r0, r1
	bne printb_true

printb_false:
	ldr r0, =f
	b prints

printb_true:
	ldr r0, =t
	b prints

tf:	.word	f, t
t:	.asciz	"true"
f:	.asciz	"false"
	.align	4

@ # test cases
@ r0 = 0
@ r0 = -123
@ r0 = 123
@ r0 = 2147483647
@ r0 = -2147483648
@ 
@ if r0 < 0:
@         print('-', end='')
@         r0 = -r0
@ 
@ r3 = ''
@ 
@ do:
@         r2 = 10
@         r1 = r0 // r2
@         r2 = r1 * r2
@         r2 = r0 - r2    # mod 10
@         r2 = r2 + ord('0')
@         r3 = chr(r2) + r3
@         r0 = r1
@ while r0 != 0
@ 
@ print(r3)

printi:
	cmp	r0,#0
	movge	r1,#0
	movlt	r1,#1
	rsblt	r0,r0,#0
	strb	r1,posneg

	adr	r3,negbufend
printi1:
	mov	r2,#10
	udiv	r1,r0,r2
	mul	r2,r1,r2
	sub	r2,r0,r2
	add	r2,#'0
	strb	r2,[r3],#-1
	mov	r0,r1
	cmp	r0,#0
	bne	printi1

	ldrb	r0,posneg
	cmp	r0,#0
	addeq	r3,#1
	movne	r2,#'-		@ else r2 will still hold the last (1st) digit
	strb	r2,[r3]

	mov	r0,r3
	b	prints

posneg:	.byte	0
negbuf:	.byte	'-',2,1,4,7,4,8,3,6,4,8,0
negbufend = .-2	@ skip NUL byte

	.align	4

@ XXX assumes NUL-terminated strings
prints:
	str	r0,writeparms_buf

	mov	r1,#0
prints1:
	ldrb	r2,[r0],#+1
	cmp	r2,#0
	addne	r1,#1
	bne	prints1
	str	r1,writeparms_n

	ldr	r0,ofd
	str	r0,writeparms_fd

	mov	r0,#0x5		@ SYS_WRITE
	adr	r1,writeparms
	svc	0x123456

	mov	pc,lr

@ will print NUL if need be
printc:
	strb	r0,buf		@ r0 == a1

	ldr	r0,ofd
	str	r0,writeparms_fd
	adr	r0,buf
	str	r0,writeparms_buf
	mov	r0,#1
	str	r0,writeparms_n

	mov	r0,#0x5		@ SYS_WRITE
	adr	r1,writeparms
	svc	0x123456

	mov	pc,lr

getchar:
	ldr	r0,ifd
	str	r0,readparms_fd

	mov	r0,#0x6		@ SYS_READ
	adr	r1,readparms
	svc	0x123456

	cmp	r0,#1		@ r0 == 0 if no error; r0 == 1 if EOF
	moveq	r0,#-1
	moveq	pc,lr

	ldrb	r0,readbuf
	mov	pc,lr
	
halt:
	mov	r0,#0x18	@ SYS_EXIT
	svc	0x123456

ifd:	.word	0
ofd:	.word	0

readparms:
readparms_fd:
	.word	0
	.word	readbuf
	.word	1
readbuf:
	.byte	0
	.align	4

writeparms:
writeparms_fd:
	.word	0
writeparms_buf:
	.word	0
writeparms_n:
	.word	0

inopenparms:
	.word	iofilename
	.word	0		@ "r" mode
	.word	iofilenamelen-1

outopenparms:
	.word	iofilename
	.word	4		@ "w" mode
	.word	iofilenamelen-1

iofilename:
	.asciz ":tt"
iofilenamelen = .-iofilename

buf:	.byte	0

	.align 4
