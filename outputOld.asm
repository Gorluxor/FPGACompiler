
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
			MOV		r0,[r7 + 8]EXPRETION
			ADD		r0,10
			MOV		r1,r0EXPRETION
			SUB		r1,[r7 - 4]
			MOV 	r6,r1
			J 	.f8plus_exit
.f8plus_exit:
			MOV 	sp,r7
			POP 	r7
			RET
main:
			PUSH	r7
			MOV 	r7,sp
			SUB		sp, 24
.main_body:
			MOV 	[r7 - 4],1		ASSIGN
			MOV 	[r7 - 8],2		ASSIGN
			MOV 	[r7 - 12],3		ASSIGN
			MOV 	[r7 - 16],4		ASSIGN
			MOV 	[r7 - 20],5		ASSIGN
			MOV 	[r7 - 24],5		ASSIGN
			PUSH	3
			CALL	f8plus
			ADD 	sp, 4
			MOV 	r0,r6		FUN_REG
			MOV 	[r7 - 4],r0		ASSIGN
.if0:
			CMP 	[r7 - 4],[r7 - 8]
			JP 	.false0
.true0:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,1
			MOV 	[r7 - 4],r0		ASSIGN
			J 	.exit0
.false0:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,-2
			MOV 	[r7 - 4],r0		ASSIGN
.exit0:
.if1:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,[r7 - 12]
			MOV		r1,[r7 - 8]EXPRETION
			ADD		r1,[r7 - 16]
			MOV		r2,r1EXPRETION
			SUB		r2,4
			CMP 	r0,r2
			JNZ 	.false1
.true1:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,11
			MOV 	[r7 - 4],r0		ASSIGN
			J 	.exit1
.false1:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,2
			MOV 	[r7 - 4],r0		ASSIGN
.exit1:
.if2:
			CMP.b 	[r7 - 20],[r7 - 24]
			JNZ 	.false2
.true2:
			MOV		r0,2EXPRETION
			ADD.b		r0,[r7 - 20]
			MOV 	[r7 - 20],r0		ASSIGN
			CALL	f2
			MOV 	r0,r6		FUN_REG
			MOV		r1,[r7 - 4]EXPRETION
			ADD		r1,r0
			MOV 	[r7 - 4],r1		ASSIGN
			J 	.exit2
.false2:
			MOV 	[r7 - 24],2		ASSIGN
.exit2:
.if3:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,[r7 - 12]
			MOV		r1,[r7 - 8]EXPRETION
			SUB		r1,[r7 - 16]
			MOV		r2,r1EXPRETION
			SUB		r2,-4
			CMP 	r0,r2
			JNZ 	.false3
.true3:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,7
			MOV 	[r7 - 4],r0		ASSIGN
			J 	.exit3
.false3:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,4
			MOV 	[r7 - 4],r0		ASSIGN
.exit3:
			PUSH	25
			CALL	f8plus
			ADD 	sp, 4
			MOV 	r0,r6		FUN_REG
			MOV		r1,[r7 - 4]EXPRETION
			ADD		r1,r0
			MOV 	[r7 - 4],r1		ASSIGN
.if4:
			MOV		r0,[r7 - 4]EXPRETION
			SUB		r0,[r7 - 12]
			MOV		r1,[r7 - 4]EXPRETION
			ADD		r1,r0
			MOV		r0,r1EXPRETION
			SUB		r0,[r7 - 16]
			MOV		r1,[r7 - 8]EXPRETION
			SUB		r1,[r7 - 4]
			MOV		r2,[r7 - 8]EXPRETION
			ADD		r2,r1
			CMP 	r0,r2
			JNP	.false4
.true4:
			MOV		r0,[r7 - 24]EXPRETION
			SUB.b		r0,[r7 - 20]
			MOV 	[r7 - 20],r0		ASSIGN
			J 	.exit4
.false4:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,[r7 - 8]
			MOV		r1,r0EXPRETION
			SUB		r1,[r7 - 12]
			MOV 	[r7 - 16],r1		ASSIGN
.exit4:
.if5:
			CMP 	[r7 - 4],[r7 - 16]
			JSE 	.false5
.true5:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,[r7 - 16]
			MOV		r1,r0EXPRETION
			SUB		r1,4
			MOV 	[r7 - 4],r1		ASSIGN
			J 	.exit5
.false5:
.exit5:
.if6:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,[r7 - 12]
			MOV		r1,[r7 - 8]EXPRETION
			SUB		r1,+4
			CMP 	r0,r1
			JNZ 	.false6
.true6:
			MOV		r0,[r7 - 4]EXPRETION
			ADD		r0,13
			MOV 	[r7 - 4],r0		ASSIGN
			J 	.exit6
.false6:
.exit6:
			MOV 	r6,[r7 - 4]
			J 	.main_exit
.main_exit:
			MOV 	sp,r7
			POP 	r7
			RET