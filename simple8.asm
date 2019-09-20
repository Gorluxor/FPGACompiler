Begin_INST:
		MOV sp, 0xeeee
		PUSH	 0x0
		CALL	 main
		HALT
main:
		PUSH	r7
		MOV 	r7,sp
		ADD	sp, 12
.main_body:
		MOV	r0,4
		ST 	[r7 + 0],r0 ;ASSIGN
		MOV	r0,r7	    ;POINTER
		ST 	[r7 + 4],r0 ;ASSIGN
		LD 	r0,[r7 + 4]
		LD	r0,[r0]
		MOV	r1,r0       ;EXPRESSION
		MUL	r1,3
		ST 	[r7 + 2],r1 ;ASSIGN
		LD 	r6,[r7 + 2]
		J 	.main_exit
.main_exit:
		MOV 	sp,r7
		POP 	r7
		RET
