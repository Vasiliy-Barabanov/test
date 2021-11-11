#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void DFS(vector<vector<int>> a, int n, int k,vector<int> &vec) {
	a[k][k] = 2;
	vec.push_back(k);
	for (int i = 1; i <= n; i++)
		if (a[k][i] == 1) {
			a[k][i] = 2;
			DFS(a, n, i, vec);
		}	
}

int main()
{

	cout << "map" << endl;
	string s, s1;
	getline(cin, s);
	map<string, int> mp;
	int i = 0;
	while (i != -1) {
		i = s.find(' ');
		if (i != -1) {
			s1 = s.substr(0, i);
			s.erase(0, i + 1);
		}
		else s1 = s;
		map <string, int> ::iterator it;
		it = mp.find(s1);
		if (it == mp.end()) mp[s1] = 1;
		else mp[s1]++;
	}
	map <string, int> ::iterator it = mp.begin();
	for (it; it != mp.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}

	//////////////////

	cout << "vector" << endl;
	int a, b;
	cin >> a >> b;
	vector<int> v1, v2;
	srand(time(0));
	double k1 = 0, k2 = 0;
	int chet = 0;
	for (int i = 0; i < a; i++) {
		chet = rand() % 201 - 100;
		v1.push_back(chet);
		k1 = k1 + chet;
	}
	for (int i = 0; i < b; i++) {
		chet = rand() % 201 - 100;
		v2.push_back(chet);
		k2 = k2 + chet;
	}
	for (int i = 0; i < a; i++)
		cout << v1[i] << ' ';
	cout << endl;
	for (int i = 0; i < b; i++)
		cout << v2[i] << ' ';
	cout << endl;
	cout << k1 / a << endl;
	cout << k2 / b << endl;
	vector<int> v3{ -300 };
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (v1[i] == v2[j]) {
				bool l = true;
				if (v3[0] == -300) v3[0] = v1[i];
				for (int g = 0; g < v3.size(); g++)
					if (v3[g] == v1[i]) {
						l = false;
						break;
					}
				if (l)
					v3.push_back(v1[i]);
			}
		}
	}
	if (v3[0] != -300)
		for (int i = 0; i < v3.size(); i++) {
			cout << v3[i] << ' ';
		}


	////////////////////

	cout << endl;
	cout << "stak" << endl;
	int n;
	s = "";
	cin >> n;
	vector<vector<int>> dost(n + 1, vector<int>(n + 1));
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				d[i][j] = 1;
				dost[i][j] = 1;		
			}			
			else {
				d[i][j] = 0;
				dost[i][j] = 0;		
			}
		}
	}
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		a = 0;
		s = "";
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != ' ') {
				a = a * 10 + int(s[j]) - int('0');
			}
			if (s[j] == ' ' || j == s.size() - 1) {
				d[i][a] = 1;
				a = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		DFS(d, n, i, vec);
		cout << endl;
		for (int j = 0; j < vec.size(); j++) {
			cout << j << ' ';
		}
		cout << endl;
		for (int j = 0; j < vec.size(); j++) {
			dost[i][vec[j]] = 1;
		}
		cout << endl;
		vec.clear();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dost[i][j] << ' ';
		}
		cout << endl;
	}
}
