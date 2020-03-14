#ifdef MAP_H
/*
 * Senior Portfolio Entry
 * Student Name: Chris McClure
 * Program Name: Large Map Project
 * Creation Date: Fall Semester 2018
 * Last Modified Date: 3/23/2019
 * CSCI Course: CSCI 315 Data Structures Analysis
 * Grade Received: 80%
 * Comments regarding design:
 *  The PDF attached to the project explains the full scope
 *  To run a test of the project, type within the github repo directory:
 *  "make && ./map-test"
 *
 * This will run the program and display the functionality of the program, not
 * necesarily show off the binary search capabilities
 */

Map::Map() {
    //functions for testing
    storeFirstNameVector(); //get firstnames from the .txt
    storeLastNameVector(); //get lastnames from the .txt
    keyMaker(); //at this point we now have full names instead of first OR last
    deriveIDbyIndex(); //Now we have ID's to throw into add() from main.cpp
}

/*
	The add() function is mainly for testing, being able to add values to a bank
	to be obtained from later
	Note: you can influence the performance for get() by adding the values pre sorted
 */
bool Map::add(const std::string key, int val) {
	std::string keyVal;
    int foundIndex;
	//if key and val are valid while the mCentral array is greater than 0
	if (key != "" && val > 0 && mCentral.size() >= 0) {
		//keyVal is the key with the val appended on the end
		keyVal = key + ' ' + std::to_string(val);

		foundIndex = binarySearch(mCentral, mCentral.size(), keyVal);
		if (foundIndex != -1 && mCentral[foundIndex] == keyVal) {
			std::cout << mCentral[foundIndex] << " & " << keyVal << '\n';
			return false;
		}
        mCentral.push_back(keyVal);

        //stl sort function after inserting the values so that binary search remains
        //valid throughout, speeding up our searches
        std::sort(mCentral.begin(), mCentral.end());

        //printVec(mCentral);

        /*
        At this point, our storeLastNameVector() and storeFirstNameVector()
        functions were used previously for testing for filling the vectors with
        a large number of values
         */

		return true;
	} else {return false;}

}

//unused binary search, since the stl sort was much easier to implement
int Map::binarySearch(std::vector<std::string> list, int length, std::string& val) {
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found) {
        mid = (first + last) / 2;

        if (findKey(list[mid]) == val + ' ') {//if the middle is the same...
            //std::cout << "Mark: " << findKey(list[mid]) << '\n';
            return mid;
            found = true;
        } else if (findKey(list[mid]) > val) {
            //std::cout << "Mark: " << val << findKey(list[mid]) << '\n';
            last = mid - 1;
        } else if (findKey(list[mid]) < val) {
            //std::cout << "Mark: " << findKey(list[mid]) << '\n';
            first = mid + 1;
        }
    }

    if (found) {
        //std::cout << "Key Found!! \n";
        return mid;
    } else {
        //std::cout << "Key Not Found!! \n";
        return -1;
    }
}

//retrieves the key from the inserted string to be used with the binary search
std::string Map::findKey(std::string& keyVal) {
    std::string stringKey;
    int length = stringKey.length();
	for (int i = 0; i < keyVal.length(); i++) {
		if (!isdigit(keyVal[i])) {
			stringKey += keyVal[i];
		}
	}
	return stringKey;
}

//This function finds the ID from our Key by parsing the string, but used outside of
//binarysearch
int Map::findID(std::string& keyVal) {
	std::string stringID;
	int ID;

	for (int i = 0; i < keyVal.length(); i++) {
		if (isdigit(keyVal[i])) {
			stringID += keyVal[i];
		}
	}
    //kills the whitespace- makes it friendlier to handle
	std::stringstream ss(stringID);
	ss >> ID;
	return ID;
}

/*
    Utilizes the STL binarySearch function to retrieve the key marking as found
 */
bool Map::get(const std::string key, int &ret) {
    int foundIndex;
    std::string keyCon = key;

    foundIndex = binarySearch(mCentral, mCentral.size(), keyCon);

    ret = findID(mCentral[foundIndex]);

	if (ret != NULL) {
		//std::cout << ret << '\n';
        return ret;
    } else {
        return false;
    }
}

