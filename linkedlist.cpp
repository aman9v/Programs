#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    };
    
class LinkedList {
    private:
        Node *head, *tail;
    
    public:
        LinkedList() : head(NULL), tail(NULL){};
        
        void insertNodeAtStart(int x) {
            Node *n = new Node;
            n -> data = x;
            n -> next = head;
            head = n;
            }
        
        void insertNodeAtEnd(int x){
            Node *temp = head;
            Node *n = new Node;
            while(temp -> next != NULL) temp = temp->next;
            n -> data = x;
            n->next = temp->next;
            temp->next = n;
            }    
        
        void opAtPos(int pos, int op=1, int x=0){ // 1 for adding and 0 for deleting a node
        	Node *temp = head;
        	int i = 1;
	while(i++ < pos-1 && temp->next != NULL)temp = temp -> next;
	if (op == 1 && x != 0){
	   Node *n = new Node;
	   n -> data = x;
	   n -> next = temp -> next;
	   temp -> next = n;
	}
	else {
	temp -> next = temp -> next -> next;		
	}
        }    
        
        void sortList(){
        	Node *temp = head;
        	vector <int> count(3 ,0);
        	while(temp != NULL){
        		count[temp->data]++;
        		temp = temp -> next;
        		}
        	// cout << count[0] << " " << count[1] << " " << count[2] << "\n";
        	temp = head;
            int i = 0;
            while(temp != NULL){
            	if (count[i] == 0) i++;
            	else {
            		
            		temp->data = i;
            		count[i]--;
            		temp = temp->next;
            	}	
            }
        }
        
        void traverseList() {
            Node *temp = head;
            while(temp != NULL) {
                cout << temp -> data;
                if (temp -> next != NULL) cout << " --> ";
                temp = temp -> next;
                }
            }    
	
        Node *getHead(){
	return head; 
	}	        
    
    };    

int main(){
    ios_base::sync_with_stdio(false);
    LinkedList ll;
    ll.insertNodeAtStart(0);
    ll.insertNodeAtStart(1);
    ll.insertNodeAtStart(0);
    ll.insertNodeAtStart(2);
    ll.insertNodeAtStart(1);
    ll.insertNodeAtStart(1);
    ll.insertNodeAtStart(2);
    ll.insertNodeAtStart(1);
    ll.insertNodeAtStart(2);
    //ll.opAtPos(5, 6);
    Node *head = ll.getHead();
    ll.traverseList();
    cout << "\n";
    ll.sortList();
    
    //ll.insertNodeAtEnd(6);
    //cout << head->next->next->data << "\n";
    ll.traverseList();
    return 0;
    }