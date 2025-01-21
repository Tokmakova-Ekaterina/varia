// SongsList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "iomanip"
#include "conio.h"
#include "stdio.h"
#include "cstdio"
#include "cstring"


using namespace std;

struct Song
{
    char songsName[70]{};
    char path[70];
    char autor[70];
    char date[5];
};

void keyboardSongAdd()       //добавить текст песни с клавиатуры в файл                   
{
    string filename;
    string b;
    cout << "\n\tПоcтрочная запись в файл\n";
    cout << "\n\tВведите имя файла для записи данных: \n";
    cin >> filename;
    cout << "\n\tДля завершения работы: \n"
        << "\tв новой пустой строке введите +++ \n";
    ofstream file(filename, ios::out | ios::app);
    if (!file.is_open())
        cout << "\n\tОшибка открытия файла\n";
    else
    {
        cout << "\n\tФайл открыт для записи, введите данные:\n";
        while (b != "+++")
        {
            getline(cin, b);
            if (b == "+++")
                break;
            file << "\n";
            file << b;   // или file << "\nНаши данные\n";
        }
        file.close();
        cout << "\n\tДанные успешно записаны в файл\n";
    }
    cout << endl << endl;
}

int subs(char* str, char* sub)  // ищет подстроку в строке
{
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++)
    {
        while (((char)tolower(str[i + j]) != '\0') && ((char)tolower(sub[j]) == (char)tolower(str[i + j]))) j++;

        if (sub[j] == '\0')
            return i;
        j = 0;
    }
    return -1;
}

void databaseShow()  // показывает весь список песен
{
    system("cls");

    ifstream fin("songsDB.txt");
    if (!fin.is_open())
        cout << "\n\tОшибка открытия файла\n";
    else
    {
        cout << "\n\t Файл открыт для считывания\n\n";
        cout << "\n\t\t\t\tdatabase: \n\n";
        cout << setw(14) << "songsName" << setw(17) << "path" << setw(25) << "autor" << setw(22) << "date\n";
        cout << "\-----------------------------------------------------------------------------\n";
        cout << endl;
        const int size = 19;
        char ch;
        while (fin.get(ch) && !fin.eof())
        {
            if (ch == ',')
            {
                // cout << setiosflags(ios::left)
                 //    << setw(size - 10);
                 //cout << "\t";
                cout << setw(size - 10);
                //  cout.width(25); 
                continue;
            }
            cout << ch;
        }


        fin.close();
    }
}

void show(Song songs[], int N, int i) // показывает один элемент из списка
{
    system("cls");

    cout << "\n\t\t\tdatabase: \n\n";
    cout << "\t" << setw(14) << "songsName" << setw(14) << "path" << setw(14) << "autor" << setw(9) << "date\n";
    cout << "\t---------------------------------------------------\n";
    cout << endl;
    cout << endl;
    cout << "\t" << setw(14) << songs[i].songsName
        << setw(14) << songs[i].path
        << setw(14) << songs[i].autor
        << setw(8) << songs[i].date << "\n";

    cout << endl;
}

void autorSearch(Song songs[], int size) // поиск песни по автору регистронезависимый
{
    const int n{ 25 };
    char d[n]{};
    char* p = d;
    char* f = songs[0].autor;
    Song* s = &songs[0];
    int a = 1;
    int j = 0;
     
  
       
    cout << "\n\tВведите имя автора:\n";
    cin.unsetf(ios::skipws);

    //cin.getline((char*)&d, n);
    //fgets(d, n, stdin); 
    // puts(d);
    //cin.getline(d, n); 
    // //fputs(d, stdout);

    scanf_s("%s", (char*)&d, n);
    //printf("%s\n", (char*)&d);

    int b = -3, flag = 1;
    for (int i = 0; i < size; i++)
    {
        b = subs(f, p);
        if (b != -1)
        {
            cout << "\n\t" << songs[i].songsName << " " << songs[i].path << " " << songs[i].autor << " " << songs[i].date << endl;
            flag = 0;
        }
        s++;
        f += (sizeof(Song));
    }
    if (flag)
            cout << "\n\tне найдены песни данного автора\n";
}

void showText()  // посмотреть текст из файла на экране Построчное чтение из файла     
{
    string path, str;

    cout << "\n\tВведите имя файла для считывания данных: \n";
    cin >> path;
    const string& filename = path;
    ifstream fin(filename);
    if (!fin.is_open())
        cout << "\n\tОшибка открытия файла\n";
    else
    {
        cout << "\n\t Файл открыт для считывания\n\n";
        while (!fin.eof())
        {
            str = "";

            getline(fin, str);
            cout << "\t" << str << endl;
        }
        fin.close();
    }
    cout << endl << endl;
}

