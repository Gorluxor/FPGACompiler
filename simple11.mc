//return 
//adds the d number to the address of a

int testFunction(int* a, int d){
	return a + d;
}

int main(){
	int* a;
	int c;
	a = 100;
	c = testFunction(a,55);
	return c;
}
