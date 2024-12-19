#pragma once
#include <iostream>
using namespace std;

namespace lr4 {

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    // Базовый класс с виртуальными функциями
    class BaseDATE {
    public:
        virtual void Print(char smb) = 0;
        virtual BaseDATE* Prev() = 0;
        virtual void Setformat(char format) = 0;
        virtual void getCF() = 0;
        virtual BaseDATE* add(BaseDATE* otherDate) = 0;
    };

    // Производный класс DATE
    class DATE : public BaseDATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy);
        void Print(char smb) override;
        BaseDATE* Prev() override;
        void Setformat(char format) override;
        void getCF() override;
        BaseDATE* add(BaseDATE* otherDate) override;

        // Методы доступа
        unsigned getDay() const;
        month getMonth() const;
        unsigned getYear() const;

    protected:
        unsigned dd;
        month mm;
        unsigned yy;
        char format;
    };

    // класс TimeData
    class TimeData : public DATE {
    public:
        TimeData(unsigned dd, month mm, unsigned yy, unsigned hh, unsigned min, unsigned ss);
        void Print(char smb) override;
        BaseDATE* add(BaseDATE* otherDate) override;

    private:
        unsigned hh; // часы
        unsigned min; // минуты
        unsigned ss; // секунды
    };

    void runDemo(); // Объявление функции для демонстрации
}