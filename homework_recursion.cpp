#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void print(int min, int max)
{
    cout << min << "  ";
    if (min != max)
	print(min + 1, max);
}

void print(int min, int max, bool isAscending)
{
    if (isAscending)
    {
	cout << min << " ";
	if (min != max)
	    print(min + 1, max, true);
    }
    else if (!isAscending)
    {
	cout << max << " ";
	if (min != max)
	    print(min, max - 1, false);
    }
}

bool isPowTwo(int num, int res = 1)
{
    static int base = 2;
    if (res == num)
	return true;
    else if (res > num)
	return false;
    else
	return isPowTwo(num, res * base);

    return false;
}

int numberDigitsSum(int num)
{
    static int res = 0;
    if (num == 0)
	return res;
    res += num % 10;
    numberDigitsSum(num / 10);    
}

void printNumberVV(int num)
{
    if (num != 0)
    {
	cout << num % 10 << " ";
	printNumberVV(num / 10);
    }
}

void printNumber(int num)
{
    if (num != 0) 
    {
	printNumber(num / 10);
	cout << num % 10 << " ";
    }	
}

int reverseNumber(int num)
{
    static int res = 0;
    if (num != 0)
    {
	res = res*10 + num % 10;
	reverseNumber(num / 10);
    }
    return res;
}

bool isPalindrom(string str)
{
   /* cout << str.length() << endl;
    for (auto i = 0; i < str.length(); i++)
	cout << str[i];*/
    int len = str.length();
    if (len <= 1)
	return true;
    if (str[0] != str[len - 1])
	return false;
    else
	return isPalindrom(str.substr(1, len - 2)); // убираю длину 2 символов (вначале и вконце)
    
}

int fibonachi(int ind)
{
    static int res = 1;
    if (ind <= 1)   
	return ind;
    else
    {
	//cout << ind << " ";
	return fibonachi(ind - 1) + fibonachi(ind -2);	
    }   
}

int myPow(int base, int pow)
{
    static int res = base;
    if (pow == 0)
	return 1;

    if (base == 0 || base == 1)
	return base;

    if (pow != 1)
    {
	res *= base;
	myPow(base, pow - 1);
    }

    return res;
}

int sumRange(int min, int max)
{
    static int res = 0;
    if (min <= max)
    {
	res += min;
	sumRange(min + 1, max);
    }
    else
	return res;
}

int GCD(int a, int b) // Greatest common divisor
{
    if (b == 0)
	return a;
    return GCD(b, a % b);
}


