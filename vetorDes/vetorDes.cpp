#include "vetorDes.hpp"


vetorDes::vetorDes(string file_name) {
   fstream textFile;
   Chave word;

   table = new Node<Chave, Valor> * [10];
   size = 10;
   n = 0;
   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);

   printTable();
   textFile.close();  
}

vetorDes::~vetorDes() {
   for (int i = 0; i < n; i++)
      delete table[i];

   delete [] table;
}

void vetorDes::insere(Chave key, Valor value) {
   if (size == n) 
      resize();

   for (int i = 0; i < n; i++) {
      if (table[i] != nullptr) {
         Chave x = table[i]->getKey();

         if (key == x) {
            table[i]->setValue(table[i]->getValue() + 1);
            return;
         }
      }
   }

   table[n] = new Node<Chave, Valor>;
   table[n]->setKey(key);
   table[n++]->setValue(1);
}

Valor vetorDes::devolve(Chave key) {
   for (int i = 0; i < n; i++)
      if (table[i]->getKey() == key)
         return table[i]->getValue();

   return 0;
}

void vetorDes::remove(Chave key) {
   int i = 0;
   for (; table[i]->getKey() != key && i < n; i++);
      
   if (table[i]->getKey() == key) {
      // Remove e traz todo mundo pra tras
      table[i]->setKey("");
      table[i]->setValue(0);
      for (; i + 1 < n; i++) {
         table[i]->setKey(table[i+1]->getKey());
         table[i]->setValue(table[i+1]->getValue());
      }
      table[i+1]->setKey("");
      table[i+1]->setValue(0);
   }

   else {
      cout << "Chave não encontrada\n";
   }
}

int vetorDes::rank(Chave key) {
   int i, m;
   i = 0;
   m = 1;

   for (; table[i]->getKey() != key && i < n; i++) 
      m++;

   if (table[i]->getKey() == key)
      return m;
   else
      cout << "Chave não encontrada\n";

   return -1;
}

Chave vetorDes::seleciona(int k) {
   if (k < n)
      return table[k]->getKey();

}

void vetorDes::printTable() {
   for (int i = 0; i < n; i++)
      cout << table[i]->getKey() << "     "<< table[i]->getValue() << "\n"; 
}

void vetorDes::resize() {
   Node<Chave, Valor> ** newTable;
   newTable = new Node<Chave, Valor> * [size + 10];
   size = size + 10;

   for (int i = 0; i < n; i++) {
      newTable[i] = table[i];
      table[i] = nullptr;
   }

   delete [] table;
   table = newTable;
}