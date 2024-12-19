#include "lr4.h"

namespace lr4 {

    // Реализация методов класса DATE
    DATE::DATE(unsigned dd, month mm, unsigned yy) : dd(dd), mm(mm), yy(yy), format('.') {}

    void DATE::Print(char smb) {
        cout << dd << smb << mm << smb << yy << endl;
    }

    BaseDATE* DATE::Prev() {
        if (dd > 1) {
            return new DATE(dd - 1, mm, yy);
        }
        else {
            if (mm == jan) {
                return new DATE(31, dek, yy - 1);
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
                return new DATE(prevDay, prevMonth, yy);
            }
        }
    }

    void DATE::Setformat(char format) {
        this->format = format;
    }

    void DATE::getCF() {
        cout << format << endl;
    }

    unsigned DATE::getDay() const { return dd; }
    month DATE::getMonth() const { return mm; }
    unsigned DATE::getYear() const { return yy; }

    BaseDATE* DATE::add(BaseDATE* otherDate) {
        DATE* other = dynamic_cast<DATE*>(otherDate);
        if (!other) {
            cout << "Ошибка: Невозможно привести к типу DATE." << endl;
            return nullptr;
        }
        unsigned d = this->dd + other->dd;
        month m = static_cast<month>(this->mm + other->mm);
        unsigned y = this->yy + other->yy;

        if (m > dek) {
            y += (m - 1) / 12;
            m = static_cast<month>((m - 1) % 12 + 1);
        }

        unsigned daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
            (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;

        while (d > daysInMonth) {
            d -= daysInMonth;
            m = static_cast<month>(static_cast<int>(m) + 1);
            if (m > 12) {
                m = jan;
                y++;
            }
            daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
                (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;
        }

        return new DATE(d, m, y);
    }

    // Реализация методов класса TimeData
    TimeData::TimeData(unsigned dd, month mm, unsigned yy, unsigned hh, unsigned min, unsigned ss)
        : DATE(dd, mm, yy), hh(hh), min(min), ss(ss) {
    }

    void TimeData::Print(char smb) {
        DATE::Print(smb);
        cout << "время: " << hh << smb << min << smb << ss << endl;
    }

    BaseDATE* TimeData::add(BaseDATE* otherDate) {
        TimeData* other = dynamic_cast<TimeData*>(otherDate);
        if (!other) {
            cout << "Ошибка: Невозможно привести к типу TimeData." << endl;
            return nullptr;
        }

        unsigned totalSeconds = this->ss + other->ss;
        unsigned totalMinutes = this->min + other->min + totalSeconds / 60;
        unsigned totalHours = this->hh + other->hh + totalMinutes / 60;

        totalSeconds %= 60;
        totalMinutes %= 60;
        totalHours %= 24;

        DATE baseDate(dd, mm, yy);
        BaseDATE* resultDate = baseDate.add(other);
        if (resultDate) {
            DATE* dateResult = dynamic_cast<DATE*>(resultDate);
            if (dateResult) {
                return new TimeData(dateResult->getDay(), dateResult->getMonth(), dateResult->getYear(), totalHours, totalMinutes, totalSeconds);
            }
        }
        return nullptr;
    }
}