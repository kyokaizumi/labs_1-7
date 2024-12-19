#pragma once
#include <iostream>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;

namespace lr7 {

    class Manip {
    private:
        int width;
        int base;
        int precision;
        char fillChar;

    public:
        // Конструктор по умолчанию
        Manip() : width(0), base(10), precision(2), fillChar(' ') {}

        // Установка ширины
        void setWidth(int w) { width = w; }
        // Установка базы (10, 16, 8)
        void setBase(int b) { base = b; }
        // Установка точности
        void setPrecision(int p) { precision = p; }
        // Установка символа заполнения
        void setFill(char c) { fillChar = c; }
        // Получение ширины
        int getWidth() const { return width; }
        // Получение базы
        int getBase() const { return base; }
        // Получение точности
        int getPrecision() const { return precision; }
        // Получение символа заполнения
        char getFill() const { return fillChar; }
        // Применение настроек к потоку вывода
        void apply(ostream& os) const {
            os << setfill(fillChar) << setw(width) << setbase(base) << setprecision(precision);
        }
    };

    class DataProcessor {
    public:
        tuple<float, int, float, char, char> Get();
        void print(const tuple<float, int, float, char, char>& data, ofstream& outfile, const Manip& manip);
        string decimalToHex(int decimal);
        string decimalToHexWithDecimals(float decimal, int decimalPlaces);
        string hexUpper(int value);
        string formatOutput(const string& value, int width, char fill);
        string formatOutput(int value, int width, char fill);
    };

    void runDemo();

}