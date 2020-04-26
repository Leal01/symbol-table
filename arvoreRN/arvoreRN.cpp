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

arvoreRN::~arvoreRN() {
   deleteTree(root);
}

void arvoreRN::deleteTree(TreeNodeRN<Chave, Valor> * root) {
   if (root == nullptr)
      return;
   
   deleteTree(root->getLeft());
   deleteTree(root->getRight());
   delete root;
}

void arvoreRN::insere(Chave key, Valor value) {
   root = put(root, key, value);
}

Valor arvoreRN::devolve(Chave key) {
   return get(root, key);
}

Valor arvoreRN::get(TreeNodeRN<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
       return 0;
   else if (root->getKey() == key)
      return root->getValue();
   else if  (root->getKey() > key)
      return get(root->getLeft(), key);
   
   return get(root->getRight(), key);
}

void arvoreRN::remove(Chave key) {
   root = destroy(root, key);
   printTable(root);
}

TreeNodeRN<Chave, Valor> * arvoreRN::destroy(TreeNodeRN<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
      return root;

   else {
      TreeNodeRN<Chave, Valor> * p = root;
      bool found = false;

      while (!found) {
         if (key < p->getKey())
            p = p->getLeft();

         else if (key > p->getKey())
            p = p->getRight();

         else {
            if (p->getLeft() == nullptr && p->getRight() == nullptr) {
               found = true;
            }
            else if (p->getLeft() != nullptr) {
               TreeNodeRN<Chave, Valor> * aux = max(p->getLeft());
               p->setKey(aux->getKey());
               p->setValue(aux->getValue());
               key = aux->getKey();
               p = p->getLeft();
            }
            else {
               TreeNodeRN<Chave, Valor> * aux = min(p->getRight());
               p->setKey(aux->getKey());
               p->setValue(aux->getValue());
               key = aux->getKey();
               p = p->getRight();
            }
         }
      }

      if (found) {
         if (p == root) {
            delete p;
            root = nullptr;
         }
         else if (p->getColor() == "red") {
            // caso 1.0: folha vermelha
            if (p->getFather()->getLeft() == p)
               p->getFather()->setLeft(nullptr);
            else
               p->getFather()->setRight(nullptr);
        
            delete p;
         }
         else {
            TreeNodeRN<Chave, Valor> * aux = p;

            while (true) {
               if (p->getColor() == "doubleBlack" && p->getFather() == nullptr) {
                  // caso 2.0: duplo preto é a root
                  p->setColor("black");
                  break;
               }
               else {
                  TreeNodeRN<Chave, Valor> * father = p->getFather();
                  TreeNodeRN<Chave, Valor> * brother = (father->getKey() > p->getKey()) ? father->getRight() : father->getLeft();
            
                  if (brother != nullptr && brother->getColor() == "red") {
                     // caso 2.2: irmão vermelho
                     string auxColor = brother->getColor();
                     brother->setColor(father->getColor());
                     father->setColor(auxColor);

                     p->setColor("doubleBlack");

                     if (father->getLeft() == p) {
                        // rotaciona pra esquerda
                        // NÃO ESQUECER DE ATUALIZAR OS PAIS
                        brother->setFather(father->getFather()); // avo

                        if (father->getFather() != nullptr) {
                           if (father->getFather()->getLeft() == father)
                              father->getFather()->setLeft(brother);
                           else
                              father->getFather()->setRight(brother);
                        }
                        else {
                           root = brother;
                        }

                        father->setRight(brother->getLeft());

                        if (brother->getLeft() != nullptr)
                           brother->getLeft()->setFather(father);

                        brother->setLeft(father);
                        father->setFather(brother);
                     }
                     else {
                        // rotaciona pra direita
                        brother->setFather(father->getFather());

                        if (father->getFather() != nullptr) {
                           if (father->getFather()->getLeft() == father)
                              father->getFather()->setLeft(brother);
                           else
                              father->getFather()->setRight(brother);
                        }
                        else {
                           // quer dizer que o irmão vai ser a nova root;
                           root = brother;
                        }

                        father->setLeft(brother->getRight());
   
                        if (brother->getRight() != nullptr)
                           brother->getRight()->setFather(father);

                        brother->setRight(father);
                        father->setFather(brother);
                     }
                  }
                  else if (brother != nullptr && brother->getColor() == "black") {
                     if ((brother->getLeft() == nullptr || brother->getLeft()->getColor() == "black") && 
                        (brother->getRight() == nullptr || brother->getRight()->getColor() == "black")) {
                           // caso 2.1: irmão preto com filhos pretos
                           brother->setColor("red");

                           if (p == aux) {
                              if (father->getLeft() == p)
                                 father->setLeft(nullptr);
                              else
                                 father->setRight(nullptr);
                  
                              delete p;
                           }

                           if (father->getColor() == "red") {
                              father->setColor("black");
                              break;
                           }
                           else {
                              father->setColor("doubleBlack");
                              p = father; // empurrei o problema pra cima
                           }
                     }
                     else {
                        TreeNodeRN<Chave, Valor> * closerNephew = (father->getLeft() == p) ? brother->getLeft() : brother->getRight();
                        TreeNodeRN<Chave, Valor> * farNephew = (father->getLeft() == p) ? brother->getRight() : brother->getLeft();

                        if (farNephew != nullptr && farNephew->getColor() == "red") {   
                           /* 
                           caso 2.4: troca a cor do father com o irmão,
                           rotaciona a subarvore com o father do duplo preto na direção do duplo preto
                           e pinta o antigo sobrinho que era vermelho de preto
                           */
                           string auxColor = brother->getColor();
                           brother->setColor(father->getColor());
                           father->setColor(auxColor);

                           if (father->getLeft() == p) {
                              // rotaciona pra esquerda
                              brother->setFather(father->getFather());

                              if (father->getFather() != nullptr) {
                                 if (father->getFather()->getLeft() == father)
                                    father->getFather()->setLeft(brother);
                                 else
                                    father->getFather()->setRight(brother);
                              }
                              else {
                                 // quer dizer que o irmão vai ser a nova root;
                                 root = brother;
                              }

                              father->setRight(brother->getLeft());
                     
                              if (brother->getLeft() != nullptr)
                                 brother->getLeft()->setFather(father);

                              brother->setLeft(father);
                              father->setFather(brother);
                           }
                           else {
                              // rotaciona pra direita
                              brother->setFather(father->getFather());

                              if (father->getFather() != nullptr) {
                                 if (father->getFather()->getLeft() == father)
                                    father->getFather()->setLeft(brother);
                                 else
                                    father->getFather()->setRight(brother);
                              }
                              else {
                                 // quer dizer que o irmão vai ser a nova root;
                                 root = brother;
                              }

                              father->setLeft(brother->getRight());

                              if (brother->getRight() != nullptr)
                                 brother->getRight()->setFather(father);

                              brother->setRight(father);
                              father->setFather(brother);
                           }
   
                           farNephew->setColor("black");

                           if (p == aux) {
                              if (father->getLeft() == p)
                                 father->setLeft(nullptr);
                              else
                                 father->setRight(nullptr);
                    
                              delete p;
                           }

                           else
                              p->setColor("black");

                           break;
                        }

                        if (closerNephew != nullptr && closerNephew->getColor() == "red") {
                           /* 
                           caso 2.3: troca a cor do irmão e desse filho e
                           rotaciona a subarvore do irmão na direção contrária do duplo preto 
                           (se ele tá na direita, rotaciona pra esquerda. Se ele tá na esquerda, rotaciona pra direita)
                           */
                           string auxColor = brother->getColor();
                           brother->setColor(closerNephew->getColor());
                           closerNephew->setColor(auxColor);

                           if (father->getLeft() == p) {
                              // rotaciona pra direita (contrário da onde o p tá)
                              closerNephew->setFather(brother->getFather());
                              brother->getFather()->setRight(closerNephew);

                              brother->setLeft(closerNephew->getRight());

                              if (closerNephew->getRight() != nullptr)
                                 closerNephew->getRight()->setFather(brother);
   
                              closerNephew->setRight(brother);
                              brother->setFather(closerNephew);
                           }
                           else {
                              // rotaciona pra esq (contrário da onde o p tá)
                              closerNephew->setFather(father);
                              father->setLeft(closerNephew);

                              brother->setRight(closerNephew->getLeft());
   
                              if (closerNephew->getLeft() != nullptr)
                                 closerNephew->getLeft()->setFather(brother);

                              closerNephew->setLeft(brother);
                              brother->setFather(closerNephew);
                           }
                        }
                     }
                  }
               }
            }
         }
      }

      return root;
  }
}

