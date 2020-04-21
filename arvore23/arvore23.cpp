#include "arvore23.hpp"

TreeNode23<Chave, Valor> * arvore23::put(TreeNode23<Chave, Valor> * root, Chave key, Valor value, bool &grew) {
   if (root == nullptr) {
      root = new TreeNode23<Chave, Valor>;
      root->setKey(key, 1);
      root->setValue(value, 1);
      root->setTwoNode(true);
      grew = true;
   }

   else if (key == root->getKey(1)) {
      root->setValue(root->getValue(1) + 1, 1);
      grew = false;
   }

   else if (!root->getTwoNode() && key == root->getKey(2)) {
      root->setValue(root->getValue(2) + 1, 2);
      grew = false;
   }

   else if (root->isLeaf()) {
      if (root->getTwoNode()) {
         if (key > root->getKey(1)) {
            root->setKey(key, 2);
            root->setValue(value, 2);
         }
         else {
            root->setKey(root->getKey(1), 2);
            root->setValue(root->getValue(1), 2);
            root->setKey(key, 1);
            root->setValue(value, 1);
         }
         
         root->setTwoNode(false);
         grew = false;
      }

      else {
         TreeNode23<Chave, Valor> * mid = new TreeNode23<Chave, Valor>;
         TreeNode23<Chave, Valor> * higher = new TreeNode23<Chave, Valor>;
         Chave higherKey, midKey;
         Valor higherValue, midValue;

         if (key > root->getKey(2)) {
            higherKey = key;
            higherValue = value;
            midKey = root->getKey(2);
            midValue = root->getValue(2);
         }

         else {
            higherKey = root->getKey(2);
            higherValue = root->getValue(2);

            if (key > root->getKey(1)) {
               midKey = key;
               midValue = value;
            }

            else {
               midKey = root->getKey(1);
               midValue = root->getValue(1);
               root->setKey(key, 1);
               root->setValue(value, 1);
            }
         }

         higher->setKey(higherKey, 1);
         higher->setValue(higherValue, 1);
         mid->setKey(midKey, 1);
         mid->setValue(midValue, 1);
         mid->setLeft(root);
         mid->setMid(higher);
         higher->setTwoNode(true);
         mid->setTwoNode(true);
         root->setTwoNode(true);

         grew = true;
         root = mid;
      }
   }

   else if (key < root->getKey(1)) {
      TreeNode23<Chave, Valor> * p = put(root->getLeft(), key, value, grew);

      if (grew) {
         if (root->getTwoNode()) {
            root->setKey(root->getKey(1), 2);
            root->setValue(root->getValue(1), 2);
            root->setRight(root->getMid());
            root->setKey(p->getKey(1), 1);
            root->setValue(p->getValue(1), 1);
            root->setLeft(p->getLeft());
            root->setMid(p->getMid());
            root->setTwoNode(false);
            grew = false;

            delete p;
         }

         else {
            TreeNode23<Chave, Valor> * higher = new TreeNode23<Chave, Valor>;

            higher->setKey(root->getKey(2), 1);
            higher->setValue(root->getValue(2), 1);
            higher->setLeft(root->getMid());
            higher->setMid(root->getRight());
            higher->setTwoNode(true);

            root->setLeft(p);
            root->setMid(higher);
            root->setRight(nullptr);
            root->setTwoNode(true);

            grew = true;
         }
      }
   }
   else if (!root->getTwoNode() && root->getKey(2) < key) {
      TreeNode23<Chave, Valor> * p = put(root->getRight(), key, value, grew);
      
      if (grew) {
         TreeNode23<Chave, Valor> * lesser = new TreeNode23<Chave, Valor>;

         lesser->setKey(root->getKey(1), 1);
         lesser->setValue(root->getValue(1), 1);
         lesser->setLeft(root->getLeft());
         lesser->setMid(root->getMid());
         lesser->setTwoNode(true);

         root->setKey(root->getKey(2), 1);
         root->setValue(root->getValue(2), 1);
         root->setLeft(lesser);
         root->setMid(p);
         root->setRight(nullptr);
         root->setTwoNode(true);

         grew = true;
      }
   }
   else {
      TreeNode23<Chave, Valor> * p = put(root->getMid(), key, value, grew);

      if (grew) {
         if (root->getTwoNode()) {
            root->setKey(p->getKey(1), 2);
            root->setValue(p->getValue(1), 2);
            root->setMid(p->getLeft());
            root->setRight(p->getMid());
            root->setTwoNode(false);
            grew = false;

            delete p;
         }
         else {
            TreeNode23<Chave, Valor> * lesser = new TreeNode23<Chave, Valor>;
            TreeNode23<Chave, Valor> * higher = new TreeNode23<Chave, Valor>;

            lesser->setKey(root->getKey(1), 1);
            lesser->setValue(root->getValue(1), 1);
            lesser->setLeft(root->getLeft());
            lesser->setMid(p->getLeft());
            lesser->setTwoNode(true);

            higher->setKey(root->getKey(2), 1);
            higher->setValue(root->getValue(2), 1);
            higher->setLeft(p->getMid());
            higher->setMid(root->getRight());
            higher->setTwoNode(true);

            root->setKey(p->getKey(1), 1);
            root->setValue(p->getValue(1), 1);
            root->setLeft(lesser);
            root->setMid(higher);
            root->setRight(nullptr);
            root->setTwoNode(true);

            grew = true;

            delete p;
         }
      }
   }
   return root;

}

void arvore23::insere(Chave key, Valor value) {
   bool grew = true;
   root = put(root, key, value, grew);
}

arvore23::arvore23(string file_name) {
   fstream textFile;
   Chave word;

   root = nullptr;
   textFile.open(file_name);

   while (textFile >> word)
      insere(word, 1);

   printTable(root);
   textFile.close();

}

arvore23::~arvore23() {
   

}



Valor arvore23::devolve(Chave key) {

}

void arvore23::remove(Chave key) {


}

int arvore23::rank(Chave key) {


}

Chave arvore23::seleciona(int k) {

}

void arvore23::printTable(TreeNode23<Chave, Valor> * root) {
   if (root == nullptr)
      return;

   printTable(root->getLeft());
   cout << root->getKey(1) << " " << root->getValue(1) << endl;
   printTable(root->getMid());

   if (!root->getTwoNode()) {
      cout << root->getKey(2) << ": " << root->getValue(2) << endl;
      printTable(root->getRight());
   }
}