/*1551445 ͯ���� �������ѧ�뼼��1��*/
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;

/*��ӡ�˵�*/
void print_menu()
{
	cout << "-------------------------------------" << endl;
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.9*9�Ŀ�ܣ�50�������һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "--------------------------------------" << endl;
}

/*��ʼ�����飬�����������������Լ��ڲ���ֵ*/
void init(int *rows, int *cols, int(*p)[10], int n)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	cout << "������������7-9��";
	cin >> *rows;
	check_rows_cols(rows);//��rows�����жϣ���������ʣ�����Ҫ�����룬ͬʱ��������������

	cout << "������������7-9��";
	cin >> *cols;
	check_rows_cols(cols);

	cout << "\n��ʼ����:" << endl;

	/*��ȫ����ʼ��Ϊ0*/
	int(*q)[10];
	int *w;
	for (q = p; q < p + *rows; q++)
		for (w = *q; w < *q + *cols; w++)
			*w = 0;

	/*�������С������ֲ�*/
	for (int i = 0; i < n && i<(*rows)*(*cols)*0.6;)//n�������ƴ�ӡ5������60%����
	{
		int x = rand() % *cols;
		int y = rand() % *rows;
		if (*(*(p + y) + x) == 0)
		{
			*(*(p + y) + x) = rand() % 7 + 1;
			i++;
		}
	}
}

/*��ӡ�ڲ�����*/
void print(int(*p)[10], int rows, int cols, int(*rout)[2], int leap, int leap_2)//��ӡ�ڲ�����
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  |";
	for (int i = 1; i <= cols; i++)
		cout << setw(3) << i;
	cout << endl;
	cout << "----";
	for (int i = 1; i <= cols; i++)
		cout << "---";
	cout << endl;
	int(*q)[10];
	int *w;
	char c = 65;
	for (q = p; q < p + rows; q++)
	{
		cout << c << setw(2) << "|";
		for (w = *q; w < *q + cols; w++)
		{
			cout << "  ";
			if (leap == 0)//leap=0---��Ӧ�����*���ڲ����飬��ɫ������ʾ��ӦС��
			{
				if (*w != 0)
					setcolor(hout, 7, *w + 7);
				cout << *w;
			}
			else
			{
				int judge = 0;
				for (int num_pace = 0; num_pace < 81; num_pace++)
					if (q - p == rout[num_pace][0] && w - *q == rout[num_pace][1])
					{
						judge = 1;
						if (leap_2 == 0)//leap_2==0��Ӧ��ӡ������ɫ��·��������*����·��  leap_2!=0��Ӧ�ô���ɫ��ɫ�����·��
							cout << '*';
						else
						{
							setcolor(hout, COLOR_HYELLOW, COLOR_HBLUE);
							cout << *w;
						}
						break;
					}
				if (judge == 0)
				{
					setcolor(hout, 0, 7);
					if (leap_2 == 0)
						cout << 0;
					else
						cout << *w;
				}
			}
			setcolor(hout, 0, 7);
		}
		c++;
		cout << endl;
	}
}

/*��ӡ���������End�����ж�*/
void end()
{
	int a, b;
	int &x = a, &y = b;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	cout << "\n��С�������������End����...";
	char End[4];//���������ַ�
	for (int i = 0; i < 3; i++)
		cin >> End[i];
	End[3] = '\0';//����β���������ַ��������
	if (strcmp("End", End))//�Ƚ��ַ���
	{
		cout << "�����������������";
		while (1)
		{
			getxy(hout, x, y);
			gotoxy(hout, 28, y - 1);
			cout << "        ";
			gotoxy(hout, 28, y - 1);
			for (int i = 0; i < 3; i++)
				cin >> End[i];
			End[3] = '\0';
			if (!(strcmp("End", End)))
				break;
		}
	}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	setcursor(hout, CURSOR_VISIBLE_NORMAL);
	setconsoleborder(hout, 80, 21, 21);
	setfontsize(hout, L"������", 15);
}

//���������н��м��  rc��ָ��
void check_rows_cols(int *rc)
{
	int a, b;
	int &x = a;
	int &y = b;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	while (*rc < 7 || *rc>9)
	{
		cout << "�����������������.";
		getxy(hout, x, y);
		gotoxy(hout, 17, y - 1);
		cout << "  ";
		gotoxy(hout, 17, y - 1);
		cin >> *rc;
	}
	cout << endl;
}

