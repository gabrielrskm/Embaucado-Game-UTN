#include <iostream>
#include <windows.h>
#include <conio.h>
#include "../include/functions.h"

using namespace std;

void initScore(string nameScore[],int pointScore[]){
   //esta funcion inicializa el score del programa, se ejecuta una unica vez
   for(int i = 0; i < 100; i++){
      nameScore[i] = "";
      pointScore[i] = 0;
   }
}

void addScore(string nameScore[],int pointScore[],string name, int points){
   //añade de forma ordenada un score, supone que el array esta ordenado
   cout << "entro joya" << endl;
   for (int i = 0; i < 100; i++){
      if(points > pointScore[i]){
         for (int j = 100-1; j > i;j--){
            pointScore[j] = pointScore[j - 1];
            nameScore[j] = nameScore[j - 1];
         }
         pointScore[i] = points;
         nameScore[i] = name;
         return;
      }
   }
}

void showScore(string nameScore[],int pointScore[]){
   cout << title() << endl;
   cout << "\t\tEstadisticas" << endl;
   cout << "----------------------------------------------------------------" << endl;
   cout << "Posicion\tPuntaje\t\tJugador" << endl;
   cout << "----------------------------------------------------------------" << endl;
   for (int i = 0; i < 100;  i++)
   {  
      if(pointScore[i] == 0){
         cout << "Presione enter para salir " << endl;
         _getch();
         return;
      }
      cout << i+1 << "\t\t" << pointScore[i] << "\t\t" << nameScore[i] << endl;
   }
   cout << "Presione enter para salir " << endl;
   _getch();
}

void calcScore(string player1, string player2, int pointP1[], int pointP2[], int discountP1[],int discountP2[],string nameScore[],int pointScore[]){
   int pointWinner = 0;
   string nameWinner = "";
   int sumP1 = pointP1[0] + pointP1[1] + pointP1[2] + discountP1[0] + discountP1[1];
   int sumP2 = pointP2[0] + pointP2[1] + pointP2[2] + discountP2[0] + discountP2[1];
   if (sumP1 > sumP2)
   {
      nameWinner = player1;
      pointWinner = sumP1;
   }
   else if (sumP1 < sumP2)
   {
      nameWinner = player2;
      pointWinner = sumP2;
   }
   else
   {
      if(pointP1[0] > pointP2[0])
      {
         nameWinner = player1;
         pointWinner = sumP1;
      }
      else if(pointP1[0] < pointP2[0])
      {
         nameWinner = player2;
         pointWinner = sumP2;
      }
   }
   if(nameWinner != ""){
      addScore(nameScore,pointScore,nameWinner,pointWinner);
   }
}