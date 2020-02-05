#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

//Function which generates all the permutations from the obtained array of words
//Using recursion to append each letter of the word till the end
//When function is returned prevWord is used to restore the previous stored letters and now append next character
void Permutations(vector<string> &v, string word, int word_index){
    if(word_index == v.size()){
        ans.push_back(word);
        return;
    }
    string prevWord = word;
    for(int i=0; i<v[word_index].size(); i++){
        word += v[word_index][i];
        Permutations(v,word,word_index+1);
        word = prevWord;
    }
}
	
int main() {

	//Opening the CSV file in read mode
    fstream f;
    f.open("input.csv", ios::in);

    string temp, line, word;
    vector<string> v;

    //Reading the CSV file
    while(f >> temp){
    	word = "";
    	getline(f, line, '\n');

    	//Appending the first character
		word += temp[1];

		//Checking the obtained line for characters and appending in a string variable
		for(auto x: line) if((x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z')) word += x;
		v.push_back(word);
    }


    Permutations(v,"",0);

    //Printing the required output
    int len = ans.size();
    for(int i=0; i<len-1; i++) cout << ans[i] << ", ";
    cout << ans[len-1];
}