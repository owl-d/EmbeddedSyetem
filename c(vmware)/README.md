gcc -c main.c
gcc -c client.c
gcc client.o main.o -o main
./main
