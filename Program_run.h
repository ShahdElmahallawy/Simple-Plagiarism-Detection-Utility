#pragma once
#include <iostream>
#include "Corpus.h"
#include <map>
using namespace std;
struct plagiarized_sentence {
	string content;
	string doc_dir;
};
class Program_run
{
public:
	Corpus C;
	P_P_document doc;
	map<string, int> results_KMP;
	map<string, int> results_Rabin;
	map<string, int> results_Booyer;
	map<string, int> results_Hamming;
	vector<plagiarized_sentence> KMP_result;
	vector<plagiarized_sentence> Rabin_result;
	vector<plagiarized_sentence> Hamming_result;
	vector<plagiarized_sentence> Booyer_result;
	long long time_KMP;
	long long time_Rabin;
	long long time_Booyer;
	long long time_Hamming;
	void check_match_kmp();
	void check_match_rabin();
	void check_match_Booyer();
	void check_match_hamming();
	void get_doc(string directory);
};

