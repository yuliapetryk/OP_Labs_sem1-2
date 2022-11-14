#include <locale>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

long double  cage;
int rowM, columnsM;
vector<vector< int> >M1(rowM, vector<int>(columnsM));
vector<vector< int> >M2(rowM, vector<int>(columnsM));
vector<vector< int> >ra(rowM, vector<int>(columnsM));

vector <vector < int> > multiply (int rowM, int columnsM, vector <vector < int> > M1, vector <vector < int> > M2)
{
    
    vector<vector< int> >M12(rowM, vector<int>(rowM));
    int sum = 0;
     for (int row = 0; row < rowM; row++)
    {
        for (int column = 0; column < rowM; column++)
        {
            sum = 0;
            for (int k = 0; k < columnsM; k++)
            {
                sum = sum + (M1[row][k] * M2[k][column]);
            }
            M12[row][column] = sum;

        }
    }
    return (M12);
}

int rang(int columnsM, int rowM, vector <vector < int> > M1) // ������� ��� ����������� ����� �������
{

    for (int row = 0; row < rowM; row++)
    {
        for (int column = 0; column < columnsM; column++)
        {
            ra[row][column] = M1[row][column];
        }
    }
    float cage = ra[0][0];
    for (int row = 0; row < rowM; row++)   //����� ������ ����� �� �������� ������� ��������
    {

        for (int column = 0; column < columnsM; column++)
        {
            if (row > 0)
                break;
            ra[0][column] = ra[0][column] / cage;
        }
    }
    for (int row = 1; row < rowM; row++)  //������ ����� �������� ������� ����� ������
    {
        cage = ra[row][0];
        for (int column = 0; column < columnsM; column++)
        {
            ra[row][column] = ra[row][column] - (ra[0][column] * cage);
        }
    }
    cage = ra[1][1];
    for (int column = 0; column < columnsM; column++)
        ra[1][column] = ra[1][column] / cage;

    for (int l = 1; l < rowM - 2; l++)
    {

        for (int row = 2; row < rowM; row++)  //��������� ������� �� ������������ ����
        {

            float n = ra[row + l - 1][l] * (-1);
            for (int column = 0; column < columnsM; column++)
            {
                float oppositecage = ra[l][column] * cage;
                ra[row + l - 1][column] = ra[row + l - 1][column] + oppositecage;
            }
        }
    }

    double sum = 0;
    int rangk = 0;   // ��������� ���� : ���� ���� ����� � ����� ������� 0, �� ������ �� ��������� sum
    for (int row = 0; row < rowM; row++)
    {
        sum = 0;
        for (int column = 0; column < columnsM; column++)
        {
            sum = sum + ra[row][column];
        }
        if (sum != 0)
            rangk++;
    }

    return rangk;
}





float vuznach(int rowM, vector <vector < int> > M1) // ������� ��� ����������� ���������� �������
{
    long double vuz[100][100];
    for (int row = 0; row < rowM; row++)
    {
        for (int column = 0; column < rowM; column++)
        {
            vuz[row][column] = M1[row][column];
        }
    }
    double cage;
    for (int k = 0; k < rowM; k++)
    {
        for (int row = 0; row < rowM; row++)
        {
            cage = vuz[row + k + 1][k] / vuz[k][k];
            for (int column = 0; column < rowM; column++)
            {

                vuz[row + k + 1][column] = vuz[row + k + 1][column] - vuz[k][column] * cage;
            }
        }
    }
    long double vuznachnuk = 1;
    for (int row = 0; row < rowM; row++)
    {
        vuznachnuk = vuznachnuk * vuz[row][row];
    }
    return(vuznachnuk);
}

void enterM( vector <vector < int> > &M1, int rowM, int columnsM)
{
    
    for (int row= 0; row < rowM; row++)
        for (int column = 0; column < columnsM; column++)
        {
            cin >> M1[row][column];
        }
   
}

void displayM (vector <vector < int> > multiply, int rowM, int columnsM)
{
    
    for (int row = 0; row < rowM; row++)
    {
        for (int column = 0; column < rowM; column++)
        {
            cout << multiply(rowM, columnsM, M1, M2) << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    int columnsM, rowM, column, row;

    cout << "����i�� ����i�� ������i: ";
    cin >> columnsM >> rowM;

    cout << "����i�� �������: " << endl;
    enterM( M1, rowM, columnsM);
    cout << "����i�� ����� ������� ����i��� " << rowM << " �� " << columnsM << endl;
    enterM(M2, columnsM, rowM);
    cout << "�������, ��� �������� �i��� ��������" << endl;
    displayM( multiply(rowM, columnsM, M1, M2), rowM, columnsM);

    cout << "���� ������i ���i����  " << rang(columnsM, rowM, M1) << endl;
    if (rowM == columnsM)
    {
        cout << "��������� ������i ���i���� " << vuznach(rowM, M1);
    }
    else
        cout << "��������� �� ������������, ���� ������� �� ��������� ";
    cin.get(); cin.get();
    return 0;
}