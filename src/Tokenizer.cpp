#include "Tokenizer.h"
#include <sstream>
#include <iterator>
#include <algorithm>
std::vector<std::string> Tokenizer::tokenize(std::string in_sentence) {
	 std::string chars = ".?!,";

	in_sentence.erase(remove_if(in_sentence.begin(), in_sentence.end(),
	                        [&chars](const char &c) {
	                            return chars.find(c) != std::string::npos;
	                        }),
			in_sentence.end());
	std::istringstream iss(in_sentence);
	std::vector<std::string> sentence_vector((std::istream_iterator<std::string>(iss)),
	                                 std::istream_iterator<std::string>());

	return sentence_vector;


}
