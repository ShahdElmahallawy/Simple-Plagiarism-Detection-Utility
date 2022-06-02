#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Document
{
public:
	string directory;
	vector <string> sentences;
	void populate_sentences();
	string text;
	void fill_in_text();
	void adjust_sentences();
};

