#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string one, two;

    ifstream in;       // ���� ��� �������
    in.open("laba.txt"); // �������� ���� ��� ������� 
    if (in.is_open())
    {
        while (!in.eof())
        {
            in >> one >> two; //������� ���
        }
    }
    in.close();

    int z1, z2, s, i, n, o, m=0, k, u;
    z1 = one.size();
    z2 = two.size();
    const int t = 14;
    int dod1[t] = { 0 };
    int dod2[t] = { 0 };
    int vyvid[t];
    for ( u = z1-1; u!=-1; u--)
    {
         dod1[u] = (int)one[u] - 48;
        
    }
    
    for (u = z2-1; u!=-1; u--)
    {
        dod2[u] = (int)two[u] - 48;    // ������������ ����� � ����� �����
    }
    k = 0;
    int q;
    q = z1 - z2;
    int l = -1;
    int p=0;
   
     
    for (i = z1 - 1; i != -2; i--)
    {
            l = l + 1;
            p = i - q;
            s = dod1[i] + dod2[p] + k; //�������� ���������
            o = s % 10;
            vyvid[l] = o;
            k = s / 10;
        
    }
   if (dod1[0]+dod2[0]>9) //������ �������� , ���� ���� ���� ������ ���� ������� ����� 9
    {
        cout<<1;
    }
   for (int i = z1-1 ; i >= 0; i--)
   {

       cout << vyvid[i] ; //�������� ����� �������, ������� �������� � ���� , � �� � �������

   } 
 cin.get(); cin.get();
 return 0;

} 






