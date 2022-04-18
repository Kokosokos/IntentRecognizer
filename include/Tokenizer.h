/*
 * Tokenizer.h
 *
 *  Created on: Apr 16, 2022
 *      Author: ivan
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_
#include <string>
#include <vector>

class Tokenizer {
public:
	Tokenizer() = default;
	~Tokenizer() = default;
	std::vector<std::string> tokenize(std::string sentence);
};

#endif /* TOKENIZER_H_ */
