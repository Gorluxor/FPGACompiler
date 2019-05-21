// return 65
// demonstrates the use of do_while
int main(){
	int a;
	int b;
	int sum;
	sum = 0;
	a = 10;

	do{
		do {
		sum = sum + a;
		--a;
		} while (a > 5);
		sum = sum + a;
	}while(a > 0);

	b = 6;
	do{
		sum = sum - 5;
		--b;
	} while (b > 5);
	return sum;
}
