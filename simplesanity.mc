//OPIS: Sanity check za miniC gramatiku
//RETURN: 50

int f2() {
    return 2;
}

int f8plus(int x) {
    int y;
    y = f2();
    return x + 10 - y;
}


int main() {
  int a;
  int b;
  int c;
  int d;
  char u;
  char w;

  a = 1;
  b = 2;
  c = 3;
  d = 4;
  u = 5b;
  w = 5b;

  //poziv funkcije
  a = f8plus(3);  //a = 11

  //if iskaz sa else delom
  if (a < b)  //11 < 2
    a = a + 1;
  else
    a = a + -2; // a = 9

  if (a + c == b + d - 4) //1 == 2
    a = a + 11;
  else
    a = a + 2; // a = 11

  if (u == w) {   // true
    u = 2b + u;
    a = a + f2(); // a = 13
  }
  else {
    w = 2b;
  }

  if (a + c == b - d - -4) {  //13+3 == 2-4--4  false
    a = a + 7;
  }
  else
    a = a + 4; // a = 17
  a = a + f8plus(25); // a = a + 33 => 50
 
  if (a + (a-c) - d >= b + (b-a))    //50+(50-3)-4 >= 2+(2-50)  93 >= -46 true
    u = w-u;
  else
    d = a+b-c; 

  //if iskaz bez else dela
  if (a > d) // 50 > 4
    a = a + d - 4; // a = 50 + 4 - 4; 

  if (a + c == b - +4)    //50+3 == 2-4  false
    a = a + 13;

  return a; // return 50
}

