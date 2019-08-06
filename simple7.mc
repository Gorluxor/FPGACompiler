int main(){
	int a;

	asm{
		PUSH r1
		MOV r1, 5
		ST [r7 + 0], r1
		POP r1
	}
	
	a = a + 5;
	return a;
}
