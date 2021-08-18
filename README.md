The information of both assignment partners (if working in a pair) or about yourself:

Team: Asgmt2_Team82

Student 1:

Name: Anahita Gupta

CCID: anahita3

Student Number: 1588387

Lecture:B1, Ildar Akhmetov 

Lab: H02

Student 2:

Name: Kingsley Okeke

CCID: nkokeke

Student Number: 1631514

Lecture: B1 Ildar Akhmetov

Lab: H02 

----




The purpose of your program:

The purpose of our program is to use the Rabin-Karp algorithm to solve a word-search puzzle. The program is able to find words in a grid of letters and output if it found the word and the direction the word was in. 

The exact commands we need to run your code:
make
./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o
<solution_file>]


The files submitted in your assignment, how they are structured and what they do:

wordSearch2D.c - Error Checking,main function, Reads the puzzle grid, Reads the words to be found file, Starts the search 

puzzle2D.c - Consider the 8 different directions, calculates hash function, compares word, checks to see if string exists in grid, uses functions to process each character grid

puzzle2D.h -header file for puzzle2D.c

Makefile - compiles the program into an executable called wordSearch2D, has a clean target, connects various files together

README - Explains the individuals who created the code, the purpose of the program, the commands needed to run the code, what all the files do, references, and what each partner did

License.md - License that contains the authors of this program names and has license information

puzzle.txt - puzzle file that we provide as a test case

wordlist.txt -wordlist file we created as a test case

expected_soln.txt - the solution you should get from our test case

sample_test.sh -the script for the test case

----

References:
Used ideas from the previous assignment that my assignment 1 partner and I worked on to implement error checking in this assignment 

----

Each partner's role in the assignment:

Anahita Gupta: 
Error checking: Created functions to ensure that the puzzle file, wordlist file, and solution file can be opened, displayed error message if not. 

Made sure that there are either 7 or 9 arguments.

If there are 7 or 9 arguments ensured that the p,l,w,o flag existed based on the number of arguments. Seperate error checking based on number of arguments.

Displayed error message if a specific flag was never found.

Checked to make sure there are n lines of string of length n, made sure n lines of sing strings are between 0 to n-1.

Ensured word length is correct, made sure word list file has exactly word length characters. 

Implemented error checking in code, created READ me file, included the license.

Created the test cases. 

Kingsley Okeke:

Code for reading the puzzle grid, Reads the words to be found file, Started the search by implementing a fcn that reads the puzzle fle and reads the word file

Header file, Makefile

Code to consider all of the 8 different directions, implemented Rabin-Karp by implementing fcn that calculates the hash fcn of the word to be found

calculated the hash function of a defined window and see if it matches hash function of word to be found

calculate hash of word we are looking for, check if string exists in the grid, traverse the grid

BOTH: 

Used pair programming for certain things at the end, for example ensuring that te program works regardless of if the input has a newline character at the end or not. 

Communicated with each other daily, and attended a lot of meetings with each other.
