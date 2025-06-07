#include<iostream>
#include<climits>
using namespace std;

bool isArmstrong(int num){
    int ans=0,original=num;
    while(num>0){
        int r=num%10;
        ans+=(r*r*r);
        num/=10;
    }
    return ans==original;
}

int reverse(int num){
    int reversed=0;
    while(num>0){
        int r=num%10;
        if(reversed>INT_MAX/10 ||reversed<INT_MIN)return 0;
        
        reversed=reversed*10+r;
        num/=10;
    }
    return reversed;
}

bool isPalindrome(int n){
    int original=n;
    int reversed=reverse(n);
    
    return original==reversed;
}

int GCD(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0)return b;
    return a;
}

int LCM(int a,int b){
    return (a*b)/GCD(a,b);
}


int main(){
    
        int option;
    do{
        cout<<"---||||========MENU========||||---"<<endl;
        cout<<"1. Armstrong Number"<<endl;
        cout<<"2. Palindrome Number"<<endl;
        cout<<"3. GCD "<<endl;
        cout<<"4. LCM "<<endl;
        cout<<"5. Reverse Number"<<endl;
        cout<<"0 return"<<endl;
        cout<<"Choose one option"<<endl;
        cin>>option;
        
        if(option==1){
            int num;
            cout<<"enter the num: "<<endl;
            cin>>num;
            
            if(isArmstrong(num)){
                cout<<"This is armstrong number"<<endl;
            }else{
                cout<<"This is not armstrong number"<<endl;
            }
            
            
        }
        
        if(option==2){
            int num;
            cout<<"enter the num: "<<endl;
            cin>>num;
            
            if(isPalindrome(num)){
                cout<<"The number is palindrome"<<endl;
            }else{
                cout<<"this is not a palindrome number"<<endl;
            }
            
        }
        
        if(option==5){
            int num;
            cout<<"enter the num: "<<endl;
            cin>>num;
            
            int reversed=reverse(num);
            cout<<"the original number is "<<num<<endl;
            cout<<"the reversed number is "<<reversed<<endl;
            
            
        }
        
        if(option==3){
            int a;
            cout<<"enter the first num: "<<endl;
            cin>>a;
            
            int b;
            cout<<"enter the second num: "<<endl;
            cin>>b;
            
            
            int gcd=GCD(a,b);
            cout<<"the gcd of two number is "<<gcd<<endl;
            
            
        }
        
        if(option==4){
            int a;
            cout<<"enter the first num: "<<endl;
            cin>>a;
            
            int b;
            cout<<"enter the second num: "<<endl;
            cin>>b;
            
            
            int lcm=LCM(a,b);
            cout<<"the gcd of two number is "<<lcm<<endl;
            
            
        }
        
        if(option==0){
            cout<<"Exit the program"<<endl;
            break;
        }
        
        
        
        
        
    }while(option!=0);
    
    return 0;
}