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
	return isPalindrom(str.substr(1, len - 2)); // ������ ����� 2 �������� (������� � ������)
    
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
    /*1. �� 1 �� n.
���� ����������� ����� n. �������� ��� ����� �� 1 �� n.
����: 5
�����: 1 2 3 4 5*/
   /* int n;
    cout << "����: ";
    cin >> n;
    print(1, n);*/

    /*2. �� A �� B.
���� ��� ����� ����� A � �. �������� ��� ����� �� A �� B ������������, � ������� �����������, ���� A < B, ��� � ������� �������� � ��������� ������.
����: 5 1
�����: 5 4 3 2 1*/
    /*int A, B;
    cout << "����: ";
    cin >> A >> B;
    if (A < B)
	print(A, B, true);
    else
	print(B, A, false);*/
    /*3. ������ ������� ������.
���� ����������� ����� N. �������� ����� YES, ���� ����� N �������� ������ �������� ������, ��� ����� NO � ��������� ������.
��������� ���������� � ������� ������������ ������!
����: 3 8
�����: NO YES*/
    /*int N;
    cout << "����: ";
    cin >> N;
    cout << "�����: ";
    isPowTwo(N) ? cout << "Yes\n" : cout << "NO\n";*/

    /*
    4. ����� ���� �����.
���� ����������� ����� N. ��������� ����� ��� ����.
��� ������� ���� ������ ������ ������������ ������, ������, �������, ���������� ���������� (�� � �����, ����������).
����: 179
�����: 17
    */
    /*int N;
    cout << "����: ";
    cin >> N;
    cout << "�����: ";
    cout << numberDigitsSum(N) << "\n";*/

    /*
    5. ����� ����� ������ ������.
���� ����������� ����� N. �������� ��� ��� ����� �� �����, � �������� �������, �������� �� ���������.
��� ������� ���� ������ ������ ������������ ������, ������, ������� (�� � �����, ����������). ��������� ������ �������� � ������������� ����������.
����: 179
�����: 9 7 1*/
    /*int N;
    cout << "����: ";
    cin >> N;
    cout << "�����: ";
    printNumberVV(N);*/

    /*
    6. ����� ����� ����� �������.
���� ����������� ����� N. �������� ��� ��� ����� �� �����, � ������� �������, �������� �� ��������� ��� ������ ��������.
��� ������� ���� ������ ������ ������������ ������, ������, ������� (�� � �����, ����������). ��������� ������ �������� � ������������� ����������.
����: 179
�����: 1 7 9*/
    /*int N;
    cout << "����: ";
    cin >> N;
    cout << "�����: ";
    printNumber(N);*/

    /*
    * 7. �������� �����.
���� ����� n, ���������� ������ �������� �� �������� �����. �������� �����, ���������� ���� �� �������, �� � ��������������� �������. ��� ������� ���� ������ ������ ������������ �����, ������, ������, �������, ����������� ������ �������� � ������������� ����������. ������� ������ ���������� ����� �����, ���������� ����������� ������ ���������, �������� ����� �� ����� ����� ������.
����: 179
�����: 971
    */
    /*int N;
    cout << "����: ";
    cin >> N;
    cout << "�����: " << reverseNumber(N)<<"\n";*/

    /*8. ���������.
���� �����, ��������� ������ �� �������� ��������� ����. ���������, �������� �� ��� ����� �����������. �������� YES ��� NO.
��� ������� ���� ������ ������ ������������ �������.
����: radar yes
�����: YES NO
    */

    /*string str = "";
    cout << "����: ";
    getline(cin, str);   
    cout << "�����: ";
    isPalindrom(str) ? cout<<"YES\n": cout<< "NO\n";*/

    /*
    * 9. ���������.
�������� ������� ��� ���������� ��������� ���� ����� ���������, ������ �� ������������� ��������� F(n) = F(n-1) + F(n-2).
������� ��������� ������ �����, ���������� �������� �����.
    */
    /*int N;
    cout << "����: ";
    cin >> N;

    cout << "�����: " << fibonachi(N) << "\n";

    cout << "��� ����� ��������� �� " << N << ":\n";
    for (auto i = 0; i <= N; i++)
	cout << fibonachi(i) << " ";*/

/*
* 10. ������� �����.
��������� ������� �����, ��������� ��������. � ������� ��������� 2 ��������� - ����� � �������.
*/
   /* int base, pow;
    cout << "����: ";
    cin >> base >> pow;
    cout <<"�����: "<< myPow(base, pow) << "\n";*/

/*
11. ����� ����� � ���������.
��������� ����� ����� � ����������� ���������. ������ � ����� ��������� ������� ����������� �������.
*/
    /*int min, max;
    cout << "����: ";
    cin >> min >> max;
    cout << "�����: " <<  sumRange(min, max) << "\n";*/

/*
* 12. ���.
�������� ����������� ������� ���������� ����������� ������ �������� ���� ����� �����.*/

    int a, b;
    cout << "����: ";
    cin >> a >> b;
    cout << "�����: " << GCD(a,b) << "\n";


    return 0;
}

/*

14*. ����� ����
������ ����� � ��������. �������� ������������ ����� ��������� ������ ����� ����� MxN, ��������� �������� �������� ������� ������������ ��������� (0 � ��������� ������, 1 � ������� ������). ������ ������ � ������ [A;B], � �� ����� ������� � ������ [C;D]. ����������, �������� �� ���, � ���� �� � ���������� ���������� ���� ����������.
http://www.cyberforum.ru/cpp-beginners/thread127275.html


*/