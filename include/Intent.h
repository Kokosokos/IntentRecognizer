#ifndef INCLUDE_INTENT_H_
#define INCLUDE_INTENT_H_

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

enum class IntentType{Weather, Fact, Unknown};
static std::unordered_map<IntentType, std::string> g_IntentTypeString = {
		{IntentType::Weather, "Get Weather"},{IntentType::Fact, "Get Fact"}, {IntentType::Unknown, ""}
	};
class Intent {
public:
	using Pointer = std::unique_ptr<Intent>;
	Intent() = default;
	virtual std::string getString() {return m_intent_string;}
	virtual ~Intent() = default;
private:
	std::string m_intent_string;
};

class KeyWordIntent:public Intent
{
public:
	KeyWordIntent(IntentType intent_type): m_intent_type(intent_type){}
	std::string getString() override {return g_IntentTypeString[m_intent_type];}
	~KeyWordIntent() = default;
private:
	IntentType m_intent_type;
};

#endif /* INCLUDE_INTENT_H_ */
