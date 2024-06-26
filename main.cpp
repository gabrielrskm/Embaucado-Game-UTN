#include <iostream>
#include <windows.h>
#include <conio.h>
#include "./include/introduction.h"
#include "./include/credits.h"
#include "./include/game.h"
#include "./include/stage.h"
#include <locale>

using namespace std;

void initGame(string score[]){

   system("cls");
   string player1, player2;
   int pointP1[3] = {0,0,0};
   int pointP2[3] = {0,0,0};
   int discountP1[2] = {0,0};
   int discountP2[2] = {0,0};
   getNames(player1, player2);
   firstTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   secondTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   thirdTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   showResult(player1, player2, pointP1, pointP2, discountP1,discountP2);
   cout << "\n\nfin del juego, pulse enter para continuar";
   _getch();
}

void stats(){
   system("cls");
}

void credits(){
   system("cls");
   showCredits();
}

int main()
{
   //set the console to show the special characters
   SetConsoleOutputCP(65001);

   //set random seed
   srand(time(NULL));

   //set array for visualization of score
   string score[100];
   int sizeScore = 0;


   system("cls");
   int option = introduction();
   while(option != 0){
      if(option == 1)initGame(score);
      else if(option == 2)stats();
      else if(option == 3)credits();
      option = introduction();
   }
   system("cls");
   return 0;
}