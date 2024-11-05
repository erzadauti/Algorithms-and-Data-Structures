#include <iostream>
#include <set>
#include <cstdlib> 
#include <cstddef> 
#include <ctime> 


using namespace std;

int main() {
	int temp;
	set<int> rands;
	set<int>::iterator it;

	// Initializing random number generator
	srand(time(NULL));
	
	while (rands.size() != 6) {
		temp = rand() % 49 + 1;
		rands.insert(temp);
	}

	// Iterate through the set and output each integer into stdout
	for (it = rands.begin(); it != rands.end(); it++) {
		if (it == rands.begin())
			cout << *it;
		else cout << " " << *it;
	}
	cout << endl;

	return 0;
}