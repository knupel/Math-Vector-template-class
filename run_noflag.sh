clang++ -std=c++11 \
main.cpp *.hpp \
rope/*.cpp rope/*.hpp \
rope/vec/*.hpp \
&& ./a.out \
&& rm rope/*.gch rope/vec/*.gch 