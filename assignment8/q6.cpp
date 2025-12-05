#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    vector<int>heap;
    void heapifyUp(int i){
        while(i>0){
            int p=(i-1)/2;
            if(heap[p]>heap[i]){
                swap(heap[p],heap[i]);
                i=p;
            }else break;
        }
    }
    void heapifyDown(int i){
        int n=heap.size();
        while(true){
            int l=2*i+1;
            int r=2*i+2;
            int s=i;
            if(l<n&&heap[l]<heap[s])s=l;
            if(r<n&&heap[r]<heap[s])s=r;
            if(s!=i){
                swap(heap[i],heap[s]);
                i=s;
            }else break;
        }
    }
public:
    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    void pop(){
        if(heap.empty())return;
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty())heapifyDown(0);
    }
    int top(){
        if(heap.empty()){ cout<<"heap is empty";
        return heap[0];
    }
    bool empty(){
        return heap.empty();
    }
    void print(){
        for(int x:heap)cout<<x<<" ";
        cout<<"\n";
    }
};

int main(){
    MinHeap pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.print();
    cout<<pq.top()<<"\n";
    pq.pop();
    cout<<pq.top()<<"\n";
    pq.print();
}
