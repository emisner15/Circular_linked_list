#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string error =  "something went wrong exiting program";
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

    //~nodes();

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
        // check to see if there is a list isn't working
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

    void make_premade_list(){
        cout << "Making you a pre-made list" << endl;
        make_node(2);
        make_node(3);
        make_node(4);
        make_node(5);
        make_node(6);
        make_node(7);
        display();
    }


    void menu(){
        int selection;
        cout << "Option 1: Make Node" << endl;
        cout << "Option 2: Add node at selected destination" << endl;
        cout << "Option 3: Add node at front" << endl;
        cout << "Option 4: Delete Node" << endl;
        cout << "Option 5: Size of List" << endl;
        cout << "Option 6: Search List" << endl;
        cout << "Option 7: Update A Node" << endl;
        cout << "Option 8: Display List" << endl;
        cout << "Option 9: Make pre-made list" <<endl;
        cout << endl;
        cout << "Enter your selection: ";
        cin >> selection;

        if(!cin){
            cout << error << endl;
            return;
        }

        switch((int)selection){
        case 1:
            int node_info;
            cout <<"Enter Information for the Node" << endl;
            cin >> node_info;
            make_node(node_info);
            break;
        case 2:
            int location;
            cout <<"Enter Information for the node" << endl;
            cin >> node_info;
            cout << "Enter the Location you would like to place this new node" << endl;
            cin >> location;
            add_at_position(location,node_info);
            break;
        case 3:
            cout << "Enter node information" << endl;
            cin >> node_info;
            insert_front(node_info);
            break;
        case 4:
            cout << "Select node information you would like to delete" << endl;
            cin >> node_info;
            delete_node(node_info);
            break;
        case 5:
            cout << "Here is the current size of the list " << size_of() << endl;
            break;
        case 6:
            cout << "Enter node information to find in the list" << endl;
            cin >> node_info;
            search_list(node_info);
            break;
        case 7:
            cout << "Enter new Node information" << endl;
            cin >> node_info;
            cout << "Enter Node location you wish to update" << endl;
            update_node(node_info,location);
            break;
        case 8:
            display();
            break;
        case 9:
            make_premade_list();
            break;
        default:
            cout << " not a selection" << endl;
            break;
        }
    }

};


int main()
{
    nodes obj1;
    char question;
    do{
        obj1.menu();
        do{
            cout << endl;
            cout << "Continue?(y/n) ";
            cin >> question;
        }
        while(question != 'Y' & question != 'y' & question != 'N' & question != 'n');
        cout << endl;
    }
    while(question != 'N' & question != 'n');
}
