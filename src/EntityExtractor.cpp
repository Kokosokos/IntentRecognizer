#include <EntityExtractor.h>
#include <iostream>
std::vector<Entity::Pointer> KeyWordsEntityExtractor::getEntities(
		std::vector<std::string> sentence_vector) {
	std::vector<Entity::Pointer> res;
	//Some processing logic
	for (const auto& word: sentence_vector)
	{
		if (m_known_entities.count(word))
		{
			res.push_back(Entity::Pointer(new KeyWordEntity(m_known_entities.at(word))));
		}
	}
	return res;
}
