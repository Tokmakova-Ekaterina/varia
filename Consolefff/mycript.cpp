#include <iostream>
using namespace std;

char* crypt(const char* str, int key)
{
	char* cryptStr = new char[strlen(str) + 1] {0};
	for (int i = 0; i < strlen(str); i++)
	{
		cryptStr[i] = str[i] + key;
	}
	return cryptStr; //надо очистить память после cryptStr!
}
char* decrypt(const char* str, int key)
{
	char* cryptStr = new char[strlen(str) + 1] {0};
	for (int i = 0; i < strlen(str); i++)
	{
		cryptStr[i] = str[i] - key;
	}
	return cryptStr;
	
}
char* crypt1(char*& str, int key)
{
	cout << &str << endl;
	char* cryptStr = str;
	for (int i = 0; i < strlen(str); i++)
	{
		cryptStr[i] = str[i] + key;
	}
	return cryptStr;
}
char* decrypt1(char*& str, int key)
{
	cout << &str << endl;
	char* cryptStr = str;
	for (int i = 0; i < strlen(str); i++)
	{
		cryptStr[i] = str[i] - key;
	}
	return cryptStr;
}