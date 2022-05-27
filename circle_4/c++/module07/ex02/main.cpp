#include "Array.hpp"
#define MAX_VAL 750


int testOnSubject() {
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	return 0;
}

void test() {
	std::cout << "==TEST1==" <<std::endl;
	Array<int> a(10);

	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	std::cout << a << std::endl;
	try {
		std::cout << a[10] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========" <<std::endl;

	std::cout << "==COPY TEST==" <<std::endl;
	Array<int> b(a);
	std::cout << b << std::endl;
	for (int i = 0; i < 10; i++) {
		b[i] = i + 10;
	}
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	Array<std::string> stra(10);
	for (int i = 0; i < stra.size(); i++) {
		stra[i] = "Hello " + std::to_string(i);
	}
	std::cout << stra << std::endl;
}

int main() {
	//testOnSubject();
	test();
	system("leaks array || grep leaked");
	return 0;
}