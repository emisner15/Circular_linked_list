#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string error =  "something went wrong";
string does_not_exist = "This item does not exist in the list: ";

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

        cout << current -> next << endl;
        cout << current -> data << endl;
    }

    int size_of(){
        node * temp = new node;
        temp = current -> next;
        int counter = 1;

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

    void delete_node(int value){

        node *curr = new node;
        node *temp = new node;

        curr = current -> next;

        if(current -> next == current && current -> data == value)
        {
            temp = current;
            current = NULL;
            delete temp;
            return;
        }
        if (curr -> data == value){
            temp = current;
            current -> next = curr -> next;
            delete temp;
            return;
        }
        while(curr -> next != current){
            if (curr -> next -> data == value){
                temp = curr -> next;
                curr -> next = temp -> next;
                delete temp;
                return;
            }
            curr = curr -> next;
        }
        if (curr-> next -> data == value){
            temp = curr -> next;
            curr -> next = current -> next;
            delete temp;
            current = curr;
            return;
        }
        else{
            cout << does_not_exist << value << endl;
        }
    }

    void search_list(int value){
        int counter = 0;
        node *curr = new node;
        curr = current -> next;
        // check to see if there is a list isnt working
        if (current == NULL){
            cout << "There is no list. Make one" << endl;
        }

        while(curr != current){
            counter +=1;
            if(curr -> data == value){
                cout << "here is your value: " << curr -> data << ", at location: " << counter << endl;
                return;
            }
            curr = curr -> next;
        }
        if(curr -> data == value){
            counter += 1;
            cout << "here is your value: " << curr -> data << ", at location: " << counter << endl;
        }
        else{
            cout << does_not_exist << value << endl;
        }
    }

    void update_node(int value, int pos){
        // check to see if there is a list isnt working
        // enter position and value to update an existing node
        // if nodes do not exist ask user to make one

        node *curr =  new node;

        curr = current -> next;

        cout << current -> next << endl;
        cout << error << endl;

        if (current -> next == NULL ){
            cout << "Make a list first" << endl;
            return;
        }
        for (int i = 0;i < pos - 1; i++){
            if(curr == current){
                cout << "Size of " << pos << " is too larger. There are only " << size_of() << " values in the current list" << endl;
                return;
            }
            curr = curr -> next;
        }
        curr -> data = value;

        cout << " node at " << pos << " has been updated" << endl;


    }

};


int main()
{
    nodes obj1;
    obj1.make_node(8);
    obj1.make_node(45);
    obj1.make_node(0);
    obj1.make_node(7);
    obj1.make_node(7);
    obj1.insert_front(3);
    //obj1.add_at_position(3,2);
    //obj1.add_at_position(4 ,200000);
    //obj1.delete_first();
    cout << obj1.size_of() << endl;
    //obj1.delete_node(12);
    //obj1.search_list(45);
    obj1.update_node(1,5);
    //obj1.search_list(10);
    obj1.display();
}
