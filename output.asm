
	Begin_INST:	J main
hello:
			PUSH	r7
			MOV 	r7,sp
.hello_body:
			MOV 	r6,2
			J 	.hello_exit
.hello_exit:
			MOV 	sp,r7
			POP 	r7
			RET
main:
			PUSH	r7
			MOV 	r7,sp
			SUB		sp, 8
.main_body:
			MOV 	r0,15
			ST 	[r7 - 2],r0		;ASSIGN
			MOV 	r0,5
			ST 	[r7 - 4],r0		;ASSIGN
			CALL	hello
			MOV 	r0,r6		;FUN_REG
			LD 	r1,[r7 - 2]	;EXPRETION
			ADD		r1,r0
			ST 	[r7 - 2],r1		;ASSIGN
.if0:
			LD 	r0,[r7 - 2]
			CMP 	r0,15
			JSE 	.false0
.true0:
			LD 	r0,[r7 - 2]	;EXPRETION
			ADD		r0,5
			ST 	[r7 - 2],r0		;ASSIGN
			J 	.exit0
.false0:
			LD 	r0,[r7 - 2]	;EXPRETION
			SUB		r0,5
			ST 	[r7 - 2],r0		;ASSIGN
.exit0:
			LD 	r6,[r7 - 2]
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			HALT