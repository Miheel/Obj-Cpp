#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "linked_list.hpp"

void print(linked_list<int> l);


int main()
{
	srand(static_cast<int>(time(NULL)));

	linked_list<int> list_1, list_2, list_3;

	//1 load two lists with 100 elements
	std::cout << "1. load list\n\n";

	list_1.push_back(rand() % 20);
	list_2.push_back(rand() % 20);
	for (int i = 0; i < 99; i++)
	{
		list_1.push_back(list_1.back() + rand() % 20);
		list_2.push_back(list_2.back() + rand() % 20);
	}

	//2 check the biggest
	std::cout << "2. check the biggest\n\n";

	size_t l1, l2;
	if ((l1 = list_1.at(50)) > (l2 = list_2.at(50)))
	{
		std::cout << "list 1 is bigger at place 50: " << l1 << "\n";
		list_1.remove(50);
	}
	else
	{
		std::cout << "list 2 is bigger at place 50: " << l2 << "\n";
		list_2.remove(50);
	}
	std::cout << "\n";

	//3 remove the biggets
	std::cout << "3. remove biggest\n\n";

	//4 operator = declare list3 assign list1 to it
	std::cout << "4. operator =\n\n";
	try
	{
		list_3 = list_1;
		std::cout << "Success\n\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Failed\n\n";
	}


	//5
	std::cout << "5. remove every 2nd item in list 3\n\n";
	try
	{
		for (size_t i = 0; i < 5; i++)
		{
			list_3.pop_back();
			list_3.push_front(list_3.pop_back());
		}
		std::cout << "Success\n\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Failed\n\n";
	}

	//6 global print
	std::cout << "6. Print list\n\n";

	std::cout << "list 3: ";
	print(list_3);
	std::cout << "\n";

	//7 merger two lists
	std::cout << "7. merge list_1 & list_2\n\n";

	linked_list<int> list_4;
	try
	{
		list_4.merge(list_1, list_2);
		std::cout << "Merge successfull\n\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Merge failed\n\n";
	}

	//8 is list in order
	std::cout << "8. is list in order\n\n";

	std::cout << std::boolalpha << "list_4 order is: " << list_4.is_order() << "\n";

	return 0;
}

void print(linked_list<int> l)
{
	for (size_t i = 0; i < l.size(); i++)
	{
		std::cout << l.at(i) << ", ";
	}
	std::cout << "\n";
}
