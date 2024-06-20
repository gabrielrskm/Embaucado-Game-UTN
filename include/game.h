#include <iostream>
#include <string>
#include <cstdlib>
#include <array>

using namespace std;

void sumPoints(int &p1, int &p2, int deck[], int specialDeck);
void shuffleCards(int deck[], int &specialDeck);
void getNames(string &player1, string &player2);
void showSumPoints(int deck[], int specialDeck, string &sum1, string &sum2);
void showPoints(string player1, string player2, int p1, int p2, int deck[], int specialDeck);
void showStage(string player1, string player2, int deck[], int p1[], int p2[], int specialDeck, int stage, int subP1[], int subP2[]);
void showResult(string player1, string player2, int p1[], int p2[], int subP1[], int subP2[], string score[]);
string showCard(int card);

// the cards are represented by the following concept
// heart: 10 = 0 , jack = 1, queen = 2, king = 3, ace = 4
// spades: 10 = 5 , jack = 6, queen = 7, king = 8, ace = 9
// clubs: 10 = 10 , jack = 11, queen = 12, king = 13, ace = 14
// diamonds: 15 = 0 , jack = 16, queen = 17, king = 18, ace = 19
// diamond-figure: 20, heart-figure: 21, spades-figure: 22, club-figure: 23

void sumPoints(int &p1, int &p2, int deck[], int specialDeck)
{
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
   srand(time(NULL));
   for (int i = 0; i < 10; i++)
   {
      int value = -1;
      int rand;
      do
      {
         rand = std::rand() % 20;
         value = sortDek[rand];
      } while (value < 0);

      sortDek[rand] = -1;
      unsortDeck[i] = value;
   }
   for (int i = 0; i < 10; i++)
   {
      deck[i] = unsortDeck[i];
   }
   specialDeck = rand() % 4;
}

void getNames(string &player1, string &player2)
{
   string intro = R"(EMBAUCADO
-- -- -- -- -- -- -- -- -- -- -
Antes de comenzar deben registrar sus nombres:)";
   cout << intro << endl;
   char option;
   do
   {
      cin.clear();
      cout << endl
           << "¿Nombre del Jugador 1 : ";
      cin >> player1;
      cout << endl
           << "¿Nombre del Jugador 2 : ";
      cin >> player2;
      cout << endl
           << "Confirma nombres ? (s/n) ";
      cin >> option;
      if (option != 's' && option != 'S' && option != 'n' && option != 'N')
      {
         system("cls");
         cout << " Opcion Invalida, ingrese los datos nuevamente" << endl;
      }
   } while (option != 's' && option != 'S');

   cout << "Jugador 1: " << player1 << endl;
   cout << "Jugador 2: " << player2 << endl;
}

void firstTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[])
{
   int deck[10];
   int specialDeck = -1;
   shuffleCards(deck, specialDeck);
   showStage(player1, player2, deck, p1, p2, specialDeck, 1, subP1, subP2);
   sumPoints(p1[0], p2[0], deck, specialDeck);
   showPoints(player1, player2, p1[0], p2[0], deck, specialDeck);
   cout << "\npulse enter para continuar a la ronda 2";
   _getch();
}

void secondTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[])
{
   int deck[10];
   int specialDeck = -1;
   shuffleCards(deck, specialDeck);
   showStage(player1, player2, deck, p1, p2, specialDeck, 2, subP1, subP2);
   char option = 'n';
   int specialDeckPrevius = specialDeck;
   int sumP1 = p1[0] + p1[1] + p1[2] + subP1[0];
   int sumP2 = p2[0] + p2[1] + p2[2] + subP2[0];
   if ( sumP1 >= 20)
   {
      cout << player1 << " desea cambiar la carta Embaucadora ? (s/n) : ";
      cin >> option;
      if (option == 's' || option == 'S')
      {
         subP1[0] = subP1[0] - 20;
         srand(time(NULL));
         specialDeck = rand() % 4;
         do
         {
            specialDeck = rand() % 4;
         } while (specialDeckPrevius == specialDeck);
         showStage(player1, player2, deck, p1, p2, specialDeck, 2, subP1, subP2);
      }
   }
   if (sumP2 >= 20 && option != 's' && option != 'S')
   {
      cout << player2 << " desea cambiar la carta Embaucadora ? (s/n) : ";
      cin >> option;
      if (option == 's' || option == 'S')
      {
         subP2[0] = subP2[0] - 20;
         srand(time(NULL));
         specialDeck = rand() % 4;
         do
         {
            specialDeck = rand() % 4;
         } while (specialDeckPrevius == specialDeck);
         showStage(player1, player2, deck, p1, p2, specialDeck, 2, subP1, subP2);
      }
   }

   sumPoints(p1[1], p2[1], deck, specialDeck);
   showPoints(player1, player2, p1[1], p2[1], deck, specialDeck);
   cout << "\npulse enter para continuar a la ronda 3" << endl;
   _getch();
}

