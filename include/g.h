#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Librerías necesarias (si aplica)
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>

// Prototipos de funciones
void sumPoints(int& p1, int& p2, const int deck[], int specialDeck); // Ten en cuenta el cambio a const para deck
void shuffleCards(int deck[], int& specialDeck);
void getNames(std::string& player1, std::string& player2);
void showSumPoints(const int deck[], int specialDeck, std::string& sum1, std::string& sum2); // Ten en cuenta el cambio a const para deck
void showPoints(const std::string player1, const std::string player2, int p1, int p2, const int deck[], int specialDeck); // Cambios a const
void showStage(const std::string player1, const std::string player2, const int deck[], const int p1[], const int p2[], int specialDeck, int stage, const int subP1[], const int subP2[]); // Cambios a const
void showResult(const std::string player1, const std::string player2, const int p1[], const int p2[], const int subP1[], const int subP2[], std::string score[]);
std::string showCard(int card);

#endif