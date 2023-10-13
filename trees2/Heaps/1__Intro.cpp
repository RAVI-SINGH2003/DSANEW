#include <iostream>
using namespace std;

// Insertion
// Best Case: O(1)
// Worst Case: O(logN)
// Average Case: O(logN)

// Deletion
// Best Case: O(1)
// Worst Case: O(logN)
// Average Case: O(logN)

// Searching
// Best Case : O(1)
// Worst Case : O(N)
// Average Case : O(N) 
class heap
{
    int arr[100];
    int size = 0;

public:
    void insertNode(int data)
    {
        size++;
        arr[size] = data;
        int i = size;
        while (i > 1 && arr[i] > arr[(i >> 1)])
        {
            swap(arr[i], arr[(i >> 1)]);
            i >>= 1;
        }
    }
    void deleteNode()
    {

        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int largest = i;
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }
            if (rightIndex < size &&  arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }
            if(largest!=i){
                swap(arr[i],arr[largest]);
            }
            else{
                break;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= this->size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main()
{
    heap h;
    int nodesData[] = {10,20,30,40};
    for(int i=0;i<4;i++) {
        h.insertNode(nodesData[i]);
    }
    h.print();
    for(int i =0;i<4;i++){
        cout << "After deletion : ";
        h.deleteNode();
        h.print();
    }
}
//   10 -> 10 -> 20 -> 20  ->  30 -> 30  -> 30  -> 40
//         /     /    /  \    /  \  /  \   /  \   /  \
//         20    10   10  30 10  20 10 20  40 20 30  20
//                                  /      /     /
//                                  40    10    10
//        0  1  2  3  4
// arr = [* ,40,30,20,10];