	Begin_INST:
		MOV.w sp, 65534
		ADD.w r13, 65530
		CALL	 main
		HALT
fact:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 4
.fact_body:
.if0:
			 LD.w 		r0,[r13 + 8]
			CMP.w 	r0,1
			JSE 	.false0
.true0:
			 LD.w 		r0,[r13 + 8]	;EXPRESSION
			???		r0,1
			PUSH	r0
			CALL	fact
			ADD.w 	sp, 4
			MOV.w 		r0,r12		;FUN_REG
			 LD.w 		r1,[r13 + 8]	;EXPRESSION
			???		r1,r0
			ST.w 		[r13 - 4],r1		;ASSIGN
			J 	.exit0
.false0:
			MOV.w 		r0,1
			ST.w 		[r13 - 4],r0		;ASSIGN
.exit0:
			 LD.w 		r12,[r13 - 4]
			J 	.fact_exit
.fact_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET
main:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 4
.main_body:
			MOV.w 		r0,15
			ST.w 		[r13 - 4],r0		;ASSIGN
			PUSH	3
			CALL	fact
			ADD.w 	sp, 4
			MOV.w 		r0,r12		;FUN_REG
			 LD.w 		r1,[r13 - 4]	;EXPRESSION
			???		r1,r0
			ST.w 		[r13 - 4],r1		;ASSIGN
			 LD.w 		r12,[r13 - 4]
			J 	.main_exit
.main_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET