#include<iostream>
#include<string> 
using namespace std;
class Student
{
    private:
        int rollNumber;
        string name;
        string stream;
        int year;
    public:
        inline void studentRollNo(int);
        inline void studentDetails(int,string,string,int);
        inline int getRollNo();
        inline void printStuDetail();
        inline bool checkRollNo(int);
};
struct node
{
    Student item;
    node *next;
    node();
};
class HashTable
{
    private:
        int capacity;
        node *StuRecords;
    public:
        HashTable(int);
        void openHashing(node*,node*);
        int hashFunction(int); //Using Simple mod function
        int simpleModFun(int);
        void insertStuData();
        void getStuDetail();

};
node::node()
{
    next=NULL;
    item.studentRollNo(0);
}
HashTable::HashTable(int cap)
{
    capacity=cap;
    StuRecords=new node[capacity];
}
void Student::studentRollNo(int Rn)
{
    rollNumber=Rn;
}
void Student::studentDetails(int Rn,string na,string st,int y)
{
    rollNumber=Rn;
    name=na;
    stream=st;
    year=y;
}
int Student::getRollNo()
{
    return rollNumber;
}
void Student::printStuDetail()
{
    cout<<endl;
    cout<<"Roll Number - "<<rollNumber<<endl;
    cout<<"Name - "<<name<<endl;
    cout<<"Stream - "<<stream<<endl;
    cout<<"Year - "<<year<<endl;
}
bool Student::checkRollNo(int Rn)
{
    return rollNumber==Rn;
}
void HashTable::openHashing(node *ptr,node *n)
{
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=n;
}
int HashTable::hashFunction(int key)
{
    //Using Simple mod function
    if(key<=capacity)
    {
        return key-1;
    }
    else
    {
        //Collision Resolution...
        return simpleModFun(key);
    }
    return -1;
}
int HashTable::simpleModFun(int key)
{
    //we can use switch for it
    if(capacity>0 && capacity<=10)
    {
        if(key%10<capacity)
            return key%10;
        cout<<"Index is not exits"<<endl;
        return -1;
    }
    else if(capacity>10 && capacity<=100)
    {
        if(key%100<capacity)
            return key%100;
        return key%10;
    }
    else if(capacity>100 && capacity<=1000)
    {
        if(key%1000<capacity)
            return key%1000;
        return key%100;
    }
    else if(capacity>1000 && capacity<=10000)
    {
        if(key%10000<capacity)
            return key%10000;
        return key%1000;
    }
    else if(capacity>10000 && capacity<=100000)
    {
        if(key%100000<capacity)
            return key%100000;
        return key%10000;
    }
    else if(capacity>100000 && capacity<=1000000)
    {
        if(key%1000000<capacity)
            return key%1000000;
        return key%100000;
    }
    return -1;
}
void HashTable::insertStuData()
{
    try{
        int index,recRoll;
        int rollNo, year;
        string name,stream;
        cout<<"Enter Student Roll-Number: ";
        cin>>rollNo;
        index=hashFunction(rollNo);
        recRoll=StuRecords[index].item.getRollNo();
        if(recRoll==index+1 && recRoll!=0)
            throw 1;
        cout<<"Enter Student Name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Student Stream: ";
        getline(cin,stream);
        cout<<"Enter Student joining Year: ";
        cin>>year;
        cout<<endl;
        node n;
        n.next=NULL;
        n.item.studentDetails(rollNo,name,stream,year);
        if(StuRecords[index].item.getRollNo()==0)
        {
            StuRecords[index].item.studentDetails(rollNo,name,stream,year);
        }
        else
        {
            node *n=new node;
            n->next=NULL;
            n->item.studentDetails(rollNo,name,stream,year);
            openHashing(StuRecords+index,n);
        }
    }
    catch(int e)
    {
        cout<<"This RollNo. already used, 'please use different Rollno."<<endl;
    }
}
void HashTable::getStuDetail()
{
    bool flag=true;
    int index,rollNo;
    cout<<endl<<"Enter Student Roll Number: ";
    cin>>rollNo; 
    index=hashFunction(rollNo);
    node *ptr=StuRecords+index;
    while(flag)
    {
        if(ptr->item.getRollNo()==0)
        {
            cout<<"Empty";
            flag=false;
        }
        else if(ptr->item.checkRollNo(rollNo))
        {
            ptr->item.printStuDetail();
            flag=false;
        }
        else
            ptr=ptr->next;
    }
}
int main()
{
    int match;
    HashTable ht(100);
    while(1)
    {
        cout<<"1.Add Student details type '1' ";
        cout<<"\n2.Retrieving student records type '2' ";
        cout<<"\n3.Exit type '3' "<<endl;
        cout<<"type number your choice: ";
        cin>>match;
        cout<<endl;
        switch(match)
        {
            case 1:
                ht.insertStuData();
                break;
            case 2:
                ht.getStuDetail();
                break;
            case 3:
                exit(0);
        }
        cout<<endl;
    }
}