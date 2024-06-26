#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <conio.h>

using namespace std;

// Prototipos de funciones
void showPoints(string player1, string player2, int p1, int p2, int deck[], int specialDeck);
void sumPoints(int &p1, int &p2, int deck[], int specialDeck);
void shuffleCards(int deck[], int &specialDeck);
void getNames(std::string &player1, std::string &player2);
void showSumPoints(const int deck[], int specialDeck, std::string &sum1, std::string &sum2);
void showPoints(const std::string player1, const std::string player2, int p1, int p2, const int deck[], int specialDeck);
void showStage(string player1, string player2, int deck[], int p1[], int p2[], int specialDeck, int stage, int subP1[], int subP2[]);
void showResult(string player1, string player2, int p1[], int p2[], int subP1[], int subP2[]);
std::string showCard(int card);

