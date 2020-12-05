//******************************
//* TNG033 : Lab3 *
//* Exercise 1 *
//******************************* /

#include <algorithm>  //std::copy
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>  //std::pair
#include <cmath> //std::hypot


//std::ostream& operator<<(std::ostream& os, const my_pair& p)  // used by std::copy to copy table to cout
//{
//	os << p.first << ": " << p.second;
//
//	return os;
//}

//Pair a word with it´s occurences
using my_pair = std::pair<std::string, int>;


//Display
struct display {
	void operator() (my_pair p) {
		std::cout << std::left << std::setw(20) << p.first;
		std::cout << std::setw(10) << p.second;
		std::cout << "\n";
	}
};

//Valid characters
bool isRealChar(char x) {
	if (isalnum(x) || x == '\'') return false;
	else
		return true;
}

//Decreasing order of occurences		
bool sortDe (const my_pair &a, const my_pair &b) {

	if(a.second==b.second) return (a.first < b.first);
	return(a.second > b.second);
}

/******************************
	   MAIN
 *******************************/
int main() {

	std::ifstream in_file("uppgift1_kort.txt");

	if (!in_file) {
		std::cout << "Could not open file!\n";
		return 1;
	}

	//Creating a table that matches words with their occurences.  
	auto table = std::map<std::string, int>{};// frequency table

	std::string s;
	int counter = 0;

	while (in_file >> s) {

		s.erase(remove_if(s.begin(), s.end(), ::isRealChar), s.end()); //Erases the faulty characters 

		std::transform(s.begin(), s.end(), s.begin(), [](char c) { return static_cast<char>(::tolower(c)); }); //Transformes to lower case

		++table[s]; //Table stores all the uniqe words
		++counter; //counter (countes the duplets too)

	}

	std::cout << "Number of words in the file =  " << counter << "\n";
	std::cout << "Number of unique words in the file =  " << table.size() << "\n\n\n";

	// Display the frequency table
	std::cout << "Frequency table sorted alphabetically ..." << "\n\n";
	std::for_each(table.begin(), table.end(), display{});
	std::cout << "\n\n";


	//Vector, same size as table 
	//Skapar en vector av table direkt
	std::vector <my_pair> V(table.begin(), table.end());

	//Skapar en vektor utan någon size och fyller den efteråt
	//std::vector<my_pair> v;
	//v.assign(table.begin(), table.end());

	//Tar för mycket minne, onödigt att skapa vektorn med en size och sen skriva över
	//std::vector <my_pair> V(table.size()); 
	//
    //copy the table to V
    //std::copy(table.begin(), table.end(), V.begin());

	//sort after freq
	std::sort(V.begin(), V.end(), ::sortDe);

	std::cout << "Frequency table sorted by frequence ..." << "\n\n";
	
	std::for_each(V.begin(), V.end(), display{}); 


	return 0;
}