clang++ -Wall -Wextra -Werror main_std.cpp -o std
clang++ -Wall -Wextra -Werror main_ft.cpp -o ft
time ./std | tee  
time ./ft  | tee 
# echo
# echo "========  diff =============" && \
# diff stdout ftout 
rm -rf ./std ./ft