/*1551445 ͯ���� �������ѧ�뼼��1��*/
#include"90-b2.h"
#include"cmd_console_tools.h"
using namespace std;
void one(int(*p)[10])//��ӡ�����
{
	int rows, cols;
	int rout[81][2];
	init(&rows, &cols, p, 5);
	print(p, rows, cols, rout);
	end();
}

void two(int(*p)[10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int rows, cols;
	int balls;//�ڻ�
	char begin[2];//������ begin[0]  A-I  begin[1] 1-9
	char final[2];//����յ� 
	int *next = &balls;
	int rout[81][2];//���·��
	int num_pace = 0;
	init(&rows, &cols, p, 100);//��ʼ��+���������
	print(p, rows, cols, rout);//��ӡ��ʼ���飨��������ɫ��
	next_balls(next);//*next��ż������ֵ����ֵ����û��ȷ���ֲ�λ��
	input_position(p, rows, cols, begin, final);//Ҫ��������ʼ����ֹλ�ã�ͬʱ������ֱ����begin��final��������
	int begin_value = p[begin[0] - 'A'][begin[1] - '1'];//������ֵ���ȴ���������Ϊ��search�лᷢ���ı䡣
	if (search(p, rout, begin[1] - '1', begin[0] - 'A', final[1] - '1', final[0] - 'A', rows, cols, &num_pace))
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (p[i][j] == -1)
					p[i][j] = 0;//search�ǰ�̽�����ĵ�ȫ�������-1Ҫ�������������ʼ��
		p[begin[0] - 'A'][begin[1] - '1'] = begin_value;
		print_rout(rows, cols, rout, p);
	}
	else
		cout << "\nno way";
	end();
}

void three(int p[][10])
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setconsoleborder(hout, 60, 60, 200);//���ô��ڴ�С
	int rows, cols, score = 0, eve_score = 0, num_pace;
	char begin[2], final[2];
	int next[3], rout[81][2];
	init(&rows, &cols, p, 5);//��ʼ��+���������
	const int * const row_ptr = &rows;
	const int * const col_ptr = &cols;
	print(p, *row_ptr, *col_ptr, rout);
	next_balls(next);
	int x, y;
	while (1)
	{
		for (int i = 0; i < 81; i++)
			for (int j = 0; j < 2; j++)
				rout[i][j] = -1;//ÿ��Ѱ·����ԭ�ȴ��·���ϵ���������

		num_pace = 0;//ÿ�ζ���Ҫ����
		input_position(p, *row_ptr, *col_ptr, begin, final);
		int begin_value = p[begin[0] - 'A'][begin[1] - '1'];
		if (search(p, rout, begin[1] - '1', begin[0] - 'A', final[1] - '1', final[0] - 'A', *row_ptr, *col_ptr, &num_pace))
		{
			reset_array(p, col_ptr, row_ptr);//search�ǰ�̽�����ĵ�ȫ�������-1Ҫ�������������ʼ��
			p[final[0] - 'A'][final[1] - '1'] = begin_value;
		}
		else
		{
			cout << "\n���ε÷֣�" << 0 << " �ܹ��÷֣�" << score << endl;
			reset_array(p, col_ptr, row_ptr);
			print(p, *row_ptr, *col_ptr, rout);
			cout << "\n�������������ɫ�ֱ��ǣ� " << next[0] << "  " << next[1] << "  " << next[2];
			continue;
		}
		judge(p, final, *row_ptr, *col_ptr, &score, &eve_score);
		if (!eve_score)
			update_array(p, next, col_ptr, row_ptr, 0);
		cout << "\n���ε÷֣�" << eve_score << " �ܹ��÷֣�" << score << endl;
		print(p, *row_ptr, *col_ptr, rout);
		if (eve_score)
			cout << "\n�������������ɫ�ֱ��ǣ� " << next[0] << "  " << next[1] << "  " << next[2];
		else
			next_balls(next);
		getxy(hout, x, y);
		if (game_over(p, row_ptr, col_ptr,y-1))
			break;
	}
	end();
}