#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <conio.h>
#include "../include/functions.h"

using namespace std;

// Las cartas seran representadas bajo el siguiente concepto
// heart: 10 = 0 , jack = 1, queen = 2, king = 3, ace = 4
// spades: 10 = 5 , jack = 6, queen = 7, king = 8, ace = 9
// clubs: 10 = 10 , jack = 11, queen = 12, king = 13, ace = 14
// diamonds: 15 = 0 , jack = 16, queen = 17, king = 18, ace = 19
//"Corazon ♥" = 20, "Pica ♠" = 21, "Trebol ♣"= 22, "Diamante ♦"=23

void sumPoints(int &p1, int &p2, int deck[], int specialDeck)
{
   //en esta funcion se suman los puntajes de la partida y se asignan a la posicion de memoria dentro del array
   //correspondiente a cada jugador
   //                  corazon          |    trebol         |  pica             |       diamante
   int points[20] = {10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20};
   for (int i = 0; i < 5; i++)
   {
      points[i + (specialDeck * 5)] = 0;
   }
   for (int i = 0; i < 5; i++)
   {
      p1 += points[deck[i]];
      p2 += points[deck[i + 5]];
   }
}

void shuffleCards(int deck[], int &specialDeck)
{

   int sortDek[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
   int unsortDeck[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
   int value;
   int randNum;
   
   for (int i = 0; i < 10; i++)
   {
      value = -1;
      do
      {
         randNum = rand() % 20;
         value = sortDek[randNum];
      } while (value < 0);

      sortDek[randNum] = -1;
      unsortDeck[i] = value;
   }
   for (int i = 0; i < 10; i++)
   {
      deck[i] = unsortDeck[i];
   }
   specialDeck = rand() % 4;
}

int getNames(string &player1, string &player2)
{
   string intro = R"(Antes de comenzar deben registrar sus nombres:)";
   string option;
   system("cls");
   do
   {
      cout << title()<< intro << endl;
      cout << "\n¿Nombre del Jugador 1 : ";
      getline(cin,player1);
      cout << "\n¿Nombre del Jugador 2 : ";
      getline(cin,player2);
      cout << "\nConfirma nombres ? (s/n) ";
      getline(cin,option);

      //da la opcion de salir porque pinto
      if(option == "salir" || option == "Salir")
      {
         return -1;
      }
      if (option != "s" && option != "S" && option != "n" && option != "N")
      {
         system("cls");
         cout << " Opcion Invalida, ingrese los datos nuevamente :" << endl;
      }
      else if (option == "n" || option =="N"){
         system("cls");
      }
   } while (option != "s" && option != "S");
   return 0;
}

string showCard(int card)
{
   string cards[24] = {
       "10 de corazon ♥   ", "jota de corazon ♥", "reina de corazon ♥", "rey de corazon ♥", "as de corazon ♥  ",
       "10 de pica ♠   ", "jota de pica ♠  ", "reina de pica ♠  ", "rey de pica ♠  ", "as de pica ♠     ",
       "10 de trebol ♣  ", "jota de trebol ♣", "reina de trebol ♣", "rey de trebol ♣", "as de trebol ♣  ",
       "10 de diamante ♦  ", "jota de diamante ♦", "reina de diamante ♦", "rey de diamante ♦", "as de diamante ♦",
       "Corazon ♥", "Pica ♠", "Trebol ♣", "Diamante ♦"};

   return cards[card];
}

void showSumPoints(int deck[], int specialDeck, string &sum1, string &sum2)
{
   //es similar a la funcion sumPoints, se decidio aplicar el mismo codigo por mas que sea repetitivo
   //o sea se podia implementar todo en la anterior funcion pero asi teniamos separado las funciones de cada
   //funcion ( valga la redundancia )
   int points[20] = {10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20};
   int card = specialDeck - 20;
   for (int i = 0; i < 5; i++)
   {
      points[i + (specialDeck * 5)] = 0;
   }
   for (int i = 0; i < 5; i++)
   {
      sum1 += to_string(points[deck[i]]);
      sum2 += to_string(points[deck[i + 5]]);
      if (i < 4)
      {
         sum1 += " + ";
         sum2 += " + ";
      }
   }
}

void showStage(string player1, string player2, int deck[], int p1[], int p2[], int specialDeck, int stage, int subP1[], int subP2[])
{
   int pointP1 = p1[0]+p1[1]+p1[2]+subP1[0]+subP1[1];
   int pointP2 = p2[0]+p2[1]+p2[2]+subP2[0]+subP2[1];
   system("cls");
   cout << title();
   cout << "Ronda #" << stage << endl;
   cout << "+-------------------------------+\n|\t\t\t\t|\n";
   cout << "| " + player1 + " (" << pointP1 << " puntos)\t\t|\n";
   for (int i = 0; i <= 4; i++)
   {
      cout << "| ";
      cout << " \t" << showCard(deck[i]) << "\t|" << endl;
   }

   cout << "|\t\t\t\t|\n";
   cout << "|\t\t\t\t|\n";
   cout << "| " + player2 + " (" + to_string(pointP2) + " puntos)\t\t|\n";

   for (int i = 5; i <= 9; i++)
   {
      cout << "| ";
      cout << " \t" << showCard(deck[i]) << "\t|" << endl;
   }

   cout << "|\t\t\t\t|\n";
   cout << "| Carta Embaucadora : " << showCard(specialDeck + 20) << "\t|" << endl;
   cout << "|\t\t\t\t|\n";
   cout << "+-------------------------------+\n\n";
}

void showPoints(string player1, string player2, int p1, int p2, int deck[], int specialDeck)
{

   string sum1 = "";
   string sum2 = "";
   showSumPoints(deck, specialDeck, sum1, sum2);
   cout << "\nPuntaje obtenido \n--------------------------------------------------------\n";
   cout << player1 + ": " << sum1 << " = " << to_string(p1) << " puntos" << endl;
   cout << player2 + ": " << sum2 << " = " << to_string(p2) << " puntos" << endl;
}

void showResult(string player1, string player2, int p1[], int p2[], int subP1[], int subP2[])
{
   system("cls");
   cout << title();
   cout << "Ronda\t" << player1 << "\t" << player2 << endl;
   cout << "------------------------------------------------------------------------" << endl;
   for (int i = 0; i < 3; i++)
   {
      cout << i + 1 << "\t" << p1[i] << "\t" << p2[i] << "\t" << endl;
   }
   cout << "------------------------------------------------------------------------" << endl;
   int desc1 = subP1[0] + subP1[1];
   int desc2 = subP2[0] + subP2[1];
   cout << "desc\t" << desc1 << "\t" << desc2 << "\t" << endl;
   cout << "------------------------------------------------------------------------" << endl<<endl;

   int sum1 = p1[0] + p1[1] + p1[2] + subP1[0] + subP1[1];
   int sum2 = p2[0] + p2[1] + p2[2] + subP2[0] + subP2[1];
   cout << "Total" << "\t" << sum1 << "\t" << sum2 << "\t" << endl;


   if (sum1 > sum2)
   {
      cout << "Ganador: " << player1 << endl;
   }
   else if (sum1 < sum2)
   {
      cout << "Ganador: " << player2 << endl;
   }
   else
   {
      if(p1[0] > p2[0])
      {
         cout << "Ganador: " << player1 << endl;
      }
      else if(p1[0] < p2[0])
      {
         cout << "Ganador: " << player2 << endl;
      }
      else {
         cout << "Empate" << endl;
      }
   }

}