/*�����������С�򣬴���ָ��next_ballsָ��ĵ�ַ����ӡ��ʾ*/
void next_balls(int *next_balls)
{
	cout << "\n�������������ɫ�ֱ��ǣ� ";
	for (int i = 0; i < 3; i++)
	{
		next_balls[i] = rand() % 7 + 1;
		cout << next_balls[i] << "��";
	}
}

/*���������յ��������Ϣ A-I,1-9 ���ַ�������ʽ���룬ͬʱ�����жϺϷ���*/
void input_position(int(*p)[10], int rows, int cols, char *begin, char *final)
{
	int n = 0;//���ڿ�������Ϊ������ݻ����յ�����
	char po[2];
	while (n<2)
	{
		if (!n)
			cout << "\n������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ���Ŀ�꣺ ";
		else
			cout << "\n������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ��Ŀ�꣺ ";
		for (int i = 0; i < 2; i++)
			cin >> *(po + i);
		if (*po >= 'a'&&*po <= 'z')
			*po -= 32;
		if (*po >= 'A'&&*po <= 'A' + rows - 1 && *(po + 1) >= '1'&&*(po + 1) <= cols + '0')
		{
			if (*(*(p + *po - 'A') + *(po + 1) - '1') == 0 && n == 0)
				cout << "��ʼλ��Ϊ�գ����������룺";
			else if (*(*(p + *po - 'A') + *(po + 1) - '1') != 0 && n == 1)
				cout << "Ŀ��λ��Ϊ�ǿգ����������룺";
			else
			{
				cout << "����Ϊ" << *po << "��" << *(po + 1) << "��";
				if (!n)
					for (int i = 0; i < 2; i++)
						*(begin + i) = *(po + i);
				else
					for (int i = 0; i < 2; i++)
						*(final + i) = *(po + i);
				n++;
			}
		}
		else
			cout << "�����������������";
	}
}

/*Ѱ·�����߹��ĵ�ȫ���Ž�rout���飬����ֵΪint�ͣ�����Ϊ0����·���ɹ���1����·�ɹ�*/
int search(int(*p)[10], int(*rout)[2], int x1, int y1, int x2, int y2, int rows, int cols, int *num_pace)
{
	if (x1 >= 0 && x1 < cols&&y1 >= 0 && y1 < rows)
	{
		if (x1 == x2&&y1 == y2)
		{
			rout[*num_pace][0] = y1;
			rout[*num_pace][1] = x1;
			(*num_pace)++;
			return 1;
		}
		else
			p[y1][x1] = -1;

		if (p[y1][x1 + 1] == 0)
		{
			search(p, rout, x1 + 1, y1, x2, y2, rows, cols, num_pace);
			if (*num_pace)
			{
				rout[*num_pace][0] = y1;
				rout[*num_pace][1] = x1;
				(*num_pace)++;
				return 1;
			}
		}
		if (p[y1 - 1][x1] == 0)
		{
			search(p, rout, x1, y1 - 1, x2, y2, rows, cols, num_pace);
			if (*num_pace)
			{
				rout[*num_pace][0] = y1;
				rout[*num_pace][1] = x1;
				(*num_pace)++;
				return 1;
			}
		}
		if (p[y1][x1 - 1] == 0)
		{
			search(p, rout, x1 - 1, y1, x2, y2, rows, cols, num_pace);
			if (*num_pace)
			{
				rout[*num_pace][0] = y1;
				rout[*num_pace][1] = x1;
				(*num_pace)++;
				return 1;
			}
		}
		if (p[y1 + 1][x1] == 0)
		{
			search(p, rout, x1, y1 + 1, x2, y2, rows, cols, num_pace);
			if (*num_pace)
			{
				rout[*num_pace][0] = y1;
				rout[*num_pace][1] = x1;
				(*num_pace)++;
				return 1;
			}
		}
		return 0;
	}
	else
		return 0;
}

/*�ж��Ƿ�������Ϸ����������*/
int game_over(int(*p)[10], const int *row_ptr, const int *col_ptr,int Y)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, n = 0;
	for (i = 0; i < *row_ptr; i++)
	{
		for (j = 0; j < *col_ptr; j++)
			if (p[i][j] == 0)
			{
				n++;
				if (n >= 3)
					return 0;//0����û��game over
			}
	}
	gotoxy(hout, 0, Y - 1);
	cout << "game over!";
	return 1;
}

