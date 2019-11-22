#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>


using namespace std;

template <typename T>
void DisplayContents(const T& input){
	for(auto element = input.cbegin();
			element != input.cend();
			++element){
		cout << *element << endl;
	}
}

template <typename elementType>
struct DisplayElementKeepcount{
	int count;
	DisplayElementKeepcount():count(0){}

	void operator()(const elementType& element){
		++count;
		cout << element << ' ';
	}
};
bool IsEven(const int& num){
	return ((num%2)==0);
}

int main(){
	vector <int> numsInVec{101, -4, 500, 21, 42, -1 };

	list<char> charsInList{ 'a', 'h', 'z','k', 'l' };
	cout << "Display elements in a vector using a lambda: " << endl;
	for_each(numsInVec.cbegin(),
			numsInVec.cend(),
			[](const int& element){
				cout << element << ' ';
				});
	cout << endl;

	for_each(charsInList.cbegin(),
			charsInList.cend(),
			[](const char & element){
				cout << element << ' ';
				});
	cout << endl;

	auto evenNum = find_if(numsInVec.cbegin(),
				numsInVec.cend(),
				[](const int& num){
					return ((num % 2) == 0);
					});
	if(evenNum != numsInVec.cend()){
		cout << "Even number in collection is :" << 
			*evenNum << endl;
	}
	int divisor = 2;
	auto elem = find_if( numsInVec.begin(),
					numsInVec.end(),
					[divisor](int dividend){
						return (dividend%divisor) == 0;
					});
	if(elem != numsInVec.end()){
		cout << "First element in vector divisible by " <<
			divisor;
		cout << ": " << *elem << endl;
	}
	
	cout << "\nTest lambda operation" << endl;
	vector <int> vecMultiplicand{ 0,1,2,3,4};
	vector <int> vecMultiplier{ 100,101,102,103,104 };

	vector <int> vecResult;

	vecResult.resize(vecMultiplier.size());

	transform(vecMultiplicand.begin(),
			vecMultiplicand.end(),
			vecMultiplier.begin(),
			vecResult.begin(),
			[](int a, int b){
				return a*b;
				});

	cout << "The contents of the first vector are: " <<endl;
	for(size_t index=0; index < vecMultiplicand.size(); ++index){
		cout << vecMultiplicand[ index ] << ' ';
	}
	cout << endl;

	cout << "The contents of the second vector are: " << endl;
	for(size_t index=0; index < vecMultiplier.size(); ++index){
		cout << vecMultiplier[index] << ' ';
	}
	cout << endl;

	cout << "The result of the multiplication is:" << endl;
	for(size_t index=0; index< vecResult.size(); ++ index){
		cout << vecResult[index] << ' ';
	}
	cout << endl;

	vector <string> namesInVec{ "jim", "Jack", "Sam", "Anna" };
	cout << "\nThe name in vector in order of insertion: " << endl;
	DisplayContents(namesInVec);

	cout << "\nOrder after case sensitive sort: " << endl;
	sort(namesInVec.begin(), namesInVec.end());
	DisplayContents(namesInVec);

	cout << "\nOrder after sort ignoring case: " << endl;
	sort(namesInVec.begin(),
			namesInVec.end(),
			[](const string& str1,
				const string& str2)-> bool{
				string str1LC; // lower case
				str1LC.resize(str1.size());

				transform(str1.begin(),
						str1.end(),
						str1LC.begin(),
						::tolower);
				string str2LC;
				str2LC.resize(str2.size());

				transform(str2.begin(),
						str2.end(),
						str2LC.begin(),
						::tolower);
				return (str1LC < str2LC);
				}
		);
	DisplayContents(namesInVec);

	size_t numZeros = count(numsInVec.cbegin(),
			numsInVec.cend(),
			21);
	cout << "Number of instances of '21': " << numZeros <<endl;
	cout << endl;

	cout << "\nTest search ..." << endl;
	vector <int> numsInVec1{2017,0,-1, 42, 10101, 25, 9 ,9 ,9 };
	list<int> numsInList1{ -1, 42, 10101};

	cout << "The contents of the sample vector are: " << endl;
	DisplayContents(numsInVec1);

	cout << "search() for the conents of list in vector"<<endl;
	auto range = search(numsInVec1.cbegin(),
			numsInVec1.cend(),
			numsInList1.cbegin(),
			numsInList1.cend()
			);
	if(range != numsInVec.end()){
		cout << "Sequenced in list found in vector at position: ";
		cout << distance(numsInVec1.cbegin(), range) <<endl;
	}

	cout << "Searching {9,9,9} in vector: " << endl;
	auto partialRange = search_n(numsInVec1.cbegin(),
				numsInVec1.cend(),
				3,
				9);
	if(partialRange != numsInVec1.end()){
		cout <<"Sequence found"<<endl;
		cout << distance(numsInVec1.cbegin(), partialRange)<<endl;
	}

	cout <<"\nfill in container"<<endl;
	vector <int> numsInVec2(3);
	fill(numsInVec2.begin(), numsInVec2.end(), 9);
	DisplayContents(numsInVec2);

	numsInVec2.resize(6);
	fill_n(numsInVec2.begin()+3, 3, -9);
	cout<<"Contents of the new vector are: " << endl;
	DisplayContents(numsInVec2);

	cout << "\nGenerate ..." << endl;
	srand(time(NULL)); // seed random generator using time
	
	vector <int> numsVec(5);
	generate(numsVec.begin(),
			numsVec.end(),
			rand);
	DisplayContents(numsVec);

	list<int> numsList(5);
	generate_n(numsList.begin(), 3, rand);
	cout <<"Elements in the list are:";
	DisplayContents(numsList);

	cout << " \
		elem" << endl;
	vector <int> numsVec2{2017,0,-1,42,10101,25};
	DisplayElementKeepcount<int> functor =
		for_each(numsVec2.cbegin(),
				numsVec2.cend(),
				DisplayElementKeepcount<int>());
	cout << endl;

	cout << "'" << functor.count << "' elements displayed" << endl;

	string str("for_each and string!");
	cout << "Sample string: " << str << endl;

	int numChars = 0;
	for_each(str.cbegin(),
			str.cend(),
			[&numChars](char c){
				cout << c << ' ';
				++numChars;
				});

	cout << endl;
	cout << "'" << numChars << "' characters displayed" << endl;

	string str1("This is a TEST string!");
	string strLowerCaseCopy;
	strLowerCaseCopy.resize(str1.size());

	transform(str1.cbegin(),
			str1.cend(),
			strLowerCaseCopy.begin(),
			::tolower);
	cout << "Result of transform: " << endl;
	cout << strLowerCaseCopy << endl;

	cout << "\n" << endl;
	list <int> numsInListA{2017,0,-1,42,10101,25};
	cout << "Source list contains:" << endl;
	DisplayContents(numsInListA);

	cout << "copy to VecA"<< endl;
	vector <int > numsInVecA(numsInListA.size()*2);

	auto lastElement = copy( numsInListA.cbegin(),
			numsInListA.cend(),
			numsInVecA.begin());
//	DisplayContents(lastElement);

	copy_if(numsInListA.cbegin(),
			numsInListA.cend(),
			lastElement,
			[](const int element){
				return ((element%2) != 0);}
			);
	cout << "After copy_if "<< endl;
	DisplayContents(numsInVecA);

	auto newEnd = remove(numsInVecA.begin(),
						numsInVecA.end(),
						0);
	numsInVecA.erase(newEnd, numsInVecA.end());
	cout << "\nAfter erase:"<< endl;
	DisplayContents(numsInVecA);

	cout << "\nreplace 5 by 8" << endl;
	replace_if(numsInVecA.begin(),
			numsInVecA.end(),
			[](const int element){
				return ((element %2) == 0);},
			-1);
	DisplayContents(numsInVecA);

	cout << "\nSearch"<<endl;
	vector <string> vecNames{"John","Jack", "Sean","Anna"};
	vecNames.push_back("Jack");
	cout <<"The initial contents of vector:" << endl;
	DisplayContents(vecNames);

	cout << "The sorted contents of Vector:" << endl;
	sort(vecNames.begin(),
			vecNames.end());
	DisplayContents(vecNames);

	auto minPos= lower_bound(vecNames.begin(),
			vecNames.end(),
			"Brad");
	cout << distance(vecNames.begin(), minPos)  << endl;


	bool elementFound = binary_search(vecNames.begin(),
			vecNames.end(),
			"John");
	if(elementFound){
		cout << "Found" << endl;
	}else{
		cout << "Not Found"<<endl;
	}

	auto newEndA = unique(vecNames.begin(), vecNames.end());
	vecNames.erase(newEndA, vecNames.end());
	cout << "After unique"<< endl;
	DisplayContents(vecNames);

	return 0;

}


		
