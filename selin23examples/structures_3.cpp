#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct Time { //structure og time given i the problem
    int hour;
    int minute;
};

struct Node { //maintain for list
    Time time;
    Node* prev;
    Node* next;
};

class doubleLinkedList{ //class for dLL
    private:
        Node* head;
        Node* tail;
    public:
        doubleLinkedList() : head(nullptr), tail(nullptr) {}

    //desending order add
    void placeBack(int hour, int minute){
        Node* newNode = new Node;
        newNode -> time.hour = hour;
        newNode -> time.minute = minute;
        newNode -> prev = nullptr;
        newNode -> next = nullptr;

        if (!head){
            head = newNode;
            tail = newNode;
        }else{
            Node* current = head;
            while (current && (current->time.hour > hour || (current->time.hour == hour && current->time.minute > minute))) {
                current = current->next;
            }
            if (!current) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }else if (!current->prev) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }else{
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

    //delete element from back
    void deleteBack(){
        if(!tail){
            cout << "error: List is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail -> prev;
        if (tail){
            tail -> next = nullptr;
        }else{
            head = nullptr;
        }
        delete temp;
        getch();
    }

    //the all elements
    void printList(){
        Node* current = head;
        if (!head){
            cout << "error: List is empty" << endl;
            return;
        }
        while (current){
            cout << current -> time.hour << ":" << current -> time.minute << endl;
            current = current -> next;
        }
        getch();
    }

    //print lowest element
    void printLowest(){
        if (!head){
            cout << "error: List is empty" << endl;
            return;
        }
        cout << "Lowest element in List: " << head->time.hour << ":" << head->time.minute << endl;
        getch();
    }

    //delete all
    void forceDelete() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "deleted successfully" << endl;
        getch();
    }
};


int main(int argc, char const *argv[])
{
    doubleLinkedList timeList;
    int choice;
    while (true){
        cout << "1. Place Back" << endl;
        cout << "2. Delete Back" << endl;
        cout << "3. Print Lowest" << endl;
        cout << "4. Print All" << endl;
        cout << "5. Delete All" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice 1 - 6: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int min, hour;
            do {
                cin >> hour >> min;
            }while(hour >= 24 && min >= 60);

            timeList.placeBack(hour, min);
            break;
        case 2:
            timeList.deleteBack();
            break;
        case 3:
            timeList.printLowest();
            break;
        case 4:
            timeList.printList();
            break;
        case 5:
            timeList.forceDelete();
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
