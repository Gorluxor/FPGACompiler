int main(){
	int a;

	asm{
		PUSH r1
		MOV.w r1, 5
		ST.w [r7 + 0], r1
		POP r1
	}
	
	a = a + 5;
	return a;
}
