#include "arvore23.hpp"

TreeNode23<Chave, Valor> * arvore23::put(TreeNode23<Chave, Valor> * root, Chave key, Valor value, bool &grew) {
   if (root == nullptr) {
      root = new TreeNode23<Chave, Valor>;
      root->setKey(key, 1);
      root->setValue(value, 1);
      root->setFather(nullptr);
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
         higher->setFather(mid);
         mid->setKey(midKey, 1);
         mid->setValue(midValue, 1);
         mid->setLeft(root);
         mid->setMid(higher);
         mid->setFather(root->getFather());
         higher->setTwoNode(true);
         mid->setTwoNode(true);
         root->setTwoNode(true);
         root->setFather(mid);

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
            root->getMid()->setFather(root);
            root->setKey(p->getKey(1), 1);
            root->setValue(p->getValue(1), 1);
            root->setLeft(p->getLeft());
            root->setMid(p->getMid());
            p->getLeft()->setFather(root);
            p->getMid()->setFather(root);
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
            root->getMid()->setFather(higher);
            root->getRight()->setFather(higher);
            higher->setFather(root);
            higher->setTwoNode(true);

            root->setLeft(p);
            root->setMid(higher);
            root->setRight(nullptr);
            root->setTwoNode(true);

            p->setFather(root);

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
         root->getLeft()->setFather(lesser);
         root->getMid()->setFather(lesser);
         lesser->setFather(root);
         lesser->setTwoNode(true);

         root->setKey(root->getKey(2), 1);
         root->setValue(root->getValue(2), 1);
         root->setLeft(lesser);
         root->setMid(p);
         p->setFather(root);
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
            p->getLeft()->setFather(root);
            p->getMid()->setFather(root);
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
            root->getLeft()->setFather(lesser);
            lesser->setMid(p->getLeft());
            p->getLeft()->setFather(lesser);
            lesser->setFather(root);
            lesser->setTwoNode(true);

            higher->setKey(root->getKey(2), 1);
            higher->setValue(root->getValue(2), 1);
            higher->setLeft(p->getMid());
            p->getMid()->setFather(higher);
            higher->setMid(root->getRight());
            root->getRight()->setFather(higher);
            higher->setFather(root);
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
   deleteTree(root);   
}

void arvore23::deleteTree(TreeNode23<Chave, Valor> * root) {
   if (root == nullptr)
      return;
   
   deleteTree(root->getLeft());
   deleteTree(root->getMid());
   if (!root->getTwoNode())
      deleteTree(root->getRight());
   delete root;
}


Valor arvore23::devolve(Chave key) {
   return get(root, key);
}

Valor arvore23::get(TreeNode23<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
       return 0;
   else if (root->getKey(1) == key)
      return root->getValue(1);
   else if (!root->getTwoNode() && root->getKey(2) == key)
      return root->getValue(2);
   else if  (root->getKey(1) > key)
      return get(root->getLeft(), key);
   else if (!root->getTwoNode() && root->getKey(2) < key)
      return get(root->getRight(), key);
   
   return get(root->getMid(), key);
}

void arvore23::remove(Chave key) {
   bool decreased = false;
   root = destroy(root, key, decreased);
   printTable(root);
}

int arvore23::rank(Chave key) {
   return getRank(root, key);

}

int arvore23::getRank(TreeNode23<Chave, Valor> * root, Chave key) {
   int r = 0;
   
   if (root->getKey(1) == key)
      return size(root->getLeft());
   else if (!root->getTwoNode() && root->getKey(2) == key) {//
      r += size(root->getLeft()) + 1;
      return (r + size(root->getMid()));
   }

   else if (!root->getTwoNode() && key > root->getKey(2)) {
      r += size(root->getLeft()) + 1;
      r += size(root->getMid()) + 1;
      r += getRank(root->getRight(), key);
   }

   else if (key < root->getKey(1)) {
      r += getRank(root->getLeft(), key);
   }

   else {
      r += size(root->getLeft()) + 1;
      r += getRank(root->getMid(), key);
   }

   return r;   
}

int arvore23::size(TreeNode23<Chave, Valor> * root) {
   int s = 0;

   if (root == nullptr)
      return s;
   
   s += size(root->getLeft()) + 1;
   s += size(root->getMid());
   if (!root->getTwoNode())
      s += size(root->getRight()) + 1;
      

   return s;
}

Chave arvore23::seleciona(int k) {
   return select(root, k);
}

Chave arvore23::select(TreeNode23<Chave, Valor> * root, int k) {
   if (root == nullptr) 
      return 0;

   int r = rank(root->getKey(1));

   if (k == r)
      return root->getKey(1);
   else if (k == (r + 1) && !root->getTwoNode())
      return root->getKey(2);
   else if (k < size(root->getLeft()))
      return select(root->getLeft(), k);
   else if (k > size(root->getLeft()) && k > size(root->getLeft()) + size(root->getMid()))
      return select(root->getRight(), k);
   else
      return select(root->getMid(), k);
   
   
}

void arvore23::printTable(TreeNode23<Chave, Valor> * root) {
   if (root == nullptr)
      return;

   printTable(root->getLeft());
   cout << root->getKey(1) <<  endl;
   printTable(root->getMid());

   if (!root->getTwoNode()) {
      cout << root->getKey(2) << endl;
      printTable(root->getRight());
   }
}

TreeNode23<Chave, Valor> * arvore23::destroy(TreeNode23<Chave, Valor> * root, Chave key, bool & decreased) {
   if (root == nullptr) {
      return root;
   }
   else if (root->getFather() == nullptr && root->isLeaf() && root->getTwoNode() && key == root->getKey(1)) {
      delete root;
      root = nullptr;
   }
   else if (key == root->getKey(1)) {
      if (!root->isLeaf()) {
         // pega o nó da folha com maior valor possível, substitui nessa posição e remove a folha
         TreeNode23<Chave, Valor> * aux = max(root->getLeft());

         if (aux->getTwoNode()) {
            root->setKey(aux->getKey(1), 1);
            root->setValue(aux->getValue(1), 1);
            root->setLeft(destroy(root->getLeft(), aux->getKey(1), decreased));
         }
         else {
            root->setKey(aux->getKey(2), 1);
            root->setValue(aux->getValue(2), 1);
            root->setLeft(destroy(root->getLeft(), aux->getKey(2), decreased));
         }
         decreased = false;
      }

      else {
         if (!root->getTwoNode()) {
            root->setKey(root->getKey(2), 1);
            root->setValue(root->getValue(2), 1);
            root->setTwoNode(true);
            decreased = false;
         }
         else {
            decreased = true;
         }
      }
   }
   else if (!root->getTwoNode() && key == root->getKey(2)) {
      if (!root->isLeaf()) {
         // pega o nó da folha com maior valor possível, substitui nessa posição e remove a folha
         TreeNode23<Chave, Valor> * aux = max(root->getMid());

         if (aux->getTwoNode()) {
            root->setKey(aux->getKey(1), 2);
            root->setValue(aux->getValue(1), 2);
            root->setMid(destroy(root->getMid(), aux->getKey(1), decreased));
         }
         else {
            root->setKey(aux->getKey(2), 2);
            root->setValue(aux->getValue(2), 2);
            root->setMid(destroy(root->getMid(), aux->getKey(2), decreased));
         }
         decreased = false;
      }
      else {
         root->setTwoNode(true);
         decreased = false;
      }
   }
   else if (key < root->getKey(1)) {
      TreeNode23<Chave, Valor> * p = destroy(root->getLeft(), key, decreased);

      if (decreased) {
         TreeNode23<Chave, Valor> * brother = root->getMid();

         if (!root->getTwoNode()) {
            if (!brother->getTwoNode()) {
               // desce a menor key do pai pra root e sobe a menor key do brother pro pai
               p->setKey(root->getKey(1), 1);
               p->setValue(root->getValue(1), 1);
               root->setKey(brother->getKey(1), 1);
               root->setValue(brother->getValue(1), 1);
               brother->setKey(brother->getKey(2), 1);
               brother->setValue(brother->getValue(2), 1);
               brother->setTwoNode(true);
               
               if (p->getLeft() == nullptr)
                  p->setLeft(p->getMid());
               
               p->setMid(brother->getLeft());

               if (brother->getLeft() != nullptr)
                  brother->getLeft()->setFather(p);
               
               brother->setLeft(brother->getMid());
               brother->setMid(brother->getRight());
               brother->setRight(nullptr);

               decreased = false;
            }
            else {
               brother->setKey(brother->getKey(1), 2);
               brother->setValue(brother->getValue(1), 2);
               brother->setKey(root->getKey(1), 1);
               brother->setValue(root->getValue(1), 1); 
               brother->setTwoNode(false);
               root->setKey(root->getKey(2), 1);
               root->setValue(root->getValue(2), 1);
               root->setLeft(brother);
               root->setMid(root->getRight());
               root->setRight(nullptr);
               root->setTwoNode(true);

               brother->setRight(brother->getMid());
               brother->setMid(brother->getLeft());
                  
               if (p->getLeft() == nullptr) {
                  brother->setLeft(p->getMid());

                  if (p->getMid() != nullptr)
                     p->getMid()->setFather(brother);
               }
               else {
                  brother->setLeft(p->getLeft());

                  if (p->getLeft() != nullptr)
                     p->getLeft()->setFather(brother);
               }

               decreased = false;
               delete p;
            }
         }
         else {
            if (!brother->getTwoNode()) {
               p->setKey(root->getKey(1), 1); 
               p->setValue(root->getValue(1), 1); 
               root->setKey(brother->getKey(1), 1); 
               root->setValue(brother->getValue(1), 1); 
               brother->setKey(brother->getKey(2), 1);
               brother->setValue(brother->getValue(2), 1);
               brother->setTwoNode(true);

               if (p->getLeft() == nullptr)
                  p->setLeft(p->getMid());
               
               p->setMid(brother->getLeft());

               if (brother->getLeft() != nullptr)
                  brother->getLeft()->setFather(p);
               
               brother->setLeft(brother->getMid());
               brother->setMid(brother->getRight());
               brother->setRight(nullptr); 

               decreased = false;
            }
            else {
               brother->setKey(brother->getKey(1), 2);
               brother->setValue(brother->getValue(1), 2);
               brother->setKey(root->getKey(1), 1);
               brother->setValue(root->getValue(1), 1);
               brother->setTwoNode(false);

               brother->setRight(brother->getMid());
               brother->setMid(brother->getLeft());

               // TEM QUE PEGAR OS PONTEIRO DA RAIZ E COLOCAR NO IRMAO
               if (p->getLeft() == nullptr) {
                  brother->setLeft(p->getMid());

                  if (p->getMid() != nullptr)
                  p->getMid()->setFather(brother);
               }
               else {
                  brother->setLeft(p->getLeft());

                  if (p->getLeft() != nullptr)
                     p->getLeft()->setFather(brother);
               }

               root->setLeft(nullptr); // desvincula a root do pai

               decreased = true;

               delete p;

               if (root->getFather() == nullptr) {
                  delete root;
                  root = brother;
                  root->setFather(nullptr);
               }
            }
         }
      }
   }
   else if (!root->getTwoNode() && key > root->getKey(2)) {
      TreeNode23<Chave, Valor> * p = destroy(root->getRight(), key, decreased);

      if (decreased) {
         TreeNode23<Chave, Valor> * brother = root->getMid();

         if (!brother->getTwoNode()) {
            p->setKey(root->getKey(2), 1);
            p->setValue(root->getValue(2), 1);
            root->setKey(brother->getKey(2), 2);
            root->setValue(brother->getValue(2), 2);
            brother->setTwoNode(true);

            if (p->getLeft() == nullptr) {
               p->setLeft(brother->getRight());
            }
            else {
               p->setMid(p->getLeft());
               p->setLeft(brother->getRight());
            }

            if (brother->getRight() != nullptr)
               brother->getRight()->setFather(p);

            brother->setRight(nullptr);
         
            decreased = false;
         }
         else {
            brother->setKey(root->getKey(2), 2);
            brother->setValue(root->getValue(2), 2);
            brother->setTwoNode(false);
            root->setTwoNode(true);

            if (p->getLeft() == nullptr) {
               brother->setRight(p->getMid());

               if (p->getMid() != nullptr)
                  p->getMid()->setFather(brother);
            }
            else {
               brother->setRight(p->getLeft());

               if (p->getLeft() != nullptr)
                  p->getLeft()->setFather(brother);
            }

            root->setRight(nullptr);

            decreased = false;
            delete p;
         }
      }
   }
   else {
      TreeNode23<Chave, Valor> * p = destroy(root->getMid(), key, decreased);

      if (decreased) {
         TreeNode23<Chave, Valor> * brother = root->getLeft();

         if (!root->getTwoNode()) {
            if (!brother->getTwoNode()) {
               p->setKey(root->getKey(1), 1);
               p->setValue(root->getValue(1), 1);
               root->setKey(brother->getKey(2), 1);
               root->setValue(brother->getValue(2), 1);
               brother->setTwoNode(true);

               if (p->getLeft() == nullptr) {
                  p->setLeft(brother->getRight());
               }
               else {
                  p->setMid(p->getLeft());
                  p->setLeft(brother->getRight());
               }

               if (brother->getRight() != nullptr)
                  brother->getRight()->setFather(p);

               brother->setRight(nullptr);

               decreased = false;
            }
            else {
               brother->setKey(root->getKey(1), 2);
               brother->setValue(root->getValue(1), 2);
               brother->setTwoNode(false);
               root->setKey(root->getKey(2), 1);
               root->setValue(root->getValue(2), 1);
               root->setMid(root->getRight());
               root->setRight(nullptr);
               root->setTwoNode(true);

               if (p->getLeft() == nullptr) {
                  brother->setRight(p->getMid());

                  if (p->getMid() != nullptr)
                     p->getMid()->setFather(brother);
               }
               else {
                  brother->setRight(p->getLeft());

                  if (p->getLeft() != nullptr)
                     p->getLeft()->setFather(brother);
               }

               delete p;
               decreased = false;
            }
         }
         else {
            if (!brother->getTwoNode()) {
               p->setKey(root->getKey(1), 1);
               p->setValue(root->getValue(1), 1);
               root->setKey(brother->getKey(2), 1);
               root->setValue(brother->getValue(2), 1);
               brother->setTwoNode(true);

               if (p->getLeft() == nullptr) {
                  p->setLeft(brother->getRight());
               }
               else {
                  p->setMid(p->getLeft());
                  p->setLeft(brother->getRight());
               }

               if (brother->getRight() != nullptr)
                  brother->getRight()->setFather(p);

               brother->setRight(nullptr);

               decreased = false;
            }
            else {
               // irmão pobre com pai dois-no
               brother->setKey(root->getKey(1), 2);
               brother->setValue(root->getValue(1), 2);
               brother->setTwoNode(false);

               // TEM QUE PEGAR OS PONTEIRO DA RAIZ E COLOCAR NO IRMAO
               if (p->getLeft() == nullptr) {
                  brother->setRight(p->getMid());

                  if (p->getMid() != nullptr)
                     p->getMid()->setFather(brother);
               }
               else {
                  brother->setRight(p->getLeft());

                  if (p->getLeft() != nullptr)
                     p->getLeft()->setFather(brother);
               }
               
               decreased = true;

               root->setMid(nullptr); // desvincula p da root

               delete p;

               if (root->getFather() == nullptr) {
                  delete root;
                  root = brother;
                  root->setFather(nullptr);
               }
            }
         }
      }
   }

  return root;
}

TreeNode23<Chave, Valor> * arvore23::max(TreeNode23<Chave, Valor> * root) {
   if (root == nullptr || root->getMid() == nullptr || (!root->getTwoNode() && root->getRight() == nullptr))
      return root;

   if (root->getTwoNode())
      return max(root->getMid());
   else
      return max(root->getRight());
}