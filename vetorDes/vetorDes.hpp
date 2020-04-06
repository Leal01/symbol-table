#include "../util.hpp"
#include <fstream>

class vetorDes {
   private:
      No table;
      int n;
      int size;
      void printTable();
      void resize();

   public:
      vetorDes(string file_name);
      ~vetorDes();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
}; 
