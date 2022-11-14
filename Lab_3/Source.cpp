#include <iostream>
#include <cmath>
#include <string>
#include <locale>
using namespace std;
long double fact(int x)
{
    if (x < 0) 
        return 0; 
    if (x == 0) 
        return 1; 
    else 
        return x * fact(x - 1); 
}
int main()
{
    long double PI = 3.1415926535, s,f,x,d;
    int  n,k, h,i;
    setlocale(LC_CTYPE, "ukr");
    cout << "Введiть кут ";
    cin >> k;
    cout << "Введiть точнiсть ";
    cin >> n;
    x = (k * PI)/180;
    s = 0; 
    for (i = 0; i <= n; i++)
    {
        f = fact(2 * i + 1);
        d = pow(x, (2 * i + 1));
        h = pow(-1, i);
        s = s + (h * d / (f));
    }
    cout << "Наближене обчислення дорiвнює " <<s;
    cin.get(); cin.get();
    return 0;

}






