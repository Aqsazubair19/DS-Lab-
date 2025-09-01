#include<iostream>
using namespace std;

int main(){
int n;
cout<<"enter length of array:"<<endl;
cin>>n;


int *arr = new int[n]{0};

int update;
cout<<"enter how many elements you want to update in array: "<<endl;
cin>>update;

int pos,val;

for(int i=0; i<update; i++){
cout<<"choose position between 0 to "<<n-1<<": "<<endl;
cin>>pos;

if(pos>=0 && pos <n){
    cout<<"enter value:"<<endl;
    cin>>val;
    arr[pos]=val;
}
else{
    cout<<"invalid position"<<endl;
}

}


cout<<"your entered elements in arrays:"<<endl;
for(int i=0; i<n;i++){
    cout<<arr[i]<<" ";
}

delete[] arr;
return 0;
}
