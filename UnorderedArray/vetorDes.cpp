#include "vetorDes.hpp"
#include <fstream>

vetorDes::vetorDes(string file_name) {
   fstream textFile;
   Chave word;

   table = nullptr;
   table = new Node[10];
   size = 10;
   n = 0;
   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);

   printTable();
   textFile.close();  
}

vetorDes::~vetorDes() {
   delete [] table;
}

void vetorDes::insere(Chave key, Valor value) {
   if (size == n) {
      table = new Node[size + 10];
      size = size + 10;
   }

   for (int i = 0; table[i]->getKey() != ""; i++) 
      if (table[i]->getKey() == word)
         table[i]->setValue(0);
      
      
   if (table[i]->getKey() == "") {
         table[i]->setValue(0);
         table[i]->setKey(key);
         n++;
   }
}

Valor vetorDes::devolve(Chave key) {
   for (int i = 0; i < n; i++)
      if (table[i]->getKey() == key)
         return table[i]->getValue();
}

void vetorDes::remove(Chave key) {
   int i = 0;
   for (; table[i]->getKey() != key && i < n; i++) 
      
   if (table[i]->getKey() == key) {
      // Remove e traz todo mundo pra tras
      table[i]->setKey = "";
      table[i]->setValue(-1);
      for (; i + 1 < n; i++) {
         table[i]->setKey(table[i+1]->getKey());
         table[i]->setValue(table[i+1]->getValue());
      }
      table[i+1]->setKey("");
      table[i+1]->setValue(-1);
   }

   else {
      cout << "Chave não encontrada\n";
   }
}

int vetorDes::rank(Chave key) {
   int i = m = 0;
   for (i; table[i]->getKey() != key && i < n; i++) 
      m++;

   if (table[i]->getKey() == key)
      return m;
   else
      cout << "Chave não encontrada\n";
}

// Chave vetorDes::seleciona() {

// }

void vetorDes::printTable() {
   for (int i = 0; i < n; i++)
      cout << table[i]->getKey() << table[i]->getValue() << "\n"; 
}