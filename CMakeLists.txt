cmake_minimum_required(VERSION 3.10)

# set the project name
project(intentRecognizer)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(intentRecognizer src/main.cpp src/Intent.cpp src/IntentClassifier.cpp src/EntityExtractor.cpp src/Entity.cpp src/Tokenizer.cpp) 
add_executable(test src/test.cpp src/Intent.cpp src/IntentClassifier.cpp src/EntityExtractor.cpp src/Entity.cpp src/Tokenizer.cpp) 
target_link_libraries(test gtest pthread)