/*���û�е÷֣����λ�ø�ֵ��һ��Ԥ���С������*/
void update_array(int(*p)[10], int next[], const int *col_ptr, const int *row_ptr, int move_img)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i <3;)
	{
		int x = rand() % *col_ptr;
		int y = rand() % *row_ptr;
		if (p[y][x] == 0)
		{
			p[y][x] = next[i];
			if (move_img == 1)
				showstr(hout, 2 + x * 4, y * 2 + 2, "��", p[y][x] + 1, COLOR_HWHITE);
			i++;
		}
	}
}

/*Ѱ·�����У�������̽�����ĵ㶼��ֵΪ-1��Ѱ·�����󣬻ָ�Ϊ0*/
void reset_array(int(*p)[10], const int *col_ptr, const int *row_ptr)
{
	for (int i = 0; i < *row_ptr; i++)
		for (int j = 0; j < *col_ptr; j++)
			if (p[i][j]<0)
				p[i][j] = 0;
}

/*�򵥵����print�������������0+*   ��ֵ+ɫ�飩�µ����*/
void print_rout(int rows, int cols, int(*rout)[2], int(*p)[10])
{
	cout << endl;
	cout << "�ƶ�·����·��*��ʾ����\n";
	print(p, rows, cols, rout, 1);
	cout << endl << endl;
	cout << "�ƶ�·����·����ɫ��ǣ���\n";
	print(p, rows, cols, rout, 1, 1);
}

/*�ж��ܷ�÷֣���¼ÿ�ε÷֣����۵÷֣�����������������ڲ���������*/
void judge(int(*p)[10], char final[2], const int rows, const int cols, int *score, int *eve_score)
{
	int new_chess = p[final[0] - 'A'][final[1] - '1'];
	int x = final[1] - '1', y = final[0] - 'A';
	int i1 = 1, i2 = 1, i3 = 1, i4 = 1, j1 = 1, j2 = 1, j3 = 1, j4 = 1, sum = 0;

	if (x >= 1 && new_chess == p[y][x - 1] || x<cols - 1 && new_chess == p[y][x + 1])
	{
		while (x - i1 >= 0 && p[y][x - i1] == new_chess)
			i1++;
		while (x + j1<cols&&p[y][x + j1] == new_chess)
			j1++;
	}
	if (y >= 1 && p[y - 1][x] == new_chess || y < rows - 1 && p[y + 1][x] == new_chess)
	{
		while (p[y - i2][x] == new_chess && y - i2 >= 0)
			i2++;
		while (p[y + j2][x] == new_chess && y + j2<rows)
			j2++;
	}
	if (x >= 1 && y >= 1 && p[y - 1][x - 1] == new_chess || x < cols - 1 && y < rows - 1 && new_chess == p[y + 1][x + 1])
	{
		while (p[y + i3][x + i3] == new_chess && y + i3<rows && x + i3<cols)
			i3++;
		while (p[y - j3][x - j3] == new_chess &&y - j3 >= 0 && x - j3 >= 0)
			j3++;
	}
	if (x<cols - 1 && y >= 1 && p[y - 1][x + 1] == new_chess || x >= 1 && y < rows - 1 && new_chess == p[y + 1][x - 1])
	{
		while (p[y - i4][x + i4] == new_chess && y - i4 >= 0 && x + i4<cols)
			i4++;
		while (p[y + j4][x - j4] == new_chess && x - j4 >= 0 && y + j4<rows)
			j4++;
	}
	if (i1 + j1 >= 6)
	{
		sum += (i1 + j1 - 1);
		for (int i = x + 1 - i1; i < x + j1; i++)
			p[y][i] = 0;
	}
	if (i2 + j2 >= 6)
	{
		sum += (i2 + j2 - 1);
		for (int i = y - i2 + 1; i < y + j2; i++)
			p[i][x] = 0;
	}
	if (i3 + j3 >= 6)
	{
		sum += (i3 + j3 - 1);
		for (int i = 1 - j3; i < i3; i++)
			p[y + i][x + i] = 0;
	}
	if (i4 + j4 >= 6)
	{
		sum += (i4 + j4 - 1);
		for (int i = 1 - i4; i<j4; i++)
			p[y + i][x - i] = 0;
	}

	if (sum)
	{
		*eve_score = (sum - 1)*(sum - 2);
		*score += (sum - 1)*(sum - 2);
	}
	else
		*eve_score = 0;
}

