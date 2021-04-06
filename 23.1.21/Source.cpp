#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool odd(int& val)
{
	if (val % 2!= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector <int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	auto it = remove_if(a.begin(), a.end(), odd);
	a.erase(it, a.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}