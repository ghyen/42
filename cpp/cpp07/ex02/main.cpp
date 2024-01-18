#include "Array.hpp"

static void printArray(const Array<int> &array)
{
	std::cout << "length: " << array.size() << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "[" << i << "]: " << array[i] << std::endl;
}

//void f()
//{
//  system("leaks Array");
//}

int main() {
  {
    //atexit(f);
    Array<int> a(1);
    Array<int> b(42);

    a[0] = 1;
    a = b;
    b = Array<int>(5);
    b[0] = 1;

    printArray(a);
    printArray(b);

    try {
      Array<int> c(1);
      c[0] = 1;
      printArray(c);
      std::cout << c[2] << std::endl;
    } catch (const std::exception &e) {
      std::cout << "failed" << std::endl;
    }
  }
}
