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
