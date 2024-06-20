#include <iostream>
#include <cstring>

using namespace std;
int introduction() {
   string intro = R"(EMBAUCADO
-- -- -- -- -- -- -- -- -- -- -
1 - JUGAR 
2 - ESTADÍSTICAS 
3 - CRÉDITOS
-- -- -- -- -- -- -- -- -- -- -
0 - SALIR 
)";
   int option;
   system("cls");
   cout << intro << endl;
   cin >> option;
   if(option == 0) return 0;
   else if(option == 1) return 1;
   else if(option == 2) return 2;
   else if(option == 3) return 3;
   else {
      cout << "Opción incorrecta" << endl;
      return 0;
   }
}