                 /*----- Sección de Declaraciones --------------*/ 
%{
#include "Chomsky.cpp"

Chomsky chomsky;
%}

Terminal       [a-z]
Simbolo        [A-Z]
Produccion     {Simbolo}"->"({Simbolo}|{Terminal})+

%%
                 /*----- Sección de Reglas ----------------*/ 

Produccion			{chomsky.Aniade(yytext());}

%%   
                /*----- Sección de Procedimientos --------*/ 

int main (int argc, char *argv[]){
   yyin = stdin;
   yyout = stdout;

   if (argc >= 2){     
      yyin = fopen (argv[1], "rt");     

      if (yyin == NULL){       
         printf ("El fichero %s no se puede abrir\n", argv[1]);       
         exit (-1);     
      }  

      if(argc == 3){
         yyout = fopen(argv[2], "w");

         if (yyout == NULL){       
            printf ("El fichero %s no se puede abrir\n", argv[2]);       
            exit (-1);     
         }
      }
   }
  
   yylex (); 
   chomsky.Imprime(argv[2]);  

  return 0; 
}

