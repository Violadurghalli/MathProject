//
// Created by Viola Durghalli on 11/4/24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Helper_Functions.h"
#include<cmath>
#include <iostream>
#include <iomanip>

void printEquation(int top, int bottom, char op, std::ostream &fout);
void printEquation(std::vector<int> carries, int top, int bottom, int answer, char op, std::ostream &cout);
// void add(int top, int bottom, int answer, std::vector<int> carries, char op, std::ofstream &cout);
void add(int top, int bottom, std::ostream &cout);
void run();
void printCarries(std::vector<int> carries, int top);
void generateRandProblems(std::string arr[][100], int &numUsed, int numProblems);
void printRandProblems(std::string arr[][100], int numUsed, int cols);
void printAnswer(std::string arr[][100], int numUsed);
void test();
void fileRead();
void accessEquation(std::string arr[][100], int rows, int cols, int equations);
void subtract(int top, int bottom, std::ostream &cout);
void printCarriesSub(std::vector<int> carries, int top);
void multiply1(int top, int bottom, std::ostream &cout);
void printCarriesM(std::vector<int> carries, int top);
void finalMultiply(int top, int bottom, std::ostream &cout);
char randOperator(char &op);

//gonna make the multiplication function for now, then i have to go back and test it in the access equation
//then fix the generate problems to do sub, add, and multiplication instead of just add.
//then fix access equation to read the char before calling add or sub or multiply


#endif //FUNCTIONS_H
