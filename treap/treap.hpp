#include "../util.hpp"

template <class Key, class Value>
class TreeNode {
   private:
      Key key;
      Value value;
      TreeNode<Key, Value> * left;
      TreeNode<Key, Value> * right;
   
   public:
      TreeNode();
      ~TreeNode();
      void setKey(Key newKey);
      void setValue(Value newValue);
      Key getKey();
      Value getValue();
      void setLeft(TreeNode<Key, Value> * newLeft);
      void setRight(TreeNode<Key, Value> * newRight);
      TreeNode<Key, Value> * getLeft();
      TreeNode<Key, Value> * getRight();
};

template <class Key, class Value>
TreeNode<Key, Value>::TreeNode() {
   key = "";
   value = 0;
   left = nullptr;
   right = nullptr;
}

template <class Key, class Value>
TreeNode<Key, Value>::~TreeNode() {
}

template <class Key, class Value>
Key TreeNode<Key, Value>::getKey() {
   return key;
}

template <class Key, class Value>
Value TreeNode<Key, Value>::getValue() {
   return value;
}

template <class Key, class Value>
void TreeNode<Key, Value>::setKey(Key newKey) {
   key = newKey;
}

template <class Key, class Value>
void TreeNode<Key, Value>::setValue(Value newValue) {
   value = newValue;
}

template <class Key, class Value>
void TreeNode<Key, Value>::setLeft(TreeNode<Key, Value> * newLeft) {
   left = newLeft;
}

template <class Key, class Value>
void TreeNode<Key, Value>::setRight(TreeNode<Key, Value> * newRight) {
   right = newRight;
}

template <class Key, class Value>
TreeNode<Key, Value> * TreeNode<Key, Value>::getLeft() {
   return left;
}

template <class Key, class Value>
TreeNode<Key, Value> * TreeNode<Key, Value>::getRight() {
   return right;
}

class arvoreBin {
   private:
      TreeNode<Chave, Valor> * root;
      TreeNode<Chave, Valor> * put(TreeNode<Chave, Valor> * root, Chave key, Valor value);
      Valor get(TreeNode<Chave, Valor> * root, Chave key);
      int getRank(TreeNode<Chave, Valor> * root, Chave key);
      void printTable(TreeNode<Chave, Valor> * root);

   public:
      arvoreBin(string file_name);
      ~arvoreBin();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};

