# CMPUT 201 Assignment 2 Feedback

**Student**: Kingsley Okeke  
**Commit message**: Delete student_2_wordlist.txt  
**Commit time**: Sun Mar 21 21:28:52 2021 -0600  

**Grader**: TA name (TA email)


## Mandatory files and compilation checking
**README grade**: 1/1
**Makefile grade**: 1/1
**make clean grade**: 1/1

## Testing your own test case
Test failed (output.txt differs from expected_soln.txt or sample_test.sh is not executable
**Own test grade**: 0/2

## Argument checking
Puzzle not found (code 4): exit code passed; error msg passed  
Wordlist not found (code 5): exit code passed; error msg passed  
No -p: exit code passed; error msg passed  
No -l: exit code passed; error msg passed  
No -w: exit code passed; error msg passed  
No -o with sample test 1: exit code passed; error msg passed  
-o xxx.txt with sample test 1: exit code passed; error msg passed  
Arguments -p, -l, -w with sample test 1: exit code passed; error msg passed  
Arguments -w, -p, -l with sample test 1: exit code passed; error msg passed  
Arguments -l, -w, -p with sample test 1: exit code passed; error msg passed  

**Argument checking grade**: 10/10

## Running test cases, 23 test cases, 1 mark each
Test case 1
Files temp_output/output_1.txt and tests/table1_s.txt differ
Execution time: 0.011089 seconds
Test 1 failed
Test case 2
Execution time: 0.011026 seconds
Test 2 passed
Test case 3
Files temp_output/output_3.txt and tests/table3_s.txt differ
Execution time: 0.011436 seconds
Test 3 failed
Test case 4
Execution time: 0.010046 seconds
Test 4 passed
Test case 5
Files temp_output/output_5.txt and tests/table5_s.txt differ
Execution time: 0.010700 seconds
Test 5 failed
Test case 6
Execution time: 0.011009 seconds
Test 6 passed
Test case 7
Execution time: 0.010561 seconds
Test 7 passed
Test case 8
Execution time: 0.009430 seconds
Test 8 passed
Test case 9
Execution time: 0.009154 seconds
Test 9 passed
Test case 10
Execution time: 0.010904 seconds
Test 10 passed
Test case 11
Execution time: 0.009186 seconds
Test 11 passed
Test case 12
Execution time: 0.008740 seconds
Test 12 passed
Test case 13
Files temp_output/output_13.txt and tests/table13_s.txt differ
Execution time: 0.012709 seconds
Test 13 failed
Test case 14
Execution time: 0.060887 seconds
Test 14 passed
Test case 15
Files temp_output/output_15.txt and tests/table15_s.txt differ
Execution time: 0.011718 seconds
Test 15 failed
Test case 16
Execution time: 0.009390 seconds
Test 16 passed
Test case 17
Execution time: 0.011173 seconds
Test 17 passed
Test case 18
Execution time: 0.071819 seconds
Test 18 passed
Test case 19
Execution time: 0.016747 seconds
Test 19 passed
Test case 20
Execution time: 0.009513 seconds
Test 20 passed
Test case 21
Execution time: 0.012607 seconds
Test 21 passed
Test case 22
Execution time: 0.010318 seconds
Test 22 passed
Test case 23
Files temp_output/output_23.txt and tests/table23_s.txt differ
Execution time: 0.012272 seconds
Test 23 failed
**Test cases grade**: 17/23
## wordSearch2D.c
```c
/****
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Anahita Gupta, Kingsley Okeke

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email address:

      nadi@ualberta.ca
	  ildar@ualberta.ca

***/

/***
Team: assignment2-asgmt2_team82

Student 1:
Name: Anahita Gupta
CCID: anahita3
student number: 1588387
Lecture: B1 Akhmetov Ildar
Lab: H02

Student 2: 
Name: Kingsley Okeke
ccid:nkokeke
student number: 1631514
Lecture: B1 Akhmetov Ildar
Lab: H02

***/



#include "puzzle2D.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
	
	//------------ERROR CHECKING BEGINS HERE--------------------------	
	
//this checks to make sure that the puzzle file can be opened
		
int find_puzzle_file(int p_flag, char *argv[]){

	int p_file_index=p_flag+1;
	
	if (fopen(argv[p_file_index], "r")==0){
		fprintf(stderr, "Error: Puzzle file %s does not exist\n", argv[p_file_index]);
		return(-1);
	}

	else {
		return p_file_index;
	}
}
	
//this checks to make sure the wordlist file can be opened
int find_wordlist_file(int w_flag, char *argv[]){
	
	int w_file_index=w_flag+1;

	if (fopen(argv[w_file_index], "r")==0){
		fprintf(stderr, "Error: Wordlist file %s does not exist\n", argv[w_file_index]);
		return(-1);
	}

	else{
		
		return w_file_index;

	}
}

	
//this checks to make sure the solution file can be opened
int find_solution_file(int o_flag, char *argv[]){
	
	int o_file_index=o_flag+1;

	if (fopen(argv[o_file_index], "w+")==0){
		fprintf(stderr, "Encountered error\n");
		return(-1);
	}

	else{
		return o_file_index;

	}
}




void read_puzzle_file(char *file, int n, char word[n][n]);
void read_word_file(char file[], int r, int c, char word[r][c]);


int main(int argc, char *argv[]) {

	//this makes sure it either has 7 or 9 arguments
	if( (argc!=7)&&(argc!=9)){
		fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]\n");
		return 6;
	}
	//if it has 7 or 9 arguments make sure all of them are correct
	//we are searching for flags at index 1,3,5 if there are 7 flags	
	int flag_index=1, p_flag=0, l_flag=0, w_flag=0, o_flag;
	if((argc==7)||(argc==9)){
		while((flag_index<=6)&&(p_flag==0)){
			if (strcmp(argv[flag_index], "-p")==0){
				p_flag=flag_index;
			}
			
			flag_index=flag_index+2;
		}
		
		flag_index=1;
		while((flag_index<=6)&&(l_flag==0)){
			if (strcmp(argv[flag_index], "-l")==0){
				l_flag=flag_index;
			}

			flag_index=flag_index+2;
		}
		
		flag_index=1;
		while((flag_index<6)&&(w_flag==0)){
			if (strcmp(argv[flag_index], "-w")==0){
				w_flag=flag_index;
			}

			flag_index=flag_index+2;
		}
	}

	//does the checks if there are 9 arguments, makes sure that they exist
	if(argc==9){
		flag_index=7;
		//see if the p_flag is not found maybe it is at index 7
		if((p_flag==0)&&(strcmp(argv[flag_index], "-p")==0)){
			p_flag=flag_index;
		}
		
		flag_index=7;
		//see if the w_flag is not found maybe it is at index 7
		if((w_flag==0)&&(strcmp(argv[flag_index], "-w")==0)){
			w_flag=flag_index;
		}
		
		flag_index=7;
		//see if the l_flag is not found maybe it is at index 7
		if((l_flag==0)&&(strcmp(argv[flag_index], "-l")==0)){
			l_flag=flag_index;
		}
		//search for -o flag

		flag_index=1;
		while((flag_index<=8)&&(o_flag==0)){
			if (strcmp(argv[flag_index], "-o")==0){
				o_flag=flag_index;
			}
			flag_index=flag_index+2;
		}
	}


	
		//p_flag was never found
		if (p_flag==0){
			fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file>	[-o <solution_file>]\n");
			return 6;
		}
		
		//l_flag never found
		if (l_flag==0){
			fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file>	[-o <solution_file>]\n");
			return 6;
		}
		
		//w flag never found
		if (w_flag==0){
			fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file>	[-o <solution_file>]\n");
			return 6;
		}

		//o flag was never found
		if((argc==9)&&(o_flag==0)){
			fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file>	[-o <solution_file>]\n");
			return 6;
		}



	//stores values of the puzzzle file, wordlist file and where the word length was found
	//calls the fcn that tries to open these files
	int puzzle_file_index, wordlist_file_index, wordlength_index=(l_flag+1), solution_file_index;
	puzzle_file_index=find_puzzle_file(p_flag,argv);
	wordlist_file_index=find_wordlist_file(w_flag,argv);

	//see if solution file can be opened only if there are 9 arguments and o flag was found above
	if (argc==9){
		solution_file_index=find_solution_file(o_flag,argv);
		if (solution_file_index==-1){
			return 7;
		}		

	 }	





	//puzzle file can't be opened
	if (puzzle_file_index==-1){
		return 4;
	 }	

	//wordlist file can't be opened
	if (wordlist_file_index==-1){
		return 5;
	}


//------------------------------------ERROR CHECKING ADDITIONAL
	FILE *file; char ch; int line = 0;
	char temp;

    //A single file pointer to get the number of lines
    //of the puzzle.txt file
    file = fopen(argv[puzzle_file_index], "r");
    //read character by character and check for new line
    while((ch=fgetc(file))!=EOF) {
		temp=ch;
		if(ch=='\n'){
            line++;
		}
    }

	if (temp!='\n'){
		line++;
	}
	
    //close the file
    fclose(file);



//CHECKS TO MAKE SURE THERE ARE N LINES OF STRING OF LENGTH N
	int num_char=0;
    file= fopen(argv[puzzle_file_index], "r");
    //read character by character and counts how many characters each line has
    while((ch=fgetc(file))!=EOF) {
		if(ch!='\n'){
			num_char++;
		}
		else if (num_char!=line){
			fprintf(stderr,"Encountered error\n");
			return 7;
		}

		else{
			num_char=0;
		}
    }


	//	N LINES OF SINGLE STRINGS MUST BE BETWEEN 0 TO N-1
	if ((line<0)||(line>100)){
		fprintf(stderr,"Encountered error\n");
		return 8;
	 }	

    //close the file
    fclose(file);
	
	//MAKE SURE WORD LENGTH IS CORRECT
	if (((atoi(argv[wordlength_index]))<1)||((atoi(argv[wordlength_index]))>line)){
		fprintf(stderr, "Encountered error\n");
	}	
	//MAKE SURE WORD LIST FILE HAS EXACTLY WORD_LENGTH CHARACTERS		
	int char_wordlist=0;
	file=fopen(argv[wordlist_file_index], "r");
	while ((ch=fgetc(file))!=EOF) {
		if(ch!='\n'){
			char_wordlist++;
		}	
		else if (char_wordlist!=atoi(argv[wordlength_index])){
			fprintf(stderr, "Encountered error\n");
			return 7;
		}
		else{
		char_wordlist=0;
		}
	 }

	fclose(file);

	
	FILE *p;

	if (argc==7){
		p=fopen("output.txt", "w+");
	}
	else {
		p=fopen(argv[solution_file_index],"w+");
	}

    

    //READS THE PUZZLE GRID =============================
    FILE *fp; char c; int count = 0;
	char temp2;

    //A single file pointer to get the number of lines
    //of the puzzle.txt file
    fp = fopen(argv[puzzle_file_index], "r");
    //read character by character and check for new line
    while((c=fgetc(fp))!=EOF) {
       temp2=c;
		if(c=='\n')
            count++;
    }
	
	if (temp2!='\n'){
		count++;
	}
	
    //close the file
    fclose(fp);




    char grid[count][count];
    read_puzzle_file(argv[puzzle_file_index], count, grid);

    //READS THE WORDS TO BE FOUND FILE====================
    FILE *word; int num = 0; char w;
    char temp3;
	//get the number of lines in the file
    word = fopen(argv[wordlist_file_index], "r");
    while((w=fgetc(word))!=EOF) {
       temp3=w;
		if(w=='\n')
            num++;
    }

	if (temp3!='\n'){
		num++;
	}
    //close the file
    fclose(word);
    int x = atoi(argv[wordlength_index]);
    char wordList[num][x+1]; //store the words here and adds one to include "\0"
    read_word_file(argv[wordlist_file_index], num, x+1, wordList);
    // traverse_grid(count, grid, x, chr);
    
    //STARTS THE SEARCH================================
    generate_all_characters_positions(count, grid, x, num, x+1, wordList,p);
	fclose(p);
}


void read_puzzle_file(char file[], int n, char word[n][n]){
    FILE *stream;
    stream = fopen(file, "r"); 
    char c;
    //Initializes every element in thr grid
    //as the empty 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            word[i][j] = ' ';
        }
    }

    int rows = 0; int cols = 0;
    while((c=fgetc(stream))!=EOF && rows < n) {
        if(c=='\n'){
            rows+=1;
            cols = 0;
            continue;
        }
        word[rows][cols] = c;
        cols+=1;
    }
    // printArr(n, n, word);
}

void read_word_file(char file[], int r, int c, char word[r][c]){
    FILE *stream;
    stream = fopen(file, "r"); 
    char def;
    //Initializes every element in thr grid
    //as the empty 
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            word[i][j] = ' ';
        }
    }

    int rows = 0; int cols = 0;
    while((def=fgetc(stream))!=EOF && rows < r) {
        if(def=='\n'){
            word[rows][cols] = '\0';
            rows+=1;
            cols = 0;
            continue;
        }
        word[rows][cols] = def;
        cols+=1;
    }
    word[rows][cols] = '\0';
    // printArr(r, c, word);
}
```
## puzzle2D.h
```c
/****
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Anahita Gupta, Kingsley Okeke

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email address:

      nadi@ualberta.ca
	  ildar@ualberta.ca

***/

/***
Team: assignment2-asgmt2_team82

Student 1:
Name: Anahita Gupta
CCID: anahita3
student number: 1588387
Lecture: B1 Akhmetov Ildar
Lab: H02

Student 2: 
Name: Kingsley Okeke
ccid:nkokeke
student number: 1631514
Lecture: B1 Akhmetov Ildar
Lab: H02

***/



#ifndef PUZZLE2D_H
#define PUZZLE2D_H
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(int n, char path[n+1]);
void horizontal_right(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void horizontal_left(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void vertical_up(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void vertical_down(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void top_left_to_bottom_right_diagonal(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void bottom_right_to_top_left_diagonal(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void bottom_left_to_top_right(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
void top_right_to_bottom_left(int row, int col, int size, int n, char grid[n][n], char path[size+1]);
int word_to_be_found(char word[]);
bool rolling_hashes(int word_hash, int wordLen, char path[]);
bool compareWords(char path[], char word[]);
int check_word(int row, int col,int n, char grid[n][n], int size, char word[size]);
void traverse_grid(int n, char grid[n][n], int len, char word[], FILE *p);
void generate_all_characters_positions(int n, char grid[n][n], int len,int row, int col,char wordList[row][col],FILE *p);
#endif /* PUZZLE2D_H */
```
## puzzle2D.c
```c
/****
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Anahita Gupta, Kingsley Okeke

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email address:

      nadi@ualberta.ca
	  ildar@ualberta.ca

***/

/***
Team: assignment2-asgmt2_team82

Student 1:
Name: Anahita Gupta
CCID: anahita3
student number: 1588387
Lecture: B1 Akhmetov Ildar
Lab: H02

Student 2: 
Name: Kingsley Okeke
ccid:nkokeke
student number: 1631514
Lecture: B1 Akhmetov Ildar
Lab: H02

***/



#include "puzzle2D.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

//Steps: ->
//Consider the eight different directions

void initialize(int n, char path[n+1]) {
    for(int i = 0; i < n; i++){
        path[i] = ' ';
    }
}
// horizontal right (→)
//Starting from a particular position, we run-off those characters that occur
//in the horizontal-right direction into a particular array of size, n.
void horizontal_right(int row, int col, int size, int n, char grid[n][n], char path[size+1]){
    //initialize the path array to empty space
    initialize(size, path);
    //copy every character that occur in the horizontal right direction
    //starting from (row, col)
    //into the path array
    int i = col;
    int start = 0; //start of characters in the path
    while(i < n && start < size){
        path[start] = grid[row][i];
        start+=1;
        i+=1;
    }
    path[start] = '\0'; //end that as a null terminated string
}

//horizontal left (←)
void horizontal_left(int row, int col, int size, int n, char grid[n][n], char path[size+1]){
    //initialize the path array to empty space
    initialize(size, path);
    //copy every character that occur in the horizontal right direction
    //starting from (row, col)
    //into the path array
    int i = col;
    int start = 0; //start of characters in the path
    while(i >= 0 && start < size){
        path[start] = grid[row][i];
        start+=1;
        i-=1;
    }
   path[start] = '\0'; //end that as a null terminated string
}

//vertical up (↑)
void vertical_up(int row, int col, int size, int n, char grid[n][n], char path[size+1]){
    //initialize the path array to empty space
    initialize(size, path);
    //copy every character that occur from starting position (row,col)
    //traverse upwardly by subracting the row by 1.
    int j = row;
    int start = 0; //start of characters in path.
    while(j >= 0 && start < size){
        path[start] = grid[j][col];
        start+=1;
        j-=1;
    }
    path[start] = '\0';
}


//vertical down (↓)
void vertical_down(int row, int col, int size, int n, char grid[n][n], char path[size+1]){
    //initialize the path array to empty space
    initialize(size, path);
    //copy every character that occur in the position (row,col)
    //traverse downwardly by adding the row by 1.
    int j = row;
    int start = 0;
    while(j < n && start < size){
       path[start] = grid[j][col];
        start+=1;
        j+=1;
    } 
    path[start] = '\0';
}

// top left to bottom right diagonal (↘)
void top_left_to_bottom_right_diagonal(int row, int col, int size, int n, char grid[n][n], char path[size+1]) {
    initialize(size, path);
    //traverse downwardly and increase the rows and columns by 1
    int i = row;
    int j = col;
    int start = 0;
    while(i < n && j < n && start < size) {
        path[start] = grid[i][j];
        start+=1;
        i+=1;
        j+=1;
    }
    path[start] = '\0';
}
// bottom right backwards to top left diagonal (↖)
void bottom_right_to_top_left_diagonal(int row, int col, int size, int n, char grid[n][n], char path[size+1]) {
    initialize(size, path);
    //traverse upwardly and reduce the rows and cols
    int i = row;
    int j = col;
    int start = 0;
    while(i >= 0 && j >= 0 && start < size) {
        path[start] = grid[i][j];
        i-=1;
        j-=1;
        start+=1;
    }
   path[start] = '\0';
}

// bottom left to top right (↗)
void bottom_left_to_top_right(int row, int col, int size, int n, char grid[n][n], char path[size+1]) {
    initialize(size, path);
    //traverse upwardly and increase col by 1 and reduce row by 1
    int i = row;
    int j = col;
    int start = 0;
    while(i >= 0 && j < n && start < size) {
        path[start] = grid[i][j];
        i-=1;
        j+=1;
        start+=1;
    }
    path[start] = '\0';
}

// top right backwards to bottom left (↙)
void top_right_to_bottom_left(int row, int col, int size, int n, char grid[n][n], char path[size+1]) {
    initialize(size, path);
    //traverse downwardly by increasing the row by 1 and reducing col by 1
    int i = row;
    int j = col;
    int start = 0;
    while(i < n && j >= 0 && start < size) {
        path[start] = grid[i][j];
        i+=1;
        j-=1;
        start+=1;
    }
    path[start] = '\0';
}

//To implement Rabin-Karp=================

//Calculate the hash function of the word to be found
int word_to_be_found(char word[]){

    int previous_hash = 0;
    int D = 256;
    int P = 7079;
    
    int row = 0;
    int size = strlen(word); //word--null terminated string
    while(row < size){
        previous_hash = ((D * previous_hash + word[row]) % P);
        row+=1;
    }
    return previous_hash;
}

//Calculate the hash function of a defined window(length of the word(tobefound))
//see if it matches the hash function of the word to be found above
bool rolling_hashes(int word_hash, int wordLen, char path[]){
    int previous_hash = 0;
    int D = 256;
    int P = 7079;
    //we calculate the first len size window
    int i = 0;
    while(i < wordLen && i < strlen(path)){
        previous_hash = ((D * previous_hash + path[i]) % P);
        i+=1;
    }
    if(i != wordLen)
	return false;	
    if(previous_hash == word_hash)
        return true;


    if(i >= strlen(path))
        return false;

    int h = (D^(wordLen - 1)) % P;
    //calculate the fixed sized window 
    while(i < strlen(path)){
        previous_hash = ((D * (previous_hash - path[i - wordLen] * h) + path[i]) % P);
        if(previous_hash == word_hash)
            return true;
        i+=1;
    }
    return false;
}

bool compareWords(char path[], char word[]) {
	int i = 0;
	while(i < strlen(path) && i < strlen(word) ) {
		if(path[i] != word[i])
			return false;
		i+=1;
	}
	return true;

}

//=====================
//Use the functions above and process each character grid
//checks if the string exists in the grid

int check_word(int row, int col,int n, char grid[n][n], int size, char word[size]){
    //calculate the hash of the word we are looking for
    int val = word_to_be_found(word);
    bool def;
    //create an array to print each path
    char path[size+1];

    horizontal_right(row, col, size, n, grid, path);
    def = rolling_hashes(val,size,path);
    if(def && compareWords(path, word)) return 1;

    horizontal_left(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 2;

    vertical_up(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 4;

    vertical_down(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 3;

    top_left_to_bottom_right_diagonal(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 5;

    top_right_to_bottom_left(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 8;

    bottom_left_to_top_right(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 7;

    bottom_right_to_top_left_diagonal(row, col, size, n, grid, path);
    def = rolling_hashes(val, size, path);
    if(def && compareWords(path,word)) return 6;

    return -1;
}

void traverse_grid(int n, char grid[n][n], int len, char word[], FILE *p){
    int position = 0;
    int r, c;
    r = 0; c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == word[0]){
              int value = check_word(i, j, n, grid, len ,word);
              if(value != -1){
                  r= i; c= j;
                  position = value;
	          i = n; j = n;
                  break;
              }
           }
        }
    }
   fprintf(p, "%s;(%d,%d);%d\n", word, r, c, position);
}

void generate_all_characters_positions(int n, char grid[n][n], int len,int row, int col,char wordList[row][col],FILE *p) {
    for(int i = 0; i < row; i++){
        traverse_grid(n, grid, len, wordList[i],p);
    }
}
```
**Proper structure of header and source files grade**: 3/3
**Using the Rabin-Karp algorithm grade**: 7/7
**Code is properly formatted, commented grade**: 2/2
**Using global variables (penalty) grade**: /-10

# Total grade
**Total grade**: 42/50 (84%)
