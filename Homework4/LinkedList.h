//
// Created by Jun Kim on 11/12/21.
//

#ifndef CS2_NOV132021_HOMEWORK4_LINKEDLIST_H
#define CS2_NOV132021_HOMEWORK4_LINKEDLIST_H
#include <iostream>
template <typename T>
class LinkedList{
private:
    struct Node{
        Node *next;
        T value;
    };
    Node *head;
public:
    LinkedList() : head(nullptr){
        head = new Node;
        head->next = nullptr;
    }
    LinkedList(const LinkedList &rhs);
    ~LinkedList() {
        // Destroys all the dynamically allocated memory
        // in the list.
        while (head != nullptr){
            Node *temp = new Node;
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    const LinkedList& operator=(const LinkedList& rhs);
    void insertToFront (const T &val);
    void printList() const;
    bool get(int i, T& item) const;
    void reverseList();
    void printReverse() const;
    void append (const LinkedList &other);
    void swap (LinkedList &other);
    int size() const;
};
template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList &rhs){
    // assignment operator
    if (this != &rhs){
        while (head != nullptr){
            Node *temp = new Node;
            temp = head->next;
            delete head;
            head = temp;
        }
        head = new Node;
        Node *temp = rhs.head;
        while (temp != nullptr){
            Node *temp2 = new Node;
            temp2->value = temp->value;
            temp2->next = temp->next;
            head = temp2;
            head = head->next;
            temp = temp->next;
        }
    }
    return *this;
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &rhs) {
    // copy constructor
//    head = new Node;
    if (rhs.head != nullptr){
        Node *temp = rhs.head;
        while (temp != nullptr){
            Node *temp2 = new Node;
            temp2->value = temp->value;
            temp2->next = temp->next;
            head = temp2;
            head = head->next;
            temp = temp->next;
        }
    }
}
template <typename T>
void LinkedList<T>::insertToFront(const T &val){
    //Inserts val at the front of the list
    Node *temp = new Node;
    temp->value = val;
    temp->next = head->next;
    head->next = temp;
}
template <typename T>
void LinkedList<T>::printList() const{
    //Prints the LinkedList
    Node *temp = head;
    int len = this->size();
    int count = len;
    while (temp != nullptr){
        if (len != count){
            std::cout<<temp->value<<" ";
        }
        count--;
        temp = temp->next;
    }
    std::cout<<std::endl;
}
template <typename T>
bool LinkedList<T>::get(int i, T& item) const{
    // Sets item to the value at position i in this
    // LinkedList and return true, returns false if
    // there is no element i
    Node *temp = head;
    for (int j=0; j<=i; j++){
        temp = temp->next;
    }
    if (temp != nullptr){
        item = temp->value;
        return true;
    }else{
        return false;
    }
}
template <typename T>
void LinkedList<T>::reverseList(){
    // Reverses the LinkedList
    Node *temp = head;
    Node *result = new Node;
    Node *result_put = result;
    int len = this->size();
    int count = len;
    while(temp!= nullptr){
        if (len != count){
            Node *temp2 = new Node;
            temp2->value = temp->value;
            temp2->next = result_put->next;
            result_put->next = temp2;
        }
        count--;
        temp = temp->next;
    }
   head = result;
}
template <typename T>
void LinkedList<T>::printReverse() const {
    // Prints the LinkedList in reverse order
    int count = this->size();
    while (count != 0){
        Node *temp = head;
        for (int i=0;i<count;i++){
            temp = temp->next;
        }
        if (temp->value != ""){
            std::cout<<temp->value<<" ";
        }
        count--;
    }
    std::cout<<std::endl;
}
template <typename T>
void LinkedList<T>::append (const LinkedList &other){
    // Appends the values of other onto the end of this
    // LinkedList.
    if (&head == &(other.head)){
        Node *temp = head;
        Node *other_head = new Node;
        Node *temp_t = other_head;
        int len = this->size();
        int count = len;
        while (temp != nullptr) {
            if (count != len){
                Node *temp2 = new Node;
                temp2->value = temp->value;
                temp2->next = temp_t->next;
                temp_t->next = temp2;
                temp_t = temp_t->next;
            }
            count--;
            temp = temp->next;
        }
        temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = other_head->next;
    }else{
        Node *temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = other.head->next;
    }
}
template <typename T>
void LinkedList<T>::swap (LinkedList &other){
    // Exchange the contents of this LinkedList with the other one.
    Node *temp = head;
    head = other.head;
    other.head = temp;

}
template <typename T>
int LinkedList<T>::size() const{
    // Returns the number of items in the Linked List.
    Node *temp = head;
    int count = 0;
    while (temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}
#endif //CS2_NOV132021_HOMEWORK4_LINKEDLIST_H
