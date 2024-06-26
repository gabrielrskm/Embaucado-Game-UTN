 #include "../include/stage.h"
 #include "../include/game.h"

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

