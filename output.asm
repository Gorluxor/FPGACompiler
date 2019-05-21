	Begin_INST:
		MOV sp, 0xeeee
		PUSH	 0x0
		CALL	 main
		HALT
f2:
			PUSH	r7
			MOV 	r7,sp
.f2_body:
			MOV 		r6,2
			J 	.f2_exit
.f2_exit:
			MOV 	sp,r7
			POP 	r7
			RET
f8plus:
			PUSH	r7
			MOV 	r7,sp
			ADD		sp, 2
.f8plus_body:
			CALL	f2
			MOV 		r0,r6		;FUN_REG
			ST 		[r7 + 0],r0		;ASSIGN
			LD 		r0,[r7 - 6]	;EXPRETION
			ADD		r0,10
			MOV 		r1,r0	;EXPRETION
			SUB		r1,[r7 + 0]
			MOV 		r6,r1
			J 	.f8plus_exit
.f8plus_exit:
			MOV 	sp,r7
			POP 	r7
			RET
main:
			PUSH	r7
			MOV 	r7,sp
			ADD		sp, 12
.main_body:
			MOV 		r0,1
			ST 		[r7 + 0],r0		;ASSIGN
			MOV 		r0,2
			ST 		[r7 + 2],r0		;ASSIGN
			MOV 		r0,3
			ST 		[r7 + 4],r0		;ASSIGN
			MOV 		r0,4
			ST 		[r7 + 6],r0		;ASSIGN
			MOV 		r0,5
			ST.b 		[r7 + 8],r0		;ASSIGN
			MOV 		r0,5
			ST.b 		[r7 + 10],r0		;ASSIGN
			PUSH	3
			CALL	f8plus
			SUB 	sp, 2
			MOV 		r0,r6		;FUN_REG
			ST 		[r7 + 0],r0		;ASSIGN
.if0:
			LD 		r0,[r7 + 0]
			CMP 	r0,[r7 + 2]
			JP 	.false0
.true0:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,1
			ST 		[r7 + 0],r0		;ASSIGN
			J 	.exit0
.false0:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,-2
			ST 		[r7 + 0],r0		;ASSIGN
.exit0:
.if1:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,[r7 + 4]
			LD 		r1,[r7 + 2]	;EXPRETION
			ADD		r1,[r7 + 6]
			MOV 		r2,r1	;EXPRETION
			SUB		r2,4
			CMP 	r0,r2
			JNZ 	.false1
.true1:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,11
			ST 		[r7 + 0],r0		;ASSIGN
			J 	.exit1
.false1:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,2
			ST 		[r7 + 0],r0		;ASSIGN
.exit1:
.if2:
			LD.b 		r0,[r7 + 8]
			CMP.b 	r0,[r7 + 10]
			JNZ 	.false2
.true2:
			MOV 		r0,2	;EXPRETION
			ADD.b		r0,[r7 + 8]
			ST.b 		[r7 + 8],r0		;ASSIGN
			CALL	f2
			MOV 		r0,r6		;FUN_REG
			LD 		r1,[r7 + 0]	;EXPRETION
			ADD		r1,r0
			ST 		[r7 + 0],r1		;ASSIGN
			J 	.exit2
.false2:
			MOV 		r0,2
			ST.b 		[r7 + 10],r0		;ASSIGN
.exit2:
.if3:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,[r7 + 4]
			LD 		r1,[r7 + 2]	;EXPRETION
			SUB		r1,[r7 + 6]
			MOV 		r2,r1	;EXPRETION
			SUB		r2,-4
			CMP 	r0,r2
			JNZ 	.false3
.true3:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,7
			ST 		[r7 + 0],r0		;ASSIGN
			J 	.exit3
.false3:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,4
			ST 		[r7 + 0],r0		;ASSIGN
.exit3:
			PUSH	25
			CALL	f8plus
			SUB 	sp, 2
			MOV 		r0,r6		;FUN_REG
			LD 		r1,[r7 + 0]	;EXPRETION
			ADD		r1,r0
			ST 		[r7 + 0],r1		;ASSIGN
.if4:
			LD 		r0,[r7 + 0]	;EXPRETION
			SUB		r0,[r7 + 4]
			LD 		r1,[r7 + 0]	;EXPRETION
			ADD		r1,r0
			MOV 		r0,r1	;EXPRETION
			SUB		r0,[r7 + 6]
			LD 		r1,[r7 + 2]	;EXPRETION
			SUB		r1,[r7 + 0]
			LD 		r2,[r7 + 2]	;EXPRETION
			ADD		r2,r1
			CMP 	r0,r2
			JNP	.false4
.true4:
			LD.b 		r0,[r7 + 10]	;EXPRETION
			SUB.b		r0,[r7 + 8]
			ST.b 		[r7 + 8],r0		;ASSIGN
			J 	.exit4
.false4:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,[r7 + 2]
			MOV 		r1,r0	;EXPRETION
			SUB		r1,[r7 + 4]
			ST 		[r7 + 6],r1		;ASSIGN
.exit4:
.if5:
			LD 		r0,[r7 + 0]
			CMP 	r0,[r7 + 6]
			JSE 	.false5
.true5:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,[r7 + 6]
			MOV 		r1,r0	;EXPRETION
			SUB		r1,4
			ST 		[r7 + 0],r1		;ASSIGN
			J 	.exit5
.false5:
.exit5:
.if6:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,[r7 + 4]
			LD 		r1,[r7 + 2]	;EXPRETION
			SUB		r1,4
			CMP 	r0,r1
			JNZ 	.false6
.true6:
			LD 		r0,[r7 + 0]	;EXPRETION
			ADD		r0,13
			ST 		[r7 + 0],r0		;ASSIGN
			J 	.exit6
.false6:
.exit6:
			LD 		r6,[r7 + 0]
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			RET