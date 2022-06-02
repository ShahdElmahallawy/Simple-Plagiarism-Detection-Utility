#pragma once
#include "P_P_document.h"
#include <iostream>
#include <vector>
using namespace std;
class Corpus
{
public:
	vector<Document> docs;
	P_P_document target_doc;
	bool RabinKarpStringMatching(string pattern, string text);
	bool KMP(string pattern , string text);
	bool Boyer_Moore(string pattern, string text);
	bool Hamming_distance(string patter, string text);
	void initialize_docs();
};

