/*
 * MAC0323 Algoritmos e Estruturas de Dados II
 *
 * NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ARQUIVO
 *
 * Aqui esta o prototipo das funÃ§Ãµes emalloc(), ecalloc(),
 * getLine(), getNextToken() alÃ©m das definiÃ§Ãµes de
 * Bool, String, Integer e algumas macros de uso geral.
 */

#ifndef _UTIL_H
#define _UTIL_H

#include <string>
#include <iostream>
#include "node.hpp"
using namespace std;
typedef string Chave;
typedef int Valor;
typedef Node<Chave, Valor> * No;

#define MAX(a,b)     ((a) > (b) ? (a): (b))

/*---------------------------------------------------------------*/


/*-------------------------------------------------------------*/ 
/* alguma macros/abreviaturas uteis */
#define ERROR(msg)   fprintf(stderr,"ERROR: %s\n", #msg)
#define WARNING(msg) fprintf(stdout,"WARNING: %s\n", #msg)

/*---------------------------------------------------------------*/


#endif /* _UTIL_H */