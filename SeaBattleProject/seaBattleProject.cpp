#include "seaBattleProject.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

void Create2D(char*** arr, int rows, int cols)
{
	*arr = new char* [rows];
	for (int i = 0; i < rows; i++)
		(*arr)[i] = new char[cols];
}

int convertCharToInt(char c)
{
	return c - 'a';
}

void Show2D(char** arr, int rows, int cols)
{
	cout << "\n\t   1 2 3 4 5 6 7 8 9 10 \n";
	const char str[] = { '=', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '=' };
	const char* ch = &str[0];
	for (int i = 0; i < rows; i++)
	{
		cout << "\t" << *ch;
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
		ch++;
	}
}

void Show2D2Boards(char** arr, char** arr1, int rows, int cols, string name)
{
	cout << "\n\t" << name << ": ����������� �������� \t\t" << name << ": ����� �� ���������� \n";
	cout << "\n\t   1 2 3 4 5 6 7 8 9 10 \t\t   1 2 3 4 5 6 7 8 9 10\n";
	const char str[] = { '=', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '=' };

	const char* ch = &str[0];
	for (int i = 0; i < rows; i++)
	{
		cout << "\t" << *ch;
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\t\t";
		cout << *ch;
		for (int j = 0; j < cols; j++)
		{
			cout << arr1[i][j] << " ";
		}
		cout << endl;
		ch++;
	}
}

void Init2D(char** arr, int rows, int cols, int who, string name)
{
	int amountOfShips = 20;
	char coord = '�';
	int ro = -1, co = -1;

	for (int i = 0; i < rows; i++)
	{
		arr[i][0] = '|';
		for (int j = 1; j < cols - 1; j++)
		{
			arr[i][j] = '-';
			if (i == 0 || i == cols - 1)
			{
				arr[i][j] = '=';
			}
		}
		arr[i][cols - 1] = '|';
	}

	if (who > 0)
	{
		for (int i = 0; i <= amountOfShips; i++)
		{
			cout << "\n\t" << name << ", ���������� ���� �������, ��� ����� ������� ���������� (x,y) ��-��������: x(a-j), y(1-10)\n\n";
			cout << "\t��������, f4  Enter, � ��� 20 ���������, �� ���: \n\n"
				<< "\t1 �� - 4-� ��������\n"
				<< "\t2 �� - 3-� ��������\n"
				<< "\t3 �� - 2-� ��������\n"
				<< "\t4 �� - 1- ��������, �� ���� ���� ������ ��� ������������, ��� ������ ������ ��� ������������ � ��� ����� \n";

			Show2D(arr, rows, cols);
			if (i == amountOfShips) continue;
			cin >> coord >> co;
			while (coord < 'a' || coord > 'j' || co < 1 || co > 10)
			{
				cout << "\n\t�������� ������, ������� ���������� ��������: ";
				cin >> coord >> co;
			}
			ro = convertCharToInt(coord) + 1;
			arr[ro][co] = '1';
			system("cls");
		}
		cout << "\n\t�� ��������� ����������� ��������";
		Sleep(3200);
	}
}

void targ(char** arr, int rows, int cols, int& x, int& y, int show1)
{
	const char str[] = { '=', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '=' };
	int kind4x = 0; // �������� ��������� ��������
	int kind3x = 0;
	int kind2x = 0;
	int kind1x = 0;
	int size[] = { 1, 2, 3, 4 }; // �� ������� ������� ��� ������ ����� ����
	int precedingX = 11;  // ���������� ����� ��� ���
	int precedingY = 11;  // ���������� ����� ��� ���
	int compX = 11; // develop ����������� ����
	int compY = 11;
	char IsDidX = 'y'; // ���������� ��������� ��� ���
	char IsDidY = 'y';   // ���������� ��������� ��� ���
	char IscurrentFoundShip = 'n';
	int currentFoundShip[4][2]{}; // ����� ������� ����� �������� �� ������

	if (show1 == 0)
	{
		if (IsDidX == 'y' && IsDidY == 'y')
		{
			do
			{
				compX = rand() % 10 + 1;
				compY = rand() % 10 + 1;
			} while (arr[compX][compY] != '-');

			if ((IsDidX == 'y' && IsDidY == 'y') && (arr[compX][compY] == '-'))
			{
				x = compX;
				y = compY;
			}
		}
	}
	else if (show1 == 1)
	{
		cout << "\n\t����: " << str[x] << y << endl;
		Sleep(1000);
	}

}

