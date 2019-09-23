//return 3
int funk(int b){
	b = 12345;	
	return b;
}

int main(){
	int c;
	c = 100001; 
	c = c + funk(3);
	return c;
}
