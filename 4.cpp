#include <regex>
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//std::cout<<"Enter the string to find date and time:"<<std::endl;
    std::regex pattern1(R"(([0-9]{4}[.]([0][0-9]|[1][012])[.]([012][0-9]|[3][01]))|(([012][0-9]|[3][01])[.]([0][0-9]|[1][012])[.][0-9]{4}))");
	std::regex pattern2(R"(([01][0-9]|[2][0123])[:][0-5][0-9][:][0-5][0-9])");
	 std::istringstream input;
	 input.str("12.02.2002 32.54.1000 23:32:54 24:21:43");
	 std::cout<<"The string to find date and time: "<<input.str()<<std::endl;
	for (std::string line; getline(input, line);) {
		std::sregex_iterator begin1(line.cbegin(), line.cend(), pattern1);
		std::sregex_iterator end1;

		std::for_each(begin1, end1, [](const std::smatch& m)
			{
				std::cout << m[0] << std::endl;
			});
		std::sregex_iterator begin2(line.cbegin(), line.cend(), pattern2);
		std::sregex_iterator end2;
		std::for_each(begin2, end2, [](const std::smatch& m)
			{
				std::cout << m[0] << std::endl;
			});
	}
	return 0;
}
