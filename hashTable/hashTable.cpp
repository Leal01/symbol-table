#include "hashTable.hpp"

hashTable::hashTable(string file_name) {
   fstream textFile;
   Chave word;

   table = new Node<Chave, Valor>*[8191];
   for (int i = 0; i < 8191; i++)
      table[i] = nullptr;

   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);

   printTable();
   textFile.close();  
}

hashTable::~hashTable() {
   for (int i = 0; i < 8191; i++) {
      No aux = table[i];

      while (aux != nullptr) {
         No aux2 = aux;
         aux = aux->getNext();
         delete aux2;
      }
   }
}

void hashTable::insere(Chave key, Valor value) {
   int h = hash(key);
   No aux = table[h];

   while (aux != nullptr && aux->getKey() != key)
      aux = aux->getNext();

   if (aux == nullptr) {
      No newNode = new Node<Chave, Valor>;
      newNode->setKey(key);
      newNode->setValue(value);
      newNode->setNext(table[h]);
      table[h] = newNode;
   }

   else {
      aux->setValue(aux->getValue() + 1);
   }
}

int hashTable::hash(Chave key) {
   int keyLength = key.length();
   int hashValue = 0;

   for (int i = 0; i < keyLength; i++) 
      hashValue = (hashValue * 23 + key[i]) % 8191;
   

   return hashValue;
}

Valor hashTable::devolve(Chave key) {
   int h = hash(key);
   No aux = table[h];

   while (aux != nullptr) {
      if (aux->getKey() == key)
         return aux->getValue();

      aux = aux->getNext();
   }

   cout << "Chave não encontrada\n";
   return -1;
}

void hashTable::remove(Chave key) {
   int h = hash(key);
   No aux = table[h];
   No aux2 = nullptr;

   while (aux != nullptr) {
      if (aux->getKey() == key) {
         if (aux2 == nullptr)
            table[h] = aux->getNext();
         else
            aux2->setNext(aux->getNext());
         delete aux;
         break;
      }
      aux2 = aux;
      aux = aux->getNext();
   }

   printTable();
}

int hashTable::rank(Chave key) {
   int rank = 0;

   for (int i = 0; i < 8191; i++) {
      No aux = table[i];
      
      while (aux != nullptr && aux->getKey() != key) {
         if (aux->getKey() < key)
            rank++;
         aux = aux->getNext();
      }
   }

   return rank;
}

Chave hashTable::seleciona(int k) {
   for (int i = 0; i < 8191; i++) {
      No aux = table[i];
      while (aux != nullptr) {
         if (rank(aux->getKey()) == k)
            return aux->getKey();
         aux = aux->getNext();
      }
   }
   cout << "Rank indisponível\n";   

}

void hashTable::printTable() {
   Node<Chave, Valor> ** aux = table;
   for (int i = 0; i < 8191; i++) {
      if (aux[i] != nullptr) {
         cout << aux[i]->getKey() << endl;
         Node<Chave, Valor> * aux2 = aux[i]->getNext();
         while (aux2 != nullptr) {
            cout << aux2->getKey() << endl;
            aux2 = aux2->getNext();
         }
      }
   }
}


