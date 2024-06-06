#pragma once
#include "priNode.h"
#include"../ArmyUnits/Earth/EarthSoldier.h"
#include"../ArmyUnits/Earth/EarthTank.h"

//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
    bool enqueue(const T data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);
        if (isEmpty() || priority > head->getPri()) 
        {
            newNode->setNext(head);
            head = newNode;
            return true;
        }
       
        priNode<T>* current = head;     
        while (current->getNext() && priority <= current->getNext()->getPri()) 
        {
            current = current->getNext();
        }
        newNode->setNext( current->getNext() );
        current->setNext( newNode );
        return true;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
       
        
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    bool enqueue_UML(const T data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);
        if (isEmpty() || (priority < head->getPri() && typeid(newNode)==typeid(EarthSoldier*)))
        {
            newNode->setNext(head);
            head = newNode;
            return true;
        }

        priNode<T>* current = head;
        if (typeid(newNode)==typeid(EarthSoldier*))
        {
            while (current->getNext() && priority >= current->getNext()->getPri() && typeid(current->getNext())==typeid(EarthSoldier*))
            {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            return true;
        }
        else if (typeid(newNode) == typeid(EarthTank*))
        {
            while (current->getNext())
            {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            return true;
        }
    }
    void print() {
        priQueue<T> temp;
        T tempnode;
        int trash = 0;
        cout << "[";
        while (!this->isEmpty()) {
            this->dequeue(tempnode, trash);
            temp.enqueue(tempnode, trash);
            if (this->isEmpty())
            {
                cout << *tempnode << "]" << endl;
                while (!temp.isEmpty()) {
                    temp.dequeue(tempnode, trash);
                    this->enqueue(tempnode, trash);
                }
                return;
            }
            else
                cout << *tempnode << ", ";
        }
        cout << "]" << endl;
    }
};