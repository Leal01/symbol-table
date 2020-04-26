#include "../util.hpp"

template <class Key, class Value>
class TreapNode {
   private:
      Key key;
      Value value;
      int priority;
      TreapNode<Key, Value> * left;
      TreapNode<Key, Value> * right;
   
   public:
      TreapNode();
      ~TreapNode();
      void setKey(Key newKey);
      void setValue(Value newValue);
      void setPriority(int n);
      int getPriority();
      Key getKey();
      Value getValue();
      void setLeft(TreapNode<Key, Value> * newLeft);
      void setRight(TreapNode<Key, Value> * newRight);
      TreapNode<Key, Value> * getLeft();
      TreapNode<Key, Value> * getRight();
};

template <class Key, class Value>
TreapNode<Key, Value>::TreapNode() {
   key = "";
   value = 0;
   left = nullptr;
   right = nullptr;
}

template <class Key, class Value>
TreapNode<Key, Value>::~TreapNode() {
}

template <class Key, class Value>
Key TreapNode<Key, Value>::getKey() {
   return key;
}

template <class Key, class Value>
Value TreapNode<Key, Value>::getValue() {
   return value;
}

template <class Key, class Value>
void TreapNode<Key, Value>::setPriority(int n) {
   priority = n;
}

template <class Key, class Value>
int TreapNode<Key, Value>::getPriority() {
   return priority;
}

template <class Key, class Value>
void TreapNode<Key, Value>::setKey(Key newKey) {
   key = newKey;
}

template <class Key, class Value>
void TreapNode<Key, Value>::setValue(Value newValue) {
   value = newValue;
}

template <class Key, class Value>
void TreapNode<Key, Value>::setLeft(TreapNode<Key, Value> * newLeft) {
   left = newLeft;
}

template <class Key, class Value>
void TreapNode<Key, Value>::setRight(TreapNode<Key, Value> * newRight) {
   right = newRight;
}

template <class Key, class Value>
TreapNode<Key, Value> * TreapNode<Key, Value>::getLeft() {
   return left;
}

template <class Key, class Value>
TreapNode<Key, Value> * TreapNode<Key, Value>::getRight() {
   return right;
}

class treap {
   private:
      TreapNode<Chave, Valor> * root;
      TreapNode<Chave, Valor> * put(TreapNode<Chave, Valor> * root, Chave key, Valor value);
      Valor get(TreapNode<Chave, Valor> * root, Chave key);
      int getRank(TreapNode<Chave, Valor> * root, Chave key);
      void deleteSt(TreapNode<Chave, Valor> * root);
      TreapNode<Chave, Valor> * newNode(Chave key, Valor value);
      TreapNode<Chave, Valor> * rotateLeft(TreapNode<Chave, Valor> * root);
      TreapNode<Chave, Valor> * rotateRight(TreapNode<Chave, Valor> * root);
      TreapNode<Chave, Valor> * destroy(TreapNode<Chave, Valor> * root, Chave key);
      int size(TreapNode<Chave, Valor> * root);
      Chave select(TreapNode<Chave, Valor> * root, int k);
      void printTable(TreapNode<Chave, Valor> * root);

   public:
      treap(string file_name);
      ~treap();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};

