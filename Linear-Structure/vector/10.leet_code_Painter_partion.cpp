#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>&paint,int m, int mid){
    int painter=1,time=paint[0];
    for(int i=1;i<paint.size();i++){
        if(time>mid)return false;
        if(paint[i]+time<=mid)time+=paint[i];
        else{
            painter++;
            time=paint[i];
        }
    }
    return painter>m?false:true;
}

int Painter_partition(vector<int>&paint,int m){
    int sum=0;
    for(int i=0;i<paint.size();i++)sum+=paint[i];
    
    int start=0,end=sum,ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(paint,m,mid)){
            end=mid-1;
            ans=mid;
        }
        else start=mid+1;
    }
    return ans;
}

int main(){

    vector<int>paint={8,4,3,7,1,5,8,5,2};
    int m=3;
    cout<<"the minimum time of painting the partition is "<<Painter_partition(paint,3)<<endl;
    return 0;
}