#include "../Node.hpp"

class vetorDes {
   private:
      Node * table;
      int n;
      int size;
      void printTable();

   public:
      vetorDes();
      ~vetorDes();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k); // ?
}; 
