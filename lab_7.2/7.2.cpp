#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMaxMin(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    // Створення та ініціалізація матриці
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Заповнення матриці випадковими значеннями
    Create(a, k, n, Low, High);
    Print(a, k, n);

    // Міняємо місцями максимальні та мінімальні елементи
    SwapMaxMin(a, k, n);
    Print(a, k, n);

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMaxMin(int** a, const int k, const int n)
{
    for (int i = 1; i < k; i += 2) {
        // Знаходимо мінімальний елемент непарного рядка
        int min = a[i - 1][0];
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (a[i - 1][j] < min) {
                min = a[i - 1][j];
                minIndex = j;
            }
        }

        // Знаходимо максимальний елемент парного рядка
        int max = a[i][0];
        int maxIndex = 0;
        for (int j = 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                maxIndex = j;
            }
        }

        // Міняємо місцями максимальний і мінімальний елементи
        int temp = a[i][maxIndex];
        a[i][maxIndex] = a[i - 1][minIndex];
        a[i - 1][minIndex] = temp;
    }
}