#include "listaDes.hpp"

listaDes::listaDes(string file_name) {
   fstream textFile;
   Chave word;
  
   first = nullptr;
   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);
   

   printTable();
   textFile.close();  

}
listaDes::~listaDes() {
   No aux = first;
   No aux2;
   
   while (aux != nullptr) {
      aux2 = aux->getNext();
      delete aux;
      aux = aux2;
   }
}

void listaDes::insere(Chave key, Valor value) {  
   No aux = first;
   No aux2;


   while (aux != nullptr) {
      if (aux->getKey() == key) {
         aux->setValue(aux->getValue() + 1);
         return;
      }
      aux2 = aux;
      aux = aux->getNext();
   }

   aux = new Node<Chave, Valor>;
   aux->setKey(key);
   aux->setValue(1);

   if (first == nullptr)
      first = aux;
   else
      aux2->setNext(aux);

}

Valor listaDes::devolve(Chave key) {
   No aux = first;

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return aux->getValue();
      
      aux = aux->getNext();
   }
   if (aux == nullptr)
      cout << "Chave não encontrada!\n";
} 
void listaDes::remove(Chave key) {
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

   printTable();
}

int listaDes::rank(Chave key) {
   No aux = first;
   int r = 0;

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return r;

      r++;
      aux = aux->getNext();
   }

   cout << "Chave não encontrada!\n";
}

Chave listaDes::seleciona(int k) { 
   No aux = first;
   for (int i = 0; i < k; i++, aux = aux->getNext());
   
   return aux->getKey();
}

void listaDes::printTable() {
   No aux = first;

   while (aux != nullptr) {
      cout << aux->getKey() << "     " << aux->getValue() << endl; 
      aux = aux->getNext();
   }
}