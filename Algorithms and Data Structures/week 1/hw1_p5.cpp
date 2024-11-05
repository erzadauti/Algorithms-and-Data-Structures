#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::string temp;
	std::vector<std::string> wordVector;
	std::cin >> temp;

	// Push back each word into vector each word until END is inputted
	while (temp.compare("END") != 0) {
		wordVector.push_back(temp);
		std::cin >> temp;
	}

	// Swap strings of the second and fifth elements
	if (wordVector.size() > 5) {
		temp = wordVector[1];
		wordVector[1] = wordVector[4];
		wordVector[4] = temp;
	}

	// Set last string element to "???" in case the vector is not empty
	if (!wordVector.empty())
		wordVector[wordVector.size() - 1] = "???";

	// Loop through the vector and output the words using index operator
	if (!wordVector.empty())
		for (unsigned int i = 0; i < wordVector.size(); i++) {
			if (i == 0)
				std::cout << wordVector[i];
			else std::cout << "," << wordVector[i];
		}
	std::cout << std::endl;

	// Set a mark variable at the beginning of the vector
	std::vector<std::string>::iterator begin = wordVector.begin();

	// Iterate through the vector using iterator and output using dereferencing
	if (!wordVector.empty())
		for (std::vector<std::string>::iterator it = wordVector.begin();
				it != wordVector.end(); it++) {
			if (it == begin)
				std::cout << *it;
			else std::cout << ";" << *it;
		}
	std::cout << std::endl;

	std::vector<std::string>::reverse_iterator rbegin = wordVector.rbegin();

	if (!wordVector.empty())
		for (
			std::vector<std::string>::reverse_iterator it = wordVector.rbegin();
			it != wordVector.rend(); it++) {
			if (it == rbegin)
				std::cout << *it;
			else std::cout << " " << *it;
		}
	std::cout << std::endl;

	return 0;
}