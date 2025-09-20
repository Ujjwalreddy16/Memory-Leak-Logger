#include <iostream>
using namespace std;

static int allocations;

void* operator new(size_t size)
{
	void* pointer = malloc(size);
	cout << "allot called for "<<pointer<<", for size: " << size << ", members alloted : "<<++allocations << endl;
	return pointer;
}

void operator delete(void* pointer)noexcept
{
	cout << "deallot called for " << pointer << ", members alloted after deallocation : " << --allocations << endl;
	free(pointer);
}


void check()
{
	if (allocations != 0)
		cout << "\nUNSAFE\n";
	else
		cout << "\nSAFE\n";
}

int main()
{
	int* num = new int;
	float* num1 = new float;
	double* num2 = new double;
	
	int* numarr = new int[10];

	delete num;
	delete num1;
	delete num2;
	delete[] numarr;
	check();
	return 0;
}
