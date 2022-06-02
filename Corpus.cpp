#include "Corpus.h"
#include <iostream>
#define d 256
using namespace std;


void badCharHeuristic(string text, int size, int badchar[2000])
{
	int i;
	for (i = 0; i < 2000; i++) {
		badchar[i] = -1;
	}
	for (i = 0; i < size; i++) {
		badchar[(int)text[i]] = i;
	}
}
bool Corpus::Hamming_distance(string pattern, string text) {
	
	for (int i = 0; i < text.size(); i++) {
		int counter = 0;
		int k = i;
		for (int j = 0; j < pattern.size(); j++) {
			if (pattern[j] == text[k]) {
				counter++;
				k++;
			}
		}
		if (counter == pattern.size()) {
			return true;
		}
	}
	return false;
}
bool Corpus::Boyer_Moore(string str, string sentence) {
	int m = sentence.size();
	int n = str.size();
	int frequency = 0;
	int badchar[2000];
	badCharHeuristic(sentence, m, badchar);

	int s = 0; 
	while (s <= (n - m))
	{
		int j = m - 1;
		while (j >= 0 && sentence[j] == str[s + j])
			j--;

		if (j < 0)
		{
			frequency++;
			
			s += (s + m < n) ? m - badchar[str[s + m]] : 1;
		}
		else
			s += max(1, j - badchar[str[s + j]]);
	}
	if (frequency > 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Corpus:: RabinKarpStringMatching(string pattern, string text)
{
	int q = 101;
	int j;
	int m = pattern.length();
	int n = text.length();
	int hashcode = 0;
	int hashCode = 0;
	int h = 1;
	for (int i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}
	for (int i = 0; i < m; i++)
	{
		hashcode = (d * hashcode + pattern[i]) % q;
		hashCode = (d * hashCode + text[i]) % q;
	}

	for (int i = 0; i <= n - m; i++)
	{
		if (hashcode == hashCode)
		{
			bool flag = true;
			for (j = 0; j < m; j++)
			{
				if (text[i + j] != pattern[j])
				{
					flag = false;
					break;
				}
			}

			if (j == m)
			{
				return true;
			}

		}

		if (i < n - m)
		{
			hashCode = (d * (hashCode - text[i] * h) + text[i + m]) % q;

			if (hashCode < 0)
			{
				hashCode = (hashCode + q);
			}

		}
	}
	return false;
}
bool Corpus::KMP(string pattern, string text) {

	int patLen = pattern.length();
	int textLen = text.length();

	int *lps = new int[patLen];
	lps[0] = 0;

	int len = 0;
	int i = 1;
	int index = -1;

	while (i < patLen)
	{
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}

		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	i = 0;
	int j = 0;

	while (i < textLen) {

		if (pattern[j] == text[i]) {
			i++;
			j++;
		}

		if (j == patLen) {
			index = i - j;
			//cout << "Found pattern at: " << i - j << endl;
			j = lps[j - 1];
		}

		else if (i < textLen && pattern[j] != text[i]) {

			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				i++;
			}

		}

	}
	if (index >= 0) {
		return true;
	}
	else {
		return false;
	}

}
void Corpus::initialize_docs() {
	Document temp_doc;
	for (int i = 0; i < 6; i++) {
		temp_doc.directory = "Corpus/file"+to_string(i+1)+".txt" ;
		docs.push_back(temp_doc);
		docs[i].fill_in_text();
	}
	//cout << docs.size();

}