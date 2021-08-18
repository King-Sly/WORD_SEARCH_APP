#Team: assignment2-asgmt2_team82

#Student 1:
##Name: Anahita Gupta
##CCID: anahita3
##student number: 1588387
##Lecture: B1 Akhmetov Ildar
##Lab: H02

##Student 2: 
##Name: Kingsley Okeke
##ccid:nkokeke
##student number: 1631514
##Lecture: B1 Akhmetov Ildar
##Lab: H02

wordSearch2D: puzzle2D.o wordSearch2D.o
	gcc -Wall -std=c99 -o wordSearch2D puzzle2D.o wordSearch2D.o

wordSearch2D.o: wordSearch2D.c puzzle2D.h
	gcc -Wall -std=c99 -c wordSearch2D.c

puzzle2D.o: puzzle2D.c puzzle2D.h
	gcc -Wall -std=c99 -c puzzle2D.c

clean:
	rm -f wordSearch2D *.o

