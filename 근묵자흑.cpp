#include <iostream>
using namespace std;
int main() {
	int n, k;
	int list[100000];
	
	cin >>n>>k;
	for(int i = 0; i < n; i++)
		cin >> list[i];
	
	int result;
	
	if((n - 1) % (k - 1) == 0)
		result = (n - 1) / (k - 1);
	else
		result = (n - 1) / (k - 1) + 1;
		
	cout << result <<"\n";
	return 0;
}
