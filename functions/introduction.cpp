#include "../include/functions.h"

using namespace std;

int introduction()
{
   
   string intro = R"(
-- -- -- -- -- -- -- -- -- -- --- -- -- -- -- -- -- -- -- -- -- --
                  1 - JUGAR 
                  2 - ESTADÍSTICAS 
                  3 - CRÉDITOS
-- -- -- -- -- -- -- -- -- -- --- -- -- -- -- -- -- -- -- -- -- --
                  0 - SALIR 
-- -- -- -- -- -- -- -- -- -- --- -- -- -- -- -- -- -- -- -- -- --
               OPCION ELEGIDA: )";
   string option;
   system("cls");
   cout << title();
   cout  << intro;
   //se decidio usar getline ya que permite un metodo de validacion en caso que el usuario introduzca 
   //un valor erroneo, cuando se usaba cin quedaba abierta la posibilidad de romper la visual del programa
   //en caso de elegir un valor de mas de un caracter   
   getline(cin,option);
   if (option == "0")
      return 0;
   else if (option == "1")
      return 1;
   else if (option == "2")
      return 2;
   else if (option == "3")
      return 3;
   else
      return -1;
}