void Init2DComp(char** arr, int rows, int cols)
{
	int a;
	int st;  // ����� ������ ��� �������
	int column;  // ����� ������� ��� �������
	int rang[]{ 4, 3, 2, 1 }; // �������� ����������� �������
	int kindsAmount = 4;   // ����� ���������� ����� ��������
	int shipsAmount[]{ 1, 2, 3, 4 }; // ���������� �������� ������� ����
	int shipsAmount_1;
	int size; // ������� ������ ��������
	int flag;
	int amount;

	for (int i = 0; i < rows; i++)
	{
		arr[i][0] = '|';
		for (int j = 1; j < cols - 1; j++)
		{
			arr[i][j] = '-';
			if (i == 0 || i == cols - 1)
			{
				arr[i][j] = '=';
			}
		}
		arr[i][cols - 1] = '|';
	}

	shipsAmount_1 = shipsAmount[0];  // ������������� ���������� �������� ��� ������� ����: 1
	size = rang[0];           // ������������� ���������� ����� ��� ������� ����: 4 

	for (int n = 0; n < kindsAmount; n++)     // ���� �� ����� ��������
	{
		amount = 0;
		while (amount < shipsAmount_1)  // ���� �� ���������� �������� ������ ����
		{
			flag = 0;
			a = rand() % 2;  // ��������� ������������ �������: ������������ ��� ��������������
			if (a == 0)              // ���� ������ �������������� ������������ �������
			{
				st = rand() % (rows - 2) + 1; // �������� ������ ������� ������� �� �����������
				column = rand() % ((cols - 1) - size) + 1; // �������� ������ ������� ������� �� ���������

				for (int i = st - 1; i < st + 2; i++) // ��������� ��� ����� ��������� � 
				{                                        //������� ��� ������ ��������
					for (int j = column - 1; j < (column - 1) + size + 2; j++)
					{
						if (arr[i][j] == '1')
							flag = 1;
					}
				}

				if (flag == 0)
				{
					amount++;
					for (int i = 0; i < size; i++) // ������ ������� ������������ �����������
					{
						arr[st][column] = '1';
						column++;
					}
				}
			}
			else if (a == 1)          // ���� ������ ������������ ������������ �������
			{
				st = rand() % ((rows - 1) - size) + 1; // �������� ������ ������� �������
				column = rand() % (cols - 2) + 1; // �������� ������ ������� ������� 

				for (int i = st - 1; i < (st - 1) + size + 2; i++)  // ��������� ��� ����� ��������� � 
				{                                                 //������� ��� ������ ��������
					for (int j = column - 1; j < column + 2; j++)
					{
						if (arr[i][j] == '1')
							flag = 1;
					}
				}
				if (flag == 0)
				{
					amount++;
					for (int i = 0; i < size; i++) // ������ ������� ������������ �����������
					{
						arr[st][column] = '1';
						st++;
					}
				}
			}
		}
		size--; // ��������� ���������� ����� ��� ��������, �� ���� ��������� � ���������� ����
		shipsAmount_1++; // ����������� ���������� ��������
	}
	Show2D(arr, rows, cols);
}

