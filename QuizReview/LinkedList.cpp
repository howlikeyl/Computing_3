#include <iostream>
using namespace std;
class Node{
    private:
    int value;
    Node* next;
    public:
    
};
void printlist(Node* n){
    while(n!=NULL){
        cout << n->value << endl;
        n = n->next;
    }
}
int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;
    printlist(head);
}