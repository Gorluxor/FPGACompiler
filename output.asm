	Begin_INST:
		MOV sp, 0xeeee
		PUSH	 0x0
		CALL	 main
		HALT
main:
			PUSH	r7
			MOV 	r7,sp
			ADD		sp, 8
.main_body:
			MOV 		r0,1
			ST 		[r7 + 0],r0		;ASSIGN
			LD 		r0,[r7 + 0]	;EXPRETION
			MUL		r0,5
			ST 		[r7 + 0],r0		;ASSIGN			LD	r0,[[r7 + 0]]
			ST 		[r7 + 4],r0		;ASSIGN
			MOV 		r6,0
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			RET