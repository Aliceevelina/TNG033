//#include <algorithm>  //std::copy
//#include <fstream>
//#include <iostream>
//#include <iterator>
//#include <map>
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <utility>  //std::pair
//#include <cmath> //std::hypot
//#include <set>
//
////LÄS PÅ OM std::
//
////Pairing a string with a set of strings
//using my_pair = std::pair<std::string, std::set<std::string>>;
//
////Displaying the anagrams
//void display_anagram(std::string s) {
//	std::cout << s << " ";
//}
//
////As long as there is more than one word in the set, keep displaying the anagrams and the amount of words
//struct display {
//	void operator() (my_pair p) {
//		if (p.second.size() != 1){
//			std::for_each(p.second.begin(), p.second.end(), display_anagram);
//			std::cout << " ---> " << p.second.size() << " words. \n";
//		}
//	}
//};
//
//
//int main() {
//
//	//Loading file
//	std::ifstream in_file("uppgift2_kort.txt");
//
//	if (!in_file) {
//		std::cout << "Could not open file!\n";
//		return 1;
//	}
//
//	//Creating the word table to display
//	auto wordTable = std::map<std::string, std::set<std::string>>{};
//
//	//empty vector
//	std::vector<std::string> myWords;
//
//	 // create stream iterators operating on the file
//	//Iterator points to an element within a range
//	auto inIt = std::istream_iterator<std::string>{ in_file };
//	auto inItEnd = std::istream_iterator<std::string>{};  
//
//	//Copying all the words from the file into the vector
//	std::copy(inIt, inItEnd, back_inserter(myWords));
//	
//	std::cout << "Number of unique words in the file =  " << myWords.size() << "\n\n\n";
//
//	//Lambda expression, checks which subject a word belongs to and inserts it in the subject 
//	auto anagrams = [&wordTable](const std::string &word) {
//		std::string subject = word;
//		std::sort(subject.begin(), subject.end());
//		wordTable[subject].insert(word);
//	};
//	
//	//Loop that stores the anagrams correctly in wordTable
//	std::for_each(myWords.begin(), myWords.end(), anagrams);
//
//	std::cout << " ------ANAGRAMS------ \n";
//	std::for_each(wordTable.begin(), wordTable.end(), display{});
//
//		return 0;
//}
