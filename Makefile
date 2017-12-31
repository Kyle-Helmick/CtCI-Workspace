all:
	make chapter1 chapter1-run
chapter1:
		g++ Chapter1/Question1.cpp -o Executables/Q1-1
		g++ Chapter1/Question2.cpp -o Executables/Q1-2
		g++ Chapter1/Question3.cpp -o Executables/Q1-3
		g++ Chapter1/Question4.cpp -o Executables/Q1-4
		g++ Chapter1/Question5.cpp -o Executables/Q1-5
		g++ Chapter1/Question6.cpp -o Executables/Q1-6
		#g++ Chapter1/Question7.cpp -o Executables/Q1-7
		#g++ Chapter1/Question8.cpp -o Executables/Q1-8
		#g++ Chapter1/Question9.cpp -o Executables/Q1-9

chapter1-run:
		./Executables/Q1-1
		./Executables/Q1-2
		./Executables/Q1-3
		./Executables/Q1-4
		./Executables/Q1-5
		./Executables/Q1-6
		#./Executables/Q1-7
		#./Executables/Q1-8
		#./Executables/Q1-9

clean:
		rm Executables/*