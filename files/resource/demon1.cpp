#include "lr1.h"

namespace lr1 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        DATE date1(1, dek, 2020);
        DATE date2(8, mar, 2023);

        cout << "���� 1: ";
        date1.Print('.');
        cout << "���� 2: ";
        date2.Print('.');

        date1.Setformat('*');
        cout << "������ � ���� 1: ";
        date1.getCF();

        DATE prevDate1 = date1.Prev();
        cout << "���������� ���� ��� ���� 1: ";
        prevDate1.Print('.');
        DATE prevDate2 = date2.Prev();
        cout << "���������� ���� ��� ���� 2: ";
        prevDate2.Print('.');

        // ������������ ������ ������������ �����������
        DATE copiedDate = date1; // ����������� date1 � copiedDate
        cout << "\n������������� ���� (����������� �����������): ";
        copiedDate.Print('.');
        cout << "������ � ������������� ����: ";
        copiedDate.getCF();

        DATE sumDate = date1 + date2; // �������� ���
        cout << "����� ���: ";
        sumDate.Print('.');
    }
}