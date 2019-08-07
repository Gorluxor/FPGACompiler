	Begin_INST:
		MOV sp, 0xeeee
		PUSH	 0x0
		CALL	 main
		HALT
main:
			PUSH	r7
			MOV 	r7,sp
			ADD		sp, 4
.main_body:		PUSH r1
		MOV r1, 5
		ST [r7 + 0], r1
		POP r1
	
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,5
			ST 		[r7 + 0],r0		;ASSIGN
			LD 		r6,[r7 + 0]
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			RET