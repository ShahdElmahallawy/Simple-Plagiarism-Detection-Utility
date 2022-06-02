#include "Program_run.h"
#include <chrono>
//get the doc we need to check from the user 
void Program_run::get_doc(string directory) 
{
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i] == '\\') 
		{
			directory[i] = '/';
		}
	}
	doc.directory = directory;
	C.initialize_docs();//intialize the docs we have in corpurs
	doc.populate_sentences();
	doc.adjust_sentences();
}
void Program_run::check_match_kmp() 
{
	auto started = std::chrono::steady_clock::now();

	for (int i = 0; i < doc.sentences.size(); i++) {
		for (int j = 0; j < C.docs.size(); j++) {
			if (C.KMP(doc.sentences[i], C.docs[j].text)) {
				plagiarized_sentence S;
				S.content = doc.sentences[i];
				S.doc_dir = C.docs[j].directory;
				results_KMP[S.doc_dir]++;
				KMP_result.push_back(S);
				break;
			}
		}
	}
	auto done = std::chrono::steady_clock::now();

	time_KMP = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
}


void Program_run::check_match_rabin() {
	auto started = std::chrono::steady_clock::now();
	for (int i = 0; i < doc.sentences.size(); i++) {
		for (int j = 0; j < C.docs.size(); j++) {
			if (C.KMP(doc.sentences[i], C.docs[j].text)) {
				plagiarized_sentence S;
				S.content = doc.sentences[i];
				S.doc_dir = C.docs[j].directory;
				results_Rabin[S.doc_dir]++;
				Rabin_result.push_back(S);
				break;
			}
		}
	}
	auto done = std::chrono::steady_clock::now();
	time_Rabin = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
}
void Program_run::check_match_Booyer() {
	auto started = std::chrono::steady_clock::now();
	for (int i = 0; i < doc.sentences.size(); i++) {
		for (int j = 0; j < C.docs.size(); j++) {
			if (C.KMP(doc.sentences[i], C.docs[j].text)) {
				plagiarized_sentence S;
				S.content = doc.sentences[i];
				S.doc_dir = C.docs[j].directory;
				results_Booyer[S.doc_dir]++;
				Booyer_result.push_back(S);
				break;
			}
		}
	}
	auto done = std::chrono::steady_clock::now();

	time_Booyer = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();

}
void Program_run::check_match_hamming() 
{
	auto started = std::chrono::steady_clock::now();
	for (int i = 0; i < doc.sentences.size(); i++)
	{
		for (int j = 0; j < C.docs.size(); j++)
		{
			if (C.Hamming_distance(doc.sentences[i], C.docs[j].text))//pass to it the 
			{
				plagiarized_sentence S;
				S.content = doc.sentences[i];
				S.doc_dir = C.docs[j].directory;
				results_Hamming[S.doc_dir]++;
				Hamming_result.push_back(S);
				break;
			}
		}
	}
	auto done = std::chrono::steady_clock::now();

	time_Hamming = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
}
