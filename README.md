# IntentRecognizer
A small intent recognition command line tool.
The initial implementation works by searching "key words" in a sentence (TO DO: ML intent recognizer).
The vocabulary is built-in and quite narrow but can be extended (TO DO: vocab from file).

# Easy Build
mkdir build && cd build && cmake .. && make

# Examples
What is the weather like today? => Prints (Intent: Get Weather)
What is the weather like in Paris today? => Prints (Intent: Get Weather City)
Tell me an interesting fact. => Prints (Intent: Get Fact)
Weather? => Prints (Intent: Get Weather)
