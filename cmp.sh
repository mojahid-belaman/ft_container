clang++ -Wall -Wextra -Werror org.cpp -o origin
clang++ -Wall -Wextra -Werror dup.cpp -o dup
./origin > original
./dup > duplicated
diff original duplicated
rm -rf duplicated dup
rm -rf original origin