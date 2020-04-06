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
            aux = nullptr;
         }
         else {
            aux2 = aux->getNext();
            delete aux;
            aux = nullptr;
         }
      }
      aux2 = aux;
      aux = aux->getNext();
   }

   if (aux == nullptr)
      cout << "Chave não encotrada!\n";
}

int listaDes::rank(Chave key) {
   No aux = first;
   int m = 0;

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return m;

      m++;
      aux = aux->getNext();
   }
}

Chave listaDes::seleciona(int k) {
   No aux = first;
   int i = 0;
   while (aux != nullptr && i < k) {
      if (aux->getKey() == key)
         return aux->getKey();
         
      i++;
      aux = aux->getNext();
   }
}

void listaDes::printTable() {
   No aux = first;

   while (aux != nullptr) {
      cout << aux->getKey() << "     " << aux->getValue() << endl; 
      aux = aux->getNext();
   }
}