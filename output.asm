	Begin_INST:
		MOV.w sp, 65534
		ADD.w r13, 65530
		CALL	 main
		HALT
test:
			PUSH	r13
			MOV.w 	r13,sp
.test_body:
			MOV.w 		r0,5
			ST.w 		[r13 + 4],r0		;ASSIGN
			MOV.w 		r0,6
			ST.w 		[r13 + 8],r0		;ASSIGN
			MOV.w 		r0,7
			ST.w 		[r13 + 12],r0		;ASSIGN
			 LD.w 		r12,[r13 + 12]
			J 	.test_exit
.test_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET
main:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 4
.main_body:
			MOV.w 		r0,5
			ST.w 		[r13 - 4],r0		;ASSIGN
			PUSH	1
			PUSH	2
			PUSH	3
			CALL	test
			ADD.w 	sp, 12
			MOV.w 		r0,r12		;FUN_REG
			MOV.w 		r12,r0
			J 	.main_exit
.main_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET