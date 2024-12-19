#include "lr7.h"

namespace lr7 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        DataProcessor dp;
        Manip manip;

        ofstream outfile("output.txt", ios::app);
        cout << "Данная программа предназначена для ввода последовательности|"
            << "\nи форматирования её по заданным условиям.                  |"
            << "\nf - вещественное число, i - целое, c - символ              |"
            << "\n               *все числа последовательности положительные*|"
            << "\n----------------------------------------------------------- \n";

        while (true) {
            // Ввод параметров форматирования
            int width, base, precision;
            char fillChar;
            cout << "Введите ширину: ";
            cin >> width;
            manip.setWidth(width);
            cout << "Введите базу (10 или 16): ";
            cin >> base;
            manip.setBase(base);
            cout << "Введите точность: ";
            cin >> precision;
            manip.setPrecision(precision);
            cout << "Введите символ заполнения: ";
            cin >> fillChar;
            manip.setFill(fillChar);

            auto data = dp.Get();
            dp.print(data, outfile, manip);
            char choice;
            cout << "\nХотите продолжить? (y/n): ";
            cin >> choice;
            if (choice != 'y') break;
        }

        outfile.close();
    }

}