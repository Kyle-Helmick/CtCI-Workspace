all:
	make chapter1 chapter1-run
	make chapter2 chapter2-run

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

chapter2:
		g++ Chapter2/Question1.cpp -o Executables/Q2-1
		#g++ Chapter2/Question2.cpp -o Executables/Q2-2
		#g++ Chapter2/Question3.cpp -o Executables/Q2-3
		#g++ Chapter2/Question4.cpp -o Executables/Q2-4
		#g++ Chapter2/Question5.cpp -o Executables/Q2-5
		#g++ Chapter2/Question6.cpp -o Executables/Q2-6
		#g++ Chapter2/Question7.cpp -o Executables/Q2-7
		#g++ Chapter2/Question8.cpp -o Executables/Q2-8

chapter2-run:
		./Executables/Q2-1
		#./Executables/Q2-2
		#./Executables/Q2-3
		#./Executables/Q2-4
		#./Executables/Q2-5
		#./Executables/Q2-6
		#./Executables/Q2-7
		#./Executables/Q2-8

clean:
		rm Executables/*