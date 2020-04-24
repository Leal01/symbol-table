#include "hashTable.hpp"

hashTable::hashTable(string file_name) {
   fstream textFile;
   Chave word;

   table = new Node<Chave, Valor>*[9106];
   for (int i = 0; i < 9106; i++)
      table[i] = nullptr;

   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);

   printTable();
   textFile.close();  
}

hashTable::~hashTable() {
   for (int i = 0; i < 9106; i++)
      delete table[i];

   delete [] table;
}

void hashTable::insere(Chave key, Valor value) {
   int h = hash(key);
   Node<Chave, Valor> * aux, * aux2;
   aux = table[h];

   while (aux != nullptr &&  aux->getKey() != key)
      aux = aux->getNext(); 

   if (aux == nullptr) {
      aux = new Node<Chave, Valor>;
      aux->setKey(key);
      aux->setValue(value);
      aux->setNext(table[h]);
      table[h] = aux;
   }

   else {
      aux->setValue(aux->getValue() + 1);
   }
}

int hashTable::hash(Chave key) {
   int len = key.length();
   int hashValue = 0;

   for (int i = 0; i < len; i++) 
      hashValue = (hashValue*23+key[i]) % 9106;
   

   return hashValue;
}

Valor hashTable::devolve(Chave key) {
   int h = hash(key);

   while (table[h] != nullptr && table[h]->getKey() != key) 
      table[h] = table[h]->getNext();
   

   if (table[h] != nullptr)
      return table[h]->getValue();

   else {
      cout << "Chave não encontrada\n";
      return -1;
   }
      

}

void hashTable::remove(Chave key) {
   int h = hash(key);

   while (table[h] != nullptr) {
      Node<Chave, Valor> * aux = table[h];
      if (table[h]->getKey() == key) {
         table[h] = table[h]->getNext();
         return;
      }
      table[h] = table[h]->getNext();
   
   }

   printTable();
}

int hashTable::rank(Chave key) {
   int h = hash(key);

   return h;
}

Chave hashTable::seleciona(int k) {

}

void hashTable::printTable() {
   Node<Chave, Valor> ** aux = table;
   for (int i = 0; i < 9106; i++) {
      if (aux[i] != nullptr) {
         cout << aux[i]->getKey() << "     " << aux[i]->getValue() << "\n";
         Node<Chave, Valor> * aux2 = aux[i]->getNext();
         while (aux2 != nullptr) {
            cout << "COLISÃO:   ";
            cout << aux2->getKey() << "     " << aux2->getValue() << "\n";
            aux2 = aux2->getNext();
         }
      }
   }
}


