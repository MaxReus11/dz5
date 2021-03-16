#include <regex>
#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string line;
	std::regex pattern(R"((([[:alpha:]]|[[:alnum:],._]){3,}[@])(([[:alpha:]]+[.]){1,}[[:alpha:]]{2,6}))");
	getline(std::cin, line);
	std::sregex_iterator begin(line.cbegin(), line.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m)
		{
			std::cout << m[3] << std::endl;
		});
	return 0;
}
