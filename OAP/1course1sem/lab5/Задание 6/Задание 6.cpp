#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	puts("Здарова, Саня, пойдешь гулять?(1-да, 2-нет)");
	std::cin >> k;
	switch (k)
	{
	case 1: {
		puts("Окей куда (1-Парк, 2-Площадь, 3-Киберклуб)");
		std::cin >> (k);
		switch (k)
		{
		case 1: puts("Не скучно будет? А ладно погнали, подходи тогда к 18:00."); break;
		case 2: puts("Ну норм, тогда подходи к 18:00."); break;
		case 3: puts("Оооо погнали, жду в 18:00.");
			break;
		}
		break;
	}
	case 2: puts("Все стобой ясно, ладно давай"); break;
	default: puts("Некорректный вариант"); break;
	}
	return 0;
}