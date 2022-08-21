// Leaky Bucket

#include<iostream>
#include<stdlib.h>
//#include<windows.h>
#include<unistd.h>
#define bucketSize 512

using namespace std;

void bktInput(int a,int b) {
    if(a>bucketSize)
        cout<<"\n\t\tBucket overflow";
    else {
        sleep(5);
        while(a>b){
            cout<<"\n\t\t"<<b<<" bytes outputted.";
            a-=b;
            sleep(5);
        }
        if (a>0) cout<<"\n\t\tLast "<<a<<" bytes sent\t";
        cout<<"\n\t\tBucket output successful";
    }
}
int main() {
    int op, pktSize;
    srand(time(nullptr));
    cout<<"Enter output rate : "; cin>>op;
    for(int i=1;i<=5;i++){
        sleep(rand()%5);
        pktSize=rand()%1000;
        cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
        bktInput(pktSize,op);
    }
    return 0;
}
 
