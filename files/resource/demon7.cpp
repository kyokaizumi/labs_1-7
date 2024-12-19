#include "lr7.h"

namespace lr7 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        DataProcessor dp;
        Manip manip;

        ofstream outfile("output.txt", ios::app);
        cout << "������ ��������� ������������� ��� ����� ������������������|"
            << "\n� �������������� � �� �������� ��������.                  |"
            << "\nf - ������������ �����, i - �����, c - ������              |"
            << "\n               *��� ����� ������������������ �������������*|"
            << "\n----------------------------------------------------------- \n";

        while (true) {
            // ���� ���������� ��������������
            int width, base, precision;
            char fillChar;
            cout << "������� ������: ";
            cin >> width;
            manip.setWidth(width);
            cout << "������� ���� (10 ��� 16): ";
            cin >> base;
            manip.setBase(base);
            cout << "������� ��������: ";
            cin >> precision;
            manip.setPrecision(precision);
            cout << "������� ������ ����������: ";
            cin >> fillChar;
            manip.setFill(fillChar);

            auto data = dp.Get();
            dp.print(data, outfile, manip);
            char choice;
            cout << "\n������ ����������? (y/n): ";
            cin >> choice;
            if (choice != 'y') break;
        }

        outfile.close();
    }

}