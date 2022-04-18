#ifndef INCLUDE_ENTITY_H_
#define INCLUDE_ENTITY_H_

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

enum class EntityType{ City, Unknown};
static std::unordered_map<EntityType, std::string> g_EntityTypeString = {
		{EntityType::City, "City"}, {EntityType::Unknown, ""}
};

class Entity {
public:
	using Pointer = std::unique_ptr<Entity>;
	Entity() = default;
	virtual std::string getString() = 0;
	virtual ~Entity() = default;

};

class KeyWordEntity:public Entity
{
public:
	KeyWordEntity(EntityType entity_type):m_entity_type(entity_type){}
	std::string getString() override {return g_EntityTypeString[m_entity_type];}
	~KeyWordEntity() = default;
private:
	EntityType  m_entity_type;
	std::string m_entity_info;
};

#endif /* INCLUDE_ENTITY_H_ */
