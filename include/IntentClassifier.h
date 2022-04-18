#ifndef INCLUDE_INTENTCLASSIFIER_H_
#define INCLUDE_INTENTCLASSIFIER_H_
#include "Intent.h"

class IntentClassifier {
public:
	IntentClassifier() = default;
	virtual Intent::Pointer getIntent(std::vector<std::string> input) = 0;
	virtual ~IntentClassifier() = default;
private:
};

class KeyWordIntentClassifier:public IntentClassifier {
public:
	KeyWordIntentClassifier() = default;
	Intent::Pointer getIntent(std::vector<std::string> sentence_vector) override;
	~KeyWordIntentClassifier() = default;
private:
	std::unordered_map<std::string, IntentType> m_known_intents = {
			{"weather", IntentType::Weather}, {"fact", IntentType::Fact}};
};

//IntentClassifier based on Machine Learning classification
class MLIntentClassifier;

#endif /* INCLUDE_INTENTCLASSIFIER_H_ */
