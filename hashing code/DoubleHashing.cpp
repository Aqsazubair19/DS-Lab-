#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n <=1) return false;

    for(int i=2; i*i <=n ;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    while(!isPrime(++n));// jab tak false ho loop continues
    return n;
}

class HashTable{
    public:

    int* table;
    int capacity;
    int count;
public:
    HashTable(int size =13){
        capacity = size;
        count =0;
        table = new int[capacity];
        for(int i=0;i<capacity;i++){
            table[i] = -1;
        }

    } 
void rehash(){
    int oldcapacity = capacity;
    int* oldtable = table;

    capacity = nextPrime(capacity * 2);
    table = new int[capacity];

    for(int i=0;i<capacity;i++){
        table[i] = -1;
    }

    for(int i=0;i<oldcapacity;i++){
        if(oldtable[i] >=0 ){
            insert(oldtable[i]);
        }
    }

    delete[] oldtable;
}

   float  loadfactor(){
    return (float) count/capacity;
   }

   int hashfunction(int key){
    return key% capacity;
   }

   int hashfunction_2(int key){
    return 7-(key % 7);
   }

void insert(int key){

    if(loadfactor() >=0.7){
        cout<<"rehashing(double hashing)"<<endl;
        rehash();  
    }

    int index = hashfunction(key);
    int index2 = hashfunction_2(key);
    for(int i=0;i<capacity ;i++){
        int newindex = (index + i* index2) % capacity;
        if(table[newindex]== -1 || table[newindex]== -2){
            table[newindex] = key;
            count++;
            return;
        } 
    }
   }

int Search(int key){
    int index = hashfunction(key);
    int index2 = hashfunction_2(key);
    for(int i=0;i<capacity;i++){
         int newindex = (index + i* index2) % capacity;
         if(table[newindex] == -1){
            cout<<"key not found"<<endl;
            return -1;
         }

         if(table[newindex] == key){
            
            return newindex;
         }
    }
    return -1;


}   

void delete_key(int key){
    int index = Search(key);

    if(index == -1){
        cout<<"key not found cant delete"<<endl;
        return;
    }

    table[index] = -2;
    count --;
    cout<<"key "<<key<<" deleted at index: "<<index<<endl;
    return;
}

void display(){
    for(int i=0;i<capacity ; i++){
        cout<<i<<" : "<<table[i]<<endl;
    }
    cout<<endl;
}

};

int main(){
  HashTable table;
  table.insert(18);
  table.insert(41);
  table.insert(22);
  table.insert(44);

  table.display();

  cout<<"key 18 found at index: "<<table.Search(18)<<endl;
   cout<<"key 2 not found  "<<table.Search(5)<<endl;

   table.delete_key(22);
   table.display();
}
