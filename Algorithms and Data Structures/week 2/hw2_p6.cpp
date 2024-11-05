#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	string firstName, lastName, birthDate, input;
	map<string, string> collection;
	fstream file("data.txt", ios::in);

	if (!file.good()) {
		cerr << "File was not opened correctly!" << endl;
		exit(1);
	}

	if (file.is_open())
		while (!file.eof()) {
			file >> firstName >> lastName >> birthDate;
			collection[firstName + " " + lastName] = birthDate;		
		}
	
	while (true) {
		cout << "Enter a name or Exit to close the program: ";
		getline(cin, input);

		// Check if user wants to exit the program
		if (input == "Exit")
			break;
		else {
			// Check if input is in collection
			if (collection.find(input) != collection.end())
				cout << collection[input] << endl;
			else cout << "Name not found!" << endl;
		}
	}
	
	file.close();

    return 0;
}