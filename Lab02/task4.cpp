#include<iostream>
#include<string>
using namespace std;

int * resizeArray(int*oldarr, int oldsize, int newsize){
    if(newsize == oldsize){
        return oldarr;
    }

    int * newarr = new int[newsize];

    int limit = (oldsize<newsize)?oldsize:newsize;
    for(int i=0;i<limit;i++){
        newarr[i] = oldarr[i];
    }

    delete[] oldarr;
    return newarr;
}

int main(){
    int no_month;
    cout<<"enter how many months expenses you want to entered:"<<endl;
    cin>>no_month;

    int *month= new int[no_month];

    cout<<"enter expenses for months:"<<endl;
    for(int i=0;i<no_month;i++){
        cout<<"month"<<i+1<<": ";
        cin>>month[i];
    }

    int choice;
     int total = 0; int avg=0;
    cout<<"do you want to add more expense? (1 = yes/0 = no )"<<endl;
    cin>>choice;
    if(choice == 1){
        int newsize;
      cout<<"how many total months expense you want to add ?(write total month old+new)"<<endl;
      cin>>newsize;
      month = resizeArray(month,no_month,newsize);

      cout<<"enter expenses for addedd months:"<<endl;
    for(int i= no_month;i<newsize;i++){
        cout<<"month"<<i+1<<": ";
        cin>>month[i];
    }
    no_month= newsize;
    }

       cout<<"total expense each month:"<<endl;
       for(int i=0;i<no_month;i++){
        cout<<"month"<<i+1<<": ";
        cout<<month[i];
        cout<<endl;
        total +=month[i];
       }
    avg= total/no_month;
    cout<<"average of "<<no_month<<": ";
    cout<<avg;
}

    
