#include<iostream>
using namespace std;

class Array{
    public:
    int* myArray;
    int capacity;
    int size;
    
    Array(int cap){
        this->capacity=cap;
        size=0;
        myArray=new int[capacity];
        cout<<"array is created"<<endl;
    }
    
    bool isFull(){
        return size==capacity;
    }
    
    bool isEmpty(){
        return size==0;
    }
    
    void insertAtBegin(int val){
        if(isFull()){
            cout<<"array is full cannot add any other element."<<endl;
            return;
        }
        
        for(int i=size-1;i>=0;i--){
            myArray[i+1]=myArray[i];
        }
        myArray[0]=val;
        size++;
    }
    
    void deleteAtBegin(){
        if(isEmpty()){
            cout<<"array is already empty"<<endl;
            return;
        }
        
        for(int i=1;i<size;i++){
            myArray[i-1]=myArray[i];
        }
        size--;
    }
    
    void insertAtEnd(int val){
        if(isFull()){
            cout<<"array is full cannot add any other element"<<endl;
            return;
        }
        myArray[size]=val;
        size++;
    }
    
    void deleteAtEnd(){
        if(isEmpty()){
            cout<<"array is empty "<<endl;
            return;
        }
        size--;
    }
    
    void showArray() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
        } else {
            cout << "Array elements: ";
            for (int i = 0; i < size; ++i) {
                cout << myArray[i] << " ";
            }
            cout << endl;
        }
    }
    
    ~Array(){
        delete[] myArray;
        cout<<"memory deleted"<<endl;
    }
};

int main(){
    
    Array a(5);
    a.insertAtBegin(1);
    a.insertAtBegin(2);
    a.insertAtBegin(3);
    a.insertAtBegin(4);
    
    a.showArray();
    
    
    
    return 0;
}