#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

#define $____Come_On____$ ios_base::sync_with_stdio(true); \
cout.tie(nullptr); \
cin.tie(nullptr);

#define ACM_Training main

#define MySoul 1

#define ll long long

#define I cin>>

#define to >>

#define ot <<

#define O cout<<

#define GN <<'\n';

#define GNN O '\n';

#define MS(fairyCat,Value) memset(fairyCat,Value,sizeof(fairyCat))//ȫ������

#define CIN(s,l,r) for(int i=l;i<=r;i++) I s[i]; //Ԫ��֮���ٻ���

#define COUT(s,l,r) for(int i=l;i<=r;i++) O s[i] ot " "; //Ԫ��֮��������

#define FORB(s,l,r) for(int s=l;s<=r;s++) 

#define FORE(s,l,r) for(int s=l;s>=r;s--) 

#define $_Never_give_up_$ return 0;

const ll N = 6, NN(1);

const ll mod(998244353);

typedef ll T[N];

typedef ll TT[NN][NN];

T w;

TT t;

ll O_O{ 0 }, ShowTime{600};

typedef struct Node
{
	ll row, col;
	ll move;
}NODE;

struct Stack
{
	ll Map[N][N];
	ll top;
	NODE PATH[N * N];

}STACK = {
	0,0,0,0,0,0,
	0,1,1,1,0,0,
	0,1,0,1,1,0,
	0,1,1,1,0,0,
	0,0,1,1,1,0,
	0,0,0,0,0,0,
	-1
},COPY=STACK;

NODE MinPath[N*N];
ll MIN = 1e9;
ll CASE;
bool isShow{ 0 } ;

void printMap(int sign=0)
{
	system("cls");

	printf("������������������������������������������������������������������\n");
	printf("		     ��������ܰС��ʾ��\n\n");
	printf("(1) ͨ������ͨ�У�   ");
	printf("(0) ǽ�ڣ�����ͨ�У�   ");
	printf("(*) �յ�   ");
	printf("(@) С����\n\n");
	
	printf("		  ��С����%lld,%lld��ʵ���ͼ��\n\n", STACK.PATH[STACK.top].row, STACK.PATH[STACK.top].col);

	printf("		 ����Ŀ�꣺�����յ� * (4,4)\n\n");

	FORB(i, 0, N-1)
	{
		FORB(j, 0, N - 1)
		{
			if (!j) O "		       ";
			if (i == STACK.PATH[STACK.top].row && j == STACK.PATH[STACK.top].col)
				printf("@ ");
			else if (i == 4 && j == 4)
				printf("* ");
			else
				printf("%lld ", STACK.Map[i][j]);
		}
			
		GNN
	}

	printf("\n		��������˳ʱ������С���\n");

	if(sign==1)
		printf("\n		������,����֮·��Ϊͨ����������");

	if(sign==2)
		printf("\n		ǰ����,����֮·��Ϊǽ�ڡ�������");

	printf("\n������������������������������������������������������������������\n\n");

	system("pause");
}

void printPath(bool sign=false)
{

	ll Start(0);
	ll NUM=++CASE;
loop:

	if (sign)
	{
		system("cls");
		printf("�ɹ��ҵ���%lld������·��(%lld)\n\n", NUM, STACK.top);
	}
	FORB(i, 0, Start)
	{
		printf("(%lld,%lld)", STACK.PATH[i].row, STACK.PATH[i].col);

		if (i != STACK.top)
			printf("->");
		else
			printf(" ");
	}

	GNN
	GNN

	FORB(i, 0, N - 1)
	{
		FORB(j, 0, N - 1)
		{
			if (i == STACK.PATH[Start].row && j == STACK.PATH[Start].col)
				printf("@ ");
			else if (i == 4 && j == 4)
				printf("* ");
			else
				printf("%lld ", COPY.Map[i][j]);
		}

		GNN
	}


	printf("\n��ʾ�С��� ��ǰλ�ã�%lld,%lld��\n\n", STACK.PATH[Start].row, STACK.PATH[Start].col);


	if (Start < STACK.top)
	{
		Sleep(ShowTime);
		Start++;
		goto loop;

	}

	GNN

	if(sign) 
		system("pause");


	if (STACK.top + 1 < MIN)
	{
		MIN = STACK.top;
		FORB(i, 0, MIN)
		{
			MinPath[i].row = STACK.PATH[i].row;
			MinPath[i].col = STACK.PATH[i].col;
			MinPath[i].move = STACK.PATH[i].move;
		}
	}
}

