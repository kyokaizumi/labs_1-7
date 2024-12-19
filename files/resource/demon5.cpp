#include "lr5.h"

namespace lr5 {
    // ������� ��� ������������
    void runDemo() {
        setlocale(LC_ALL, "ru");
        int choice;

        cout << "������ ��������� ������������� ��� �������������� � ������.\n����� ����� ���������� ����, ���� �� N ���� �����,\n��������� ��������� ��� � ������� ��� ����.\n\n";

        while (true) {
            cout << "\n����:\n";
            cout << "1) ����� ������� ����\n";
            cout << "2) ����� ����� ���\n";
            cout << "3) �������� ��������� ���\n";
            cout << "0) �����\n";
            cout << "�������� ��������: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                unsigned dd, yy;
                int mm;
                cout << "������� ���� (�� �� ����): ";
                cin >> dd >> mm >> yy;
                DATE date(dd, static_cast<month>(mm), yy);

                int subChoice;
                cout << "1) ����� ���������� ����\n";
                cout << "2) ����� ���� �� ��������� ���� �����\n";
                cout << "�������� ��������: ";
                cin >> subChoice;

                char formatSymbol;
                bool useCustomFormat = false;

                if (subChoice == 1) {
                    DATE prevDate = date.Prev();
                    cout << "������ ������ ������ ��� �������? (y/n): ";
                    char inputChoice;
                    cin >> inputChoice;

                    if (inputChoice == 'y') {
                        cout << "������� ������ ��� �������: ";
                        cin >> formatSymbol;
                        useCustomFormat = true;
                    }

                    if (useCustomFormat) {
                        prevDate.Print(formatSymbol);
                    }
                    else {
                        prevDate.Print(); // ���������� ������ �� ���������
                    }
                }
                else if (subChoice == 2) {
                    unsigned daysBack;
                    cout << "������� ���������� ����, �� ������� ����� ���������: ";
                    cin >> daysBack;
                    DATE prevDate = date.Prev(daysBack);
                    cout << "������ ������ ������ ��� �������? (y/n): ";
                    char inputChoice;
                    cin >> inputChoice;

                    if (inputChoice == 'y') {
                        cout << "������� ������ ��� �������: ";
                        cin >> formatSymbol;
                        useCustomFormat = true;
                    }

                    if (useCustomFormat) {
                        prevDate.Print(formatSymbol);
                    }
                    else {
                        prevDate.Print(); // ���������� ������ �� ���������
                    }
                }
                else {
                    cout << "�������� �����.\n";
                }
                break;
            }
            case 2: {
                unsigned dd1, yy1, dd2, yy2;
                int mm1, mm2;
                cout << "������� ������ ���� (�� �� ����): ";
                cin >> dd1 >> mm1 >> yy1;
                DATE date1(dd1, static_cast<month>(mm1), yy1);
                cout << "������� ������ ���� (�� �� ����): ";
                cin >> dd2 >> mm2 >> yy2;
                DATE date2(dd2, static_cast<month>(mm2), yy2);

                DATE sumDate = date1 + date2;
                char formatSymbol;
                cout << "������ ������ ������ ��� �������? (y/n): ";
                char inputChoice;
                cin >> inputChoice;

                if (inputChoice == 'y') {
                    cout << "������� ������ ��� �������: ";
                    cin >> formatSymbol;
                    sumDate.Print(formatSymbol);
                }
                else {
                    sumDate.Print(); // ���������� ������ �� ���������
                }
                break;
            }
            case 3: {
                unsigned dd1, yy1, dd2, yy2;
                int mm1, mm2;
                cout << "������� ������ ���� (�� �� ����): ";
                cin >> dd1 >> mm1 >> yy1;
                DATE date1(dd1, static_cast<month>(mm1), yy1);
                cout << "������� ������ ���� (�� �� ����): ";
                cin >> dd2 >> mm2 >> yy2;
                DATE date2(dd2, static_cast<month>(mm2), yy2);

                if (date1 == date2) {
                    cout << "���� �����.\n";
                }
                else {
                    cout << "���� �� �����.\n";
                }
                break;
            }
            case 0:
                cout << "����� �� ���������.\n";
                return;
            default:
                cout << "�������� �����. ����������, ���������� �����.\n";
                break;
            }
        }
    }

}