TreeNodeRN<Chave, Valor> * arvoreRN::max(TreeNodeRN<Chave, Valor> * root) {
  if (root == nullptr || root->getRight() == nullptr)
    return root;

  return max(root->getRight());
}

TreeNodeRN<Chave, Valor> * arvoreRN::min(TreeNodeRN<Chave, Valor> * root) {
   if (root == nullptr || root->getLeft() == nullptr)
      return root;

  return min(root->getLeft());
}


int arvoreRN::rank(Chave key) {
   return getRank(root, key);
}

int arvoreRN::getRank(TreeNodeRN<Chave, Valor> * root, Chave key) {
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

int arvoreRN::size(TreeNodeRN<Chave, Valor> * root) {
   int s = 0;

   if (root == nullptr)
      return s;
   
   s += size(root->getLeft()) + 1;
   s += size(root->getRight());

   return s;
}

Chave arvoreRN::seleciona(int k) {
   return select(root, k);
}

Chave arvoreRN::select(TreeNodeRN<Chave, Valor> * root, int k) {
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

void arvoreRN::printTable(TreeNodeRN<Chave, Valor> * root) {
   if (root == nullptr)
      return;
      
   printTable(root->getLeft());
   cout << root->getKey() << endl;
   printTable(root->getRight());

}

  