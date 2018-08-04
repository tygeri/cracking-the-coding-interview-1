//
// Created by Alex Hagiopol on 8/21/17.
//
#pragma once
#include <vector>

namespace chapter_02{
    template <typename T>
    class Node{
    protected:
        T _value;
    public:
        Node(T value) : _value(value) {}  // constructor
        Node(const Node& other) : _value(other.getValue()) {}  // copy constructor
        ~Node(){}  // destructor
        bool operator== (const Node& other) {return _value == other.getValue();}  // equality check
        T getValue() const {return _value;}
        void setValue(const T& value) {_value = value;}
    };

    template <typename T>
    class SinglyLinkedNode : public Node<T>{
    private:
        SinglyLinkedNode* _next;
    public:
        SinglyLinkedNode(T value, SinglyLinkedNode* next = nullptr) : Node<T>(value), _next(next) {}  // constructor
        SinglyLinkedNode(const SinglyLinkedNode& other) : Node<T>::_value(other.getValue()), _next(other.getNext()){}  // copy constructor
        ~SinglyLinkedNode(){   // destructor
            _next = nullptr;
        }
        SinglyLinkedNode* getNext() const {return _next;}
        void setNext(SinglyLinkedNode* next) {_next = next;}
    };  // class SinglyLinkedNode

    template <typename T>
    class GraphNode : Node<T>{
    private:
        std::vector<GraphNode*> _children;
    public:
        GraphNode(T value) : Node<T>(value) {}
        void addChild(GraphNode* child) {_children.push_back(child);}
        void removeChild(GraphNode* child, int index) {
            if (index >= _children.size() || index < 0) return;
            _children[index] = child;
        }
    };

    template <typename T>
    SinglyLinkedNode<T>* vectorToList(const std::vector<T> numbers){
        if(numbers.size() <= 0){
            return nullptr;
        }
        SinglyLinkedNode<T>* head = new SinglyLinkedNode<T>(numbers[0]);
        SinglyLinkedNode<T>* runner = head;
        for (int i = 1; i < numbers.size(); i++ ){
            SinglyLinkedNode<T>* temp = new SinglyLinkedNode<T>(numbers[i]);
            runner->setNext(temp);
            runner = runner->getNext();
        }
        return head;
    }

    template <typename T>
    std::vector<T> listToVector(SinglyLinkedNode<T>* head){
        std::vector<T> vector;
        SinglyLinkedNode<T>* runner = head;
        while (runner != nullptr){
            vector.push_back(runner->getValue());
            runner = runner->getNext();
        }
        return vector;
    }
};  // namespace chapter_02
