#include <iostream>
#include <locale> 
#include <vector> 
using namespace std;

const int INF = 90000000;
void search(int n, vector < vector<int> > g){
	vector<bool> used(n);
	vector<int> min(n, INF), end(n, -1);
	min[0] = 0;
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || min[j] < min[v]))
				v = j;
	if (min[v] == INF) {
		cout << "Не можливо !";
		exit(0);
	}
	used[v] = true;
	if (end[v] != -1)
    cout <<"(" <<end[v] << "," << v <<")" <<endl;

	for (int to = 0; to < n; ++to)
	{
		if (g[v][to] < min[to]) {
			min[to] = g[v][to];
			end[to] = v;
		}
	}
	
}
}

int main() {
	int n;
	 vector<int>  g;
	setlocale(LC_ALL, "ukr");
	cout << "Введiть кiлькiсть точок: ";
	cin >> n;
	vector< vector<int>> a(n, vector < int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cout << "Введiть вiдстань вiд x" << i  << " до x" << j  << ": ";
			cin >> a[i][j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] == 0)
				a[i][j] = INF;
		}

	}
	cout << "Шукане пiддерево складається з ребер: " << endl;
	search(n, a);
	return 0;
}