void Clean2D(char** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

void compFoo()
{
	const int rows = 12;
	const int cols = 12;
	string player1, comp;
	char first[] = { '0', '1' };
	char** pl1ships;
	char** pl2ships;
	char** fire1;
	char** fire2;
	char target = '�';
	int x = 11;
	int y = 11;
	int whoseMove = 3;
	int amountOfHits1 = 0;
	int amountOfHits2 = 0;


	Create2D(&pl1ships, rows, cols);
	Create2D(&pl2ships, rows, cols);

	Create2D(&fire1, rows, cols);
	Create2D(&fire2, rows, cols);

	system("cls");

	cout << "\n\t���� ���: " << endl;
	cin >> player1;
	comp = "����";
	cout << "\n\t� � ���� " << endl;

	Init2D(fire1, rows, cols, 0, player1);
	Init2D(fire2, rows, cols, 0, comp);

	Init2D(pl1ships, rows, cols, 1, player1);
	system("cls");

	Init2DComp(pl2ships, rows, cols);
	system("cls");

	random_shuffle(begin(first), end(first));
	if (first[0] == '0')
	{
		system("cls");
		cout << "\n\n\t � ���������� ���������� ���� ������ ��������: " << player1
			<< "\n\n\t������� ���������� ����: \n";
		Show2D2Boards(pl1ships, fire1, rows, cols, player1);
		cin >> target >> y;
		x = convertCharToInt(target) + 1;
		whoseMove = 1;
	}
	else if (first[0] == '1')
	{
		system("cls");
		cout << "\n\n\t� ���������� ���������� ���� ������ ��������: " << comp << "\n";
		Sleep(3200);
		targ(fire2, rows, cols, x, y, 0);
		whoseMove = 2;
	}

	while ((amountOfHits1 < 20) && (amountOfHits2 < 20))
	{
		if (whoseMove == 1)
		{
			system("cls");
			while (pl2ships[x][y] == '1')
			{
				if (pl2ships[x][y] == '1')
				{
					pl2ships[x][y] = 'X';
					fire1[x][y] = 'X';
					Beep(250, 600);
					Beep(150, 600);
					amountOfHits1 += 1;
					Show2D2Boards(pl1ships, fire1, rows, cols, player1);
					cout << "\n\t���������� ���������: " << player1 << ": " << amountOfHits1;
					cout << "\n\t���������� ���������: " << comp << ": " << amountOfHits2 << endl;
					cout << "\n\t�� ������ � ����, " << player1 << ": ";
					if ((amountOfHits1 == 20) || (amountOfHits2 == 20)) break;
					cout << "\n\t��� ���, " << player1 << ": ";
					cin >> target >> y;
					x = convertCharToInt(target) + 1;
					whoseMove = 1;
				}
				system("cls");
			}
			if (pl2ships[x][y] == '-')
			{
				fire1[x][y] = '0';
				pl2ships[x][y] = '0';
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t����, ������� ���� ";
				Sleep(3000);
				system("cls");
				targ(fire2, rows, cols, x, y, 0);
				whoseMove = 2;
			}
			else if (pl2ships[x][y] == '0')
			{
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t�� ������ ���� �� ��� ��������, ������� ���� ";
				Sleep(3000);
				system("cls");
				targ(fire2, rows, cols, x, y, 0);
				whoseMove = 2;
			}
			else if (pl2ships[x][y] == 'X')
			{
				
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t������ ���� ��� ���� ���������� ������, ������� ���� ";
				Sleep(3000);
				system("cls");
				targ(fire2, rows, cols, x, y, 0);
				whoseMove = 2;
			}
		}
		else if (whoseMove == 2)
		{
			while (pl1ships[x][y] == '1')
			{
				if (pl1ships[x][y] == '1')
				{
					pl1ships[x][y] = 'X';
					fire2[x][y] = 'X';
					Beep(250, 600);
					Beep(150, 600);
					amountOfHits2 += 1;
					Show2D2Boards(pl1ships, fire1, rows, cols, player1);
					
					cout << "\n\n\t��� ���, " << comp << endl;
					targ(fire2, rows, cols, x, y, 1);
                    cout << "\n\t�� ������ � ����, " << comp << endl;
                    cout << "\n\t���������� ���������: " << comp << ": " << amountOfHits2;
					cout << "\n\t���������� ���������: " << player1 << ": " << amountOfHits1 << endl;
					if ((amountOfHits1 == 20) || (amountOfHits2 == 20)) break;
					Sleep(3500);
                    targ(fire2, rows, cols, x, y, 0);
					
					whoseMove = 2;
				}
				Sleep(3500);
				system("cls");
			}

			if (pl1ships[x][y] == '-')
			{
				
				fire2[x][y] = '0';
				pl1ships[x][y] = '0';
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t��� ���, " << comp << ": \n";
				targ(fire2, rows, cols, x, y, 1);
				cout << "\n\t����, ������� ���� \n";
				cout << "\n\t���������� ���������: " << player1 << ": " << amountOfHits1;
				cout << "\n\t���������� ���������: " << comp << ": " << amountOfHits2 << endl;
				cout << "\n\t��� ���, " << player1 << ": ";
				cin >> target >> y;
				x = convertCharToInt(target) + 1;
				whoseMove = 1;
			}
		}
	}
	if (amountOfHits1 == 20)
		cout << "\n\t�� ��������, " << player1 << "!";
	if (amountOfHits2 == 20)
		cout << "\n\t�� ��������, " << comp << "!";

	cout << endl;
	cout << endl;

	Clean2D(pl1ships, rows);
	Clean2D(pl2ships, rows);

	Clean2D(fire1, rows);
	Clean2D(fire2, rows);
}

void manFoo()
{
	const int rows = 12;
	const int cols = 12;
	string player1, player2;
	char first[] = { '0', '1' };
	char** pl1ships;
	char** pl2ships;
	char** fire1;
	char** fire2;
	char target = '�';
	int x = 11;
	int y = 11;
	int whoseMove = 3;
	int amountOfHits1 = 0;
	int amountOfHits2 = 0;

	

	Create2D(&pl1ships, rows, cols);
	Create2D(&pl2ships, rows, cols);

	Create2D(&fire1, rows, cols);
	Create2D(&fire2, rows, cols);

	cout << "\n\t���� ���: " << endl;
	cin >> player1;
	cout << "\t��� ������� ������: " << endl;
	cin >> player2;

	Init2D(fire1, rows, cols, 0, player1);
	Init2D(fire2, rows, cols, 0, player2);

	Init2D(pl1ships, rows, cols, 1, player1);
	system("cls");
	Init2D(pl2ships, rows, cols, 1, player2);
	system("cls");
	random_shuffle(begin(first), end(first));
	if (first[0] == '0')
	{
		cout << "\n\t � ���������� ���������� ���� ������ ��������: " << player1
			<< ", ������� ���������� ����: " << "\n";
		Show2D2Boards(pl1ships, fire1, rows, cols, player1);
		cin >> target >> y;
		x = convertCharToInt(target)+1;
		whoseMove = 1;
	}
	else if (first[0] == '1')
	{
		cout << "\n\t� ���������� ���������� ���� ������ ��������: " << player2
			<< ", ������� ���������� ����: " << "\n";
		Show2D2Boards(pl2ships, fire2, rows, cols, player2);
		cin >> target >> y;
		x = convertCharToInt(target)+1;
		
		whoseMove = 2;
	}

	while ((amountOfHits1 < 20) && (amountOfHits2 < 20))
	{
		if (whoseMove == 1)
		{
			while (pl2ships[x][y] == '1')
			{
				if (pl2ships[x][y] == '1')
				{
					pl2ships[x][y] = 'X';
					fire1[x][y] = 'X';
					Beep(250, 600);
					Beep(150, 600);
					amountOfHits1 += 1;
					Show2D2Boards(pl1ships, fire1, rows, cols, player1);
					cout << "\n\t���������� ���������: " << player1 << ": " << amountOfHits1 << endl;
					cout << "\t���������� ���������: " << player2 << ": " << amountOfHits2 << endl;
					cout << "\n\t�� ������ � ����, " << player1 << endl;
					if ((amountOfHits1 == 20) || (amountOfHits2 == 20)) break;
					cout << "\n\t��� ���, " << player1 << ": ";
					cin >> target >> y;
					Sleep(3500);
					x = convertCharToInt(target)+1;
					whoseMove = 1;
					system("cls");
				}
			}
			if (pl2ships[x][y] == '-')
			{
				//system("cls");
				fire1[x][y] = '0';
				pl2ships[x][y] = '0';
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t����, ������� ���� � ����������";
				Sleep(3500);
				system("cls");
				Show2D2Boards(pl2ships, fire2, rows, cols, player2);
				cout << "\n\t���������� ���������: " << player1 << ": " << amountOfHits1 << endl;
				cout << "\t���������� ���������: " << player2 << ": " << amountOfHits2 << endl;
				cout << "\n\t��� ���, " << player2 << ": ";
				cin >> target >> y;
				Sleep(3500);
				x = convertCharToInt(target)+1;
				whoseMove = 2;
				system("cls");
			}
		}
		else if (whoseMove == 2)
		{
			while (pl1ships[x][y] == '1')
			{
				if (pl1ships[x][y] == '1')
				{
					pl1ships[x][y] = 'X';
					fire2[x][y] = 'X';
					Beep(250, 600);
					Beep(150, 600);
					amountOfHits2 += 1;
					Show2D2Boards(pl2ships, fire2, rows, cols, player2);
					cout << "\n\t���������� ���������: " << player2 << ": " << amountOfHits2 << endl;
					cout << "\t���������� ���������: " << player1 << ": " << amountOfHits1 << endl;
					cout << "\n\t�� ������ � ����, " << player2 << endl;
					if ((amountOfHits1 == 20) || (amountOfHits2 == 20)) break;
					cout << "\n\t��� ���, " << player2 << ": ";
					cin >> target >> y;
					Sleep(3500);
					x = convertCharToInt(target)+1;
					whoseMove = 2;
					system("cls");
				}
			}

			if (pl1ships[x][y] == '-')
			{
				//system("cls");
				fire2[x][y] = '0';
				pl1ships[x][y] = '0';
				Show2D2Boards(pl2ships, fire2, rows, cols, player2);
				cout << "\n\t����, ������� ���� � ����������";
				Sleep(3500);
				system("cls");
				Show2D2Boards(pl1ships, fire1, rows, cols, player1);
				cout << "\n\t���������� ���������: " << player2 << ": " << amountOfHits2 << endl;
				cout << "\t���������� ���������: " << player1 << ": " << amountOfHits1 << endl;
				cout << "\n\t��� ���, " << player1 << ": ";
				cin >> target >> y;
				Sleep(3500);
				x = convertCharToInt(target)+1;
				whoseMove = 1;
				system("cls");
			}
		}
	}
	if (amountOfHits1 == 20)
		cout << "\n\t�� ��������, " << player1 << "!";
	if (amountOfHits2 == 20)
		cout << "\n\t�� ��������, " << player2 << "!";

	cout << endl;
	cout << endl;

	Clean2D(pl1ships, rows);
	Clean2D(pl2ships, rows);

	Clean2D(fire1, rows);
	Clean2D(fire2, rows);

}









