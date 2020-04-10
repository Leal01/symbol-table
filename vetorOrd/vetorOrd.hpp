#include "../util.hpp"

class vetorOrd {
   private:
      Node<Chave, Valor> ** table;
      int n;
      int size;
      void printTable();
      void resize();
      int binarySearch(Chave key);
      
   public:
      vetorOrd(string file_name);
      ~vetorOrd();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
}; 