void elementsDelete(Song songs[], int& size)
{
    int index = -1;
    cout << "\n\n\tВведите номер удаляемого элемента\n";
    cin >> index;
    if (index >= 0 && index < size && (songs[index].songsName != "-")) {
        for (int i = index; i < size; i++) {
            songs[i] = songs[i + 1];
        }
        size--;
        cout << "\n\t" << size << endl;
    }
    else
        cout << "\n\tЭлемента с индексом " << index << " не существует\n";
}
/*
void textDelete(char s[], int c)
{
    int max = 100;
    
    char str0[MAX];
    int i, c;

    for (i = 0; (c = getchar()) != '\n'; i++)
        str0[i] = c;
    str0[i] = '\0';

    c = getchar();

    squeeze(str0, c);

    printf("%s\n", str0);
    
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
    
}
*/
void textEdit()
{
    cout << "Hello!!!!";
}

void elementsAdd()
{
    const int size = 256;
    char buf[size]{};
    FILE* out;
    fopen_s(&out, "songsDB.txt", "a");
    if (fopen_s(&out, "songsDB.txt", "a") != NULL)
        cout << "\n\tThe file cannot be opened\n";
    else
    {
        cout << "\n\tИмена и названия вводятся без кавычек\t\n";
        cout << "\n\tenter итую + 1 th song\n";
        cout << "\tsongsName:\n\t";
        cin.getline(buf, size);
        fprintf_s(out, buf);     //(char*)&buf
        cout << "\tpath:\n\t";
        cin.getline(buf, size);
        fprintf_s(out, buf);
        cout << "\tautor:\n\t";
        cin.getline(buf, size);
        fprintf_s(out, buf);
        cout << "\tdate:\n\t";
        cin.getline(buf, size);
        fprintf_s(out, buf);
        fprintf(out, "\n");

        fclose(out);
    }
}

void songAddFromFile()
{
    /*
    const int size = 30;
    char filename[size];
    const char* f = &filename[1];
    string b;
    int a = 0;
    FILE* pFile;
    */

    cout << "\n\tВведите имя файла для считывания данных: \n";

    /*
    cin.unsetf(ios::skipws);
    for (int i = 0; i < size; i++)
    {
        cin >> filename[i];

        if (filename[i] == filename[size - 1]) break;
    }

    for (int i = 0; i < size; i++)
    {
        cout << filename[i];
        if (filename[i] != filename[size - 1])
            a++;
    }

    cout << endl;

    filename[a + 1] = '\0';
    cout << a;

    fopen_s(&pFile, f, "r");
    if (!pFile) cout << "\n\tОшибка открытия файла";
    //ofstream file(filename, ios::out | ios::app);

    else
    {
        char ch;
        fgets(ch, size, pFile);
        while (_getсh(ch))
        {
            //fin.unsetf(ios::skipws);  //fin >> ch;
            cout << ch;
        }
        fin.close();

        cout << "\n\tФайл открыт для чтения\n";
        while (b != "+++")
        {
            getline(cin, b);
            if (b == "+++")
                break;
            file << "\n";
            file << b;   // или file << "\nНаши данные\n";
        }
        file.close();
        cout << "\n\tДанные успешно записаны в файл\n";
    }
    cout << endl << endl;
    cout << "--------------------------------------------------------------" << endl;

    const int len = 30, strings = 5;
    const char ch = '\n';
    char mass[len][strings];

    ifstream fs("strings.txt", ios::in | ios::binary);

    if (!fs) cout << "\n\tОшибка открытия файла"; //Если ошибка открытия файла, то завершаем программу

    for (int r = 0; r < strings; r++)
    {
        fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
        cout << "String " << r + 1 << " = " << mass[r] << endl; //Выводи строку из массива
    }
    fs.close(); //Закрываем файл
    */


}

