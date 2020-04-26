#include "../util.hpp"

template <class Key, class Value>
class TreeNodeRN {
   private:
      Key key;
      Value value;
      string color;
      TreeNodeRN<Key, Value> * left;
      TreeNodeRN<Key, Value> * right;
      TreeNodeRN<Key, Value> * father;
   public:
      TreeNodeRN();
      ~TreeNodeRN();
      void setKey(Key newKey);
      void setValue(Value newValue);
      void setFather(TreeNodeRN<Key, Value> * node);
      void setLeft(TreeNodeRN<Key, Value> * newLeft);
      void setRight(TreeNodeRN<Key, Value> * newRight);
      void setColor(string color);
      Key getKey();
      Value getValue();
      TreeNodeRN<Key, Value> * getFather();
      TreeNodeRN<Key, Value> * getLeft();
      TreeNodeRN<Key, Value> * getRight();
      string getColor();

};

template <class Key, class Value>
TreeNodeRN<Key, Value>::TreeNodeRN() {
   key = "";
   value = 0;
   left = nullptr;
   right = nullptr;
   father = nullptr;
}

template <class Key, class Value>
TreeNodeRN<Key, Value>::~TreeNodeRN() {
}

template <class Key, class Value>
Key TreeNodeRN<Key, Value>::getKey() {
   return key;
}

template <class Key, class Value>
Value TreeNodeRN<Key, Value>::getValue() {
   return value;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setKey(Key newKey) {
   key = newKey;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setValue(Value newValue) {
   value = newValue;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setColor(string color) {
   this->color = color;
}

template <class Key, class Value>
string TreeNodeRN<Key, Value>::getColor() {
   return color;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setFather(TreeNodeRN<Key, Value> * node) {
   father = node;
}

template <class Key, class Value>
TreeNodeRN<Key, Value> * TreeNodeRN<Key, Value>::getFather() {
   return father;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setLeft(TreeNodeRN<Key, Value> * newLeft) {
   left = newLeft;
}

template <class Key, class Value>
void TreeNodeRN<Key, Value>::setRight(TreeNodeRN<Key, Value> * newRight) {
   right = newRight;
}

template <class Key, class Value>
TreeNodeRN<Key, Value> * TreeNodeRN<Key, Value>::getLeft() {
   return left;
}

template <class Key, class Value>
TreeNodeRN<Key, Value> * TreeNodeRN<Key, Value>::getRight() {
   return right;
}

class arvoreRN {
   private:
      TreeNodeRN<Chave, Valor> * root;
      TreeNodeRN<Chave, Valor> * put(TreeNodeRN<Chave, Valor> * root, Chave key, Valor value);
      Valor get(TreeNodeRN<Chave, Valor> * root, Chave key);
      TreeNodeRN<Chave, Valor> * destroy(TreeNodeRN<Chave, Valor> * root, Chave key);
      TreeNodeRN<Chave, Valor> * max(TreeNodeRN<Chave, Valor> * root);
      TreeNodeRN<Chave, Valor> * min(TreeNodeRN<Chave, Valor> * root);
      void deleteTree(TreeNodeRN<Chave, Valor> * root);
      int getRank(TreeNodeRN<Chave, Valor> * root, Chave key);
      int size(TreeNodeRN<Chave, Valor> * root);
      Chave select(TreeNodeRN<Chave, Valor> * root, int k);
      void printTable(TreeNodeRN<Chave, Valor> * root);

   public:
      arvoreRN(string file_name);
      ~arvoreRN();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};

