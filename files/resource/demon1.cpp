#include "lr1.h"

namespace lr1 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        DATE date1(1, dek, 2020);
        DATE date2(8, mar, 2023);

        cout << "Дата 1: ";
        date1.Print('.');
        cout << "Дата 2: ";
        date2.Print('.');

        date1.Setformat('*');
        cout << "Формат в Дата 1: ";
        date1.getCF();

        DATE prevDate1 = date1.Prev();
        cout << "Предыдущая дата для даты 1: ";
        prevDate1.Print('.');
        DATE prevDate2 = date2.Prev();
        cout << "Предыдущая дата для даты 2: ";
        prevDate2.Print('.');

        // Демонстрация работы конструктора копирования
        DATE copiedDate = date1; // Копирование date1 в copiedDate
        cout << "\nСкопированная дата (конструктор копирования): ";
        copiedDate.Print('.');
        cout << "Формат в скопированной дате: ";
        copiedDate.getCF();

        DATE sumDate = date1 + date2; // Сложение дат
        cout << "Сумма дат: ";
        sumDate.Print('.');
    }
}