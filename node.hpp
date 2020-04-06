#ifndef _NODE_H
#define _NODE_H

template <class Key, class Value>
class Node {
   private: 
      Key key;
      Value value;
      Node<Key, Value> * next; 
   public: 
      Node();
      ~Node();
      Key getKey();
      Value getValue();
      Node<Key, Value> * getNext();
      void setKey(Key newKey);
      void setValue(Value i);
      void setNext(Node * newNode);
};

template <class Key, class Value>
Node<Key, Value>::Node() {
   key = "";
   value = 0;
}

template <class Key, class Value>
Node<Key, Value>::~Node() {
}

template <class Key, class Value>
Key Node<Key, Value>::getKey() {
   return key;
}

template <class Key, class Value>
Value Node<Key, Value>::getValue() {
   return value;
}

template <class Key, class Value>
void Node<Key, Value>::setKey(Key newKey) {
   key = newKey;
}

template <class Key, class Value>
void Node<Key, Value>::setValue(Value value) {
   this->value = value;
}

template <class Key, class Value>
void Node<Key, Value>::setNext(Node * newNode) {
   next = newNode;
}

template <class Key, class Value>
Node<Key, Value> * Node<Key, Value>::getNext() {
   return next;
}


#endif