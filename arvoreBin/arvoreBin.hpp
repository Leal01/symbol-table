#include "../util.hpp"

class arvoreBin {
   private:
      TreeNode<Chave, Valor> * root;
      TreeNode<Chave, Valor> * put(TreeNode<Chave, Valor> * root, Chave key, Valor value);
      Valor get(TreeNode<Chave, Valor> * root, Chave key);
      int getRank(TreeNode<Chave, Valor> * root, Chave key);
      void printTable(TreeNode<Chave, Valor> * root);

   public:
      arvoreBin(string file_name);
      ~arvoreBin();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};

