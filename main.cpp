#include <iostream>
#include <windows.h>
#include <array>
#include <conio.h>
#include "./include/introduction.h"
#include "./include/game.h"


void game(string score[]){
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
   showResult(player1, player2, pointP1, pointP2, discountP1,discountP2, score);
   cout << "fin del juego, pulse enter para continuar";
   _getch();
}

void stats(){
   system("cls");
}

void credits(){
   system("cls");
}

int main()
{
   SetConsoleOutputCP(CP_UTF8);
   system("cls");
   string score[100];
   int option = introduction();
   while(option != 0){
      if(option == 1)game(score);
      else if(option == 2)stats();
      else if(option == 3)credits();
      option = introduction();
   }
   system("cls");
   return 0;
}