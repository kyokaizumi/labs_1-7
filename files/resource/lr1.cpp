#include "lr1.h"

namespace lr1 {
    // Конструктор
    DATE::DATE(unsigned dd, month mm, unsigned yy) : dd(dd), mm(mm), yy(yy), format('.') {}

    // Вывод даты
    void DATE::Print(char smb) {
        cout << dd << smb << mm << smb << yy << endl;
    }

    // Нахождение предыдущей даты
    DATE DATE::Prev() {
        if (dd > 1) {
            return DATE(dd - 1, mm, yy);
        }
        else {
            if (mm == jan) {
                return DATE(31, dek, yy - 1);
            }
            else {
                month prevMonth = static_cast<month>(mm - 1);
                unsigned prevDay = 31;
                switch (prevMonth) {
                case apr: case jun: case sep: case nov:
                    prevDay = 30;
                    break;
                case feb:
                    prevDay = (yy % 4 == 0) ? 29 : 28; // Учет високосного года
                    break;
                }
                return DATE(prevDay, prevMonth, yy);
            }
        }
    }

    // Задать формат
    void DATE::Setformat(char format) {
        this->format = format;
    }

    // Вывести формат
    void DATE::getCF() {
        cout << format << endl;
    }

    // friend метод для сложения двух дат
    DATE operator+(const DATE& d1, const DATE& d2) {
        unsigned d = d1.dd + d2.dd; // Сумма дней
        month m = static_cast<month>(d1.mm + d2.mm); // Сумма месяцев
        unsigned y = d1.yy + d2.yy; // Сумма годов

        // Корректируем месяцы и годы, если сумма месяцев больше 12
        if (m > dek) {
            y += (m - 1) / 12; // Увеличиваем год на количество полных лет
            m = static_cast<month>((m - 1) % 12 + 1); // Корректируем месяц
        }

        // Учитываем переполнение дней и месяцев
        unsigned daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
            (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;

        while (d > daysInMonth) {
            d -= daysInMonth;
            m = static_cast<month>(static_cast<int>(m) + 1); // Увеличиваем месяц
            if (m > 12) {
                m = jan;
                y++;
            }
            daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
                (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;
        }
        return DATE(d, m, y);
    }
}