#include<iostream>
using namespace std;

int main(){
    int benches, seats;
  cout<<"enter how many benchs you required:"<<endl;
  cin>>benches;
    cout<<"enter how many seats you occupy:"<<endl;
  cin>>seats;
   
   int **arr= new int*[benches];

   for(int i=0; i< benches; i++){
    arr[i] = new int[seats]{};
  }
  int r,c;
  int choice;
do{
    
    cout<<"enter bench number between 0 to" <<benches-1<<endl;
    cin>>r;

    cout<<"enter seat number between 0 to "<<seats-1<<endl;
    cin>>c;
    
    if(r>=0 && r<benches && c >=0 && c<seats){
        arr[r][c] = 1;
        cout<<"seat has been marked"<<endl;

    }else{
        cout<<"invalid position"<<endl;

    }
     cout << "Add more seats?(0/1): 0 for no and 1 for yes";
        cin >> choice;

 }while(choice == 1);

  cout<<"Final seating chart (0 = empty, 1 = occupied):"<<endl;
    for(int i=0; i<benches; i++) {
        for(int j=0; j<seats; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<benches; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;

}

 
