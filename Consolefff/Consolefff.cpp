// Consolefff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "mycript.h"
#include <stdio.h>
#include <cstdio>

 
using namespace std;

int main()
{
	system("chcp 1251");
	char arr[128]{ 0 };

	cout << "Введите сообщение: \n";
	char* buf = new char[128] {0};
	cout << "\n\tbuf " << & buf << endl;
	cin.getline(buf, 127); 
	cout << "\n\tbuf " << &buf << " " << buf << endl;
	char* changeBuf = crypt1(buf, 3);
	cout << "\n\tchangeBuf " << &changeBuf << " " << changeBuf << endl;

	FILE* outfile;
	fopen_s(&outfile, "cript.txt", "w");//возвращает NULL если открыть файл не удалось
	if (outfile == NULL)
	{
		perror("cript.txt");
		return 1;
	}
	else if (outfile)
	{               
		cout << "\n\tфайл открыт для записи\n";
		//stdio.h
		if (fputs(changeBuf, outfile) == -1) //возвращает int(-1) при ошибке записи, при успехе - другое число
			cout << "\n\tОшибка записи данных\n";
		else
			cout << "\n\tДанные успешно записаны в файл\n";
		if (fclose(outfile) == EOF)//возвращает 0 если файл закрыт успешно и 1(EOF) - если не закрыт
			cout << "The file is not close\n";
		else
			cout << "The file is closed\n";
	}

	//char* fromFile = new char[128] {0};
	FILE* inFile;
	fopen_s(&inFile, "cript.txt", "r");
	if (inFile)
	{
		cout << "\n\tФайл открыт для чтения\n";
		while (!feof(inFile))//может добавить проверку на достижение конца файла?
		{
			if (fgets(buf, 128, inFile) != NULL)//возвращает (char*)указатель fromFile
			                //или NULL, если не удалось прочитать ни одного символа
		    puts(buf);//выводит на экран считанные символы
		}
		if (fclose(inFile) == EOF)//возвращает 0 если файл закрыт успешно и 1(EOF) - если не закрыт
			cout << "The file is not closed\n";
		else
			cout << "The file is closed\n";
	}
	

	//cout << " зашифровано: " << encrypted << endl;
  // char* newmes = decrypt1(fromFile, 3);
   // cout << " расшифрованно: " << newmes;
	//changeBuf почистить как? 
	changeBuf = decrypt1(buf, 3);
	cout << "расшифровано в : changeBuf " << &changeBuf << " " << changeBuf << endl;


  // if(fromFile)
 //  delete[] fromFile;
  // fromFile = nullptr;
   if(buf)
   delete[] buf;
   buf = nullptr;

   return 0;
}
