#include <limits.h>
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "Tokenizer.h"
#include "IntentClassifier.h"

TEST(TokenizerTest, SplitsSentenceIntoWords)
{
	std::string sentence = "alijgf, saf as ! ? ogas";
	std::vector<std::string> words = {"alijgf", "saf", "as", "ogas"};
	Tokenizer tk;
	auto tokenized_sentence = tk.tokenize(sentence);
	EXPECT_EQ(tokenized_sentence,words)<<"Original sentence: "<<sentence<<"\n";
}

TEST(IntentRecognizerTest, WeatherFactTests)
{
	std::vector<std::string> words1 = {"Weather", "saf", "fact", "ogas"};
	std::string res1{"Get Weather"};
	std::vector<std::string> words2 = {"boom", "saf", "fact", "ogas"};
	std::string res2{"Get Fact"};
	KeyWordIntentClassifier ic;

	EXPECT_EQ(ic.getIntent(words1)->getString(),res1);
	EXPECT_EQ(ic.getIntent(words2)->getString(),res2);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}