void writeOutFileChar()  // запись в файл посимвольно, если встречает пробел переходит на новую строку
{
    string filename;
    string b;
    cout << "\n\tПосимвольная запись в файл\n";
    cout << "\n\tВведите имя файла для записи данных: \n";
    cin >> filename;
    cout << "\n\tДля завершения работы: \n"
        << "\tв новой пустой строке введите +++ \n";
    ofstream file(filename, ios::out | ios::app);
    if (!file.is_open())
        cout << "\n\tОшибка открытия файла\n";
    else
    {
        cout << "\n\tФайл открыт для записи, введите данные:\n";
        while (b != "+++")
        {
            cin >> b;
            if (b == "+++")
                break;
            file << "\n";
            file << b;   // или file << "\nНаши данные\n";
        }
        file.close();
        cout << "\n\tДанные успешно записаны в файл\n";
    }
    cout << endl << endl;
}

void readInFileChar()
{
    cout << "\n\tПосимвольное чтение из файла\n";
    string path;
    cout << "\n\tВведите имя файла для считывания данных: \n";
    cin >> path;
    ifstream fin(path);
    if (!fin.is_open())
        cout << "\n\tОшибка открытия файла\n";
    else
    {
        cout << "\n\t Файл открыт для считывания\n";
        char ch;
        while (fin.get(ch))
        {
            //fin.unsetf(ios::skipws);  //fin >> ch; 
            cout << ch;
        }
        fin.close();
    }
    cout << endl << endl;
}

void search(Song songs[], int size)
{
    int oper1 = 1;

    for (;;)
    {
        cout << "\n\tselect operation:\n\n";

        cout << "\n\t 1 - поиск песни по автору\n"
            << "\n\t 2 - поиск песни по словам\n";

        cin >> oper1;

        if (!oper1)
            break;

        switch (oper1)
        {
        case 1:
            cout << "\n\n Enter autors name: \n";
            autorSearch(songs, size);
            break;
        case 2:
            cout << "\n\n  Enter words: \n";
            autorSearch(songs, size);
            break;
        }
        cout << "\n\n  Click any letter for exit\n"
            << "  or ";
    }
}

void dBShow1()
{
    const char* path = "songsDB.txt";
    int c;
    int len = 0;
    char buf[128];
    FILE* in;
    fopen_s(&in, path, "r");
    if (fopen_s(&in, path, "r") != NULL)
        cout << "\n\tThe file cannot be opened\n";
    else
    {
        while (!feof(in))
        {
            fgets(buf, 127, in);
            len = strlen(buf);
            if (buf[len - 1] == '\n')
            {
                buf[len - 1] = '\0';
            }
            //puts(buf);  
            //printf_s(out, "%-20s", buf);
             printf("%-20s\n", (char*)&buf);
        }
        fclose(in);
    }
}

void wordsSearch(Song songs[], int size)
{
    const int n{ 25 };
    char d[n]{};
    char* p = d;
    const char* f = songs[0].path;
    Song* s = &songs[0];
    int a = 1;
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        const char* path = songs[i].path;
        //const char* path = "songsDB.txt";
        int c;
        int len = 0;
        char buf[128];
        FILE* in;
        fopen_s(&in, path, "r");
        if (fopen_s(&in, path, "r") != NULL)
            cout << "The file cannot be opened";
        else
        {
            while (!feof(in))
            {
                fgets(buf, 127, in);
                len = strlen(buf);
                if (buf[len - 1] == '\n')
                {
                    buf[len - 1] = '\0';
                }

                puts(buf);  //fscanf(myfile, "%s%d", str, &a);

               
                cout << "\n\tВведите слова для поиска:\n";
                cin.unsetf(ios::skipws);

                //cin.getline((char*)&d, n);
                //fgets(d, n, stdin); 
                // puts(d);
                //cin.getline(d, n); 
                // //fputs(d, stdout);

                scanf_s("%s", (char*)&d, n);
                //printf("%s\n", (char*)&d);

                int b = -3, flag = 1;
                for (int i = 0; i < size; i++)
                {
                    cout << "\n\t" << songs[i].songsName;
                    /*
                    b = subs(f, p);
                    if (b != -1)
                    {
                        cout << "\n\t" << songs[i].songsName << " " << songs[i].path << " " << songs[i].autor << " " << songs[i].date << endl;
                        flag = 0;
                    }*/
                    s++;
                    f += (sizeof(Song));
                }
                if (flag)
                    cout << "\n\tне найдены песни данного автора\n";

                
            }
            fclose(in);
        }
    }


}

