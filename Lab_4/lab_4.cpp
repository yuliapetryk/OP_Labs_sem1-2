#include <locale>
#include <iostream>
#include <string>
using namespace std;


void  multiply(int v, int d, long double a[100][100], int b[100][100])
{


    float sum = 0;

    float c[100][100];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            sum = 0;
            for (int k = 0; k < d; k++)
            {
                sum = sum + (a[i][k] * b[k][j]);
            }
            c[i][j] = sum;

        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

 float ra[100][100];

int rang(int d, int v, long double a[100][100]) // функція для знаходження рангу матриці
{
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < d; j++)
        {
            ra[i][j] = a[i][j];
        }
    }
     float n = ra[0][0];
    for (int i = 0; i < v; i++)   //ділимо перший рядок на значення першого елемента
    {

        for (int j = 0; j < d; j++)
        {
            if (i > 0)
                break;
            ra[0][j] = ra[0][j] / n;
        }
    }
    for (int i = 1; i < v; i++)  //робимо перші елементи кожного рядка нулями
    {
        n = ra[i][0];
        for (int j = 0; j < d; j++)
        {
            ra[i][j] = ra[i][j] - (ra[0][j] * n);
        }
    }
    n = ra[1][1];
    for (int j = 0; j < d; j++)
        ra[1][j] = ra[1][j] / n;
    
    for (int l = 1; l < v - 2; l++)
    {

        for (int i = 2; i < v; i++)  //приводимо матрицю до ступінчастого виду
        {

            float n = ra[i + l - 1][l] * (-1);
            for (int j = 0; j < d; j++)
            {
                float p = ra[l][j] * n;
                ra[i + l - 1][j] = ra[i + l - 1][j] + p;
            }
        }
    }
   
    double sum = 0;
    int k = 0;   // визначаємо ранг : якщо сума чисел в рядку дорівнює 0, не додаємо до лічильника sum
    for (int i = 0; i < v; i++)
    {
        sum = 0;
        for (int j = 0; j < d; j++)
        {
            sum = sum + ra[i][j];
        }
        if (sum != 0)
            k++;
    }

    return k;
}





float vuznach(int v, long double a[100][100]) // функція для знаходження визначника матриці
{
    long double vuz[100][100];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            vuz[i][j] = a[i][j];
        }
    }
    double n;
    for ( int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            n = vuz[i + k + 1][k] / vuz[k][k];
            for (int j = 0; j < v; j++)
            {

                vuz[i + k + 1][j] = vuz[i + k + 1][j] - vuz[k][j] * n;
            }
        }
    }
    long double vuznachnuk = 1;
    for (int i = 0; i < v; i++)
    {
        vuznachnuk = vuznachnuk * vuz[i][i];
    }
    return(vuznachnuk);
}



double n;
long double a[100][100];


int main()
{
    setlocale(LC_CTYPE, "ukr");
    int d,v, j, i;

    cout << "Введiть розмiри матрицi: ";
    cin >>d>> v;

    cout << "Введiть матрицю: " << endl;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < d; j++)
        {

            cin >> a[i][j];
        }
    }
    cout << "Введiть другу матрицю розмiром " << v << " на " << d << endl;
    int b[100][100];
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < v; j++)
        {
            cin >> b[i][j];
        }
    }
    
    cout << "Матриця, яку отримаємо пiсля множення" << endl;
     multiply(v, d, a, b) ;
    
    cout << "Ранг матрицi дорiвнює  "<< rang(d,v,a)<<endl;
    if (v == d)
    {
        cout << "Визначник матрицi дорiвнює " << vuznach(v, a);
    }
    else
        cout << "Визначник не обраховується, адже матриця не квадратна ";
    cin.get(); cin.get();
    return 0;
}