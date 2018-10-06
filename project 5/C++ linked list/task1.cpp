/**
		 * CS 333 Programming Languages FA17
		 * Project 5  task 1
		 *
		 * Mkhanyisi Gamedze
		 * 23 October 2017
*/


#include <iostream>

using namespace std;

struct Node{ // no need for typedef in C++, this works fine
    int data;
    Node *next;
    Node *previous;
};

class LinkedList{
    private:
    int sz;
    Node *head, *tail; // make these private
    public:
    
    LinkedList(){// constuctor
      head=NULL;
      tail=NULL;
      sz=0;
    }
    
    /*---- Class methods ----*/
    
    void display(){
    Node *temp=new Node;
    temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" , ";
            temp=temp->next;
        }
    } 
    
    void backward(){
    	Node *temp=new Node;
    	temp=tail;
        while(temp!=NULL){
            cout<<temp->data<<" , ";
            temp=temp->previous;
        }
    } 
    
    void push(int d){ // add node to front of the list(head)
    // create new node
    Node *temp=new Node; // new struct
    temp->data=d; // assign value to node
    temp->previous=NULL; // added at top, so no previous value
    sz+=1;
    
    // add node
        if(head==NULL){ // empty list
			head=temp;
			tail=temp;
			temp=NULL;
		}
	    else{	
			temp->next=head;
			head->previous=temp;
			head=temp; // change pointer
		}
    }
    
    int pop(){ // removes the node at the front (head) & returns Node data value
        Node *temp;
        temp=head;
        if(head==NULL){
        	return -9999;
        }
        head=temp->next;
        head->previous=NULL;
        sz-=1;
        return temp->data;
    }
    
    void append(int d){ // add node to end of list
        // create new node
        Node *temp=new Node; // new struct
        temp->data=d; // assign value to node
        temp->next=NULL; // added at bottom, so no next value
        
        sz+=1;
    
        // add node
        if(tail==NULL){ // empty list
			head=temp;
			tail=temp;
			temp=NULL;
		}
	    else{	
	        cout<<"appending: "<<temp->data<<endl;
	        tail->next=temp;
			temp->previous=tail;
			tail=temp; // change pointer
		}
    }
    
    void remove(int b){ // removes first node whose data matches target b
        // temporary values
        Node *ptr=new Node;
        ptr=head;
        int value=-9999; // if this value returned, then value not found
        Node *prev=new Node;
        Node *nxt=new Node;
        int found=0;
        int val=b;
        cout << "Removing " <<b<< endl;
        
        if(head==NULL){ // first check error condition
            cout << "		Your list is Empty: error 404" << endl;
        }
        else{
            while(ptr!=NULL){
                //cout<<"trav\n"<<endl;
                
                
                if(ptr->data==b){ // remove first occurence
                	cout<<"		>found\n"<<endl;
                	found=1; 
                    sz-=1;
                    value=ptr->data; // the return value
                    cout<<"		head="<<head->data<<"  tail="<<tail->data<<" ptr data="<<ptr->data<<endl;
                    
                    if(ptr==head){
                    	cout<<"		>removing head\n"<<endl;
                        if(ptr->next==NULL){ // single list
                            head=NULL; // new head
                        }
                        else{
                            head=ptr->next;
                        }
                    }
                    if(ptr==tail){
                    	cout<<"		removing  tail\n"<<endl;
                        if(ptr->previous==NULL){
                            head=NULL;
                        }
                        else{
                            tail=ptr->previous;
                        }
                    }
                    prev=ptr->previous;
                    int x=prev->data;
                    if(prev==NULL){
                    	cout<<"			>No prev value "<<endl;
                    }
                    else{
                    	cout<<"			>prev value :"<<x<<endl;
                    }
                    
                    nxt=ptr->next;
                    
                    x=nxt->data;
                    if(nxt==NULL){
                    	cout<<"		> No next value "<<endl;
                    }
                    else{
                    	cout<<"			> Next value :"<<x<<endl;
                    }
                    
                    // changing pointers eliminating node
                    prev->next=nxt;
                   
                    nxt->previous=prev;
                    
                    
                    cout << "		Value  "<<b<<"=="<<value<<"  >Found: Succesully removed"<< endl;
                    break; // break after finding first instance
                    
                }
            
            ptr=ptr->next;
            }
            
        }
        
        if(found==0){
            	cout << "		*Error: Value   "<<val<<", not in this list: can't remove"<< endl;
        }
    }     
    
    void delete_all(int b){ // removes all node instances  whose data matches target b
        // temporary values
        Node *ptr=new Node;
        ptr=head;
        int value=-9999; // if this value returned, then value not found
        Node *prev=new Node;
        Node *nxt=new Node;
        int found=0;
        int val=b;
        cout << "Removing " <<b<< endl;
        
        if(head==NULL){ // first check error condition
            cout << "		Your list is Empty: error 404" << endl;
        }
        else{
            while(ptr!=NULL){
                //cout<<"trav\n"<<endl;
                
                
                if(ptr->data==b){ // remove first occurence
                	cout<<"		>found\n"<<endl;
                	found=1; 
                    
                    value=ptr->data; // the return value
                    cout<<"		head="<<head->data<<"  tail="<<tail->data<<" ptr data="<<ptr->data<<endl;
                    
                    if(ptr==head){
                    	cout<<"		>removing head\n"<<endl;
                        if(ptr->next==NULL){ // single list
                            head=NULL; // new head
                        }
                        else{
                            head=ptr->next;
                        }
                    }
                    if(ptr==tail){
                    	cout<<"		removing  tail\n"<<endl;
                        if(ptr->previous==NULL){
                            head=NULL;
                        }
                        else{
                            tail=ptr->previous;
                        }
                    }
                    prev=ptr->previous;
                    int x=prev->data;
                    if(prev==NULL){
                    	cout<<"			>No prev value "<<endl;
                    }
                    else{
                    	cout<<"			>prev value :"<<x<<endl;
                    }
                    
                    nxt=ptr->next;
                    
                    x=nxt->data;
                    if(nxt==NULL){
                    	cout<<"		> No next value "<<endl;
                    }
                    else{
                    	cout<<"			> Next value :"<<x<<endl;
                    }
                    
                    // changing pointers eliminating node
                    prev->next=nxt;
                   
                    nxt->previous=prev;
                    
                    
                    cout << "		Value  "<<b<<"=="<<value<<"  >Found: Succesully removed"<< endl;
                    sz-=1;
                    //break; // break after finding first instance
                    
                }
            
            ptr=ptr->next;
            }
            
        }
        
        if(found==0){
            	cout << "		*Error: Value   "<<val<<", not in this list: can't remove"<< endl;
        }
    }     
    int size(){
        return sz;
    }
    
    void clear(){ // removes all of the nodes from the list, freeing the associated data using the given function.
        Node *ptr=new Node;
        Node *temp=new Node;
		ptr=head;
		while(ptr!=NULL){// traverse whole list deleting items
		    temp=ptr;
		    ptr=ptr->next;
		    delete temp;// delete that node
		}
        // set list back to default values
        head=NULL;
        tail=NULL;
        sz=0;
    } 
};	