//returns size of the large map vector, mCentral
int Map::size() {
    return sizeof(mCentral);
}

bool Map::remove(const std::string key) {
	int foundIndex;
    std::string keyCon = key;

    foundIndex = binarySearch(mCentral, mCentral.size(), keyCon);
	std::cout << mCentral[foundIndex] << '\n';
	if (foundIndex != -1) {
		mCentral.erase(mCentral.begin() + foundIndex);
		std::cout << mCentral[foundIndex] << '\n';
		return true;
	}

    return false;
}

/*
    Return the number of entries with the given prefix
 */
int Map::howMany(const std::string prefix) { //"Ad"
	int result = 0;
	int count = 0;
    for (int i = 0; i < mCentral.size(); i++) {
        result = alphaCompare(prefix, mCentral[i]);
		if (result == 1) {
			count++;
		}
		//std::cout << "Count: " << count << '\n';
    }
	//std::cout << "Result: " << '\n';
	return count;
}

//This compares the first 3 letters of the string and returns how many letters match
int Map::alphaCompare(const std::string prefix, std::string vecEntry) {
    int alphaCount = 0;
	std::size_t prefixFound = vecEntry.find(prefix);

	if (prefixFound != std::string::npos) {
		//std::cout << "Prefix: " << prefix << '\n';
    	return 1;
	}

}


int Map::getLength(std::string subject) {
    int length;
    length = subject.length();
    //std::cout << length << std::endl;
    return length;
}

/*Programmer-created Functions*/
/*Sets the *mFirstNames vector based off of the text file firstnames.txt*/
void Map::storeFirstNameVector(){
    std::string  inputStringHolder;
    std::ifstream dataIn;
    dataIn.open("firstnames.txt");

    dataIn >> inputStringHolder; //replace input

    while (!dataIn.eof()) {
        //std::cout << inputStringHolder << std::endl;
        mFirstNames.push_back(inputStringHolder);
        dataIn >> inputStringHolder;
    }
    dataIn.close();

    //printVec(mFirstNames);
}

/*Sets the mLastNames vector based off of the text file lastnames.txt*/
void Map::storeLastNameVector(){
    std::string inputStringHolder;
    std::ifstream dataIn;
    dataIn.open("lastnames.txt");

    dataIn >> inputStringHolder; //replace input
    while (!dataIn.eof()) {
    	mLastNames.push_back(inputStringHolder);
    	dataIn >> inputStringHolder;
    }

    dataIn.close();

    //printVec(mLastNames);
}

/*Will use a for loop to concatenate the strings of our firstnames and mLastNames
by way of vector address's and store them into the *mKeyList vector*/
void Map::keyMaker(){
    int i;
    std::string key;
	char newline = '\n';
    for (i = 0; i < TESTSIZE; i++) {

        //concatenate from mFirstNames and mLastNames vectors
        int firstSize = mFirstNames[i].length();
        int lastSize = mLastNames[i].length();
        int allTogether = firstSize + lastSize + 1;

		key = key + mFirstNames[i];
		key = key + ' ';
		key = key + mLastNames[i];
		key = key + newline;

        mKeyList.push_back(key);
    }
    //printVec(mKeyList);

}

int Map::getKeyLength() {
    return mKeyList.size();
}

//testing function in main
std::string Map::fillWithKeys(int index) {
	return mKeyList[index];
}

int Map::fillWithIDs(int index) {
	return mIDList[index];
}

/*Will use another for loop to set the mIDList vector index equal to index of each
 vector location in order to create the ID's, primarily for testing purposes*/
void Map::deriveIDbyIndex() {
    int IDholder;
	srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        IDholder = rand() % 100;
        mIDList.push_back(IDholder);
    }
    //printVec(mIDList);
}

void Map::printVec(std::vector<std::string> printVec) {
    for (int i = 0; i < (signed) printVec.size(); i++) {
        std::cout << printVec[i] << std::endl;
    }
	if (!printVec.empty()) {
		std::cout << "Number of Items: " << printVec.size() << '\n';
	}

}

Map::~Map() {
}
#endif
