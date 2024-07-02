#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

// game.cpp
void showPoints(string player1, string player2, int p1, int p2, int deck[], int specialDeck);
void sumPoints(int &p1, int &p2, int deck[], int specialDeck);
void shuffleCards(int deck[], int &specialDeck);
int getNames(std::string &player1, std::string &player2);
void showSumPoints(const int deck[], int specialDeck, std::string &sum1, std::string &sum2);
void showPoints(const std::string player1, const std::string player2, int p1, int p2, const int deck[], int specialDeck);
void showStage(string player1, string player2, int deck[], int p1[], int p2[], int specialDeck, int stage, int subP1[], int subP2[]);
void showResult(string player1, string player2, int p1[], int p2[], int subP1[], int subP2[]);
std::string showCard(int card);

// introduction.cpp
int introduction();

// credits.cpp
void showCredits();

// score.cpp
void initScore(string nameScore[], int pointScore[]);
void addScore(string nameScore[], int pointScore[], string name, int points);
void showScore(string nameScore[], int pointScore[]);
void calcScore(string player1, string player2, int pointP1[], int pointP2[], int discountP1[], int discountP2[], string nameScore[], int pointScore[]);

// stage.cpp
void firstTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[]);
void secondTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[]);
void thirdTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[]);

// title.cpp
string title();