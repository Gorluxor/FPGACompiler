// returns 9
int nesto(int *a){
	int d;	

	asm{
		MOV.w	 r7, 9
		ST.w	 [r8 + 1000], r7	; put 9 in memory 100	
	}	
	d = *a;	// dereference memory 1000
	return d;
}


int main(){
	int a;
	int c;
	int* b;

	b = 1000;

	c = nesto(b); 
	
	return c;

}
