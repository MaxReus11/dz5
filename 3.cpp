#include <regex>
#include <iostream>
#include <string>
#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string line = "a a a3@ffs.fef.fef fgf.rr@gtf45.fgr ggf@ya.ru ggf@ya.ya.ru";
	//std::cout<<"Enter the string to find domains:"<<std::endl;
	std::regex pattern(R"((([[:alpha:]]|[[:alnum:],._]){3,}[@])(([[:alpha:]]+[.]){1,}[[:alpha:]]{2,6}))");
	//getline(std::cin, line);
	std::sregex_iterator begin(line.cbegin(), line.cend(), pattern);
	std::sregex_iterator end;
	std::cout<<"The string to find domains: "<<line<<std::endl;
	std::cout<<"There are some domains: "<<std::endl;
	std::for_each(begin, end, [](const std::smatch& m)
		{
			std::cout << m[3] << std::endl;
		});
	return 0;
}

