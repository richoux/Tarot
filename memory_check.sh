make clean
make debug
valgrind --leak-check=full --show-reachable=yes bin/tarot --debug
valgrind --tool=cachegrind bin/tarot --debug
