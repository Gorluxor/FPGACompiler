	Begin_INST:
		MOV sp, 0xeeee
		PUSH	 0x0
		CALL	 main
		HALT
main:
			PUSH	r7
			MOV 	r7,sp
			ADD		sp, 12
.main_body:
			MOV 		r0,0
			ST 		[r7 + 4],r0		;ASSIGN
			MOV 		r0,10
			ST 		[r7 + 0],r0		;ASSIGN
.for0:
			LD 		r0,[r7 + 0]
			CMP 	r0,0
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,1
			ST 		[r7 + 0],r0		;ASSIGN
			JSE 	.exit0
			LD 		r0,[r7 + 4]	;EXPRETION
			ADD		r0,2
			ST 		[r7 + 4],r0		;ASSIGN
			DEC 	[r7 + 0]
			j	.for0
.exit0:
			LD 		r6,[r7 + 4]
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			RET
