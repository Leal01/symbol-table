#include "../util.hpp"

template <class Key, class Value>
class TreeNode23 {
   private:
      Key key1, key2;
      Value value1, value2;
      TreeNode23<Key, Value> * left;
      TreeNode23<Key, Value> * right;
      TreeNode23<Key, Value> * mid;
      bool twoNode;
   public:
      TreeNode23();
      ~TreeNode23();
      void setKey(Key newKey, int which);
      void setValue(Value newValue, int which);
      void setMid(TreeNode23<Key, Value> * newMid);
      void setLeft(TreeNode23<Key, Value> * newLeft);
      void setRight(TreeNode23<Key, Value> * newRight);
      void setTwoNode(bool option);
      Key getKey(int which);
      Value getValue(int which);
      TreeNode23<Key, Value> * getMid();
      TreeNode23<Key, Value> * getLeft();
      TreeNode23<Key, Value> * getRight();
      bool isLeaf();
      bool getTwoNode();


};

template <class Key, class Value>
TreeNode23<Key, Value>::TreeNode23() {
   key1 = key2 = "";
   value1 = value2 = 0;
   left = mid = right = nullptr;
}

template <class Key, class Value>
TreeNode23<Key, Value>::~TreeNode23() {
}

template <class Key, class Value>
Key TreeNode23<Key, Value>::getKey(int which) {
   if (which == 1)
      return key1;
   return key2;
}

template <class Key, class Value>
Value TreeNode23<Key, Value>::getValue(int which) {
   if (which == 1)
      return value1;
   return value2;
}

template <class Key, class Value>
void TreeNode23<Key, Value>::setKey(Key newKey, int which) {
   if (which == 1)
      key1 = newKey;
   if (which == 2)
      key2 = newKey;
}

template <class Key, class Value>
void TreeNode23<Key, Value>::setValue(Value newValue, int which) {
   if (which == 1)
      value1 = newValue;
   if (which == 2)
      value2 = newValue;
}


template <class Key, class Value>
void TreeNode23<Key, Value>::setMid(TreeNode23<Key, Value> * newMid) {
   mid = newMid;
}

template <class Key, class Value>
TreeNode23<Key, Value> * TreeNode23<Key, Value>::getMid() {
   return mid;
}

template <class Key, class Value>
void TreeNode23<Key, Value>::setLeft(TreeNode23<Key, Value> * newLeft) {
   left = newLeft;
}

template <class Key, class Value>
void TreeNode23<Key, Value>::setRight(TreeNode23<Key, Value> * newRight) {
   right = newRight;
}

template <class Key, class Value>
TreeNode23<Key, Value> * TreeNode23<Key, Value>::getLeft() {
   return left;
}

template <class Key, class Value>
TreeNode23<Key, Value> * TreeNode23<Key, Value>::getRight() {
   return right;
}

template <class Key, class Value>
void TreeNode23<Key, Value>::setTwoNode(bool option) {
   this->twoNode = option;
}

template <class Key, class Value>
bool TreeNode23<Key, Value>::getTwoNode() {
   return twoNode;
}

template <class Key, class Value>
bool TreeNode23<Key, Value>::isLeaf() {
   return (left == nullptr) && (mid == nullptr) && (right == nullptr);
}

class arvore23 {
   private:
      TreeNode23<Chave, Valor> * root;
      TreeNode23<Chave, Valor> * put(TreeNode23<Chave, Valor> * root, Chave key, Valor value, bool &grew);
      void printTable(TreeNode23<Chave, Valor> * root);

   public:
      arvore23(string file_name);
      ~arvore23();
      void insere(Chave key, Valor value);
      Valor devolve(Chave key);
      void remove(Chave key);
      int rank(Chave key);
      Chave seleciona(int k);
};

