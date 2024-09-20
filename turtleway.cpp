#include <Windows.h>
#include <conio.h> 
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;


int max_v(int a, int b)
{
    if (a > b)
	return a;
    else if (b > a)
	return b;
    else
	return -1;
}

void printTurtlePath(int* arr, int N, int** frog_array, HANDLE hWnd)
{
    int coins = 0;
    for (auto i = 0; i < N; i++)
    {
	for (auto j = 0; j < N; j++)
	{
	    if (frog_array[i][j] > 0)
	    {
		coins += arr[i * N + j];	    // считаю монетки
		wcout.width(5);
		SetConsoleTextAttribute(hWnd, 6);
		wcout  << coins;
		SetConsoleTextAttribute(hWnd, 14);
	    }
	    else
	    {
		wcout.width(5);
		wcout << arr[i * N + j];
	    }

	}
	wcout << L"\n";
    }

    wcout << L"\n";
    wcout<<L"\tћонеты: " << coins << "\n";
    wcout << L"\n"; 
    wcout << L"\n";
}

int** froggy(int* arr, int n, int** frog_array, int frog)
{
    static int max_value = 1;
    if (frog == n * n) // если последн€€ клетка
    {
	frog_array[n - 1][n - 1] = max_value;
	return frog_array;
    }
    else if (frog % n == 0) //значит нахожусь на правом крайнем (последнем) столбике и можно двигатьс€ только вниз
    {
	int row = int(frog / n);    // поскольку в массиве индекс элемента на 1 меньше, значит индекс р€да мен€ть ненужно
	int col = n - 1;
	frog_array[row][col] = max_value;
	//frog += n;		    // л€гушка прыгает на следующий р€д
	froggy(arr, n, frog_array, frog + n);
    }

    else if (int(frog / n) == n - 1) // если л€гушка в последнем р€ду
    {
	int row = n - 1;
	int col = frog % n;
	frog_array[row][col] = max_value;
	//++frog;
	froggy(arr, n, frog_array, frog + 1);
    }
    else
    {
	if (arr[frog] == max_v(arr[frog], arr[frog + n - 1]))    // вес какой клетки выше: правой или нижней?
	{
	    int row = int(frog / n);
	    int col = frog % n;
	    frog_array[row][col] = max_value;
	    //++frog;
	    froggy(arr, n, frog_array, frog + 1);
	}
	else
	{
	    int row = int((frog + n - 1) / n);
	    int col = (frog + n - 1) % n;
	    frog_array[row][col] = max_value;
	    //frog += n;				    // л€гушка прыгает на следующий р€д
	    froggy(arr, n, frog_array, frog + n);
	}
    }
}

int** turtlePath(int* arr, int n)
{    
    static int max_value = 1;//arr[n * n - 1];
    static int** frog_array = new int* [n];

    for (auto i = 0; i < n; i++)
    {
	frog_array[i] = new int[n];
	for (auto j = 0; j < n; j++)
	    frog_array[i][j] = 0;
    }

    frog_array[0][0] = max_value;  

    wcout << L"\n";

    int frog = 1;	// итератор-л€гушка, который будет хранить текущее смещение от начала массива

    /*итерационно*/
 //   while (1)
 //   {
	//if (frog == n * n) // если последн€€ клетка
	//{
	//    frog_array[n - 1][n - 1] = max_value;
	//    break;
	//}
	//else if (frog % n == 0) //значит нахожусь на правом крайнем (последнем) столбике и можно двигатьс€ только вниз
	//{
	//    int row = int(frog / n);    // поскольку в массиве индекс элемента на 1 меньше, значит индекс р€да мен€ть ненужно
	//    int col = n - 1;
	//    frog_array[row][col] = max_value;
	//    frog += n;		    // л€гушка прыгает на следующий р€д
	//}

	//else if (int(frog / n) == n - 1) // если л€гушка в последнем р€ду
	//{
	//    int row = n - 1;
	//    int col = frog % n;
	//    frog_array[row][col] = max_value;
	//    ++frog;
	//}
	//else
	//{
	//    if (arr[frog] == max_v(arr[frog], arr[frog + n - 1]))    // вес какой клетки выше: правой или нижней?
	//    {
	//	int row = int(frog / n);
	//	int col = frog % n;
	//	frog_array[row][col] = max_value;
	//	++frog;
	//    }
	//    else
	//    {
	//	int row = int((frog + n - 1) / n);
	//	int col = (frog + n - 1) % n;
	//	frog_array[row][col] = max_value;
	//	frog += n;				    // л€гушка прыгает на следующий р€д
	//    }
	//}	
 //   }

    /*рекурсивно*/
    return froggy(arr, n, frog_array, frog);
}


int main()
{
   /*13 * .„ерепашка.
	Ќа квадратной доске размером NxN расставлены случайные целые положительные числа.„ерепашка, наход€ща€с€ в левом верхнем углу, мечтает попасть в правый нижний.ѕри этом она может переползать только в клетку справа или снизу(не наискосок) и хочет, чтобы сумма всех чисел, оказавшихс€ у неЄ на пути, была максимально возможной.ѕоказать на экране консоли эту сумму.“акже, программа должна показать путь следовани€ черепашки.
*/
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(0, ""); 
    srand(time(0));
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    const int N = 10;

    int arr[N][N];
    for (auto i = 0; i < N; i++)
    {
	for (auto j = 0; j < N; j++)
	    arr[i][j] = rand() % 10;
    }

    wcout << L"оригинальный массив с монетками" << L"\n";
    for (auto i = 0; i < N; i++)
    {
	int row_val = 0;
	for (auto j = 0; j < N; j++)
	{
	    wcout << arr[i][j] << "  ";
	    row_val += arr[i][j];
	}
	wcout << L"\n";
    }
    wcout << L"\n";
    int temp_arr[N][N];
    temp_arr[0][0] = arr[0][0];
    for (auto i = 1; i < N; i++)
    {
	temp_arr[0][i] = arr[0][i] + temp_arr[0][i - 1];
	temp_arr[i][0] = arr[i][0] + temp_arr[i - 1][0];
    }

    for (auto i = 1; i < N; i++)
    {
	for (auto j = 1; j < N; j++)
	{
	    if (temp_arr[i][j - 1] + arr[i][j] > temp_arr[i - 1][j] + arr[i][j])
		temp_arr[i][j] = temp_arr[i][j - 1] + arr[i][j];
	    else
		temp_arr[i][j] = temp_arr[i - 1][j] + arr[i][j];
	}
    }

    wcout << L"массив с просчитанными весами клеток" << L"\n\n";
    for (auto i = 0; i < N; i++)
    {
	for (auto j = 0; j < N; j++)
	{
	    wcout.width(4);
	    wcout << temp_arr[i][j] << L" ";
	}
	wcout << L"\n";
    }

    wcout << L"\n";
    int** frog_array = turtlePath(reinterpret_cast<int*>(temp_arr), N);

    /******** вывод массива л€гушки **********/
    wcout << L"визуализаци€ оптимального пути" << L"\n\n";
    for (auto i = 0; i < N; i++)
    {
	for (auto j = 0; j < N; j++)
	{
	    wcout << frog_array[i][j] << L" ";
	}
	wcout << L"\n";
    }
    wcout << L"\n"; wcout << L"\n";

    wcout << L"\tпуть черепахи" << L"\n\n";
    printTurtlePath(reinterpret_cast<int*>(arr), N, frog_array, hWnd); 
    
    return 0;
}