int main()
{
    /*int testarr[2][3] = { {1,2,3},{4,5,6} };
    turtleRecusion(reinterpret_cast<int*>(testarr), 2, 3);
    cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";*/
    setlocale(0, "");
    /*1. От 1 до n.
Дано натуральное число n. Выведите все числа от 1 до n.
Ввод: 5
Вывод: 1 2 3 4 5*/
   /* int n;
    cout << "Ввод: ";
    cin >> n;
    print(1, n);*/

    /*2. От A до B.
Даны два целых числа A и В. Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.
Ввод: 5 1
Вывод: 5 4 3 2 1*/
    /*int A, B;
    cout << "Ввод: ";
    cin >> A >> B;
    if (A < B)
	print(A, B, true);
    else
	print(B, A, false);*/
    /*3. Точная степень двойки.
Дано натуральное число N. Выведите слово YES, если число N является точной степенью двойки, или слово NO в противном случае.
Операцией возведения в степень пользоваться нельзя!
Ввод: 3 8
Вывод: NO YES*/
    /*int N;
    cout << "Ввод: ";
    cin >> N;
    cout << "Вывод: ";
    isPowTwo(N) ? cout << "Yes\n" : cout << "NO\n";*/

    /*
    4. Сумма цифр числа.
Дано натуральное число N. Вычислите сумму его цифр.
При решении этой задачи нельзя использовать строки, списки, массивы, глобальные переменные (ну и циклы, разумеется).
Ввод: 179
Вывод: 17
    */
    /*int N;
    cout << "Ввод: ";
    cin >> N;
    cout << "Вывод: ";
    cout << numberDigitsSum(N) << "\n";*/

    /*
    5. Цифры числа справа налево.
Дано натуральное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами.
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется). Разрешена только рекурсия и целочисленная арифметика.
Ввод: 179
Вывод: 9 7 1*/
    /*int N;
    cout << "Ввод: ";
    cin >> N;
    cout << "Вывод: ";
    printNumberVV(N);*/

    /*
    6. Цифры числа слева направо.
Дано натуральное число N. Выведите все его цифры по одной, в обычном порядке, разделяя их пробелами или новыми строками.
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется). Разрешена только рекурсия и целочисленная арифметика.
Ввод: 179
Вывод: 1 7 9*/
    /*int N;
    cout << "Ввод: ";
    cin >> N;
    cout << "Вывод: ";
    printNumber(N);*/

    /*
    * 7. Разворот числа.
Дано число n, десятичная запись которого не содержит нулей. Получите число, записанное теми же цифрами, но в противоположном порядке. При решении этой задачи нельзя использовать циклы, строки, списки, массивы, разрешается только рекурсия и целочисленная арифметика. Функция должна возвращать целое число, являющееся результатом работы программы, выводить число по одной цифре нельзя.
Ввод: 179
Вывод: 971
    */
    /*int N;
    cout << "Ввод: ";
    cin >> N;
    cout << "Вывод: " << reverseNumber(N)<<"\n";*/

    /*8. Палиндром.
Дано слово, состоящее только из строчных латинских букв. Проверьте, является ли это слово палиндромом. Выведите YES или NO.
При решении этой задачи нельзя пользоваться циклами.
Ввод: radar yes
Вывод: YES NO
    */

    /*string str = "";
    cout << "Ввод: ";
    getline(cin, str);   
    cout << "Вывод: ";
    isPalindrom(str) ? cout<<"YES\n": cout<< "NO\n";*/

    /*
    * 9. Фибоначчи.
Написать функцию для вычисления элементов ряда чисел Фибоначчи, исходя из рекуррентного выражения F(n) = F(n-1) + F(n-2).
Функция принимает индекс числа, возвращает значение числа.
    */
    /*int N;
    cout << "Ввод: ";
    cin >> N;

    cout << "Вывод: " << fibonachi(N) << "\n";

    cout << "Ряд чисел Фибоначчи до " << N << ":\n";
    for (auto i = 0; i <= N; i++)
	cout << fibonachi(i) << " ";*/

/*
* 10. Степень числа.
Вычислить степень числа, используя рекурсию. В функцию передаётся 2 параметра - число и степень.
*/
   /* int base, pow;
    cout << "Ввод: ";
    cin >> base >> pow;
    cout <<"Вывод: "<< myPow(base, pow) << "\n";*/

/*
11. Сумма чисел в диапазоне.
Вычислить сумму чисел в определённом диапазоне. Начало и конец диапазона задаётся параметрами функции.
*/
    /*int min, max;
    cout << "Ввод: ";
    cin >> min >> max;
    cout << "Вывод: " <<  sumRange(min, max) << "\n";*/

/*
* 12. НОД.
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.*/

    int a, b;
    cout << "Ввод: ";
    cin >> a >> b;
    cout << "Вывод: " << GCD(a,b) << "\n";


    return 0;
}

/*

14*. Поиск пути
Валера попал в лабиринт. Лабиринт представляет собой двумерный массив целых чисел MxN, некоторые элементы которого заросли непролазными джунглями (0 – свободная клетка, 1 – занятая клетка). Сейчас Валера в клетке [A;B], и он хочет попасть в клетку [C;D]. Определите, возможно ли это, и если да – отобразите кратчайший путь следования.
http://www.cyberforum.ru/cpp-beginners/thread127275.html


*/