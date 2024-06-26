#include "../include/introduction.h"
#include "../include/title.h"

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
   int option;
   system("cls");
   cout << title();
   cout  << intro;   
   cin >> option;
   if (option == 0)
      return 0;
   else if (option == 1)
      return 1;
   else if (option == 2)
      return 2;
   else if (option == 3)
      return 3;
   else
   {
      cout << "Opción incorrecta" << endl;
      return 0;
   }
}