#include "treap.hpp"


treap::treap(string file_name) {
   fstream textFile;
   Chave word;

   root = nullptr;
   textFile.open(file_name);

   while (textFile >> word)
      insere(word, 1);

   printTable(root);
   textFile.close();
}

treap::~treap() {
  deleteSt(root);
}

void treap::deleteSt(TreapNode<Chave, Valor> * root) {
   if (root == nullptr)
      return;

   deleteSt(root->getLeft());
   deleteSt(root->getRight());
   delete root;
}

TreapNode<Chave, Valor> * treap::newNode(Chave key, Valor value) {
   TreapNode<Chave, Valor> * treap = new TreapNode<Chave, Valor>;
   treap->setKey(key);
   treap->setValue(value);
   treap->setPriority(rand());
   treap->setLeft(nullptr);
   treap->setRight(nullptr);

   return treap;
}

TreapNode<Chave, Valor> * treap::rotateLeft(TreapNode<Chave, Valor> * root) {
   TreapNode<Chave, Valor> * newRoot = root->getRight();
   TreapNode<Chave, Valor> * aux = newRoot->getLeft();

   newRoot->setLeft(root);
   root->setRight(aux);

   return newRoot;
}

TreapNode<Chave, Valor> * treap::rotateRight(TreapNode<Chave, Valor> * root) {
   TreapNode<Chave, Valor> * newRoot = root->getLeft();
   TreapNode<Chave, Valor> * aux = newRoot->getRight();

   newRoot->setRight(root);
   root->setLeft(aux);

   return newRoot;
}

TreapNode<Chave, Valor> * treap::put(TreapNode<Chave, Valor> * root, Chave key, Valor value) {
   if (root == nullptr)
      return newNode(key, value);

   if (key == root->getKey()) {
      root->setValue(root->getValue() + 1);
   }

   else if (key < root->getKey()) {
      root->setLeft(put(root->getLeft(), key, value));

      if (root->getLeft() != nullptr && root->getLeft()->getPriority() > root->getPriority())
         root = rotateRight(root);
   }
   else {
      root->setRight(put(root->getRight(), key, value));

      if (root->getRight() != nullptr && root->getRight()->getPriority() > root->getPriority())
         root = rotateLeft(root);
   }

  return root;
}

void treap::insere(Chave key, Valor value) {
   root = put(root, key, value);
}

Valor treap::get(TreapNode<Chave, Valor> * root, Chave key) {
  if (root == nullptr) {
      cout << "Chave não encontrada\n";
      return 0;
  }
   

   if (key == root->getKey())
      return root->getValue();
   else if (key < root->getKey())
      return get(root->getLeft(), key);
   else
      return get(root->getRight(), key);
}

Valor treap::devolve(Chave key) {
   return get(root, key);
}

TreapNode<Chave, Valor> * treap::destroy(TreapNode<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
      return root;

   if (key < root->getKey())
      root->setLeft(destroy(root->getLeft(), key));

   else if (key > root->getKey())
      root->setRight(destroy(root->getRight(), key));

   else {
      if (root->getLeft() == nullptr && root->getRight() == nullptr) {
         delete root;
         root = nullptr;
      }

      else if (root->getLeft() != nullptr && root->getRight() != nullptr) {
         if (root->getLeft()->getPriority() < root->getRight()->getPriority()) {
            root = rotateLeft(root);
            root->setLeft(destroy(root->getLeft(), key));
      }

      else {
         root = rotateRight(root);
         root->setRight(destroy(root->getRight(), key));
      }
    }

   else {
      TreapNode<Chave, Valor> * newRoot;

      if (root->getLeft() == nullptr)
         newRoot = root->getRight();
      
      else
         newRoot = root->getLeft();
      
      delete root;
      root = newRoot;
    }
  }
  
  return root;
}

void treap::remove(Chave key) {
   root = destroy(root, key);

   printTable(root);
}

int treap::size(TreapNode<Chave, Valor> * root) {
   if (root == nullptr)
      return 0;

  int left = size(root->getLeft());
  int right = size(root->getRight());

  return left + right + 1;
}

int treap::getRank(TreapNode<Chave, Valor> * root, Chave key) {
   if (root == nullptr)
      return 0;
  
   if (key < root->getKey())
      return getRank(root->getLeft(), key);
   else if (key > root->getKey())
      return size(root->getLeft()) + 1 + getRank(root->getRight(), key);
   else
      return size(root->getLeft());
}

int treap::rank(Chave key) {
   if (devolve(key) == 0) {
      cout << "Chave não encontrada\n";
      return 0;
   }

  return getRank(root, key);
}

Chave treap::select(TreapNode<Chave, Valor> * root, int k) {
   if (root == nullptr) {
      cout << "Rank indisponível\n";
      return NULL;
   }

  int r = rank(root->getKey());

   if (r == k)
      return root->getKey();
   else if (r > k)
      return select(root->getLeft(), k);
   else
      return select(root->getRight(), k);
}

Chave treap::seleciona(int k) {
  return select(root, k);
}

void treap::printTable(TreapNode<Chave, Valor> * root) {
   if (root == nullptr)
      return;

  printTable(root->getLeft());
  cout << root->getKey() << endl;
  printTable(root->getRight());
}