#include "lr4.h"

namespace lr4 {
    // Функция для демонстрации
    void runDemo() {
        setlocale(LC_ALL, "ru");
        cout << "Данная программа предназначена для ввода даты и времени.\n\n";

        // Ввод первой даты (обычной)
        unsigned day1, year1;
        unsigned month1;
        cout << "Введите день, месяц (числом) и год для первой даты (например, 15 2 2023): ";
        cin >> day1 >> month1 >> year1;
        DATE date1(day1, static_cast<month>(month1), year1); // Приведение типа месяца

        // Ввод второй даты (с временем)
        unsigned day2, year2, hh, min, ss;
        unsigned month2;
        cout << "Введите день, месяц (числом), год, часы, минуты и секунды для второй даты (например, 5 4 2024 14 45 30): ";
        cin >> day2 >> month2 >> year2 >> hh >> min >> ss;
        TimeData date2(day2, static_cast<month>(month2), year2, hh, min, ss); // Приведение типа месяца

        // Вывод введенных дат
        cout << "Введенные даты:" << endl;
        cout << "Дата 1: ";
        date1.Print('.');
        cout << "Дата 2: ";
        date2.Print('.');

        // Сложение дат
        BaseDATE* result1 = date1.add(&date2);

        // Вывод результатов
        if (result1) {
            DATE* resultDate1 = dynamic_cast<DATE*>(result1);
            if (resultDate1) {
                cout << "Результат сложения обычной даты и даты с временем: ";
                resultDate1->Print('.');
            }
            delete result1; // Освобождаем память
        }

        cout << "Программа завершена." << endl;
    }
}