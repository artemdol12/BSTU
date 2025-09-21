#include "stdafx.h"
#include "In.h"
#include "Error.h"
namespace In
{
    IN getin(wchar_t infile[])
    {
        int lines = 0;
        int cols = 0;
        int ignors = 0;
        int iter = 0;
        char* str = new char[MAX_LEN_LINE];
        unsigned char* code = new unsigned char[IN_MAX_LEN_TEXT];
        IN in;
        in.size = 0;
        std::fstream file(infile, std::fstream::in);

        // если невозможно открыть файл
        if (!file.is_open())
        {
            throw ERROR_THROW(110);
        }
        while (!file.eof())
        {
            lines++;
            // считываем данные с файла
            file.getline(str, MAX_LEN_LINE);
            for (int i = 0; i < strlen(str); i++)
            {
                cols++;
                in.size++;
                // если ввели запрещенный символ
                if (in.code[int((unsigned char)str[i])] == IN::F)
                {
                    throw ERROR_THROW_IN(111, lines, cols);
                }
                // если ввели символ, который пропускаем
                else if (in.code[int((unsigned char)str[i])] == IN::I)
                {
                    ignors++;
                    dell_in(str, i);
                    i--; // уменьшаем индекс, так как удалили символ
                }
                else if (
                    in.code[int((unsigned char)str[i])] != IN::I &&
                    in.code[int((unsigned char)str[i])] != IN::F &&
                    in.code[int((unsigned char)str[i])] != IN::T
                    )
                {
                    // Замена символа (включая перевод строки)
                    str[i] = in.code[int((unsigned char)str[i])];
                }
            }

            // Добавляем разделитель '|' вместо перевода строки
            if (lines > 1) // Добавляем '|' только если это не первая строка
            {
                if (iter < IN_MAX_LEN_TEXT - 1)
                {
                    code[iter++] = '|';
                    in.size++;
                }
            }

            // Копируем обработанную строку в выходной буфер
            for (int i = 0; i < strlen(str); i++)
            {
                if (iter < IN_MAX_LEN_TEXT - 1)
                {
                    code[iter++] = (unsigned char)str[i];
                }
            }

            cols = 0;
        }
        code[iter] = '\0';
        in.ignore = ignors;
        in.lines = lines;
        in.text = code;
        file.close();
        delete[] str;
        return in;
    }

    void dell_in(char* str, int index)
    {
        for (int i = index; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
}