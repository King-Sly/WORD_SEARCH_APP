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
