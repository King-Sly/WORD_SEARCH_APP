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
