#include<iostream>
#include<vector>
using namespace std;

void SortColor(vector<int>&vec){
    int low=0,mid=0,large=vec.size();
    
    while(mid<=large){
        
        // when value will be 0
        if(vec[mid]==0){
            swap(vec[low],vec[mid]);
            low++;
            mid++;
        }else if(vec[mid]==1){
            mid++;
        }else{
            swap(vec[mid],vec[large]);
            large--;
        }
        
    }
    return ;
    
}


int main(){
    
    vector<int>vec={2,0,2,1,2,1,0,1,2,2,0};
    int n=vec.size();
    
    cout<<"the array is ";
    
    
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }cout<<endl;
    
    SortColor(vec);
    
    cout<<"the sorted array is ";
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    
    
    return 0;
}
