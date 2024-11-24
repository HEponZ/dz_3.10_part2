#include "Date.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Date date, date2;
	int choise, days;

	enum MENU {
		EXIT = 0,
		CIN,
		PRINT,
		PLUS_ONE_DAY,
		MINUS_ONE_DAY,
		COMPARE,
		ASSIGN,
		PLUS_DAYS,
		MINUS_DAYS
	};

	cout << "1 - Ввод\n2 - Вывод\n3 - + один день\n4 - - один день\n5 - сравнить\n6 - присвоить\n7 - прибавить дни\n8 - вычесть дни\n0 - EXIT\n";

	do
	{
		cin >> choise;

		switch (choise)
		{
		case CIN:
			cin >> date >> date2;
			break;
		case PRINT:
			cout << date << "\n" << date2 << "\n";
			break;
		case PLUS_ONE_DAY:
			++date;
			break;
		case MINUS_ONE_DAY:
			--date;
			break;
		case COMPARE:
			if (date != date2)
			{
				cout << "Даты не равны\n";
				if (date > date2)
				{
					cout << "Дата 1 больше\n";
				}
				else if (date < date2)
				{
					cout << "Дата 2 больше\n";
				}
			}
			else if (date == date2)
			{
				cout << "Даты равны\n";
			}
			break;
		case ASSIGN:
			date = date2;
			break;
		case PLUS_DAYS:
			cout << "Введите кол-во дней\n";
			cin >> days;
			date += days;
			break;
		case MINUS_DAYS:
			cout << "Введите кол-во дней\n";
			cin >> days;
			date -= days;
			break;
		case EXIT:
			break;
		}

	} while (choise != 0);

	return 0;
}