bool StackPath(NODE &Start,NODE &End)
{
	bool mask;

	//��ʼ��
	STACK.top++;
	STACK.PATH[STACK.top].row = Start.row;
	STACK.PATH[STACK.top].col = Start.col;
	STACK.PATH[STACK.top].move = EOF;
	STACK.Map[STACK.PATH[STACK.top].row][STACK.PATH[STACK.top].col] = 0;

	if(isShow)
		printMap();

 	while (STACK.top != EOF)
	{
		ll newRow{ STACK.PATH[STACK.top].row };
		ll newCol{ STACK.PATH[STACK.top].col };
		ll newMove{ STACK.PATH[STACK.top].move };

		if (newRow == End.row && newCol == End.col)
		{
			//���·��
			printPath(true);

			mask = true;

			STACK.Map[STACK.PATH[STACK.top].row][STACK.PATH[STACK.top].col] = 1;
			STACK.top--;

			newRow = STACK.PATH[STACK.top].row;
			newCol = STACK.PATH[STACK.top].col;
			newMove = STACK.PATH[STACK.top].move;

			if(isShow)
				printMap(true);
		}

		ll tempRow, tempCol;

		tempRow = newRow;
		tempCol = newCol;

		bool find{false};
		
		while (newMove < 4 && !find)
		{
			newMove++;
			switch (newMove)
			{
				//top
				case 0: 
					tempRow = newRow - 1; 
					tempCol = newCol;
					break;

				//right
				case 1:
					tempRow = newRow;
					tempCol = newCol+1;
					break;

				//bottom
				case 2:
					tempRow = newRow + 1;
					tempCol = newCol;
					break;

				//left
				case 3:
					tempRow = newRow;
					tempCol = newCol-1;
					break;
			}

			if (STACK.Map[tempRow][tempCol])
				find = true;
		}

		if (find)
		{
			STACK.PATH[STACK.top].move = newMove;

			STACK.top++;
			STACK.PATH[STACK.top].row = tempRow;
			STACK.PATH[STACK.top].col = tempCol;
			STACK.PATH[STACK.top].move = EOF;
			STACK.Map[STACK.PATH[STACK.top].row][STACK.PATH[STACK.top].col] = 0;

			if(isShow)
				printMap(2);

		}
		else
		{
			STACK.Map[STACK.PATH[STACK.top].row][STACK.PATH[STACK.top].col] = 1;
			STACK.top--;

			if(isShow&& STACK.top>=0)
				printMap(1);
		}
	}
	return mask;
}

bool preface()
{
	auto preface = [=]() mutable->bool
	{
	loop:
			system("cls");
			printf("�������������� �� ӭ �� �� �� �� �� ԰ ! ��������������\n\n");
			printf("��������������  �� �� �� �� �� �� ��  1 ��������������\n\n");
			printf("��������������  �� �� �� �� �� �� ��  2 ��������������\n\n");
			printf("��������������  �� �� �� �� �� �� ��  3 ��������������\n\n");

			printf("		    	  ");
			switch (_getch())
			{
				case '1':
					return true;
				case '2':
					return false;
				case '3':
					system("cls");
					O "���ߣ�lyq\n" GN
					O "�ɰࣺ��ʦ�ƿ��߰�\n" GN
					O "��ǰ�ȼ��������㼶\n" GN
					O "����ʱ�䣺2023-9-27 22:45\n" GN
					system("pause");
					goto loop;
			}

			system("cls");

			O "������������������\n\n";
			Sleep(1000);
			system("cls");

			goto loop;
	};

	return preface();
}

auto It_only_takes_a_second_to_solve_this_problem()->void
{
	system("color 0a");

	if (preface())
		isShow = true;
	else isShow = false;

	//���(1,1) �յ�(4,4) 
	NODE Start = { 1,1,0 }, End = { 4, 4, 0};

	system("cls");

	printf("С�������Թ����ߵ��յ��ȫ������·�� ~ \n\n");

	if (StackPath(Start,End))
	{
		if(isShow)
			system("cls");

		ll Start{0};
	loop:
		system("cls");
		printf("���е����·�������ȣ�%lld��\n\n", MIN);

		FORB(i, 0, Start)
		{
			printf("(%lld,%lld)", MinPath[i].row, MinPath[i].col);
			if (i != Start) printf("->");
			else O " ";
		}
		GNN


		printf("\n��ʾ�С���\n\n");

		FORB(i, 0, N - 1)
		{
			FORB(j, 0, N - 1)
			{
				if (i == MinPath[Start].row && j == MinPath[Start].col)
					printf("@ ");
				else if (i == 4 && j == 4)
					printf("* ");
				else
					printf("%lld ", COPY.Map[i][j]);
			}

			GNN
		}

		GNN
		if (Start < MIN)
		{
			Sleep(ShowTime);
			Start++;
			goto loop;

		}

	}
	system("pause");
}

#undef O;
struct
{
	/*
		��ོ��O.o��
		O.O �������
		o.o ���Ǽ��
		O.o ������ོ��
		o.O ���Ǽ�����
	*/

	bool o;

}O;

auto luckFairyCatLab(ll fairyCatSnacks = 0)->void
{
	if (fairyCatSnacks++)
		I fairyCatSnacks;

	while (fairyCatSnacks--)
		It_only_takes_a_second_to_solve_this_problem();
}
auto  ACM_Training() ->int
{
	$____Come_On____$

		luckFairyCatLab(O_O >> O.o); //��귨��

	$_Never_give_up_$
}