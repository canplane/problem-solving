using namespace std;
#include <iostream>
#include <map>

map<string, string> dic;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	while (N--) {
		string site, pwd;
		cin >> site >> pwd;
		dic[site] = pwd;
	}
	while (M--) {
		string site;
		cin >> site;
		cout << dic[site] << '\n';
	}
}