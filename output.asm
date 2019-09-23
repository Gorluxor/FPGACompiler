	Begin_INST:
		MOV.w sp, 65534
		ADD.w r13, 65530
		CALL	 main
		HALT
main:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 8
.main_body:
			MOV.w 		r0,3
			ST.w 		[r13 - 4],r0		;ASSIGN
			 LD.w 		r0,[r13 - 4]	;EXPRESSION
			ADD.w		r0,[r13 - 4]
			ST.w 		[r13 - 8],r0		;ASSIGN
		INC.w 	[r13 - 4]
		INC.w 	[r13 - 4]
			 LD.w 		r0,[r13 - 4]	;EXPRESSION
			ADD.w		r0,[r13 - 8]
			MOV.w 		r12,r0
			J 	.main_exit
.main_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET