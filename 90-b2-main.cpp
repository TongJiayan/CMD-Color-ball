/*1551445 ͯ���� �������ѧ�뼼��1��*/
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(unsigned int(time(0)));
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	int ball[10][10];
	char choice = '1';
	while (choice != '0')
	{
		system("cls");
		setfontsize(hout, L"������", 15);
		print_menu();
		cout << "������[0-7] ";
		cin >> choice;
		if (!(choice >= '0'&&choice <= '7'))
			continue;
		switch (choice)
		{
		case '1':
			one(ball);
			break;
		case '2':
			two(ball);
			break;
		case '3':
			three(ball);
			break;
		case '4':
			four(ball);
			break;
		case '5':
			five(ball);
			break;
		case '6':
			six(ball);
			break;
		case '7':
			seven(ball);
			break;
		default:break;
		}
	}
	return 0;
}