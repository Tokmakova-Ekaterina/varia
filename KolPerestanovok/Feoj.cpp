// Feoj.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Dz2212.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <string>
//#include <cstdlib>


using namespace std;

int facto(int a)
{
    int c = 1;
    if (a > 1)
    {
        for (int i = 1; i <= a; i++)
            c *= i;
        return c;
    }
    else
        return 1;
}

int foo(int* a, int c)
{
    int mu = 1;
    int amount;
    int d[9]{};
    int m[9];

    for (int i = 0; i < c; i++)
    {
        m[i] = a[i];
    }

    for (int i = 0; i < c - 1; i++)
    {
        amount = 1;
        if (a[i] == -1) continue;
        for (int j = i + 1; j < c; j++)
        {
            if (a[i] == a[j])
            {
                amount += 1;
                a[j] = -1;
            }
        }
        d[i] = facto(amount);
    }
    for (int i = 0; i < 9; i++)
    {
        if (d[i] < 2)
            d[i] = 1;
        mu *= d[i];
    }

    for (int i = 0; i < c; i++)
    {
        a[i] = m[i];
    }

    return mu;
}

void process( unsigned int n, int &c)
{
    while (n > 0)
    {
        n /= 10;
        c++;
    }
}

void process1(int* &a, unsigned int n, int c)
{
    int k, f = 0, min, temp;
    int* p1 = a;
    int* p2 = a;

    while (n > 0)
    {
        
        k = n % 10;
        *p1 = k;
        n /= 10;
        p1++;
    }
    --p1;
    
    for (int i = 0; i < c / 2; i++)
    {
        f = *p2;
        *p2 = *p1;
        *p1 = f;
        p2++;
        p1--;
    }
    for (int i = 0; i < c; i++)            // сортировка по возрастанию
    {
        min = a[0];
        for (int j = i + 1; j < c; j++)
        {
            if (a[j] < a[i])
            {
                min = a[j];
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
    

/**/
void Alloc(int** arr, int size)
{
    *arr = new int[size];
}

void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
bool NextSet(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false;                     // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;            // сортируем оставшуюся часть последовательности
    while (l < r)
        swap(a, l++, r--);
    return true;
}
void Print(int* a, int n)             // вывод перестановки
{
    static int num = 1;                 // номер перестановки
    cout.width(3);                   // ширина поля вывода номера перестановки
    cout << num++ << ":  ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}



int main()
{
    setlocale(0, "");

    int x, b, c = 0;
    unsigned int n, w;
    int* a;

    cout << "\n\t Программа выводит количество перестановок цифр в числе \n\t";
   
    cout << "\n\tEnter one-eight digit number: \n\t";
    cin >> n;

    process(n, c);
    Alloc(&a, c);
    process1(a, n, c);

    b = facto(c);
    x = foo(a, c);
    w = b / x; 

    cout << "\n\n\tNumber of permutations: " << w << endl;

    cout << endl;

    Print(a, c);
    while (NextSet(a, c))
        Print(a, c);
   
    cout << endl;

    delete[]a;

  // cout << " Hello World!\n";

    return 0;
}


