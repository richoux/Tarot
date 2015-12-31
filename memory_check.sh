valgrind --leak-check=full --show-reachable=yes bin/tarot --auto
valgrind --tool=cachegrind bin/tarot --auto
