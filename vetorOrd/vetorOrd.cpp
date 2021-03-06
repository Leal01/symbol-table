#include "vetorOrd.hpp"


vetorOrd::vetorOrd(string file_name) {
   fstream textFile;
   Chave word;

   table = new Node<Chave, Valor>*[10];
   size = 10;
   n = 0;
   textFile.open(file_name);

   while (textFile >> word) 
      insere(word, 1);

   printTable();
   textFile.close();  
}

vetorOrd::~vetorOrd() {
   for (int i = 0; i < n; i++)
      delete table[i];

   delete [] table;
}

void vetorOrd::insere(Chave key, Valor value) {
   int r;
   r = binarySearch(key);

   if (size == n + 1) 
      resize();

   if (table[r] != nullptr && table[r]->getKey() == key) 
      table[r]->setValue(table[r]->getValue() + 1);

   else {
      for (int i = n; i > r; i--) 
         table[i] = table[i - 1];
      
      table[r] = new Node<Chave, Valor>;
      table[r]->setKey(key);
      table[r]->setValue(1);
      n++;
   }
}

int vetorOrd::binarySearch(Chave key) {
   int ini, mid, end;
   ini = mid = 0;
   end = n - 1;
  

   while (ini <= end) {
      mid = (ini + end)/2;

      if (table[mid]->getKey() == key)
         return mid;
      else if (table[mid]->getKey() > key) 
         end = mid - 1;
      else
         ini = mid + 1;
   }

   return ini;
}

Valor vetorOrd::devolve(Chave key) {
   int r = binarySearch(key);

   if ( r >= 0 && table[r]->getKey() == key)
      return table[r]->getValue();
      
   else
      return 0;

}

void vetorOrd::remove(Chave key) {
   int i;
   int r = binarySearch(key);

   for (i = r; i + 1 < n; i++) {

      table[i]->setKey(table[i + 1]->getKey());
      table[i]->setValue(table[i + 1]->getValue());
   }

   n--;
   printTable();
}

int vetorOrd::rank(Chave key) {
   int r = binarySearch(key);
   return r;
}

Chave vetorOrd::seleciona(int k) {
   if (k < n)
      return table[k]->getKey();
   else 
      cout << "Rank indisponível\n";
}

void vetorOrd::printTable() {
   for (int i = 0; i < n; i++)
      cout << table[i]->getKey() << endl; 
}

void vetorOrd::resize() {
   Node<Chave, Valor> ** newTable = new Node<Chave, Valor>*[size + 10];
   size = size + 10;

   for (int i = 0; i < n; i++) {
      newTable[i] = table[i];
      table[i] = nullptr;
   }

   delete [] table;
   table = newTable;
}