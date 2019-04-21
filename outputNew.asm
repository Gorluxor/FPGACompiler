
f2:
			PUSH	r7
			MOV 	r7,sp
.f2_body:
			MOV 	r6,2
			J 	.f2_exit
.f2_exit:
			MOV 	sp,r7
			POP 	r7
			RET
f8plus:
			PUSH	r7
			MOV 	r7,sp
			SUB		sp, 4
.f8plus_body:
			CALL	f2
			MOV 	r0,r6		FUN_REG
			MOV 	[r7 - 4],r0		ASSIGN
			MOV 	[r7 + 8],r0EXPRETION
			ADD		r0,10
			MOV 	r0,r0EXPRETION
			???		r0,[r7 - 4]