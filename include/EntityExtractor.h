#ifndef INCLUDE_ENTITYEXTRACTOR_H_
#define INCLUDE_ENTITYEXTRACTOR_H_
#include "Entity.h"

class EntityExtractor
{
public:
	EntityExtractor() = default;
	virtual std::vector<Entity::Pointer> getEntities(std::vector<std::string> sentence_vector) = 0;
	virtual ~EntityExtractor() = default;
};

class KeyWordsEntityExtractor:EntityExtractor
{
public:
	KeyWordsEntityExtractor() = default;
	std::vector<Entity::Pointer> getEntities(std::vector<std::string> sentence_vector) override;
	~KeyWordsEntityExtractor() = default;
private:
	std::unordered_map<std::string, EntityType> m_known_entities = {
										{"Paris", EntityType::City}};
};

//EntityExtractor based on regular expressions
class RegExpEntityExtractor;

//EntityExtractor based on Machine Learning classification
class MLEntityExtractor;

#endif /* INCLUDE_ENTITYEXTRACTOR_H_ */
