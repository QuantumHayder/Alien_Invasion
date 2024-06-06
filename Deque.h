/*This is a program that implements the double-ended queue (Deque) using Array implementation.
The Deque is implemented such that you can add to the end of the queue and remove from both/ ends of it,
where Front of deque is at index [0] & Rear of deque is at index [rearInd]. In case array is full rearInd = MAX_SIZE - 1
*/

#pragma once
#include "QueueADT.h"
#include <iostream>
using namespace std;

template <typename T>
class Deque :public QueueADT<T>
{
	private:
		T items[100];   //array which holds items
		int rearInd;         //holds index of last element (in array) which is at rear of queue
		                     //in case array is full it holds index [MAX_SIZE - 1]

	public:

		Deque() { rearInd = -1; } //default constructor
		/* In constructor, I intialized rearInd with -1 which is one less than 0 which is index of first element in array so that
		 when adding a first element to queue rearInd will be zero which is index of first element.
		 Using this as a condition when enqueuing or dequeuing ensures that rearInd will always hold a valid index within array. */

		bool isEmpty() const { return (rearInd == -1); }

		/* This function enqueues an item to  
		 the rear of the queue in array */
		bool enqueue(const T& newEntry)
		{
			if (rearInd==100-1) 
				return false;
			else
			{
				items[rearInd+1] = newEntry;
				rearInd++;
				return true;
			}
		}

		/* This function dequeues first item in array
		 (at front of queue) which is at index [0] */
		bool dequeue(T& EntryZero)
		{
			if (rearInd==-1) return false;
			else
			{
				EntryZero = items[0];
				for (int i = 0; i < rearInd + 1; i++)
				{
					items[i] = items[i + 1];
				}
				rearInd--;
				return true;
			}
		}

		/* This function dequeues last item in array
		 (at rear of queue) which is at index [rearInd] */
		bool dequeueRear(T& EntryLast)
		{
			if (rearInd==-1) return false;
			else
			{
				EntryLast = items[rearInd];
				rearInd--;
				return true;
			}
		}
		
		/* This function returns first item in array
		 (at front of queue) which is at index [0] */
		bool peek(T& EntryZero) const
		{
			if (rearInd==-1) return false;
			else
			{
				EntryZero = items[0];
				return true;
			}
		}

		/* This function returns last item in array 
		 (at rear of queue) which is at index [rearInd] */
		bool peekRear(T& EntryLast) const
		{
			if (rearInd==-1) return false;
			else
			{
				EntryLast = items[rearInd];
				return true;
			}
		}

		void print() {
			Deque<T> temp=*this;
			T tempnode;
			cout << "[";
			while (!temp.isEmpty()) {
				temp.dequeue(tempnode);
				if (temp.isEmpty()) {
					cout << *tempnode << "]" << endl;
					return;
				}
				else
					cout << *tempnode << ", ";
			}
			cout << "] ";
		}

		~Deque() {}
}; //end of Deque