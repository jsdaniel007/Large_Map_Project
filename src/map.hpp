#ifndef MAP_H
#define MAP_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <string.h>
#include <algorithm>


class Map{
    public:
        Map();
        /* Adds (inserts) val with the associated key.
         * Returns if successful or not.  (It is not successful if we are out of
         * memory, or if the key already exists.)
         */

        bool add(const std::string key, int val);

        //Off the shelve binary Search
        int binarySearch( std::vector<std::string> list, int length, std::string& val);
		int alphaCompare(const std::string prefix, std::string vecEntry);
		int fillWithIDs(int index);
        /* Searches for the key.  If found it sets ret to the correct val and
         * returns true.  Otherwise this function returns false.
         */
        /*In essence: finds the key by going through the vector, then set the
		ret = to the value assosciated with the key*/
        bool get(const std::string key, int &ret);

        /* Returns the size (memory consumed) by this data structure. */
        int size();

        /* Removes the current value from the Map AND frees up any memory that
         * it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const std::string key);

        /*How this works:
            +Compare the first three characters using str.at(#)*/
        int howMany(const std::string prefix);

        /* Frees all memory */
        ~Map();

		/*Programmer-created Functions*/
		/*Sets the *mFirstNames vector based off of the text file firstnames.txt*/
		void storeFirstNameVector();

		/*Sets the *mLastNames vector based off of the text file lastnames.txt*/
		void storeLastNameVector();

		/*Will use a for loop to concatenate the strings of our firstnames and mLastNames
		by way of vector address's and store them into the *mKeyList vector*/
		//Note: experiment with both a deep copy and a shallow copy
		void keyMaker();

		/*This is just for testing, as in main this will return the mKeyList */
		std::string fillWithKeys(int index);

        //finds the ID of the
		int findID(std::string& keyVal);

        std::string findKey(std::string& keyVal);

		/*Will use another for loop to set the mIDList vector index equal to index of each
		 vector location in order to create the ID's*/
		void deriveIDbyIndex();

		void printVec(std::vector<std::string> printVec);

		void printVec(std::vector<int> printVec);

        int getLength(std::string subject);

        int getKeyLength();


    private:
		int const TESTSIZE = 5000;
		std::vector<std::string> mCentral;

		 //Empty Vector holding pointers of entries of firstnames.txt
		 std::vector<std::string> mFirstNames;
		 //Empty Vector holding pointers of entries of lastnames.txt
		 std::vector<std::string> mLastNames;

		 //Empty Vector holding pointers of entries of Keys (from nameMaker())
		 std::vector<std::string> mKeyList;

		 //Empty Vector holding entries of ID's
		 std::vector<int> mIDList;

         //Array specifically for the add function to be pulled from
         std::vector<std::string> mAddList;

         std::vector<int> mAddIDList;


};
#include "map.cpp"
#endif
