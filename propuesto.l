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

int main (int argc, char *argv[])
{   
   if (argc == 2)   
   {     
      yyin = fopen (argv[1], "rt");     

      if (yyin == NULL)     
      {       
         printf ("El fichero %s no se puede abrir\n", argv[1]);       
         exit (-1);     
      }   
   }   
   else yyin = stdin;   
  
   yylex (); 
   chomsky.Imprime(/*Acceso al archivo de salida*/);  

  return 0; 
}
