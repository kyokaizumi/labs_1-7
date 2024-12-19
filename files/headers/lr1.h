#pragma once
#include <iostream>
using namespace std;

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

namespace lr1 {
    void runDemo(); // Объявление функции для демонстрации

    class DATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy);
        void Print(char smb);
        DATE Prev();
        void Setformat(char format); // Задать char format
        void getCF();

        friend DATE operator+(const DATE& d1, const DATE& d2); // friend метод для сложения двух дат

    private:
        unsigned dd;
        month mm;
        unsigned yy;
        char format;
    };
}