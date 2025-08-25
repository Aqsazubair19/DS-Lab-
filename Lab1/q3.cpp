#include<iostream>
using namespace std;

class Box{
    int *value;

public:
Box(){
    value = new int(0);
}

//(shallow copy consturctr):
Box(int val){
    value = new int(val);
}

//(deep copy contructor)
Box(const Box &obj){
    value = new int(*obj.value);
}

//copy assignment 
Box& operator=(const Box& otherbox){
    if(this != &otherbox){
        delete value;
        value = new int(*otherbox.value);
    }
    return *this;
}

int get_value(){
    return *value;
}

void setvalue(int val){
    *value = val;
}

// destructor
~Box(){
    cout<<"destructor caled:"<<endl;
    cout<<"box value:"<<*value<<" destroyed"<<endl;
    delete value;
}
};

int main(){

    Box b1(10);
    cout<<"box 1 value: "<<b1.get_value()<<endl;

    Box b2= b1;
    cout<<"box 2 value: "<<b2.get_value()<<endl;

    b2.setvalue(15);
    cout<<"after modifying b2 value :"<<endl;
     cout<<"box 1 value: "<<b1.get_value()<<endl;
     cout<<"box 2 value: "<<b2.get_value()<<endl;

    Box b3(b1);
    cout<<"box 3 value: "<<b3.get_value()<<endl;

    b3.setvalue(30);
    cout<<"after modifying b3:"<<endl;
    cout<<"b1 value:"<<b1.get_value()<<endl;
    cout<<"b3 value: "<<b3.get_value()<<endl;

    return 0;


}
