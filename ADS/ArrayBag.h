/* Header file for an array-based implementation of the ADT bag. */
#pragma once

template <typename ItemType>
class ArrayBag
{
	private:
		static const int DEFAULT_CAPACITY = 100; // Small size to test for a full bag
		ItemType items[DEFAULT_CAPACITY];        // Array of bag items
		int itemCount;                           // Current count of bag items
		int maxItems;                            // Max capacity of the bag
		int getIndexOf(const ItemType& target) const
		{
			bool found = false;
			int result = -1;
			int searchIndex = 0;
			// If the bag is empty, itemCount is zero, so loop is skipped
			while (!found && (searchIndex < itemCount))
			{
				if (items[searchIndex] == target)
				{
					found = true;
					result = searchIndex;
				}
				else
				{
					searchIndex++;
				} // end if
			} // end while
			return result;
		}
	public:
		ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY){}
		int getCurrentSize() const
		{
			return itemCount;
		}
		bool isEmpty() const
		{
			return (itemCount == 0);
		}
		bool add(const ItemType& newEntry)
		{
			bool hasRoomToAdd = (itemCount < maxItems);
			if (hasRoomToAdd)
			{
				items[itemCount] = newEntry;
				itemCount++;
			}
			return hasRoomToAdd;
		}
		bool remove(const ItemType& anEntry)
		{
			int locatedIndex = getIndexOf(anEntry);
			bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
			if (canRemoveItem)
			{
				itemCount--;
				items[locatedIndex] = items[itemCount];
			}
			return canRemoveItem;
		}
		bool pop(ItemType& anEntry)
		{
			if (isEmpty()) return false;
			else
			{
                anEntry = items[itemCount - 1];
				//items[0] = items[itemCount-1];
			    itemCount--;
			    return true;
			}
			
		}
		void clear()
		{
			itemCount = 0;
		}
		bool contains(const ItemType& anEntry) const
		{
			bool found = false;
			int curIndex = 0; // Current array index
			while (!found && (curIndex < itemCount))
			{
				if (anEntry == items[curIndex])
				{
					found = true;
				}
				curIndex++; // Increment to next entry
			}
			return found;
		}
		int getFrequencyOf(const ItemType& anEntry) const
		{
			int frequency = 0;
			int curIndex = 0; // Current array index
			while (curIndex < itemCount)
			{
				if (items[curIndex] == anEntry)
				{
					frequency++;
				}
				curIndex++; // Increment to next entry
			}
			return frequency;
		}
		void print() {
			ArrayBag<ItemType> temp = *this; 
			ItemType tempnode;
			cout << "[";
			while (!temp.isEmpty()) {
				temp.pop(tempnode);
				if (temp.isEmpty()) {
					cout << *tempnode << "]" << endl;
					return;
				}
				else
					cout << *tempnode << ", ";
			}
			cout << "] ";
		}
};