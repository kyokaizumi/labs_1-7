#include "lr4.h"

namespace lr4 {
    // ������� ��� ������������
    void runDemo() {
        setlocale(LC_ALL, "ru");
        cout << "������ ��������� ������������� ��� ����� ���� � �������.\n\n";

        // ���� ������ ���� (�������)
        unsigned day1, year1;
        unsigned month1;
        cout << "������� ����, ����� (������) � ��� ��� ������ ���� (��������, 15 2 2023): ";
        cin >> day1 >> month1 >> year1;
        DATE date1(day1, static_cast<month>(month1), year1); // ���������� ���� ������

        // ���� ������ ���� (� ��������)
        unsigned day2, year2, hh, min, ss;
        unsigned month2;
        cout << "������� ����, ����� (������), ���, ����, ������ � ������� ��� ������ ���� (��������, 5 4 2024 14 45 30): ";
        cin >> day2 >> month2 >> year2 >> hh >> min >> ss;
        TimeData date2(day2, static_cast<month>(month2), year2, hh, min, ss); // ���������� ���� ������

        // ����� ��������� ���
        cout << "��������� ����:" << endl;
        cout << "���� 1: ";
        date1.Print('.');
        cout << "���� 2: ";
        date2.Print('.');

        // �������� ���
        BaseDATE* result1 = date1.add(&date2);

        // ����� �����������
        if (result1) {
            DATE* resultDate1 = dynamic_cast<DATE*>(result1);
            if (resultDate1) {
                cout << "��������� �������� ������� ���� � ���� � ��������: ";
                resultDate1->Print('.');
            }
            delete result1; // ����������� ������
        }

        cout << "��������� ���������." << endl;
    }
}