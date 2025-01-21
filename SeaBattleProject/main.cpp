// SeaBattleProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "seaBattleProject.h"

int main()
{
	system("chcp 1251");
	srand(time(0));
	system("cls");

	char with;
	cout << endl << "\n\n\n\n\tВы хотите играть в морской бой с компьютером или "
		<< "с представителем человеческой расы ? \n\n"
		<< "\t(с компьютером - нажмите 'j', с человеком - нажмите 'r')\n";

	cin >> with;

	if (with == 'r')
	{
		manFoo();
	}
	else if (with == 'j')
	{
		compFoo();
	}



	// cout << " Hello, World!\n";

	return 0;
}

