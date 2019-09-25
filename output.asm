	Begin_INST:
		MOV.w sp, 65534
		ADD.w r13, 65530
		CALL	 main
		HALT
nesto:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 4
.nesto_body:
			MOV.w	 r7, 9
		ST.w	 [r8 + 1000], r7	; put 9 in memory 100	
	
			 LD.w 		r0,[r13 + 8]
			LD.w	 r0,[r0]
			ST.w 		[r13 - 4],r0		;ASSIGN
			 LD.w 		r12,[r13 - 4]
			J 	.nesto_exit
.nesto_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET
main:
			PUSH	r13
			MOV.w 	r13,sp
			SUB.w		sp, 12
.main_body:
			MOV.w 		r0,1000
			ST.w 		[r13 - 12],r0		;ASSIGN
			 LD.w 		r0,[r13 - 12]
			PUSH	r0
			CALL	nesto
			ADD.w 	sp, 4
			MOV.w 		r0,r12		;FUN_REG
			ST.w 		[r13 - 8],r0		;ASSIGN
			 LD.w 		r12,[r13 - 8]
			J 	.main_exit
.main_exit:
			MOV.w 	sp,r13
			POP 	r13
			RET