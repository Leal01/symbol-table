#include "listaOrd.hpp"

listaOrd::listaOrd(string file_name) {
   fstream textFile;
   Chave word;
  
   first = nullptr;
   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);
   

   printTable();
   textFile.close();  

}

listaOrd::~listaOrd() {
   No aux = first;
   No aux2;
   
   while (aux != nullptr) {
      aux2 = aux->getNext();
      delete aux;
      aux = aux2;
   }
}

void listaOrd::insere(Chave key, Valor value) {
   No aux = first;
   No aux2;

   if (first == nullptr) {
      first = new Node<Chave, Valor>;
      first->setKey(key);
      first->setValue(1);
      return;
   }

   // Percorro a lista enquanto a chave é maior que as que já estão nela
   while (aux != nullptr && aux->getKey() < key) {
      aux2 = aux;
      aux = aux->getNext();
   }

   // Quando saio do loop tenho duas possibilidades, achei a chave, ou achei o lugar em que ela deve ser inserida
   if (aux != nullptr && aux->getKey() == key) {
      aux->setValue(aux->getValue() + 1);

      return;
   }
   
   // Ela deve ser então, inserida:
   // 3 casos: no fim => aux == nullptr
   //          no inicio => newNode->setNext(first) e first = newNode (aux == first)
   //          no meio => aux2->setNext(newNode) e newNode->setNext(aux)
   else {
      No nNode = new Node<Chave, Valor>;
      nNode->setKey(key);
      nNode->setValue(1);
      if (aux == nullptr) 
         aux2->setNext(nNode);
      
      else if (aux == first) {
         nNode->setNext(first);
         first = nNode;
      }
      else {
         aux2->setNext(nNode);
         nNode->setNext(aux);
      }
   }

}

Valor listaOrd::devolve(Chave key) {
   No aux = first;

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return aux->getValue();
      
      aux = aux->getNext();
   }
   if (aux == nullptr)
      cout << "Chave não encontrada!\n";
} 

void listaOrd::remove(Chave key) {
   No aux = first;
   No aux2;

   while (aux != nullptr) {
      if (aux->getKey() == key) {
         if (aux == first) {
            first = aux->getNext();
            delete aux;
         }
         else {
            if (aux->getNext() != nullptr)
               aux2 = aux->getNext();
            else
               aux2->setNext(nullptr);
            delete aux;
         }
      }
      aux2 = aux;
      aux = aux->getNext();
   }
}

int listaOrd::rank(Chave key) {
   No aux = first;
   int m = 1;

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return m;

      m++;
      aux = aux->getNext();
   }

   cout << "Chave não encontrada!\n";
}

Chave listaOrd::seleciona(int k) { // Não está funcionando, assim como outras coisas
   No aux = first;
   for (int i = 0; i < k; i++, aux = aux->getNext());
   
   return aux->getKey();
}

void listaOrd::printTable() {
   No aux = first;

   while (aux != nullptr) {
      cout << aux->getKey() << "     " << aux->getValue() << endl; 
      aux = aux->getNext();
   }
}