#include <iostream>
#include <cmath>

using namespace std;

/*
 
9 <- 8 <- NULL

size = 5

0 []
1 []
2 []
3 []
4 []




Array
- Unsorted
- Sorted

Linked List
- UnSorted
- Sorted


UnSortedLinkedList()
~UnSortedLinkedList()

int LengthIs();

bool IsFull();
bool IsEmpty();

void InsertItem(); -- 
void DeleteItem(); -- 
void RetrieveItem(); -- 

void MakeEmpty();

bool IsLastItem();
void GetNextItem();
void ResetList();

void Display();

NULL <- [5|A13] <- [4|A12]

[value|next address] <- [value|next address] <- [value|next address] <- [value|next address]
*/

template <class T>
struct Node {
    T item;
    Node<T>* next;
};

template <class T>
class UnSortedLinkedList {
private:
    int length;
    Node<T>* head;
    Node<T>* currentPos;
public:
    UnSortedLinkedList() {
        length = 0;
        head = NULL;
        currentPos = head;
    }

    ~UnSortedLinkedList() {
        MakeEmpty();
    }

    int LengthIs() {
        return length;
    }

    bool IsFull() {
        Node<T>* temp = new Node<T>();
        if (temp != NULL) {
            delete temp;
            return false;
        }

        return true;
    }

    bool IsEmpty() {
        return head == NULL;
    }

    void InsertItem(T item) {
        if (IsFull()) {
            cout << "List is full!";
            return;
        }

        Node<T>* node = new Node<T>();
        node->item = item;
        node->next = head;

        head = node;
        length++;
    }

    void DeleteItem(T item){
        if (IsEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node<T>* location = head;
        Node<T>* tempLocation = NULL;

        if (item == location->item) {
            tempLocation = location;
            head = head->next;
        }
        else {
            while (location != NULL && item != location->item) {
                location = location->next;
            }

            tempLocation = location->next;
            location->next = (location->next)->next;
        }
        
        delete tempLocation;
        length--;
    }

    bool findItem(T item) {
        Node<T>* location = head;

        while (location != NULL && !found) {
            if (item == location->item) {
                return true;
            }
        }

        return false;
    }

    void RetrieveItem(T &item, bool &found) {
        found = false;
        Node<T>* location = head;

        while (location != NULL && !found) {
            if (item == location->item) {
                found = true;
                item = location->item;
                break;
            }
        }
    }

    void MakeEmpty() {
        Node<T>* location = head;
        Node<T>* tempLocation;

        while(location != NULL) {
            tempLocation = location;
            location = location->next;
            delete tempLocation;
        }

        length = 0;
    }

    bool IsLastItem() {
        return (currentPos == NULL);
    }

    void GetNextItem(T &item) {
        if (IsLastItem()) {
            cout << "No more items left!" << endl;
            return;
        }

        item = currentPos->item;
        currentPos = currentPos->next;
    }

    void ResetList() {
        currentPos = head;
    }

    void Display() {
        ResetList();
        T item;
        cout << "NULL";
        while (!IsLastItem()) {
            GetNextItem(item);
            cout << " <- " << item;
        }
    }

    int SumItem() {
        ResetList();
        T item;
        int result = 0;
        while (!IsLastItem()) {
            GetNextItem(item);
            result += item;
        }

        return result;
    }
};


int main()
{
    UnSortedLinkedList<int> myList;

    myList.InsertItem(5);
    myList.InsertItem(10);
    myList.InsertItem(1);
    myList.InsertItem(9);
    myList.Display();
    cout << endl;
    cout << myList.SumItem();
    //cout << myList.LengthIs();
}