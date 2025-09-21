using System;
using System.Text;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine(" 1) ТИПЫ ");

        // 1a. Примитивные типы
        Console.WriteLine("\n1a. Примитивные типы:");
        byte byteVar = 255;
        sbyte sbyteVar = -128;
        short shortVar = -32768;
        ushort ushortVar = 65535;
        int intVar = -2147483648;
        uint uintVar = 4294967295;
        long longVar = -9223372036854775808;
        ulong ulongVar = 18446744073709551615;
        float floatVar = 3.14f;
        double doubleVar = 3.141592653589793;
        decimal decimalVar = 3.1415926535897932384626433832795m;
        char charVar = 'A';
        bool boolVar = true;
        string stringVar = "Hello";
        object objectVar = new object();

        Console.WriteLine($"byte: {byteVar}");
        Console.WriteLine($"sbyte: {sbyteVar}");
        Console.WriteLine($"short: {shortVar}");
        Console.WriteLine($"ushort: {ushortVar}");
        Console.WriteLine($"int: {intVar}");
        Console.WriteLine($"uint: {uintVar}");
        Console.WriteLine($"long: {longVar}");
        Console.WriteLine($"ulong: {ulongVar}");
        Console.WriteLine($"float: {floatVar}");
        Console.WriteLine($"double: {doubleVar}");
        Console.WriteLine($"decimal: {decimalVar}");
        Console.WriteLine($"char: {charVar}");
        Console.WriteLine($"bool: {boolVar}");
        Console.WriteLine($"string: {stringVar}");
        Console.WriteLine($"object: {objectVar}");

        // Ввод значений
        Console.Write("Введите целое число: ");
        int inputInt = int.Parse(Console.ReadLine());
        Console.Write("Введите строку: ");
        string inputString = Console.ReadLine();
        Console.WriteLine($"Вы ввели: число={inputInt}, строка={inputString}");

        // 1b. Приведения типов
        Console.WriteLine("\n1b. Приведения типов:");

        // Неявные приведения
        int intFromByte = byteVar;           // byte → int
        long longFromInt = intVar;           // int → long
        double doubleFromFloat = floatVar;   // float → double
        decimal decimalFromInt = intVar;     // int → decimal
        object objFromString = stringVar;    // string → object

        Console.WriteLine($"Неявные: byte({byteVar}) → int({intFromByte})");

        // Явные приведения
        byte byteFromInt = (byte)intVar;         // int → byte
        int intFromDouble = (int)doubleVar;      // double → int
        float floatFromDouble = (float)doubleVar;// double → float
        char charFromInt = (char)65;             // int → char
        long longFromDouble = (long)doubleVar;   // double → long

        Console.WriteLine($"Явные: double({doubleVar}) → int({intFromDouble})");

        // Класс Convert
        string strNumber = "123";
        int convertedInt = Convert.ToInt32(strNumber);
        bool convertedBool = Convert.ToBoolean("true");
        Console.WriteLine($"Convert: '{strNumber}' → {convertedInt}");

        // 1c. Упаковка и распаковка
        Console.WriteLine("\n1c. Упаковка и распаковка:");
        int valueType = 42;
        object boxed = valueType;            // Упаковка
        int unboxed = (int)boxed;            // Распаковка
        Console.WriteLine($"Упаковка: {valueType} → {boxed}");
        Console.WriteLine($"Распаковка: {boxed} → {unboxed}");

        // 1d. Неявно типизированная переменная
        Console.WriteLine("\n1d. Неявно типизированная переменная:");
        var implicitVar = "Это строка";
        // implicitVar = 42; // Ошибка - нельзя изменить тип
        Console.WriteLine($"var variable: {implicitVar}, тип: {implicitVar.GetType()}");

        // 1e. Nullable переменная
        Console.WriteLine("\n1e. Nullable переменная:");
        int? nullableInt = null;
        nullableInt = 42;
        Console.WriteLine($"Nullable int: {nullableInt ?? 0}, HasValue: {nullableInt.HasValue}");

        double? nullableDouble = null;
        Console.WriteLine($"Nullable double: {nullableDouble ?? 0.0}");

        // 1f. Ошибка с var
        Console.WriteLine("\n1f. Ошибка с var:");
        var varVariable = "Изначальная строка";
        // varVariable = 42; // Ошибка компиляции: нельзя изменить тип после определения
        Console.WriteLine("Ошибка компиляции при попытке изменить тип переменной var");

        Console.WriteLine("\n 2) СТРОКИ ");

        // 2a. Строковые литералы
        Console.WriteLine("\n2a. Строковые литералы:");
        string literal1 = "Hello";
        string literal2 = "World";
        string literal3 = "Hello";

        Console.WriteLine($"'Hello' == 'Hello': {literal1 == literal3}");
        Console.WriteLine($"'Hello' == 'World': {literal1 == literal2}");
        Console.WriteLine($"Reference equals: {object.ReferenceEquals(literal1, literal3)}");

        // 2b. Операции со строками
        Console.WriteLine("\n2b. Операции со строками:");
        string str1 = "Hello";
        string str2 = "World";
        string str3 = "C# Programming";

        // Сцепление
        string concatenated = str1 + " " + str2;
        Console.WriteLine($"Сцепление: {concatenated}");

        // Копирование
        string copied = string.Copy(str1);
        Console.WriteLine($"Копирование: {copied}");

        // Подстрока
        string substring = str3.Substring(0, 2);
        Console.WriteLine($"Подстрока: '{substring}' из '{str3}'");

        // Разделение на слова
        string sentence = "This is a sample sentence";
        string[] words = sentence.Split(' ');
        Console.WriteLine($"Разделение: {string.Join(" | ", words)}");

        // Вставка
        string inserted = str1.Insert(2, "INSERTED");
        Console.WriteLine($"Вставка: {inserted}");

        // Удаление
        string removed = str3.Remove(3, 5);
        Console.WriteLine($"Удаление: {removed}");

        // Интерполирование
        string interpolated = $"Строка 1: {str1}, Строка 2: {str2}";
        Console.WriteLine($"Интерполирование: {interpolated}");

        // 2c. Пустая и null строка
        Console.WriteLine("\n2c. Пустая и null строка:");
        string emptyString = "";
        string nullString = null;

        Console.WriteLine($"string.IsNullOrEmpty(null): {string.IsNullOrEmpty(nullString)}");
        Console.WriteLine($"string.IsNullOrEmpty(empty): {string.IsNullOrEmpty(emptyString)}");
        Console.WriteLine($"string.IsNullOrEmpty(regular): {string.IsNullOrEmpty("text")}");

        // Дополнительные операции
        Console.WriteLine($"emptyString.Length: {emptyString?.Length ?? -1}");
        Console.WriteLine($"nullString?.Length: {nullString?.Length ?? -1}");

        // 2d. StringBuilder
        Console.WriteLine("\n2d. StringBuilder:");
        StringBuilder sb = new StringBuilder("Hello World");
        sb.Remove(5, 6);          // Удалить " World"
        sb.Insert(0, "START-");   // Добавить в начало
        sb.Append("-END");        // Добавить в конец
        Console.WriteLine($"StringBuilder: {sb}");

        Console.WriteLine("\n 3) МАССИВЫ ");

        // 3a. Двумерный массив
        Console.WriteLine("\n3a. Двумерный массив:");
        int[,] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write($"{matrix[i, j],4}");
            }
            Console.WriteLine();
        }

        // 3b. Одномерный массив строк
        Console.WriteLine("\n3b. Одномерный массив строк:");
        string[] stringArray = { "Apple", "Banana", "Cherry", "Date" };
        Console.WriteLine($"Массив: {string.Join(", ", stringArray)}");
        Console.WriteLine($"Длина: {stringArray.Length}");

        // Изменение элемента
        stringArray[1] = "Blueberry";
        Console.WriteLine($"После изменения: {string.Join(", ", stringArray)}");

        // 3c. Ступенчатый массив
        Console.WriteLine("\n3c. Ступенчатый массив:");
        double[][] jaggedArray = new double[3][];
        jaggedArray[0] = new double[2];
        jaggedArray[1] = new double[3];
        jaggedArray[2] = new double[4];

        Console.WriteLine("Введите значения для ступенчатого массива:");
        for (int i = 0; i < jaggedArray.Length; i++)
        {
            for (int j = 0; j < jaggedArray[i].Length; j++)
            {
                Console.Write($"Элемент [{i}][{j}]: ");
                jaggedArray[i][j] = double.Parse(Console.ReadLine());
            }
        }

        Console.WriteLine("Ступенчатый массив:");
        foreach (var row in jaggedArray)
        {
            Console.WriteLine(string.Join(" ", row));
        }

        // 3d. Неявно типизированные массивы
        Console.WriteLine("\n3d. Неявно типизированные массивы:");
        var implicitArray = new[] { 1, 2, 3, 4, 5 };
        var implicitString = "Неявная строка";
        Console.WriteLine($"Массив: {string.Join(", ", implicitArray)}, тип: {implicitArray.GetType()}");
        Console.WriteLine($"Строка: {implicitString}, тип: {implicitString.GetType()}");

        Console.WriteLine("\n 4) КОРТЕЖИ ");

        // 4a. Кортеж из 5 элементов
        var tuple = (123, "Hello", 'A', "World", 123456789);

        // 4b. Вывод кортежа
        Console.WriteLine("4b. Вывод кортежа из 5 элементов:");
        Console.WriteLine($"Полный кортеж: {tuple}");
        Console.WriteLine($"Выборочно: {tuple.Item1}, {tuple.Item3}, {tuple.Item4}");

        // 4c. Распаковка кортежа
        Console.WriteLine("\n4c. Распаковка кортежа:");
        // Полная распаковка
        (int num, string str, char ch, string strin, int num2) = tuple;
        Console.WriteLine($"Полная распаковка: {num}, {str}, {ch}");

        // Частичная распаковка с _
        var (first, _, third, _, fifth) = tuple;
        Console.WriteLine($"С пропуском: {first}, {third}, {fifth}");

        // 4d. Сравнение кортежей
        Console.WriteLine("\n4d. Сравнение кортежей:");
        var tuple1 = (1, "test", 3.14);
        var tuple2 = (1, "test", 3.14);
        var tuple3 = (2, "different", 2.71);

        Console.WriteLine($"tuple1 == tuple2: {tuple1 == tuple2}");
        Console.WriteLine($"tuple1 == tuple3: {tuple1 == tuple3}");

        Console.WriteLine("\n 5) ЛОКАЛЬНАЯ ФУНКЦИЯ ");

        // 5. Локальная функция
        (int max, int min, int sum, char firstLetter) ProcessArrayAndString(int[] numbers, string text)
        {
            if (numbers == null || numbers.Length == 0)
                throw new ArgumentException("Массив не может быть пустым");

            if (string.IsNullOrEmpty(text))
                throw new ArgumentException("Строка не может быть пустой");

            return (numbers.Max(), numbers.Min(), numbers.Sum(), text[0]);
        }

        int[] testArray = { 10, 5, 8, 3, 15 };
        string testString = "Programming";

        var result = ProcessArrayAndString(testArray, testString);
        Console.WriteLine($"Максимум: {result.max}, Минимум: {result.min}, Сумма: {result.sum}, Первая буква: '{result.firstLetter}'");

        Console.WriteLine("\n 6) CHECKED/UNCHECKED ");

        // 6. Checked/Unchecked
        void CheckedFunction()
        {
            Console.WriteLine("Checked блок:");
            try
            {
                checked
                {
                    int maxInt = int.MaxValue;
                    Console.WriteLine($"Max int: {maxInt}");
                    maxInt++; // Переполнение
                    Console.WriteLine($"After increment: {maxInt}");
                }
            }
            catch (OverflowException ex)
            {
                Console.WriteLine($"OverflowException: {ex.Message}");
            }
        }

        void UncheckedFunction()
        {
            Console.WriteLine("Unchecked блок:");
            unchecked
            {
                int maxInt = int.MaxValue;
                Console.WriteLine($"Max int: {maxInt}");
                maxInt++; // Нет исключения, но неправильный результат
                Console.WriteLine($"After increment: {maxInt} (переполнение проигнорировано)");
            }
        }

        CheckedFunction();
        UncheckedFunction();

        Console.WriteLine("\nПрограмма завершена!");
    }
}