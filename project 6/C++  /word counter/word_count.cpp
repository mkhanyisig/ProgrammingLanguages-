/**
		 * CS 333 Programming Languages FA17
		 * Project 5  task 1
		 *
		 * Mkhanyisi Gamedze
		 * 11 November  2017
*/


/*  Word Counter  */

//C++ program to count number of words in text file

#include<fstream>
#include<iostream>
#include<string>
#include<unordered_map>
#include<string>
#include<cctype>
#include<locale>
using namespace std;

struct kvpair{
	string word;
	int freq;
};

/*
*	To implement my sort function, I implemented this sort algorithm, motivated how I saw it being used at this reference link:
*	http://www.cplusplus.com/forum/beginner/137046/
*/
void sort(kvpair numbers[], int count){
    string s;
    for(int i = 0; i < count - 1; i++){
        int currentMin = numbers[i].freq;
        int currentMinIndex = i;

        for(int j = i + 1; j < count; j++){
            if(currentMin > numbers[j].freq){
                currentMin = numbers[j].freq;
                currentMinIndex = j;
            }
        } 
		if(currentMinIndex != i){
			// swap frequencies
			numbers[currentMinIndex].freq = numbers[i].freq;
			s=numbers[currentMinIndex].word;
			numbers[currentMinIndex].word = numbers[i].word;
			// swap words
			numbers[i].freq = currentMin;
			numbers[i].word = s;
			
		}
	}
}


unordered_map <string, int>  // unordered map to store my key-value pairs
insert(unordered_map <string, int> map1, string word){
    if (map1.find(word)!= map1.end()){
    	//cout<<word<<"*****already exists, increase frequency"<<endl;
        map1[word]++;  // if value already exists in map, increase its frequency s
    }
    else{
    	//cout<<"new word :"<<word<<endl;
        map1.insert(unordered_map<string,int>::value_type(word,1));   // add the word and initialize its frequency to 1
    }
    return map1;
}

int main(){
    ifstream inFile; //Declares a file stream object
    string fileName;
    string word;
    int count = 0;
    
    unordered_map <string, int> map; // unordered map to store my key-value pairs

    cout << "Please enter the file name ";
    getline(cin,fileName);

    inFile.open(fileName.c_str());
	
	if(inFile.fail() == true) {  // catching error
		cout << "Error: No such file exists in this directory "<< endl;
		return 0;
    }
    
    while(!inFile.eof()){               
        inFile >> word; 
        
        // cast to lowercase
        int i=0;
        char c;
		while (word[i]){
			c=word[i];
			word[i]=tolower(c);
			i++;
		} 
        // eliminate punctuation
        for (int i = 0, len=word.size(); i<len; i++){
			if (ispunct(word[i])){// if character is a punctuation variable, eliminate its
				word.erase(i--, 1);
				len = word.size();
			}
    	}
        
        map=insert(map, word);
        count++;
    }
    cout << "Number of words in file is :" << map.size();
    
    /*------------------   Sorting ---------------*/
    
    kvpair list[map.size()];
    
    // give struct frequency values a default -ve frequency, this is helpful in my mapArray map-function @ the top
	for(int i=0;i<(map.size());i++){
		list[i].freq=(-1*i);
	}
	
	// Get an iterator pointing to begining of map
	std::unordered_map<std::string, int>::iterator it = map.begin();
 
	// Iterate over the map using iterator
	int j=0;
	while (it != map.end()){
		//cout << it->first << " :: " << it->second <<endl;
		list[j].freq=it->second;
		list[j].word=it->first;
		it++;
		j++;
	}
 	
 	// quality check of my struct lists
 	cout<<"\n********* struct list Quality check"<<endl;
 	for(int i=0;i<map.size();i++){
 		cout << list[i].freq << " :: " << list[i].word <<endl;
 	}
 	
 	// Use sort to find the top 20 most frequent words
 	sort(list,map.size());
 	
 	cout<<"\n\n********* Final Output:  TOP 20 Words"<<endl;
 	
 	int i=map.size()-1;
 	for( int j=0;j<20;j++){
 		cout << list[i].freq << " :: " << list[i].word <<endl;
 		i--;
 	}
 	
 	
    inFile.close();

    cin.get();  
    return 0;
}