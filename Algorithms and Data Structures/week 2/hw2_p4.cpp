#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;

	for (int i = 1; i < 31; i++)
		arr.push_back(i);
	arr.push_back(5);

	reverse(arr.begin(), arr.end());

	for (vector<int>::iterator it = arr.begin(); it != arr.end();
		 it++) {
		if (it == arr.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	replace(arr.begin(), arr.end(), 5, 129);

	for (vector<int>::iterator it = arr.begin(); it != arr.end();
		 it++) {
		if (it == arr.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	return 0;
}