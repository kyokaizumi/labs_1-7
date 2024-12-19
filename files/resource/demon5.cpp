#include "lr5.h"

namespace lr5 {
    // Функция для демонстрации
    void runDemo() {
        setlocale(LC_ALL, "ru");
        int choice;

        cout << "Данная программа предназначена для взаимодействия с датами.\nМожно найти предыдущую дату, дату за N дней назад,\nпроверить равенство дат и сложить две даты.\n\n";

        while (true) {
            cout << "\nМеню:\n";
            cout << "1) Найти прошлую дату\n";
            cout << "2) Найти сумму дат\n";
            cout << "3) Проверка равенства дат\n";
            cout << "0) Выход\n";
            cout << "Выберите действие: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                unsigned dd, yy;
                int mm;
                cout << "Введите дату (ДД ММ ГГГГ): ";
                cin >> dd >> mm >> yy;
                DATE date(dd, static_cast<month>(mm), yy);

                int subChoice;
                cout << "1) Найти предыдущую дату\n";
                cout << "2) Найти дату за несколько дней назад\n";
                cout << "Выберите действие: ";
                cin >> subChoice;

                char formatSymbol;
                bool useCustomFormat = false;

                if (subChoice == 1) {
                    DATE prevDate = date.Prev();
                    cout << "Хотите ввести символ для формата? (y/n): ";
                    char inputChoice;
                    cin >> inputChoice;

                    if (inputChoice == 'y') {
                        cout << "Введите символ для формата: ";
                        cin >> formatSymbol;
                        useCustomFormat = true;
                    }

                    if (useCustomFormat) {
                        prevDate.Print(formatSymbol);
                    }
                    else {
                        prevDate.Print(); // Использует формат по умолчанию
                    }
                }
                else if (subChoice == 2) {
                    unsigned daysBack;
                    cout << "Введите количество дней, на которое нужно вернуться: ";
                    cin >> daysBack;
                    DATE prevDate = date.Prev(daysBack);
                    cout << "Хотите ввести символ для формата? (y/n): ";
                    char inputChoice;
                    cin >> inputChoice;

                    if (inputChoice == 'y') {
                        cout << "Введите символ для формата: ";
                        cin >> formatSymbol;
                        useCustomFormat = true;
                    }

                    if (useCustomFormat) {
                        prevDate.Print(formatSymbol);
                    }
                    else {
                        prevDate.Print(); // Использует формат по умолчанию
                    }
                }
                else {
                    cout << "Неверный выбор.\n";
                }
                break;
            }
            case 2: {
                unsigned dd1, yy1, dd2, yy2;
                int mm1, mm2;
                cout << "Введите первую дату (ДД ММ ГГГГ): ";
                cin >> dd1 >> mm1 >> yy1;
                DATE date1(dd1, static_cast<month>(mm1), yy1);
                cout << "Введите вторую дату (ДД ММ ГГГГ): ";
                cin >> dd2 >> mm2 >> yy2;
                DATE date2(dd2, static_cast<month>(mm2), yy2);

                DATE sumDate = date1 + date2;
                char formatSymbol;
                cout << "Хотите ввести символ для формата? (y/n): ";
                char inputChoice;
                cin >> inputChoice;

                if (inputChoice == 'y') {
                    cout << "Введите символ для формата: ";
                    cin >> formatSymbol;
                    sumDate.Print(formatSymbol);
                }
                else {
                    sumDate.Print(); // Использует формат по умолчанию
                }
                break;
            }
            case 3: {
                unsigned dd1, yy1, dd2, yy2;
                int mm1, mm2;
                cout << "Введите первую дату (ДД ММ ГГГГ): ";
                cin >> dd1 >> mm1 >> yy1;
                DATE date1(dd1, static_cast<month>(mm1), yy1);
                cout << "Введите вторую дату (ДД ММ ГГГГ): ";
                cin >> dd2 >> mm2 >> yy2;
                DATE date2(dd2, static_cast<month>(mm2), yy2);

                if (date1 == date2) {
                    cout << "Даты равны.\n";
                }
                else {
                    cout << "Даты не равны.\n";
                }
                break;
            }
            case 0:
                cout << "Выход из программы.\n";
                return;
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                break;
            }
        }
    }

}