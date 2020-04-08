/*
 * MAC0323 Algoritmos e Estruturas de Dados II
 * 
 * Contador de frequencia de palavras em um texto
 *
 *     http://www.ime.usp.br/~pf/mac0122-2003/aulas/symb-table.html
 * 
 * AVISO: Este programa quebra se o conjunto de caracters nao 
 *        for de 7-bits ASCII, ou seja, textos iso-latin 8859-1
 *        com acentos, cedilha, ... fazem o programa quebrar.
 *        UTF-8 nem pensar.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;

#include "util.hpp"  /* emalloc(), ecalloc(), strCmp(), getLine(), stringCopy(), ERRO(), AVISO(), getLine() */

/* tabela de símbolos */
#include "tabeladesimbolos.hpp"  /* initST(), freeST(), get(), put(), delete(), ... */

#define PROMPT      cout << ">>> ";
#define MIN_ST      "minST"
#define DELMIN_ST   "delminST"
#define GET_ST      "getST"
#define RANK_ST     "rankST"
#define DELETE_ST   "deleteST"
#define SELECT_ST   "selectST"

/*---------------------------------------------------------------*/
/*
 *  P R O T Ó T I P O S
 */
static void mostreUso (char *nomePrograma);

template <class ST>
void testeOperacoes(ST st);

/*---------------------------------------------------------------*/
/* 
 *  M A I N 
 */
int main(int argc, char *argv[]) {
  fstream arqTexto;

  if (argc < 3) 
    mostreUso(argv[0]);

  arqTexto.open(argv[1]);

  if (arqTexto.fail()) {
    cout << "ERRO: arquivo" << argv[1] << "nao pode ser aberto.\n";
    exit(EXIT_FAILURE);
  }

  arqTexto.close();

  string nome_arquivo = argv[1];
  string tipo = argv[2];

  cout << "criando ST...\n";

  clock_t start, end; 
  double elapsed = 0;

  if (tipo == "VD") {
    start = clock(); 
    vetorDes *st = new vetorDes(nome_arquivo);
    end = clock();

    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

    testeOperacoes((vetorDes *) st);
    delete st;
  }
  else if (tipo == "VO") {
    start = clock(); 
    vetorOrd *st = new vetorOrd(nome_arquivo);
    end = clock();

    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

    testeOperacoes((vetorOrd *) st);
    delete st;
  }
  else if (tipo == "LD") {
    start = clock(); 
    listaDes *st = new listaDes(nome_arquivo);
    end = clock();

    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

    testeOperacoes((listaDes *) st);
    delete st;
  }
  else if (tipo == "LO") {
    start = clock(); 
    listaOrd *st = new listaOrd(nome_arquivo);
    end = clock();

    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

    testeOperacoes((listaOrd *) st);
    delete st;
  }
  // else if (tipo == "AB") {
  //   start = clock(); 
  //   arvoreBin *st = new arvoreBin(nome_arquivo);
  //   end = clock();

  //   elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

  //   testeOperacoes((arvoreBin *) st);
  //   delete st;
  // }
  // else if (tipo == "TR") {
  //   start = clock(); 
  //   treap *st = new treap(nome_arquivo);
  //   end = clock();

  //   elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

  //   testeOperacoes((treap *) st);
  //   delete st;
  // }
  // else if (tipo == "A23") {
  //   start = clock(); 
  //   arvore23 *st = new arvore23(nome_arquivo);
  //   end = clock();

  //   elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

  //   testeOperacoes((arvore23 *) st);
  //   delete st;
  // }
  // else if (tipo == "RN") {
  //   start = clock(); 
  //   arvoreRN *st = new arvoreRN(nome_arquivo);
  //   end = clock();

  //   elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

  //   testeOperacoes((arvoreRN *) st);
  //   delete st;
  // }
  // else if (tipo == "HS") {
  //   start = clock(); 
  //   hashTable *st = new hashTable(nome_arquivo);
  //   end = clock();

  //   elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  //   cout << "arquivo lido e ST construida em " << elapsed << " segundos\n";

  //   testeOperacoes((hashTable *) st);
  //   delete st;
  // }
  // else {
  //   cout << "A estrutura" << tipo << "não é válida";
  //   exit(EXIT_FAILURE);
  // }

  // return EXIT_SUCCESS;
}

/*-------------------------------------------------------*/
/* 
 *  TESTEOPEARCOES(ST) 
 *
 *  RECEBE uma tabela de símbolos ST e testa várias operações
 *  interativamente.
 *
 *  A função supõe que as chaves são do tipo String e os
 *  valores são do tipo Integer (ver util.h).
 */

template <class ST>
void testeOperacoes(ST st) {
  string operacao;

  cout << "Possiveis operacoes do teste interativo:\n";
  cout << "minST, delminST, getST <chave>; rankST <chave>, deleteST <chave>, selectST <int>\n";
  cout << "CRTL-D para encerrar.\n";
  PROMPT;

  while (cin >> operacao) {
    if (operacao.empty()) {
      ERROR(operacao esperada);
    }
    else if (operacao.compare(MIN_ST) == 0) {
      string key = st->seleciona(0);

      if (key.empty())
        cout << "ST vazia\n";
      else
        cout << key << endl;
    }
    else {
      /* operaÃ§Ã£o necessita de argumento key */
      string key;
      cin >> key;

      if (key.empty()) {
        ERROR(operacao necessita uma palavra);
      } 
      else {
        if (operacao.compare(GET_ST) == 0) {
          int frequencia = 0;
          frequencia = st->devolve(key); /* consulte a ST */

          /* mostre o resultado da consulta */
          if (frequencia == 0) {
            cout << key << ": 0\n";
          } 
          else {
            cout << key << ": " << frequencia << "\n";
            //free(frequencia);
          }
        }
        else if (operacao.compare(RANK_ST) == 0) {
          int r = st->rank(key);
          cout << r << "\n";
        }
        else if (operacao.compare(DELETE_ST) == 0) {
          st->remove(key);
          cout << key << " foi removida\n";
        }
        else if (operacao.compare(SELECT_ST) == 0) {
          int pos = stoi(key);
          string chave = st->seleciona(pos);
          cout << "Posição " << key << " = " << chave << "\n";
        }
        else {
          ERROR(operacao nao reconhecida);
        }
      }
    }
    
    PROMPT;
  }

  cout << "\n";
}


/*-----------------------------------------------------------*/
/* 
 *  I M P L E M E N T A Ç Ã O   D A S   F U N Ç Õ E S
 *                 A U X I L I A R E S 
 */
static void mostreUso (char *nomePrograma) {
  cout << "Uso \n"
    << "prompt> " << nomePrograma << " nome-arquivo tipo-tabela\n"
    << "    nome-arquivo = nome do arquivo com o texto\n"
    << "    tipo-tabela  = sigla de estrutura que deve ser usada\n";
  
  exit(EXIT_FAILURE);
}