void thirdTurn(string &player1, string &player2, int p1[], int p2[], int subP1[], int subP2[])
{
   int deck[10];
   int specialDeck = -1;
   shuffleCards(deck, specialDeck);
   showStage(player1, player2, deck, p1, p2, specialDeck, 3, subP1, subP2);
   char option = 'n';
   int specialDeckPrevius = specialDeck;
   int sumP1 = p1[0] + p1[1] + p1[2] + subP1[0];
   int sumP2 = p2[0] + p2[1] + p2[2] + subP2[0];
   if (sumP2 >= 20)
   {
      cout << player2 << " desea cambiar la carta Embaucadora ? (s/n) : ";
      cin >> option;
      if (option == 's' || option == 'S')
      {
         subP2[1] = subP2[1] - 20;
         srand(time(NULL));
         specialDeck = rand() % 4;
         do
         {
            specialDeck = rand() % 4;
         } while (specialDeckPrevius == specialDeck);
         showStage(player1, player2, deck, p1, p2, specialDeck, 3, subP1, subP2);
      }
   }
   if (sumP1 >= 20 && option != 's' && option != 'S')
   {
      cout << player1 << " desea cambiar la carta Embaucadora ? (s/n) : ";
      cin >> option;
      if (option == 's' || option == 'S')
      {
         subP1[1] = subP1[1] - 20;
         srand(time(NULL));
         specialDeck = rand() % 4;
         do
         {
            specialDeck = rand() % 4;
         } while (specialDeckPrevius == specialDeck);
         showStage(player1, player2, deck, p1, p2, specialDeck, 3, subP1, subP2);
      }
   }

   sumPoints(p1[2], p2[2], deck, specialDeck);
   showPoints(player1, player2, p1[2], p2[2], deck, specialDeck);
   cout << "\npulse enter para continuar para ver el resultado final" << endl;
   _getch();
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
   cout << "Embaucado\n------------------------------------------------------------------------" << endl;
   cout << "Ronda #" << stage << endl;
   cout << "+-------------------------------+\n|\t\t\t\t|\n";
   cout << "| " + player1 + " (" + to_string(pointP1) + " puntos)\t\t|\n";
   for (int i = 0; i < 5; i++)
   {
      cout << "| ";
      cout << " \t" << showCard(deck[i]) << "\t|" << endl;
   }

   cout << "|\t\t\t\t|\n";
   cout << "|\t\t\t\t|\n";
   cout << "| " + player2 + " (" + to_string(pointP2) + " puntos)\t\t|\n";

   for (int i = 5; i < 10; i++)
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
   cout << "Puntaje obtenido \n--------------------------------------------------------\n";
   cout << player1 + ": " << sum1 << " = " << to_string(p1) << " puntos" << endl;
   cout << player2 + ": " << sum2 << " = " << to_string(p2) << " puntos" << endl;
}

void showResult(string player1, string player2, int p1[], int p2[], int subP1[], int subP2[], string score[])
{
   system("cls");
   cout << "Embaucado\n------------------------------------------------------------------------" << endl
        << endl;
   cout << "Ronda\t" << player1 << "\t" << player2 << endl;
   cout << "------------------------------------------------------------------------" << endl;
   for (int i = 0; i < 3; i++)
   {
      cout << i + 1 << "\t" << p1[i] << "\t" << p2[i] << "\t" << score[i] << endl;
   }
   cout << "------------------------------------------------------------------------" << endl;
   int desc1 = subP1[0] + subP1[1];
   int desc2 = subP2[0] + subP2[1];
   cout << "desc\t" << desc1 << "\t" << desc2 << "\t" << endl;

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