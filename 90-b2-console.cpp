/*1551445 ͯ���� �������ѧ�뼼��1��*/
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;
void four(int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int rows, cols;
	int rout[81][2];
	init(&rows, &cols, p, 5);
	const int *const row_ptr = &rows;
	const int *const col_ptr = &cols;
	print(p, *row_ptr, *col_ptr, rout);
	cout << endl;
	cout << "���س�����ʾͼ��...";
	while (_getch() != '\r')
		;
	system("cls");
	print_console1(*row_ptr, *col_ptr, p);

}
void five(int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int rows, cols;
	int rout[81][2];
	init(&rows, &cols, p, 5);
	const int *const row_ptr = &rows;
	const int *const col_ptr = &cols;
	print(p, *row_ptr, *col_ptr, rout);
	cout << endl;
	cout << "���س�����ʾͼ��...";
	while (_getch() != '\r')
		;
	system("cls");
	print_console2(*row_ptr, *col_ptr, p);
	end();
}

void six(int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //ȡ��׼�����豸��Ӧ�ľ��
	int rows, cols;
	int rout[81][2];
	char begin[2], final[2];
	init(&rows, &cols, p, 100);//��ʼ�� 100�������ɰٷ�֮��ʮ����
	const int *const row_ptr = &rows;
	const int *const col_ptr = &cols;
	print_console2(*row_ptr, *col_ptr, p);//��ӡ�зָ��ߵ�����
	int X = 0, Y = 0;
	getxy(hout, X, Y);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	move_img(p, rout, begin, final, *row_ptr, *col_ptr, Y);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	gotoxy(hout, 0, Y + 1);
	setcursor(hout, CURSOR_VISIBLE_NORMAL);
	end();
}

void seven(int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	int rows, cols, X, Y;//X,Y���ڴ�Ŵ�ӡ�����̺�Ĺ�����꣬�����ӡ������
	char begin[2], final[2];//��������������������յ�����
	int next[3], rout[81][2];//next���ڴ����һ�ֽ�����ֵ������Ϣ��rout���ڴ��Ѱ����·�ϵĵ�����
	init(&rows, &cols, p, 5);//��ʼ���ڲ�����+�������5����
	const int *row_ptr = &rows;//��ֹ��С�Ķ�cols rows�۸�
	const int *col_ptr = &cols;
	int score = 0, eve_score = 0;//�ܵ÷֣�ÿ�ε÷�
	int leap = 0;
	print_console2(rows, cols, p);//��ӡ����
	getxy(hout, X, Y);
	print_console3(rows, cols, next, 0);//��ӡ�÷֣�Ԥʾ��
	for (int i = 0; i < 3; i++)
		next[i] = rand() % 7;
	print_console3(rows, cols, next, 4);
	while (1)
	{
		int num_pace = 0;
		bgn_fnl_mouse(begin, final, rows, cols, Y, p);//���������յ������
		int begin_value = p[begin[0] - 'A'][begin[1] - '1'];//�����ֵ�ȴ�������Ѱ��·���ٸ����յ㣬��ֹѰ·������ֵ�����ƻ�
		if (search(p, rout, begin[1] - '1', begin[0] - 'A', final[1] - '1', final[0] - 'A', *row_ptr, *col_ptr, &num_pace))
		{//search����1����Ѱ��·������ûѰ��·���������Ƿ�Ѱ��·����������еĲ����Ѿ�ִ�У�Ҳ����·���ϵĵ��ֵ�ѱ��ı�
			reset_array(p, col_ptr, row_ptr);//search�ǰ�̽�����ĵ�ȫ�������-1Ҫ�������������ʼ��
			p[final[0] - 'A'][final[1] - '1'] = begin_value;
			show_rout(rout, begin_value);//�Ѵ���rout���·���ϵĵ����갴˳�򣨼���ʱ����ʾ�����ƶ�·��
			for (int i = 0; i < 81; i++)
				for (int j = 0; j < 2; j++)
					rout[i][j] = -1;//��մ洢��·����¼
			judge(p, final, *row_ptr, *col_ptr, &score, &eve_score);//�ж��ܷ�÷֣����÷֣�����Ϊ0�������ڲ�����
			if (eve_score == 0)
			{
				update_array(p, next, col_ptr, row_ptr, 1);//��next�д��ֵ�������"����"�пհ׵�λ�ã�Ҳ���Ǹ��ڲ�����p
				for (int i = 0; i < 3; i++)
					next[i] = rand() % 7+1;////
				print_console3(rows, cols, next, 4);//4���ڿ��ƴ�ӡλ��
			}
			else
			{/*�������̣��Ѹ���ȥ���λ�ô�ӡ�ո�*/
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						if (p[i][j] == 0)
							showstr(hout, 2 + j * 4, (i + 1) * 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
				setcolor(hout, COLOR_HWHITE, COLOR_BLACK);
				gotoxy(hout, 4 * cols + 12, 2);
				cout << score;
			}
		}
		else//���û���ҵ�·
		{
			p[begin[0] - 'A'][begin[1] - '1']=begin_value;
			showstr(hout, 2 +(begin[1] - '1') * 4, (begin[0] - 'A' + 1) * 2, "��", begin_value + 1, COLOR_HWHITE);
			reset_array(p, col_ptr, row_ptr);
			continue;
		}
		if (game_over(p, row_ptr, col_ptr,Y-1))
			break;
	}
	end();
}