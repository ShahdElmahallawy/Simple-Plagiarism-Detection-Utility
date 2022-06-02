#include "Document.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void Document::populate_sentences()
{
	fstream fin;
	fin.open(directory, ios::in);
	string temp, line, sentence;
	
	string last_sentence; 

	bool notdot = false;//A flag to hndle the case if the rest of the sentence in the next line .. if the sentence we take didn't end with dot
	while (getline(fin, temp))
	{
		stringstream S(temp);
		//cout << temp << endl;

		int counter = 0; //counter 0 we started a new line, so we cehck if the last char in the last sentence is "." or not

		while (getline(S, sentence, '.')) //get sentences until it finds "."
		{
			if (counter == 0 && notdot)
			{
				sentences.push_back(last_sentence + " " +sentence); // push back the whole sentence 
				last_sentence = sentence;
			}
			else 
			{
				sentences.push_back(sentence);
				last_sentence = sentence;
				counter++;
			}
		}
		if (temp.size() > 0)
		{
			if (temp[temp.size() - 1] != '.') //check if the last char in the the word = . 
			{
				notdot = true;
				sentences.pop_back(); //to remove the sentence if it is not full and put the whole sentence
			}
			
		}
		
	}
}
void Document::fill_in_text() 
{
	populate_sentences();
	adjust_sentences();
	text = "";
	for (int i = 0; i < sentences.size(); i++) 
	{
		text += sentences[i] + " ";
	}
}
//To eat whitespaces
void Document::adjust_sentences()
{
	for (int i = 0; i < sentences.size(); i++) 
	{
		string temp = ""; 
		bool flag = false;
		for (int j = 0; j < sentences[i].size(); j++) 
		{
			if (sentences[i][j] != ' ' && !flag) 
			{
				flag = true;
			} 
			if (flag) 
			{
				temp += sentences[i][j]; //put adjusted sentences in a tepm an then push it back to sentences
			}
		}
		sentences[i] = temp;
	}
}