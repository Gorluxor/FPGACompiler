// returns 11
int nesto(int *a, int b){
	int d;		
    a = a + b;
	asm{
		MOV.w	 r7, 11
		ST.w	 [r8 + 1000], r7	; put 11 in memory 100	
	}	
	d = *a;	// dereference memory 1000
	return d;
}


int main(){
	int a;
	int c;
	int* b;
	a = 4;
	b = 996;

	c = nesto(b,a); 
	
	return c;

}
