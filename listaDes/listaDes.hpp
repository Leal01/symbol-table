#include "../util.hpp"


class listaDes {
   private:
      No first;
      void printTable();
   
   public:
      listaDes(string file_name);
      ~listaDes();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};