int main() {
//   int a = 1;
//   {
//     a = a + 2;
//     int a = 3;
//     a = a + 4;
//   }
//   a = a + 5;
   int a = 1;
  if(a == 1) {
	a = 2;
	int b = 3;
	b = b + a * 2;
  } else {
	a = 3;
  }
  return a * 2;
}
