#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

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
        node *temp;
        temp = current -> next;
        while(temp != current){
            cout << "temp's location: " << temp << endl;
            cout <<"temp's next location: "<<temp->next<< endl;
            cout << temp -> data << endl;
            temp = temp -> next;
        }
        cout << "temp's location: " << temp << endl;
        cout <<"temp's next location: "<<temp->next<< endl;
        cout << temp -> data << " ";
        cout << "temp's location: " << temp << endl;
        cout <<"temp's next location: "<<temp->next<< endl;
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
    obj1.display();
}
