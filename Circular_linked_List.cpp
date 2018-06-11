#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string error =  "something went wrong";

struct node
{
    int data;
    node *next;

};

class nodes
{
private:
    node *current;
public:
    nodes()
    {
        current = NULL;
    }

    void make_node(int value)
    {
        node *temp = new node;
        temp -> data = value;
        if(current == NULL ){
            current = temp;
            temp -> next = current;
        }
        else{
            temp -> next = current -> next;
            current -> next = temp;
            current = temp;
        }

    }

    void display(){
        node *temp = new node;
        temp = current -> next;
        while(temp != current){
            cout << "temp's location: " << temp << endl;
            cout <<"temp's next location: "<<temp->next<< endl;
            cout << temp -> data << " " ;
            temp = temp -> next;
        }
        cout << "temp's location: " << temp << endl;
        cout <<"temp's next location: "<<temp->next<< endl;
        cout << temp -> data << " ";
        cout << "temp's location: " << temp << endl;
        cout <<"temp's next location: "<<temp->next<< endl;
    }

    int size_of(){
        node * temp = new node;
        temp = current -> next;
        int counter = 0;

        while(temp != current){
            temp = temp -> next;
            counter +=1;
        }
        counter + 1;
        return counter;
    }

    void insert_front(int value){
        node *temp = new node;
        temp -> data = value;
        temp -> next = current -> next;
        current -> next = temp;
    }

    void add_at_position(int pos,int value){
        int counter = 0;
        node *cur = new node;
        node *temp = new node;

        cur = current -> next;

        if(pos > size_of()){
            cout << "end of list" << endl;
        }
        else if(pos <= size_of()){
            if (cur == NULL)
            {
                cout << " no list available making it now" << endl;
            }

            for(int i=0;i<pos - 1;i++){
                cur = cur -> next;
            }

            temp -> next = cur -> next;
            temp -> data = value;
            cur ->next = temp;

            if (cur == current){
                current = temp;
            }
        }
        else{
            cout << error << endl;
        }

    }

};


int main()
{
    nodes obj1;
    obj1.make_node(2);
    obj1.make_node(3);
    obj1.make_node(45);
    obj1.make_node(0);
    obj1.make_node(7);
    //obj1.insert_front(3);
    //obj1.add_at_position(3,2);
    obj1.add_at_position(4 ,200000);
    obj1.display();
}
