#include <iostream>
using namespace std;
#include "Program_run.h"
#include <iterator>
int main()
{
	cout << "Welcome" << endl;
	
	string ans;
	while (true) {
		Program_run run;
		cout << "Please Enter the directory of the file you want to detect Plagiarism in: " << endl;
		string directory;
		getline(cin, directory);
		run.get_doc(directory);
		cout << "The number of sentences in the entered directory is " << run.doc.sentences.size() << endl;
		cout << "Please choose the algorithm you want to use for detecting plagiarism" << endl;
		cout << "1. Hamming distance " << endl << "2. Rabin Karp" << endl << "3. KMP" << endl << "4. Booyer Moore" << endl;
		cin >> ans;
		cout << endl;
		if (ans == "1") {
			cout << "Please wait while the program detects plagiarism" << endl;
			run.check_match_hamming();
			map <string, int> ::iterator it;
			for (auto const& pair : run.results_Hamming) {
				cout << "Number of plagiarized sentences: " << pair.second <<endl<< "Plagiarized from :" << pair.first << endl;
			}
			cout << endl;
			cout << "----------------------------------" << endl;
			cout << "Below are the plagiarized sentences" << endl;
			for (int i = 0; i < run.Hamming_result.size(); i++) {
				cout << "Sentence: " << run.Hamming_result[i].content << endl << "Plagiatized from:" << run.Hamming_result[i].doc_dir << endl;
			}
			cout << "Time used to detect plagiarism = " << run.time_Hamming << " ms" << endl;

		}
		else if (ans == "2"){
				run.check_match_rabin();
				map <string, int> ::iterator it;
				for (auto const& pair : run.results_Rabin) {
					cout << "Number of plagiarized sentences: " << pair.second<<endl << "Plagiarized from :" << pair.first << endl;
				}
				cout << endl;
				cout << "----------------------------------" << endl;
				cout << "Below are the plagiarized sentences" << endl;
				for (int i = 0; i < run.Rabin_result.size(); i++) {
					cout << "Sentence: " << run.Rabin_result[i].content << endl << "Plagiatized from:" << run.Rabin_result[i].doc_dir << endl;
				}
				cout << "Time used to detect plagiarism = " << run.time_Rabin << " ms" << endl;
		}
		else if (ans == "3") {
			run.check_match_kmp();
			map <string, int> ::iterator it;
			for (auto const& pair : run.results_KMP) {
				cout << "Number of plagiarized sentences: " << pair.second <<endl<< "Plagiarized from :" << pair.first << endl;
			}
			cout << endl;
			cout << "----------------------------------" << endl;
			cout << "Below are the plagiarized sentences" << endl;
			for (int i = 0; i < run.KMP_result.size(); i++) {
				cout << "Sentence: " << run.KMP_result[i].content << endl << "Plagiatized from:" << run.KMP_result[i].doc_dir << endl;
			}cout << "Time used to detect plagiarism = " << run.time_KMP << " ms" << endl;
		}
		else {
			run.check_match_Booyer();
			map <string, int> ::iterator it;
			for (auto const& pair : run.results_Booyer) {
				cout << "Number of plagiarized sentences: " << pair.second <<endl<< "Plagiarized from :" << pair.first << endl;
			}
			cout << endl;
			cout << "----------------------------------" << endl;
			cout << "Below are the plagiarized sentences" << endl;
			for (int i = 0; i < run.Booyer_result.size(); i++) {
				cout << "Sentence: " << run.Booyer_result[i].content << endl << "Plagiatized from:" << run.Booyer_result[i].doc_dir << endl;
			}cout << "Time used to detect plagiarism = " << run.time_Booyer <<" ms" <<endl;
		}
		cout << "What do yoou want: " << endl;
		cout << "1. Test another file" << endl;
		cout << "2. Exit" << endl;
		cout << "Your input: ";
		cin >> ans;
		if (ans == "2") {
			break;
		}
		
		cin.ignore();
	}

}


