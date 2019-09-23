	Begin_INST:
		MOV.w sp, 65535
		ADD.w r13, 65531
		CALL	 main
		HALT
main:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 12
.main_body:
			MOV.w 		r0,4
			ST.w 		[r13 - 4],r0		;ASSIGN
			MOV.w	r0,r13	;POINTER
			ST.w 		[r13 - 12],r0		;ASSIGN
			 LD.w 		r0,[r13 - 12]
			LD	 r0,[r0]
			MOV.w 		r1,r0	;EXPRETION
			MUL.w		r1,3
			ST.w 		[r13 - 8],r1		;ASSIGN
			 LD.w 		r12,[r13 - 8]
			J 	.main_exit
.main_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET