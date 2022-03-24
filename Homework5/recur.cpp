#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int loadDictionary(istream &dictfile, vector<string> &dict);
int permute (string word, vector<string> &dict, vector<string> &results);

int loadDictionary(istream &dictfile, vector<string> &dict){
    int count = 0;
    string words = "";
    while (getline(dictfile, words)){
        dict.push_back(words);
        count++;
    }
    return count;
}

int permute (string word, vector<string> &dict, vector<string> &results){
    int count = 0;
    while (!dict.empty()){
        string temp = dict.front();
        do{
            if (word == dict.front()){
                results.push_back(word);
                count++;
            }
        }while(next_permutation(word.begin(),word.end()));
        dict.erase(dict.begin());
    }
    return count;
}

int main(){
    ifstream infile;
    vector<string> dict;
    string filename = "words.txt";
//    string filename = "/Users/junnymac/Desktop/Fall 2021/CSCI 02 0130/Assignment/Homework5/words.txt";
    infile.open(filename);
    int count = loadDictionary(infile, dict);
    if (count == 0){
        cout<<"File does not exist!"<<endl;
        exit(0);
    }
    string target = "";
    cout<<"Please enter a string for an anagram: ";
    cin>>target;
    vector<string> dict_result;

    int count_match = permute(target, dict, dict_result);
    if (count_match == 0){
        cout<<"No matches found"<<endl;
    }else{
        while(!dict_result.empty()){
            cout<<"Matching word "<<dict_result.front()<<endl;
            dict_result.erase(dict_result.begin());
        }
    }
    infile.close();
    return 0;
}

