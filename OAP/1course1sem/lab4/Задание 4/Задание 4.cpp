#include <windows.h>
#include <iostream>
void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char name[60];
	puts("Как вас зовут? ");
	gets_s(name);
	printf("Привет, %s\n", name);
	puts("Меня зовут Яндекс Алиса. \nКак прошел ваш день?");
	gets_s(name);
	puts("Спасибо большое за ответ, удачного дня :)");
}
