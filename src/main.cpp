#include <iostream>
#include <string>
#include <vector>

#include "EntityExtractor.h"
#include "IntentClassifier.h"
#include "Tokenizer.h"

std::string getIntentString(std::string in_sentence);


int main(int argc, char*argv[])
{
	std::cout<<"Hello! How can I help you? \n";
	std::string exit_str  = "exit ciao bye quit";
	std::string input;

	while (std::getline (std::cin,input) and exit_str.find(input) == std::string::npos)
	{
		std::cout<<getIntentString(input)<<"\n";
	}

	std::cout<<"Good bye\n";
	return 0;
}

std::string getIntentString(std::string in_sentence)
{
	//Preprocess: Tokenize == split
	Tokenizer tk;
	auto words = tk.tokenize(in_sentence);
	//Additional step:
	//Word embedding: word -> vector (for ML Extractors and IntentClassifiers)

	KeyWordsEntityExtractor simpleExtractor;
	auto entities = simpleExtractor.getEntities(words);

	std::string res ="Intent: ";
	KeyWordIntentClassifier simpleIntentClassifier;

	//Can also use entities to help extract intent
	auto intent = simpleIntentClassifier.getIntent(words);
	if (!intent)
		return "I am too young to understand your intentions";

	res += intent->getString();

	for (auto& entinty: entities)
	{
		res += " " + entinty->getString();
	}
	return res;
}
