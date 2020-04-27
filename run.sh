clang++ -std=c++11 \
main.cpp *.hpp \
-Wall -Wextra -Werror -Wconversion \
rope/*.cpp rope/*.hpp \
rope/vec/*.hpp \
&& ./a.out