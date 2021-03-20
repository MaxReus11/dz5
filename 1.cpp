#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <windows.h>
#include <iterator>

int main() {
    double RoublesToEU = 88.0;
    double RoublesToUSD = 74.0;
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::cin.imbue(std::locale("deu_DEU.UTF-8"));
    long double money;
    std::cout << "Enter the amount of roubles you want to convert: ";
    std::cin >> std::get_money(money);
    std::cout.imbue(std::locale("rus_rus.UTF-8"));
    std::cout << "ru: " << std::showbase << std::put_money(money) << std::endl;
    std::cout.imbue(std::locale("deu_DEU.UTF-8"));
    std::cout << "deu: " << std::put_money(money / RoublesToEU) << std::endl;
    std::cout.imbue(std::locale("en_us.UTF-8"));
    std::cout << "us: " << std::put_money(money / RoublesToUSD) << std::endl;

}