void formIn()
{
    const char* path = "songsDB.txt";
    const int size = 31;
    const int c = 4;
    char arr[size]{};
    int len = 0, i = 0;
    char buf[128];
    FILE* in;
    fopen_s(&in, path, "r");
    if (fopen_s(&in, path, "r") != NULL)
        cout << "\n\tThe file cannot be opened\n";
    else
    {
        while (!feof(in))
        {
            for (int j = 0; j < c; j++)
            {
                fgets(arr, size, in);
                len = strlen(arr);
                if (arr[len - 1] == '\n')
                {
                    arr[len - 1] = '\0';
                }

                // cin.getline(arr, size);
                //  //fprintf(stdout, "\t%s", buff);
                 // fprintf(out, "%1d ", arr[i]);
                 // fputs(arr, stdin);
                  //fgets(arr, size, );
                if (j == 0)
                    printf("%-20s\n", (char*)&arr);
                    //fprintf(stdout, "% -20s ", arr);
                if (j == 1)
                    fprintf(stdout, "% -10s ", arr);
                if (j == 2)
                    fprintf(stdout, "% -18s ", arr);
                if (j == 3)
                    fprintf(stdout, "% -10s \n", arr);




            }
            i++;
        }
        fclose(in);
    }
}

void formOut()
{
    const int size = 31;
    const int c = 4;
    char arr[size]{};
    char* pArr = arr;
    FILE* out;
    const char* path = "black.txt";
    fopen_s(&out, path, "a");

    if (out != nullptr) 
    {
        for (int i = 0; i < c; i++)
        {
            if (i == 0)
            {
                cout << "\n\tВведите название песни: \n";
                cin.getline(arr, size);
                fscanf_s(out, arr);
               // fputs(arr, stdin);
                //fgets(arr, size, );
                fprintf(out, "%-10s", arr);
            }
            if (i == 1)
            {
                cout << "\n\tВведите имя файла: \n";
                cin.getline(arr, size);
                fprintf(out, "%10s", arr);
            }
            if (i == 2)
            {
                cout << "\n\tВведите имя автора: \n";
                cin.getline(arr, size);
                fprintf(out, "%18s", arr);
            }
            if (i == 3)
            {
                cout << "\n\tВведите год написания песни: \n";
                cin.getline(arr, size);
                fprintf(out, "%10s", arr);
            }
        }
        fclose(out);
    }
    else
        cout << "The file could not be created";
   // cin.unsetf(ios::skipws);
}


int main()
{
    setlocale(0, "");
    system("chcp 1251 > null");


    Song songs[] = { {"Серый", "grey.txt", "Ю.Ю. Ежевский", "2020"},
                      {"Черный", "black.txt", "Ф.И. Иванов", "2010"},
                      {"Зеленый", "green.txt", "Ф.И. Иванов", "2011"},
                      {"Красный", "red.txt", "М.С. Сидоров", "2015"},
                      {"Прекрасный", "nice.txt", "М.С. Сидоров", "2007"},
                      {"Голубой", "blue.txt", "Г.Н. Петров", "2000"},
                      {"Феолетовый", "feo.txt", "М.С. Сидоров", "2008"},
                      {"-", "-", "-", "-"}};


    int size = sizeof(songs) / sizeof(Song);
    Song* p = songs;
    int index = 0;

    int oper = 1;


    for (;;)
    {
        cout << "\n  select operation:\n\n";

        cout << "\t 1 - добавить текст с клавиатуры и сохранить в файл\n"
            << "\t 2 - загрузить текст из файла \n"
            << "\t 3 - посмотреть текст песни\n"
            << "\t 4 - редактировать текст\n"
            << "\t 5 - поиск всех песен автора\n"
            << "\t 6 - поиск песни по словам\n"
            << "\t 7 - удалить текст\n"
            << "\t 8 - посмотреть базу данных\n"
            << "\t 9 - добавить элемент в базу данных \n"
            << "\t 10 - посмотреть базу данных \n"
            << "\t 11 - удалить элемент из базы данных \n";

        cin >> oper;

        if (!oper)
            break;

        switch (oper)
        {
        case 1:
            keyboardSongAdd();
            break;
        case 2:
            songAddFromFile();
            break;
        case 3:
            showText();
            break;
        case 4:
            textEdit();
            break;
        case 5:
            autorSearch(songs, size);
            break;
        case 6:
            formIn(); // textDelete();
            break;
        case 7:
            dBShow1();
            break;
        case 8:
            elementsAdd();
            break; //
        case 9:
            formOut();
            break;
        case 10:
            databaseShow();   // formIn();
            break;
        case 11:
            elementsDelete(songs, size);                // databaseShow(songs, N);
        }

        cout << "\n\n  Click any letter for exit\n"
            << "  or ";
    }


    cout << "\n\tHello World!\n\n\n\n";

    return 0;
}

