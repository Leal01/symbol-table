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
   int r = 0;
   
   if (root->getKey() == key)
      return size(root->getLeft());

   else if (key > root->getKey()) {
      r += size(root->getLeft()) + 1;
      r += getRank(root->getRight(), key);
   }

   else {
      r += getRank(root->getLeft(), key);
   }

   return r;
}

int arvoreBin::size(TreeNode<Chave, Valor> * root) {
   int s = 0;

   if (root == nullptr)
      return s;
   
   s += size(root->getLeft()) + 1;
   s += size(root->getRight());

   return s;
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

arvoreBin::~arvoreBin() {
   deleteTree(root);
}

void arvoreBin::deleteTree(TreeNode<Chave, Valor> * root) {
   if (root == nullptr)
      return;
   
   deleteTree(root->getLeft());
   deleteTree(root->getRight());
   delete root;
}

void arvoreBin::insere(Chave key, Valor value) {
   root = put(root, key, value);
}

Valor arvoreBin::devolve(Chave key) {
   return get(root, key);
}

void arvoreBin::remove(Chave key) {
  root = destroyNode(root, key);
  printTable(root);
}

TreeNode<Chave, Valor> * arvoreBin::destroyNode(TreeNode<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
      return root;

   if (key < root->getKey())
      root->setLeft(destroyNode(root->getLeft(), key));
   else if (key > root->getKey())
      root->setRight(destroyNode(root->getRight(), key));

   else {
      if (root->getRight() == nullptr) {
         TreeNode<Chave, Valor> * aux = root->getLeft();

         delete root;
         return aux;
      }
      else if (root->getLeft() == nullptr) {
         TreeNode<Chave, Valor> * aux = root->getRight();
         delete root;
         return aux;
      }
      else {
         TreeNode<Chave, Valor> * aux = max(root->getLeft());
         root->setKey(aux->getKey());
         root->setValue(aux->getValue());
         root->setLeft(destroyNode(root->getLeft(), aux->getKey()));
      }
   }
   return root;
}

TreeNode<Chave, Valor> * arvoreBin::max(TreeNode<Chave, Valor> * root) {
  if (root == nullptr || root->getRight() == nullptr)
      return root;

  return max(root->getRight());
}

int arvoreBin::rank(Chave key) {
   if (devolve(key) == 0)
      return 0;

   else
      return getRank(root, key);
}

Chave arvoreBin::seleciona(int k) {
   return select(root, k);
}

Chave arvoreBin::select(TreeNode<Chave, Valor> * root, int k) {
   if (root == nullptr) 
      return 0;

   int r = rank(root->getKey());

   if (k == r)
      return root->getKey();
   else if (k > r)
      return select(root->getRight(), k);
   else
      return select(root->getLeft(), k);
}

void arvoreBin::printTable(TreeNode<Chave, Valor> * root) {
   if (root == nullptr)
      return;
      
   printTable(root->getLeft());
   cout << root->getKey() << endl;
   printTable(root->getRight());

}

