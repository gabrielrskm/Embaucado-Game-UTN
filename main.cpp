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

   //la funcion recibe el score para ir guardando el historial 
   //de las partidas jugadas
   //estructura de datos para el funcionamiento del juego
   string player1, player2;
   int pointP1[3] = {0,0,0};
   int pointP2[3] = {0,0,0};
   int discountP1[2] = {0,0};
   int discountP2[2] = {0,0};

   //funciones para cada etapa del juego
   if(getNames(player1, player2) == -1){
      return;
   }
   firstTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   secondTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   thirdTurn(player1, player2, pointP1, pointP2,discountP1,discountP2);
   showResult(player1, player2, pointP1, pointP2, discountP1,discountP2);
   cout << "\n\nfin del juego, pulse enter para continuar";
   _getch(); //permite esperar a la pulsacion de enter, propia de windows.h
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
   //instruccion que configura el formato utf-8 en la consola
   //se intento con multiples codigos sin llegar a una solucion optima
   //esta opcion muestra bien los caracteres especiales del programa pero 
   //no puede mostra bien los caracteres especiales que introduce el usuario
   SetConsoleOutputCP(65001);

   //semilla inicial para que la funcion rand pueda devolver valores aleatorios en cada llamada
   srand(time(NULL));

   //array de datos para el guardado y visualicacion de ranking de puntos
   string score[100];

   int option = introduction();
   while(option != 0){
      if(option == 1)initGame(score);
      else if(option == 2)stats();
      else if(option == 3)credits();
      option = introduction();
   }
   system("cls");
   cout << "Gracias por probar nuestro juego, en caso le halla gustado contratenos : )";
   return 0;
}