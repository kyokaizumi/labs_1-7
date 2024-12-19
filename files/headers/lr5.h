#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace lr5 {

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };
    class DATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy);
        void Print() const; // Перегруженный метод Print без параметров
        void Print(char smb);
        DATE Prev();
        DATE Prev(unsigned daysBack); // метод Prev на несколько дней назад
        void Setformat(char format);
        friend DATE operator+(const DATE& d1, const DATE& d2); // Сложение двух дат
        friend bool operator==(const DATE& d1, const DATE& d2); // Оператор равенства

        DATE(const DATE& other); // Конструктор копирования
        DATE(DATE&& other) noexcept; // Конструктор перемещения
        DATE& operator=(const DATE& other); // Оператор присваивания
        DATE& operator=(DATE&& other) noexcept; // Оператор присваивания по перемещению
        friend ostream& operator<<(ostream& os, const DATE& date); // Оператор вывода
        friend istream& operator>>(istream& is, DATE& date); // Оператор ввода
        string operator()() const; // Перегрузка оператора ()
    private:
        unsigned dd;
        month mm;
        unsigned yy;
        char format;
    };

    void runDemo(); // Функция для демонстрации

}