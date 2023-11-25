/**
 * List.tpp
 * Purpose: Implementation of the list methods defined in List.hpp
 * Author: C. Cooper
 * Date Created: 2023-11-22
*/

#include "List.hpp"
#include <stdexcept>
#include <iostream>

/**
 * Creates an empty list.
*/
template <typename T>
List<T>::List()
{
    root = nullptr;//Sets the root to a null pointer
}

/**
 * Appends the given item to the list.
 * @param item The item to append.
*/
template <typename T>
void List<T>::append(T* item)
{
    if(root == nullptr)//If the list is empty,
    {
        root = new Node(item);//Makes a new node contining the given item and sets it as the root.
        return;
    }
    //If there is a root,

    /*
        Incremments current until it is the last node in the list.
    */
    Node* current = root;//Sets current to the root
    while(current->hasNext())//While current has a node after it,
    {
        current = current->getNext();//Sets current to the node after it.
    }
    current->setNext(new Node(item));//Sets current's next node to a new node containing the given item.
}

/**
 * Pops the last item from the list.
 * @returns The popped item.
 * @throws runtime_error if the list is empty.
*/
template <typename T>
T* List<T>::pop()
{
    if(root == nullptr)//If the list is empty,
    {
        throw std::runtime_error("Trying to pop from empty list!");
    }

    if(!root->hasNext())//If the root is the only node in the list,
    {
        T* value = root->getValue();//Store root's value.
        delete root;//Deletes the root from memory
        root = nullptr;//Clears the root field
        return value;
    }

    /*
        Iterates through the list until current is the last node and last the second-to-last.
    */
    Node* last = root;//The node that precedes current
    Node* current = root->getNext();//Sets current to the second node in the list
    while(current->hasNext())//While current isn't the last node in the list,
    {
        last = current;//Moves last forward
        current = current->getNext();//Moves current forward
    }

    T* value = current->getValue();//Stores current's value so we can return it later
    delete current;//Deletes current from memory (we're about to remove the only referenc to it)
    last->setNext(nullptr);//Sets last's next node to a nullptr (it was perviously current)
    return value;//Returns the value of current that we stored earlier.
}

/**
 * Gets the item in the list at the given index.
 * @param index The index to get from.
 * @returns The item in the list at the given index.
 * @throws out_of_range if the index < 0 or >= the length of the list.
*/
template <typename T>
T* List<T>::get(int index)
{
    if(index < 0)//If the index is negative,
    {
        throw std::out_of_range("List index must be positive!");
    }

    /*
        Iterates through the list until the current index is the given index.
    */
    int currentIndex = 0;//The index of the node stored in current
    Node* current = root;//The current node
    while(currentIndex < index)//While we aren't at the index we're looking for yet,
    {
        if(!current->hasNext())//If the current node doesn't have a next node (but the given index is after the current index),
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length " + std::to_string(currentIndex+1) + "!");
        }
        current = current->getNext();//Moves current forward
        currentIndex++;//Increments currentIndex so it matches current.
    }
    //Once currentIndex == the given index,
    return current->getValue();//Return the value of the current node.
}

/**
 * Sets the item at the given index in the list to the given value.
 * @param index The index of the item to set.
 * @param value The value to set the index to.
 * @throws out_of_range if the index < 0 or >= the length of the list. 
*/
template <typename T>
void List<T>::set(int index, T* value)
{
    if(index < 0)//If the index is negative,
    {
        throw std::out_of_range("List index must be positive!");
    }

   /*
        Iterates through the list until the current index is the given index.
    */
    int currentIndex = 0;//The index of the node stored in current
    Node* current = root;//The current node
    while(currentIndex < index)//While we aren't at the index we're looking for yet,
    {
        if(!current->hasNext())//If the current node doesn't have a next node (but the given index is after the current index),
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length " + std::to_string(currentIndex+1) + "!");
        }
        current = current->getNext();//Moves current forward
        currentIndex++;//Increments currentIndex so it matches current.
    }
    //Once currentIndex == the given index,
    current->setValue(value);//Sets the value of the current node to the given value.
}

/**
 * Removes the item in the list at the given index.
 * @param index Index to remove.
 * @throws out_of_range if the index < 0 or >= the length of the list. 
 * @throws runtime_error If the list is empty.
*/
template <typename T>
void List<T>::remove(int index)
{
    if(index < 0)//If the given index is negative,
    {
        throw std::out_of_range("List index must be positive!");
    }

    if(root == nullptr)//If the list is empty,
    {
        throw std::runtime_error("Trying to remove from empty list!");
    }

    if(!root->hasNext())//If the root is the only item in the list,
    {
        if(!(index == 0))//If the index to remove is not zero,
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length 1!");
        }
    }

    if(index == 0)//If we're removing the root,
    {
        Node* next = root->getNext();//Stores the node following the root
        delete root;//Deletes the root from memory
        root = next;//Sets the root to the item that preceded the root.
        return;
    }

    /*
        Iterates through the list until it gets to the given index.
    */
    Node* last = nullptr;//The node that precedes current
    Node* current = root;//The current node as we're iterating
    int currentIndex = 0;//The index of the current node
    while(currentIndex < index)//While the index of the current node is less than the given index,
    {
        if(!current->hasNext())//If the current node doesn't have a next node (but the given index is after the current index),
        {
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length " + std::to_string(currentIndex+1) + "!");
        }
        last = current;//Moves last forward
        current = current->getNext();//Moves current forward
        currentIndex++;//Increments currentIndex to match current
    }

    //Once currentIndex equals the given index,
    last->setNext(current->getNext());//Sets last's next to current's next (cuts current out of the list)
    delete current;//Deletes current from memory.
}

