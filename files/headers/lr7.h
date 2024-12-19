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
        // ����������� �� ���������
        Manip() : width(0), base(10), precision(2), fillChar(' ') {}

        // ��������� ������
        void setWidth(int w) { width = w; }
        // ��������� ���� (10, 16, 8)
        void setBase(int b) { base = b; }
        // ��������� ��������
        void setPrecision(int p) { precision = p; }
        // ��������� ������� ����������
        void setFill(char c) { fillChar = c; }
        // ��������� ������
        int getWidth() const { return width; }
        // ��������� ����
        int getBase() const { return base; }
        // ��������� ��������
        int getPrecision() const { return precision; }
        // ��������� ������� ����������
        char getFill() const { return fillChar; }
        // ���������� �������� � ������ ������
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