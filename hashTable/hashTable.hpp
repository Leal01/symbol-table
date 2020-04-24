#include "../util.hpp"

class hashTable {
   private:
      Node<Chave, Valor> ** table;  
      void printTable();
      int hash(Chave key);
      
   public:
      hashTable(string file_name);
      ~hashTable();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
}; 
