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
   if (argc == 3)   
   {     
      yyin = fopen (argv[1], "rt");     

      if (yyin == NULL)     
      {       
         printf ("El fichero %s no se puede abrir\n", argv[1]);       
         exit (-1);     
      } 
      yyout = fopen(argv[2], "w");  
   }   
   else yyin = stdin;   
  
   yylex (); 
   chomsky.Imprime(argv[2]);  

  return 0; 
}
