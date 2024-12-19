#include <iostream>
#include <limits>

#include "lr1.h"
#include "lr2.h"
#include "lr3.h"
#include "lr4.h"
#include "lr5.h"
#include "lr6.h"
#include "lr7.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int choice{ 0 };
	while (true) {
		std::cout << "\n--=====-- меню --=====--\n";
		std::cout << "Выберите программу для запуска:\n";
		std::cout << "-1) Очистить консоль\n";
		std::cout << "1) Программа lr1\n";
		std::cout << "2) Программа lr2\n";
		std::cout << "3) Программа lr3\n";
		std::cout << "4) Программа lr4\n";
		std::cout << "5) Программа lr5\n";
		std::cout << "6) Программа lr6\n";
		std::cout << "7) Программа lr7\n";
		std::cout << "0) Выход\n";
		std::cout << "Выберите действие: ";
		std::cin >> choice;

		switch (choice) {
		case -1:
			system("cls");
			break;
		case 1:
			lr1::runDemo();
			break;
		case 2:
			lr2::runDemo();
			break;
		case 3:
			lr3::runDemo();
			break;
		case 4:
			lr4::runDemo();
			break;
		case 5:
			lr5::runDemo();
			break;
		case 6:
			lr6::runDemo();
			break;
		case 7:
			lr7::runDemo();
			break;
		case 0:
			std::cout << "Выход из программы.\n";
			return 0;
		default:
			std::cout << "Некорректный выбор. Повторите попытку.\n";
		}
	}
}