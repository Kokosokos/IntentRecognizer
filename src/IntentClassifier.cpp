#include "IntentClassifier.h"
#include <algorithm>
Intent::Pointer KeyWordIntentClassifier::getIntent(std::vector<std::string> sentence_vector)
{
	Intent::Pointer intent;
	for (const auto& word: sentence_vector)
	{
		auto low_word = word;
		std::transform(low_word.begin(), low_word.end(), low_word.begin(), ::tolower);
		if (m_known_intents.count(low_word))
		{
			return Intent::Pointer(new KeyWordIntent(m_known_intents.at(low_word)));
		}
	}
	return nullptr;
}
