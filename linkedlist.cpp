#include <iostream>
#include <string>
using namespace std;

using ItemType = string;

struct Node {
    ItemType value;
    Node *next;
};

class LinkedList {
private:
    Node *head;
public:
    // default constructor
    LinkedList() : head(nullptr) {
        head = new Node;
        head->next = nullptr;
        head->value = "";
    }

    // copy constructor
    LinkedList(const LinkedList& rhs);

    // Destroys all the dynamically allocated memory
    // in the list.
    ~LinkedList();

    // assignment operator
    const LinkedList& operator=(const LinkedList& rhs);

    // Inserts val at the front of the list
    void insertToFront(const ItemType &val);

    // Prints the LinkedList
    void printList() const;

    // Sets item to the value at position i in this
    // LinkedList and return true, returns false if
    // there is no element i
    bool get(int i, ItemType& item) const;

    // Reverses the LinkedList
    void reverseList();

    // Prints the LinkedList in reverse order
    void printReverse() const;

    // Appends the values of other onto the end of this
    // LinkedList.
    void append(const LinkedList &other);

    // Exchange the contents of this LinkedList with the other one.
    void swap(LinkedList &other);

    // Returns the number of items in the Linked List.
    int size() const;
};

LinkedList::LinkedList(const LinkedList &rhs) {
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
LinkedList::~LinkedList() { //check
    // Destroys all the dynamically allocated memory
    // in the list.
    while (head != nullptr){
        Node *temp = new Node;
        temp = head->next;
        delete head;
        head = temp;
    }
}
const LinkedList &LinkedList::operator=(const LinkedList &rhs) {
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
void LinkedList::insertToFront(const ItemType &val) {
    // Inserts val at the front of the list
    Node *temp = new Node;
    temp->value = val;
    temp->next = head->next;
    head->next = temp;

}
void LinkedList::printList() const {
    // Prints the LinkedList
    Node *temp = head;
    int len = this->size();
    int count = len;
    while (temp != nullptr){
        if (len != count){
            cout<<temp->value<<" ";
        }
        count--;
        temp = temp->next;
    }
    cout<<endl;
}
bool LinkedList::get(int i, ItemType &item) const {
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
void LinkedList::reverseList() {
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
void LinkedList::printReverse() const {
    // Prints the LinkedList in reverse order
    int count = this->size();
    while (count != 0){
        Node *temp = head;
        for (int i=0;i<count;i++){
            temp = temp->next;
        }
        if (temp->value != ""){
            cout<<temp->value<<" ";
        }
        count--;
    }
    cout<<endl;
}
void LinkedList::append(const LinkedList &other) {
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
void LinkedList::swap(LinkedList &other) {
    // Exchange the contents of this LinkedList with the other one.
    Node *temp = head;
    head = other.head;
    other.head = temp;

}
int LinkedList::size() const {
    // Returns the number of items in the Linked List.
    Node *temp = head;
    int count = 0;
    while (temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    //for get function OK
    LinkedList ls;
    ls.insertToFront("Jack");
    ls.insertToFront("Germaine");
    ls.insertToFront("Agatha");
    ls.insertToFront("Agnes");

    for (int k = 0; k < ls.size(); k++)
    {
        string x;
        ls.get(k, x);
        cout << x << endl;
    }

//    //for printList and printReverse function OK
//    LinkedList ls;
//    ls.insertToFront("George");
//    ls.insertToFront("Louise");
//    ls.insertToFront("Lionel");
//    ls.insertToFront("Helen");
//
//    ls.printList();
//    ls.printReverse();

//    //for append function  OK
//    LinkedList e1;
//    e1.insertToFront("bell");
//    e1.insertToFront("biv");
//    e1.insertToFront("devoe");
//    LinkedList e2;
//    e2.insertToFront("Andre");
//    e2.insertToFront("Big Boi");
//    e1.append(e2);  // adds contents of e2 to the end of e1
//    string s;
//    assert(e1.size() == 5  &&  e1.get(3, s)  &&  s == "Big Boi");
//    assert(e2.size() == 2  &&  e2.get(1, s)  &&  s == "Andre");
//    LinkedList e3;
//    e3.insertToFront("Rare Essence");
//    e3.insertToFront("JunkYard");
//    e3.insertToFront("Chuck Brown");
//    e3.append(e3);
//    assert(e3.size() == 6  &&  e3.get(3, s)  &&  s == "Chuck Brown");

//    //for reverseList function OK
//    LinkedList e1;
//    e1.insertToFront("Sam");
//    e1.insertToFront("Carla");
//    e1.insertToFront("Cliff");
//    e1.insertToFront("Norm");
//    e1.reverseList();  // reverses the contents of e1
//    string s;
//    assert(e1.size() == 4  &&  e1.get(0, s)  &&  s == "Sam");

//    //for swap function OK
//    LinkedList e1;
//    e1.insertToFront("A");
//    e1.insertToFront("B");
//    e1.insertToFront("C");
//    e1.insertToFront("D");
//    LinkedList e2;
//    e2.insertToFront("X");
//    e2.insertToFront("Y");
//    e2.insertToFront("Z");
//    e1.swap(e2);  // exchange contents of e1 and e2
//    string s;
//    assert(e1.size() == 3  &&  e1.get(0, s)  &&  s == "Z");
//    assert(e2.size() == 4  &&  e2.get(2, s)  &&  s == "B");

}