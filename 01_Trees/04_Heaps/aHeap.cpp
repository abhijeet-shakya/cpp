#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int * arr;
    int size;
    int totalSize;

    public:

    MaxHeap(int n ){
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    // insert in the heap
    
    void insert(int val)
    {
        if(size == totalSize){
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;


        // Compare it with parent node and swaps if neccessary

        while(index > 0 && arr[(index-1)/2] < arr[index] ){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout << arr[index]<< " is inserted into heap\n";
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout<< arr[i]<<" ";
        }cout<<endl;
    }


    // Deltion in heap  
    // Time Complexity O(logn)

    void deleteNode(){
        if(size == 0){
            cout<<"Heap Underflow\n";
            return;
        }

        cout<<arr[0]<<" deleted from the heap\n";
        arr[0] = arr[size-1];
        size--;
        
        if(size == 0){
            return;
        }
        Heapify(0);

    }

    void Heapify(int i){
        int largest = i;

        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        // largest is store the index of the element which is greater beteween leftChild and rightChild

        if(leftChild < size && arr[leftChild] > arr[largest] ){
            largest = leftChild;
        }
        if(rightChild<size && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            Heapify(largest);
        }
    }


};

int main(){
    // Heap -> store in array 
    // parent child relation
    // if parent node index = i 
    // the children nodes = 2*i + 1(LEFT CHILD) & 2*i + 2(RIGHT CHILD);

    // if childre node index is given let i
    // parent = (i-1)/2


    MaxHeap H1(6);
    // Insertion in heap
    H1.insert(10);
    H1.insert(51);
    H1.insert(5);
    H1.insert(25);
    H1.insert(19);
    H1.insert(12);
    H1.insert(7);
    H1.print();

    // Deletion in heap
    // delete only top/root node and rearrage data
    H1.deleteNode();
    H1.deleteNode();
    H1.print();




    return 0;
}