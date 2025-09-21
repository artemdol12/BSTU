#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // максимальный размер исходного кода
#define IN_CODE_ENDL '\n' // символ конца строки

// таблица проверки входной информации, индекс = код (Windows-1251) символа
// значения IN::F - запрещенный символ, IN::T = разрешенный символ, IN::I - игнорировать (не вводить),
// если 0 <= значение < 256 - то вводится данное значение

#define MAX_LEN_LINE 1000
namespace In
{
    void dell_in(char* str, int index);
    struct IN
    {
        enum
        {
            T = 1024, // допустимый символ
            F = 2048, // недопустимый
            I = 4096 // игнорировать, иначе изменить
        };

        int size, // размер исходного кода
            lines, // количество строк
            ignore; // количество проигнорированных символов

        unsigned char* text; // исходный код(Windows-1251);

        int code[256] =
        {
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, '|', IN::F, IN::F, IN::F, IN::F, IN::F, // 0
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 16
            IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, // 32
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 48
            IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, // 64
            IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 80
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 96
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, // 112

            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 128
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 144
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 160
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 176
            IN::T, IN::F, IN::T, IN::F, IN::T, IN::T, IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, // 192
            IN::T, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, // 208
            IN::T, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::T, IN::F, IN::T, IN::T, IN::F, // 224
            IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, // 240

        }; // таблица проверки: T, F, I новое значение

        IN()
        {
            code['\n'] = '|'; // Гарантированная замена перевода строки на '|'
            code[88] = IN::I; // Игнорируемый символ
        }
    };

    IN getin(wchar_t infile[]);
}