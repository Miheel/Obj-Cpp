#include <iostream>
#include <exception>

int main() {
	try {
		int8_t *block;
		int menu = 0;
		
		std::cout << "1(1KiB) or 2(1GiB)";
		std::cin >> menu;

		if (menu = 1)
		{
			while (true)
			{
				block = new int8_t[1024];
			}
		}
		else if(menu = 2)
		{
			while (true)
			{
				block = new int8_t[1073741824];
			}
		}
	}
	catch (std::bad_alloc e) {
		std::cerr << e.what() << std::endl; // Körs denna rad ?
	}
	return 0;
}
