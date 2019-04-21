
f2:
			PUSH	%14
			MOV 	%15,%14
@f2_body:
			MOV 	$2,%8
			JMP 	@f2_exit
@f2_exit:
			MOV 	%14,%15
			POP 	%14
			RET
f8plus:
			PUSH	%14
			MOV 	%15,%14
			SUBS	%15,$4,%15
@f8plus_body:
			CALL	f2
			MOV 	%8,%0
			MOV 	%0,-4(%14)
			ADD	8(%14),$10,%0
			SUB	%0,-4(%14),%0
			MOV 	%0,%8
			JMP 	@f8plus_exit
@f8plus_exit:
			MOV 	%14,%15
			POP 	%14
			RET
main:
			PUSH	%14
			MOV 	%15,%14
			SUBS	%15,$24,%15
@main_body:
			MOV 	$1,-4(%14)
			MOV 	$2,-8(%14)
			MOV 	$3,-12(%14)
			MOV 	$4,-16(%14)
			MOV 	$5,-20(%14)
			MOV 	$5,-24(%14)
			PUSH	$3
			CALL	f8plus
			ADDS	%15,$4,%15
			MOV 	%8,%0
			MOV 	%0,-4(%14)
@if0:
			CMP 	-4(%14),-8(%14)
			JP 	@false0
@true0:
			ADD	-4(%14),$1,%0
			MOV 	%0,-4(%14)
			JMP 	@exit0
@false0:
			ADD	-4(%14),$-2,%0
			MOV 	%0,-4(%14)
@exit0:
@if1:
			ADD	-4(%14),-12(%14),%0
			ADD	-8(%14),-16(%14),%1
			SUB	%1,$4,%1
			CMP 	%0,%1
			JNZ 	@false1
@true1:
			ADD	-4(%14),$11,%0
			MOV 	%0,-4(%14)
			JMP 	@exit1
@false1:
			ADD	-4(%14),$2,%0
			MOV 	%0,-4(%14)
@exit1:
@if2:
			CMP.b 	-20(%14),-24(%14)
			JNZ 	@false2
@true2:
			ADD.b	$2,-20(%14),%0
			MOV 	%0,-20(%14)
			CALL	f2
			MOV 	%8,%0
			ADD	-4(%14),%0,%0
			MOV 	%0,-4(%14)
			JMP 	@exit2
@false2:
			MOV 	$2,-24(%14)
@exit2:
@if3:
			ADD	-4(%14),-12(%14),%0
			SUB	-8(%14),-16(%14),%1
			SUB	%1,$-4,%1
			CMP 	%0,%1
			JNZ 	@false3
@true3:
			ADD	-4(%14),$7,%0
			MOV 	%0,-4(%14)
			JMP 	@exit3
@false3:
			ADD	-4(%14),$4,%0
			MOV 	%0,-4(%14)
@exit3:
			PUSH	$25
			CALL	f8plus
			ADDS	%15,$4,%15
			MOV 	%8,%0
			ADD	-4(%14),%0,%0
			MOV 	%0,-4(%14)
@if4:
			SUB	-4(%14),-12(%14),%0
			ADD	-4(%14),%0,%0
			SUB	%0,-16(%14),%0
			SUB	-8(%14),-4(%14),%1
			ADD	-8(%14),%1,%1
			CMP 	%0,%1
			JNP	@false4
@true4:
			SUB.b	-24(%14),-20(%14),%0
			MOV 	%0,-20(%14)
			JMP 	@exit4
@false4:
			ADD	-4(%14),-8(%14),%0
			SUB	%0,-12(%14),%0
			MOV 	%0,-16(%14)
@exit4:
@if5:
			CMP 	-4(%14),-16(%14)
			JSE 	@false5
@true5:
			ADD	-4(%14),-16(%14),%0
			SUB	%0,$4,%0
			MOV 	%0,-4(%14)
			JMP 	@exit5
@false5:
@exit5:
@if6:
			ADD	-4(%14),-12(%14),%0
			SUB	-8(%14),$+4,%1
			CMP 	%0,%1
			JNZ 	@false6
@true6:
			ADD	-4(%14),$13,%0
			MOV 	%0,-4(%14)
			JMP 	@exit6
@false6:
@exit6:
			MOV 	-4(%14),%8
			JMP 	@main_exit
@main_exit:
			MOV 	%14,%15
			POP 	%14
			RET