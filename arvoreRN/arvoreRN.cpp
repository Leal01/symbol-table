#include "arvoreRN.hpp"

TreeNodeRN<Chave, Valor> * arvoreRN::put(TreeNodeRN<Chave, Valor> * root, Chave key, Valor value) {
   if (root == nullptr) {
      root = new TreeNodeRN<Chave, Valor>;
      root->setColor("red");
      root->setKey(key);
      root->setValue(1);
      return root;
   }
   else {
      TreeNodeRN<Chave, Valor> * father = root;
      bool found = false;

      while (!found) {
         if (father->getKey() > key && father->getLeft() != nullptr)
            father = father->getLeft();
         else if (father->getKey() > key && father->getLeft() == nullptr)
            found = true;
         else if (father->getKey() < key && father->getRight() != nullptr)
            father = father->getRight();
         else if (father->getKey() < key && father->getRight() == nullptr)
            found = true;
         else
            found = true;
      }

      if (father->getKey() == key) {
         father->setValue(father->getValue() + 1);
         return root;
      }
      else {
         TreeNodeRN<Chave, Valor> * son = new TreeNodeRN<Chave, Valor>;
         son->setKey(key);
         son->setValue(1);
         son->setColor("red");
         son->setFather(father);

         if (son->getKey() > father->getKey()) 
            father->setRight(son);
   
         else 
            father->setLeft(son);

         while (father != nullptr) {
            TreeNodeRN<Chave, Valor> * uncle = nullptr;
            TreeNodeRN<Chave, Valor> * gFather = nullptr;

            gFather = father->getFather();

            if (gFather != nullptr)  
               uncle = (gFather->getLeft() == father) ? gFather->getRight() : gFather->getLeft();
            
            else
               uncle = nullptr;

            if (father->getColor() == "black") 
               break;

            else if (gFather == nullptr) {
               father->setColor("black");
               break;
            }
            
            else if (uncle != nullptr && uncle->getColor() == "red") {
               gFather->setColor("red");
               father->setColor("black");
               uncle->setColor("black");
               father = gFather->getFather();
               son = gFather;
            }

            else {
               if (father->getRight() == son && gFather->getLeft() == father) {
                  father->setRight(son->getLeft());
                  if (son->getLeft() != nullptr)
                     son->getLeft()->setFather(father);
                  son->setLeft(father);
                  father->setFather(son);
                  son->setFather(gFather);
                  gFather->setLeft(son);
                  father = son;
                  father = father->getFather();
               }

               if (father == gFather->getLeft() && son == father->getLeft()) {
                  gFather->setLeft(father->getRight());
                  if (father->getRight() != nullptr)
                     father->getRight()->setFather(gFather);
                  father->setRight(gFather);
                  father->setFather(gFather->getFather());
                  if (gFather->getFather() != nullptr) {
                     if (gFather->getFather()->getRight() == gFather)
                        gFather->getFather()->setRight(father);
                  else
                     gFather->getFather()->setLeft(father);
                  }
                  gFather->setFather(father);
                  father->setColor("black");
                  gFather->setColor("red");
                  if (gFather == root)
                     root = father;
                  break;
               }

               if (gFather->getRight() == father && father->getLeft() == son) {
                  father->setLeft(son->getRight());
                  if (son->getRight() != nullptr)
                     son->getRight()->setFather(father);
                  son->setRight(father);
                  father->setFather(son);
                  gFather->setRight(son);
                  son->setFather(gFather);
                  father = son;
                  son = son->getRight();
               }

               if (gFather->getRight() == father && father->getRight() == son) {
                  gFather->setRight(father->getLeft());
                  if (father->getLeft() != nullptr)
                     father->getLeft()->setFather(gFather);
                  father->setLeft(gFather);
                  father->setFather(gFather->getFather());
                  if (gFather->getFather() != nullptr) {
                     if (gFather->getFather()->getRight() == gFather)
                        gFather->getFather()->setRight(father);
                  else
                     gFather->getFather()->setLeft(father);
                  }
                  gFather->setFather(father);
                  father->setColor("black");
                  gFather->setColor("red");
                  if (gFather == root)
                     root = father;
                  break;
               }
            }
         }
      }
   }
   return root;
}

arvoreRN::arvoreRN(string file_name) {
   fstream textFile;
   Chave word;

   root = nullptr;
   textFile.open(file_name);

   while (textFile >> word)
      insere(word, 1);

   printTable(root);
   textFile.close();
}

arvoreRN::~arvoreRN() {}

void arvoreRN::insere(Chave key, Valor value) {
   root = put(root, key, value);
}

Valor arvoreRN::devolve(Chave key) {}

void arvoreRN::remove(Chave key) {}

int arvoreRN::rank(Chave key) {}

Chave arvoreRN::seleciona(int k) {}

void arvoreRN::printTable(TreeNodeRN<Chave, Valor> * root) {
   if (root == nullptr)
      return;
      
   printTable(root->getLeft());
   cout << root->getKey() << "   " << root->getValue() << endl;
   printTable(root->getRight());
}

  