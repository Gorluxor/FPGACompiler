// returns 12
// demonstrates assignment with variable
int nesto(int *a, int b){
	int d;
    int rez;
    rez = 12;		
    a = a + b;
		
	*a = rez;	
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