/**
 * Inserts the given item into the list at the given index.
 * Moves the item currently at that index forward.
 * @param index Index to insert at.
 * @param value The value to insert.
 * @throws out_of_range if the index < 0 or > the length of the list. 
*/
template <typename T>
void List<T>::insert(int index, T* value)
{
    if(index < 0)//If the given index is negative,
    {
        throw std::out_of_range("List index must be positive!");
    }

    if(root == nullptr && index != 0)//If the list is empty and we're not insering to the beginning of the list,
    {
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length 0!");
    }

    if(index == 0)//If we're inserting to the beginning of the list,
    {
        Node* inserted = new Node(value);//Creates a new node conating the given value.
        inserted->setNext(root);//Sets the new node's next to the root of the list
        root = inserted;//Stes the root to the new node
        return;
    }

    /*
        Iterates through the list until it gets to the given index.
    */
    Node* last = nullptr;//The node that precedes current
    Node* current = root;//The current node as we're iterating
    int currentIndex = 0;//The index of the current node
    while(currentIndex < index)//While the index of the current node is less than the given index,
    {
        if(!current->hasNext())//If the current node doesn't have a next node (but the given index is after the current index),
        {
            if(index == currentIndex+1)//If the given index if immediately after the given index,
            {
                current->setNext(new Node(value));//Creates a new Node conatining the given value and adds it to the end of the list
                return;
            }
            //If the index to insert at is not immediately after the last node in the list,
            throw std::out_of_range("Index " + std::to_string(index) + " is out of range for list with length " + std::to_string(currentIndex+1) + "!");
        }
        last = current;//Moves last forward
        current = current->getNext();//Moves current forward
        currentIndex++;//Increments currentIndex to match current
    }

    //Once currentIndex equals the given index,
    Node* inserted = new Node(value);//Creates a new Node containing the value to be inserted.
    inserted->setNext(current);//Sets the new Node's next to the Node at the given index.
    last->setNext(inserted);//Sets the node preceding the given index's next to the new Node.
}

/**
 * Gets the length of (number of items in) the list.
 * @returns The number of items in the list.
*/
template <typename T>
int List<T>::length()
{
    if(root == nullptr)//If there are no items in the list,
    {
        return 0;
    }

    /*
        Starts with the root and counts each following node in the list.
    */
    Node* current = root;//Sets current to the root.
    int count = 1;//The number of nodes we have counted so far (we start with the root)
    while(current->hasNext())//While there is a node after current,
    {
        current = current->getNext();//Moves current forward
        count++;//Counts the new node
    }
    return count;//Returns the number of nodes we counted.
}

/**
 * Destructor for List. Deletes all of the nodes in the list. Doesn't delete the items stored in the list. 
*/
template <typename T>
List<T>::~List()
{
    if(root == nullptr)//If the list is empty,
    {
        return;//We don't have to do anything.
    }

    /*
        Iterates through the list, startting at the root, Each time it finds a node, it moves current forward and deletes the node preceding the
        new node.
    */
    Node* last = nullptr;//The node before the current node
    Node* current = root;//The current node
    while(current->hasNext())//While there is a node after current,
    {
        last = current;//Move last forward
        current = current->getNext();//Move current forward
        delete last;//Delete the previous current.
    }
    //Once all nodes preceding current have been deleted (current is the last node in the list)
    delete current;//Deletes current
}

/**
 * Overloads the stream insertion operator so we can print lists.
 * Has the format [item_0, item_1, item_2,... item_n]
 * @param stream The stream to insert into.
 * @param list The list to insert into the stream.
 * @returns The stream we inserted into.
*/
template <typename T>
std::ostream& operator << (std::ostream& stream, const List<T>& list)
{
    stream << "[";//Inserts "[" into the stream.
    if(list.root == nullptr)//If there aren't any items in the list,
    {
        stream << "]";//Closes the brackets
        return stream;
    }

    typename List<T>::Node* current = list.root;//The current node we're printing (starts with the root)
    while(current->hasNext())//While there is a node after the current,
    {
        stream << *(current->getValue()) << ", ";//Prints current's value and ", "
        current = current->getNext();//Moves current forward.
    }

    //Once current is the last nose in the list,
    stream << *(current->getValue()) << "]";//Prints current's value and "]".
}

/**
 * Creates a Node with the given value.
 * @param value The value of the node.
*/
template <typename T>
List<T>::Node::Node(T* value)
{
    next = nullptr;//Inititalizes the next node to a null pointer
    this->value = value;//Sets this's value to the given value.
}

/**
 * Getter for next.
 * @returns The Node proceeding this node. 
*/
template <typename T>
typename List<T>::Node* List<T>::Node::getNext()
{
    return next;
}

/**
 * Setter for next;
 * @param next The Node to set next to.
*/
template <typename T>
void List<T>::Node::setNext(Node* next)
{
    this->next = next;//Sets next to the address of the given node.
}

/**
 * Getter for value.
 * @returns The value contained in this node. 
*/
template <typename T>
T* List<T>::Node::getValue()
{
    return value;
}

/**
 * Setter for value;
 * @param value The value to set value to.
*/
template <typename T>
void List<T>::Node::setValue(T* value)
{
    this->value = value;//Sets value to the given value.
}

/**
 * Gets whether or not this Node has a next node.
 * @returns True if this node has a next node and false otherwise.
*/
template <typename T>
bool List<T>::Node::hasNext()
{
    return next != nullptr;//Return whether or not next isn't nullptr.
}