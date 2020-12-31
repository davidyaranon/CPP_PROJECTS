#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//Globally declared variable hashmap
unordered_map<string, bool> hashmap;

void checkValidity(){
    string temp;
    int numValidInReverse = 0;
    for(auto& i: hashmap) //Using auto in C++ makes looping through hashmap way easier
    {
        //Refers to the word from the file, or 'key', in the {key, value} pairing, where key is a string (i.first) and value is true or false (i.second)
        temp = i.first; 
        reverse(temp.begin(), temp.end()); //Reverses word
        auto got = hashmap.find(temp); //got attempts to find reversed word in hashmap
        if(got != hashmap.end()){ //If found...
            cout << i.first << endl;
            numValidInReverse++;
        }
    }
    cout << "Number of words that are also valid words when read backwards: " << numValidInReverse << endl;
}

void readFile(string fileName){
    ifstream file(fileName);
    string word, temp;
    do //do-while ensures first line is read
    {
        file >> word;
        hashmap.insert({word, true});

        /*IF YOU JUST WANT PALINDROMES, YOU CAN SIMULATANEOUSLY CHECK WHILE READING THROUGH FILE... USE THIS ->
        temp = word;
        reverse(temp.begin(), temp.end());
        if(word == temp){
           cout << word << endl;
           numPalindromes++;
        }*/

    } while(getline(file, word));
}

int main(){
    string fileName;
    cout << "Enter text file name we are going to look through (words.txt or words2.txt): " << endl;
    cin >> fileName;

    readFile(fileName); //Reads through given file and stores words in hashmap
    checkValidity(); //Checks if word is valid when in reverse

return 0;
}