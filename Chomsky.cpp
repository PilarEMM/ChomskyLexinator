#include<stdio.h>
#include <cstdlib>
//#include <ctype>
#include<vector>
#include<string>
#include <set>

using namespace std;

class Chomsky{
private:
   vector <string> producciones;
   set <char> variables;
   set <char> terminales;

public:
   void Aniade(const char* termino){
      producciones.push_back(termino);

      int length = sizeof(termino)/sizeof(char);
      for(int i=0; i < length; i++) {
         if (isupper(termino.at(i))
            variables.insert(termino.at(i));
         else if (islower(termino.at(i))
            terminales.insert(termino.at(i));
   }

   bool esChomsky() {
      bool valido = true;

      for (int i=0; producciones.size(); i++) {
         valido = valido && esReglaChomsky(producciones.at(i));
      }
      return valido;
   }

   bool esReglaChomsky(string regla) {
      bool valido = true;

      switch (regla.size()) {
         case 4:
            valido = valido && islower(regla.at(3));
         break;
         case 5:
            valido = valido && isupper(regla.at(3)) && isupper(regla.at(4));
         break;
         default:
            valido = false;
      }
      return valido;
   }

   char nuevaVariable() {
      char nueva;
      bool encontrada = false;

      for (char i='A'; i <= 'Z' && !encontrada; i++) {
         if (!variables.contains(i)) {
            nueva = i;
            encontrada = true;
         }
      }
/*      for (char i='α'; i <= 'ω' && !encontrada; i++) {
         if (!variables.contains(i)) {
            nueva = i;
            encontrada = true;
         }
      }
*/
      return nueva;
   }



   void Resolver() {
      char asociados[terminales.size()];
      vector<string> solucion, aux_inicio, aux_fin = producciones;
      int i = 0;

      for (set<char>::iterator it = terminales.begin(); it!=terminales.end()); it++)
         asociados[i] = nuevaVariable(terminales[

      while (!esChomsky()){
         aux_inicio = aux_fin;
         aux_fin.clear();
         string regla[2];



         for(int i=0; i < .size(); i++) {
            if(!esReglaChomsky(aux_inicio.at(i)) {

               //Introducimos la produccion y flecha
               regla[0] = produciones.at(0)+"->";

               switch (aux_inicio.at(i).size()) {
                  // case 4: no es posible porque entonces seria de Chomsky o no unitaria

                  case 5:
                     //Si el elemento es terminal se transforma
                     if(islower(aux_inicio.at(i).at(3)))
                        regla[0].push_back(asociados(terminales.find(aux_inicio.at(i).at(3))));
                     else
                        regla[0].push_back(aux_inicio.at(i).at(3));

                     if(islower(aux_inicio.at(i).at(4)))
                        regla[0].push_back(asociados(terminales.find(aux_inicio.at(i).at(4))));
                     else
                        regla[0].push_back(aux_inicio.at(i).at(4));
                  break;

                  default:
                     //Si el primer elemento es terminal se transforma
                     if(islower(aux_inicio.at(i).at(3)))
                        regla[0].push_back(asociados(terminales.find(aux_inicio.at(i).at(3))));
                     else
                        regla[0].push_back(aux_inicio.at(i).at(3));

                     char nueva = nuevaVariable();
                     regla[0].push_back(nueva);
                     regla[1] = nueva+"->"+aux_inicio.at(i).substr(4);
                     aux_fin.push_back(regla[1]);
               }

               solucion.push_back(regla[0]);
            }
            else
               solucion.push_back(aux_inicio.at(i));
      }

      producciones = solucion + aux_fin;
   }
}
