//RETURN 21
int fact(int n){
	int rez;	
	if (n > 1)
		rez = n * fact(n - 1);
	else
		rez = 1;
	return rez;
}

int main(){
	int a;
	a = 15;
	a = a + fact(3);
	return a;
}
