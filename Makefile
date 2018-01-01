main:
		make clean

		mkdir Executables/Chapter1
		mkdir Executables/Chapter2
		mkdir Executables/Chapter3
		mkdir Executables/Chapter4
		mkdir Executables/Chapter5
		mkdir Executables/Chapter6
		mkdir Executables/Chapter7
		mkdir Executables/Chapter8
		mkdir Executables/Chapter9

		make build-all

build-all: $(patsubst %.cpp, %.out, $(wildcard Chapter*/*.cpp))

%.out: %.cpp
		g++ $< -o Executables/$@
		./Executables/$@

clean:
		rm -rf Executables/Chapter*