/*��û�зָ��ߵ�����*/
void print_console1(const int rows, const int cols, int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const int r = rows + 6;
	setconsoleborder(hout, 35, r, 35);
	setfontsize(hout, L"������", 20);
	cout << "��Ļ��" << rows + 6 << "��" << 35 << "��" << endl;
	setcursor(hout, CURSOR_VISIBLE_FULL);
	for (int i = 0; i < cols + 2; i++)
	{
		if (i == 0)
			showstr(hout, 2 * i, 1, "��", COLOR_HWHITE, COLOR_BLACK);
		else if (i == cols + 1)
			showstr(hout, 2 * i, 1, "��", COLOR_HWHITE, COLOR_BLACK);
		else
			showstr(hout, 2 * i, 1, "��", COLOR_HWHITE, COLOR_BLACK);
	}
	for (int i = 0; i <cols + 2; i++)
	{
		if (i == 0)
			showstr(hout, 2 * i, rows + 2, "��", COLOR_HWHITE, COLOR_BLACK);
		else if (i == cols + 1)
			showstr(hout, 2 * i, rows + 2, "��", COLOR_HWHITE, COLOR_BLACK);
		else
			showstr(hout, 2 * i, rows + 2, "��", COLOR_HWHITE, COLOR_BLACK);
	}

	for (int j = 0; j < rows; j++)
	{
		showstr(hout, 0, 2 + j, "��", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 2 * (cols + 1), 2 + j, "��", COLOR_HWHITE, COLOR_BLACK);
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (p[i][j] != 0)
				showstr(hout, 2 * (j + 1), i + 2, "��", p[i][j] + 1, COLOR_HWHITE);
			else
				showstr(hout, 2 * (j + 1), i + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
		}
	cout << endl << endl;
	end();
}

/*���зָ��ߵ�����*/
void print_console2(const int rows, const int cols, int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int r = rows * 2 + 5;
	int c = cols * 2 + 21;
	int bf_c, bf_r;
	getconsoleborder(hout, c, r, bf_c, bf_r);
	int x, y;
	setconsoleborder(hout, c, r, c);
	setfontsize(hout, L"������", 20);
	cout << "��Ļ��" << r << "��" << c << "��" << endl;
	setcursor(hout, CURSOR_VISIBLE_FULL);
	for (int i = 0; i < 2 * rows + 1; i++)
		for (int j = 0; j < 2 * cols + 1; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					showstr(hout, 0, 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else if (j == 2 * cols)
					showstr(hout, j * 2, 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else if (j == 2 * cols - 1)
					showstr(hout, j * 2, 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else
				{
					if (j % 2 == 1)
						showstr(hout, 2 * j, 1, "��", COLOR_HWHITE, COLOR_BLACK);
					else
						showstr(hout, 2 * j, 1, "��", COLOR_HWHITE, COLOR_BLACK);
				}
			}
			else if (i == 2 * rows)
			{
				if (j == 0)
					showstr(hout, 0, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else if (j == 2 * cols)
					showstr(hout, j * 2, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else if (j == 2 * cols - 1)
					showstr(hout, j * 2, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else
				{
					if (j % 2 == 1)
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
					else
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				}
			}
			else
			{
				if (j == 0)
					if (i % 2 == 1)
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
					else
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else if (j == cols * 2)
					if (i % 2 == 1)
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
					else
						showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
				else
					if (i % 2 == 1)
					{
						if (j % 2 == 1)
							showstr(hout, 2 * j, i + 1, "  ", COLOR_HWHITE, COLOR_BLACK);
						else
							showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
					}
					else
					{
						if (j % 2 == 1)
							showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
						else if (j != 0 && j != cols * 2)
							showstr(hout, 2 * j, i + 1, "��", COLOR_HWHITE, COLOR_BLACK);
					}
			}
			getxy(hout, x, y);
		}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (p[i][j] != 0)
				showstr(hout, 2 + j * 4, (i + 1) * 2, "��", p[i][j] + 1, COLOR_HWHITE);
	gotoxy(hout, 0, y + 1);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
}

/*���÷�����+����Ԥ��*/
void print_console3(const int rows, const int cols, int next[], int leap)//leap=4���Ҫ��ӡ��//leap=8��ӡͳ�ƽ��
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, 4 * cols + 4, 1 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 2 * cols + 3; i<2 * cols + 8; i++)
		showstr(hout, 2 * i, 1 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * cols + 16, 1 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * cols + 4, 2 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	if (leap == 0)
	{
		showstr(hout, 4 * cols + 6, 2, "�÷֣�", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 4 * cols + 12, 2, "0   ", COLOR_HWHITE, COLOR_HWHITE);
	}
	else if(leap=4)
	{
		for (int i = 0; i < 3; i++)
		{
			showstr(hout, 2 * (2 * cols + 3 + 2 * i),6, "��", next[i] + 1, COLOR_HWHITE);
			showstr(hout, 2 * (2 * cols + 3 + 2 * i) + 2, 6, "��", COLOR_HWHITE, COLOR_BLACK);
		}
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			showstr(hout, 4 * cols + 6, 10 + i, "��", 1, COLOR_HWHITE);
		}
	}

	showstr(hout, 4 * cols + 16, 2 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * cols + 4, 3 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 2 * cols + 3; i<2 * cols + 8; i++)
		showstr(hout, 2 * i, 3 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * cols + 16, 3 + leap, "��", COLOR_HWHITE, COLOR_BLACK);
}

/*��ȡ����յ㣬����������begin final  */
void bgn_fnl_mouse(char begin[2], char final[2], int rows, int cols, int Y, int p[][10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	int loop = 1;
	int click_begin = 0;
	enable_mouse(hin);
	int action, x, y;
	setcursor(hout, CURSOR_INVISIBLE);
	while (loop)
	{
		action = read_mouse(hin, x, y);//��ȡ���Ķ�����λ��
		gotoxy(hout, 0, Y);
		setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
		int y_i = (y - 1) / 2;//0-rows-1
		int x_j = x / 4;//0-cols-1
		if ((y - 1) / 2 + 1 > 0 && (y - 1) / 2 + 1 <= rows && (x / 4 + 1) > 0 && (x / 4 + 1) <= cols)
		{
			cout << "[��ǰ����]" << char(y_i + 'A') << "��" << x_j + 1 << "��";
			switch (action)
			{
			case MOUSE_RIGHT_BUTTON_CLICK:
				end();
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				if (click_begin != -1 && p[y_i][x_j] != 0)
				{
					if (click_begin)
						showstr(hout, 2 + (begin[1] - '1') * 4, (begin[0] - 'A') * 2 + 2, "��", p[begin[0] - 'A'][begin[1] - '1'] + 1, COLOR_HWHITE);
					begin[0] = char(y_i + 'A');
					begin[1] = char(x_j + '1');
					showstr(hout, 2 + x_j * 4, y_i * 2 + 2, "��", p[y_i][x_j] + 1, COLOR_HWHITE);
					click_begin++;
					break;
				}
				else if (click_begin >0 && p[y_i][x_j] == 0)//
				{
					final[0] = char(y_i + 'A');
					final[1] = char(x_j + '1');
					loop = 0;
					break;
				}
			
			}
		}
	}
}

/*��֪�����յ㣬����search�����ж��ܲ����ҵ�·������ҵ�·������С����ƶ����������ӡ��ʾ����������������*/
void move_img(int p[][10], int rout[][2], char begin[2], char final[2], int rows, int cols, int Y)///�������Ҫ��rows,cols�����޸ģ������;Ϳ����ˣ�����Ҫ��ָ��
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int begin_value = p[begin[0] - 'A'][begin[1] - '1'];
	int num_pace;
	while (1)
	{
		num_pace = 0;
		for (int i = 0; i < 81; i++)
			for (int j = 0; j < 2; j++)
				rout[i][j] = -1;
		bgn_fnl_mouse(begin, final, rows, cols, Y, p);//�������յ㸳ֵ1-cols,A-ROWS
		int begin_value = p[begin[0] - 'A'][begin[1] - '1'];
		if (search(p, rout, begin[1] - '1', begin[0] - 'A', final[1] - '1', final[0] - 'A', rows, cols, &num_pace))
		{
			reset_array(p, &cols, &rows);
			show_rout(rout, begin_value);
			break;
		}
		else
		{
			reset_array(p, &cols, &rows);
			cout << "�����޷���" << begin[0] << begin[1] << "ת�Ƶ�" << final[0] << final[1];
			continue;
		}
	}
}

void show_rout(int rout[][2], int begin_value)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 81;
	for (; i > 0; i--)
		if (rout[i][0] >= 0)//??Ϊʲô��!=-1�������в�ͨ���������ײ
			break;
	for (int k = i - 1; k >= 0; k--)//rout[][0]��i 0-(rows-1)!  rout[][1]��j 0-(cols-1)
	{
		if (k != 0)
			showstr(hout, 2 + rout[k][1] * 4, (rout[k][0] + 1) * 2, "��", begin_value + 1, COLOR_HWHITE);
		else
			showstr(hout, 2 + rout[k][1] * 4, (rout[k][0] + 1) * 2, "��", begin_value + 1, COLOR_HWHITE);
		showstr(hout, 2 + rout[k + 1][1] * 4, (rout[k + 1][0] + 1) * 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
		Sleep(100);
	}
}

