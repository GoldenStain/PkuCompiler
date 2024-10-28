int main() {
//   int a = 1;
//   {
//     a = a + 2;
//     int a = 3;
//     a = a + 4;
//   }
//   a = a + 5;
   int a = 1;
   int b = 233;
   {
	int b = 5;
	b = a * 2 + 3;
   }
 a = a * 5 + b;
  return a * 2;
}
