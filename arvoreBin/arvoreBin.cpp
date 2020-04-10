#include "arvoreBin.hpp"

Valor arvoreBin::get(TreeNode<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
       return 0;
   else if (root->getKey() == key)
      return root->getValue();
   else if  (root->getKey() > key)
      return get(root->getLeft(), key);
   
   return get(root->getRight(), key);
}

TreeNode<Chave, Valor> * arvoreBin::put(TreeNode<Chave, Valor> * root, Chave key, Valor value) {
   if (root == nullptr) {
      root = new TreeNode<Chave, Valor>;
      root->setKey(key);
      root->setValue(value);
      return root;
   }

   else if (root->getKey() == key)
      root->setValue(root->getValue() + 1);
   
   else if (root->getKey() > key)
      root->setLeft(put(root->getLeft(), key, value));

   else 
      root->setRight(put(root->getRight(), key, value)); 

   return root;
}

int arvoreBin::getRank(TreeNode<Chave, Valor> * root, Chave key) {
}

arvoreBin::arvoreBin(string file_name) {
   fstream textFile;
   Chave word;

   root = nullptr;
   textFile.open(file_name);

   while (textFile >> word)
      insere(word, 1);

   printTable(root);
   textFile.close();

}

arvoreBin::~arvoreBin() {}

void arvoreBin::insere(Chave key, Valor value) {
   root = put(root, key, value);
}

Valor arvoreBin::devolve(Chave key) {
   return get(root, key);
}

void arvoreBin::remove(Chave key) {}

int arvoreBin::rank(Chave key) {
}

Chave arvoreBin::seleciona(int k) {

}

void arvoreBin::printTable(TreeNode<Chave, Valor> * root) {
   if (root == nullptr)
      return;
      
   printTable(root->getLeft());
   cout << root->getKey() << "   " << root->getValue() << endl;
   printTable(root->getRight());

}