int main()
{
   cout << "LinkedList Demo" << endl; 
   
   LinkedList ll;
   for(int i=0;i<10;i++){
       ll.push(i);
   }
   
   
   cout << "Displaying list >>" << endl; 
   ll.display();
   cout << "\n_________________ >>" << endl; 
   
   cout << "\nPoppinng list >>" << endl; 
   int c=ll.pop();
   cout << c<<"\nlist backward:"<<endl; 
   ll.backward();
   cout<<"\n_________________ " << endl;
   
   for(int i=-1;i>-5;i--){
       ll.append(i);
   }
   cout << "Displaying list after Appending >>" << endl; 
   ll.backward();
   cout << "\n_________________ >>" << endl; 
   
   ll.remove(0);
   ll.remove(100);
   cout << "After removing 0 & 100 >>" << endl; 
   ll.backward();
   //ll.display();
   cout << "\n_________________ >>" << endl; 
   
   cout<<"Size:  "<<ll.size()<<endl;;
   
   for(int i=-1;i<7;i++){
       ll.push(i%2);
   }
   ll.push(2);
   ll.push(4);
   ll.push(7);
   cout << "Displaying list after Appending >>" << endl; 
   ll.backward();
   cout << "\n_________________ >>" << endl; 
   cout << "Remove all instances of zero (0) >>" << endl;
   ll.delete_all(0);
   
   cout << "Displaying list after Deleting all zeros >>" << endl; 
   ll.backward();
   cout << "\n_________________ >>" << endl; 
   
   
   
   return 0;
}