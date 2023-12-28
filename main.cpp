#include<iostream>
#include<string>
//Class named task include ID,Task Name

class Task{
    public:
    int id;
    Task *nxt;
    std::string chore_name;

    Task(int id, std::string chore){
        this->id = id;
        this->chore_name = chore;
        nxt = nullptr;
    }
};

//Class called TODO list with methods like adding a task,deletion of task, view task

class TODO{
    public:
    Task *head;
    int id_ctr = 0;
    
    TODO(){
        head = nullptr;
    }

    void add(std::string chore){
        if(head == nullptr){
            head = new Task(id_ctr,chore);
            id_ctr++;
            std::cout<<"Chore Added Successfully\n";
            return;
        }
        Task *t = new Task(id_ctr,chore);
        t->nxt = head;
        head = t;
        id_ctr++;
    }
    void listChores(){
        if(head ==nullptr) std::cout<<"All chores are already completed!\n";
        else{
        Task *t = head;
        std::cout<<"-----------------\n";
        std::cout<<"|ID : Chore Name\n";
        std::cout<<"-----------------\n|";
        while(t!=nullptr){
            std::cout<<t->id<<" : "<<t->chore_name<<"\n|";
            t = t->nxt;
        }
        std::cout<<"-----------------\n";
        }
    }
    void deleteChores(int id){
        if(id>=id_ctr){std::cout<<"Enter valid ID\n";return;}
        if(head->nxt==nullptr) head = nullptr;
        else if (head->id==id)
        {
            Task *t = head;
            head = t->nxt;
            delete t;
        }
        else{
        Task *t = head;
        Task* p=nullptr;
        while(t->id!=id){
            p = t;
            t = t->nxt;
        }
        p->nxt = t->nxt;
        delete t;
        }
        std::cout<<"Chore Completed\n";
    }
};

int main(){
    TODO list;
    bool check = 1;
    std::cout<<"==================================\n              TODO            \n==================================\n";
    int option;
    std::cout<<"Choose your options:\n1> Create chore\n2>Delete chore\n3>View chore\n4>Exit\n";
    while(check){
        std::cout<<"command: ";
        std::cin>>option;
        std::string ch;
        int delC;
        switch (option)
        {
        case 1:
            std::cout<<"Enter your chore -> ";
            std::cin.ignore(256, '\n');
            std::getline(std::cin,ch);
            list.add(ch);
            std::cout<<"\n";
            break;
        case 2:
            list.listChores();
            std::cout<<"Enter the id of the chore to delete: ";
            std::cin>>delC;
            list.deleteChores(delC);
            std::cout<<"\n";
            break;
        case 3:
            list.listChores();
            std::cout<<"\n";
            break;
        case 4:
            check = 0;
            std::cout<<"Exiting....\n";
            break;
        default:
            std::cout<<"Choose a valid option\n";
            break;
        }

    }
    return 0;
}