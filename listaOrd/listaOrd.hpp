#include "../util.hpp"


class listaOrd {
   private:
      No first;
      void printTable();
   
   public:
      listaOrd(string file_name);
      ~listaOrd();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};