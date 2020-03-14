#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include "map.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	//cout << "Large Map Project \n";
	Map Key; //object for the Map
/*
	//tests for the function actually returning correct values
	std::vector<std::string> letters = {"z","ac", "ab", "e", "t"};
	std::string test = "Suzanne McCarthur 186255";
	int numTest = 1;

	//tests for making sure the get function actually works
	std::string testing1 = "Adam West";
	std::string testing2 = "Suzanne McCarthur";
	std::string testing3 = "Sydney Garling";
	std::string testing4 = "Christopher McClure";
	std::string testing5 = "Adam West";
	std::string testing6 = "Kaitlyn Vinson";
	std::string testing7 = "Brandi Grayson";
	std::string testing8 = "Peter Kaufman";

	std::cout << "Test Sample: \n";
	std::cout << testing1 << ' ' << 12345 << endl;
	std::cout << testing2 << ' ' << 186254 << endl;
	std::cout << testing3 << ' ' << 164284 << endl;
	std::cout << testing4 << ' ' << 186299 << endl;
	std::cout << testing5 << ' ' << 186255 << endl;
	std::cout << testing6 << ' ' << 999999 << endl;
	std::cout << testing8 << ' ' << 3425 << endl;

	//passing some keys and our values to our add function
	Key.add(testing1, 12345);
	Key.add(testing2, 186254);
	Key.add(testing3, 164284);
	Key.add(testing4, 186299);
	Key.add(testing5, 186255);
	Key.add(testing6, 999999);
	Key.add(testing8, 3425);

	std::cout << '\n';

	//passing our previous sample value from earlier and a number to be changed later
	std::cout << "If the value is found from the key, print the id:\n";
	std::cout << "Trial 1:" << '\n';
	Key.get(testing1, numTest); // should NOT be Adam West
	std::cout << '\n';

	std::cout << "Trial 2:" << '\n';
	Key.get(testing4, numTest);
	std::cout << '\n';

	std::cout << "Trial 3:" << '\n';
	Key.get(testing3, numTest);

	std::cout << '\n';

	std::cout << "Testing howMany with 'Ad': \n";
	std::cout << Key.howMany("Ad") << '\n';
	std::cout << "Testing howMany with 'Suz' \n";
	std::cout << Key.howMany("Suz") << '\n';
*/
	//std::cout << "Testing Remove(): \n";
	//Key.remove(testing3);

	//This is for generating timings to be put into a graph
	srand(time(NULL));
	int testSize = 1500;
	int randomNum = rand() % 100;
	int secondRando = rand() % 300;

	//fill the array to test the searches
	//cout << "Adding...\n";
	for (int i = 0; i < testSize; i++) {
		Key.add(Key.fillWithKeys(i), randomNum);
	}

	//Array and List Setups
	clock_t start, diff;
	double timeAmount = 0;

	//start the graph development
	cout << "Getting... \n";
	start = clock(); //start the clock
	for (int i = 1; i < testSize; i += 10) {

		Key.get(Key.fillWithKeys(i), randomNum);


		diff = clock() - start;
		//converts to seconds
		timeAmount = diff * 1.0 / CLOCKS_PER_SEC;
		//print results
		std::cout << i << ' ' << timeAmount << "\n";
		std::cout << std::flush;
	}

	return 0;
}
