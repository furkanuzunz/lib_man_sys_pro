all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/menu.cpp -o ./lib/menu.o
	g++ -c -I "./include" ./src/bookmanager.cpp -o ./lib/bookmanager.o
	g++ -c -I "./include" ./src/personelbook.cpp -o ./lib/personelbook.o
	g++ -c -I "./include" ./src/usermanager.cpp -o ./lib/usermanager.o
	g++ -c -I "./include" ./src/userbook.cpp -o ./lib/userbook.o
	g++ -c -I "./include" ./src/loadstack.cpp -o ./lib/loadstack.o
	g++ -c -I "./include" ./src/returnedstack.cpp -o ./lib/returnedstack.o
	g++ -c -I "./include" ./src/personelloadlist.cpp -o ./lib/personelloadlist.o
	g++ -c -I "./include" ./src/requestnode.cpp -o ./lib/requestnode.o
	g++ -c -I "./include" ./src/requestqueue.cpp -o ./lib/requestqueue.o
	g++ -c -I "./include" ./src/booktree.cpp -o ./lib/booktree.o
	g++ -c -I "./include" ./src/booktreenode.cpp -o ./lib/booktreenode.o
	g++ -c -I "./include" ./src/hashtable.cpp -o ./lib/hashtable.o
	g++ -c -I "./include" ./src/hashentry.cpp -o ./lib/hashentry.o

bagla:
	g++ ./lib/main.o ./lib/menu.o ./lib/bookmanager.o ./lib/personelbook.o ./lib/usermanager.o ./lib/userbook.o ./lib/loadstack.o ./lib/returnedstack.o ./lib/personelloadlist.o ./lib/requestnode.o ./lib/requestqueue.o ./lib/booktree.o ./lib/booktreenode.o ./lib/hashentry.o ./lib/hashtable.o -o ./bin/kitapYonetim

calistir:
	./bin/kitapYonetim

temizle:
	del /Q lib\*.o
	del /Q bin\kitapYonetim.exe
