#include "util.hpp"
#include <iostream>

using namespace std;

class Node {
   private:
      Chave key;
      Valor value;
   public: 
      Node();
      ~Node();
      Chave getKey();
      Valor getValue();
      void setKey(Chave newKey);
      void setValue(int i);
};

Node::Node() {
   key = "";
   value = 0;
};

Node::~Node() {
};

Chave Node::getKey() {
   return key;
}

Valor Node::getValue() {
   return value;
}

void Node::setKey(Chave newKey) {
   key = newKey;
}

void Node::setValue(int i) {
   if (i == 0)
      value++;
   else if (i == - 1)
      value = 0;
   else
      value = i;
}

