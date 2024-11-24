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

	cout << "1 - ����\n2 - �����\n3 - + ���� ����\n4 - - ���� ����\n5 - ��������\n6 - ���������\n7 - ��������� ���\n8 - ������� ���\n0 - EXIT\n";

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
				cout << "���� �� �����\n";
				if (date > date2)
				{
					cout << "���� 1 ������\n";
				}
				else if (date < date2)
				{
					cout << "���� 2 ������\n";
				}
			}
			else if (date == date2)
			{
				cout << "���� �����\n";
			}
			break;
		case ASSIGN:
			date = date2;
			break;
		case PLUS_DAYS:
			cout << "������� ���-�� ����\n";
			cin >> days;
			date += days;
			break;
		case MINUS_DAYS:
			cout << "������� ���-�� ����\n";
			cin >> days;
			date -= days;
			break;
		case EXIT:
			break;
		}

	} while (choise != 0);

	return 0;
}