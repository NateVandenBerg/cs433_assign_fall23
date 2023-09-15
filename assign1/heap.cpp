#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
int Heap::getMax() const {//finds max value in array
    // Initialize largest as root
    if (count == 0) {
        return -1;
    }
    int largest = getMaxIndex(0);

    return largest;
}

int Heap::getMaxIndex(int index) const {//finds maxValue index Location
    //cout << "Max I::";
                                      // Initialize largest as root
    int largest = index;
    
    // left = 2*i + 1
    int l = 2 * index + 1;

    // right = 2*i + 2
    int r = count;

    if (count > 2) {
        r = 2 * index + 2;
    }
    else {
        if (heapArray[0]->getPriority() > heapArray[1]->getPriority()) {
            return 0;
        }
        else
            return index + 1;
    }

    // If left child is larger than root
    if (l < count && heapArray[l]->getPriority() > heapArray[largest]->getPriority() 
        && heapArray[l]->getPriority() > heapArray[r]->getPriority()) {
        largest = l;
        getMaxIndex(l);
    }

    // If right child is larger than largest
    // so far
    if (r < count && heapArray[r]->getPriority() > heapArray[largest]->getPriority() 
        && heapArray[r]->getPriority() > heapArray[l]->getPriority()) {
        largest = r;
        getMaxIndex(r);
    }
    //cout <<"LRG: " << largest << "=" << heapArray[largest] << "::";
    return largest;
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap() {
    //cout << "HEAP::HEAP()\n";
    capacity = 500;
    heapArray = new T[capacity];
    count = 0;
}

// @brief destructor
Heap::~Heap() {
    //cout << "HEAP::~HEAP\n";
    delete[] heapArray;
    //heapArray = NULL;
}

// @brief Copy constructor
Heap::Heap(const Heap& heap) {
    cout << "HEAP::HEAP(Const&)\n";
    this->capacity = heap.capacity;
    this->heapArray = new T[capacity];
    this->count = 0;
    for (int i = 0; i < heap.count; i++) {
        cout << "HEAP::HEAP(Const&)\n";
        this->insert(heap.heapArray[i]);
    }
}

Heap& Heap::operator= (const Heap& heap) {
    cout << "HEAP::Operator = \n";
    if (this != &heap) {
        delete[] heapArray;
        capacity = heap.capacity;
        count = heap.count;
        heapArray = new T[capacity];
        for (int i = 0; i < count; i++) {
            cout << "HEAP::Operator = \n";
            heapArray[i] = heap.heapArray[i];
        }
    }
    return *this;
}

//@brief Resize the data array to double its allocation size
void Heap::resizeArray() {
    T* newArray = new T[capacity * 2];

    for (int i = 0; i < count; i++) {
        newArray[i] = heapArray[i];
    }

    capacity *= 2;
    delete[] heapArray;
    heapArray = newArray;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(T *values, int length) {
    Heap* newHeap = new Heap;
    delete[] heapArray;
    //newHeap->capacity = length;
    newHeap->count = length*2;
        // Copy from existing array to new array
    newHeap->heapArray = values;
}



/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {
    int i = count / 2 - 1;
    while (i >= 0) {
        percolateDown(i);
        i--;
    }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {
    int childIndex = 2 * index + 1;
    T value = heapArray[index];

    if (childIndex < count) {
        // Find the max among the node and all the node's children
        T maxValue = value;
        int maxIndex = -1;
        int i = 0;
        while (i < 2 && i + childIndex < count) {
            if (heapArray[i + childIndex] > maxValue) {
                maxValue = heapArray[i + childIndex];
                maxIndex = i + childIndex;
            }
            i++;
        }

        // Check for a violation of the max-heap property
        if (maxValue == value) {
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[maxIndex]
            std::cout << "   PercolateDown() swap: " << heapArray[index];
            std::cout << " <-> " << heapArray[maxIndex] << std::endl;
            swap(index, maxIndex);

            // Continue loop from the max index node
            percolateDown(maxIndex);
        }
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp(int index) {
    if (index > 0) {
        // Compute the parent node's index
        int parentIndex = parent(index);

        // Check for a violation of the max-heap property
        if (heapArray[index] <= heapArray[parentIndex]) {
            // No violation, so percolate up is done.
            return;
        }
        else {
            // Swap heapArray[nodeIndex] and heapArray[parentIndex]
            swap(index, parentIndex);

            // Continue the loop from the parent node
            percolateUp(parentIndex);
        }
    }
}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(T PCB) {
    // Resize if needed
    if (count == capacity) {
        resizeArray();
    }

    // Add the new value to the end of the array
    heapArray[count] = PCB;
    count++;

    // Percolate up from the last index to restore heap property
    percolateUp(count - 1);
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
T Heap::removeMax() {
    // Save the max value from the root of the heap

    T maxValue = heapArray[0];

    // Move the last item in the array into index 0
    
    //int i = 0;
    if (count > 1) {
        swap(0, count - 1);
        count--;
        // Percolate down to restore max-heap property
        percolateDown(0);
    }
    
    //printHeap();

    // Return the max value
    return maxValue;
}

//@brief converts the heap into a string
// string Heap::toString()
// {
//     string s = "[ ";
//     for (int i = 0; i < count; i++)
//     {
//         s += to_string(heapArray[i]->display()) + " ";
//     }
//     s += "]";
//     return s;
// }

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    if(count>0){
            for(int i =0; i < count; i++) {
                T val = heapArray[i];
                if(val != nullptr)
                    {
                        cout << endl;
                        val->display();
                    }
            }
        }
        else
        cout << "\nPCBTable is empty";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
    //cout << "swap::";
    T temp = heapArray[index1];
    heapArray[index1] = heapArray[index2];
    heapArray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void heapSort(T values[], int length) {
    /*Heap* heapPtr2->heapArray = values;
    heapPtr2->printHeap();
    delete heapPtr2;*/
    
    
    cout << "Array Before Sorting: \n";
    printArray(values, length);

    Heap* newHeap = new Heap;

    Heap* newHeap2 = new Heap(values, length);
    newHeap2->printHeap();

    for (int i = 0; i < length; i++) {
        newHeap->insert(values[i]);
    }
    newHeap->printHeap();
    
    // Build heap (rearrange array)        
    for (int i = 0; i < length;i++) {
        //cout << "step " << i + 1 << ": \n";
        values[length-1-i] = newHeap->removeMax();
        //printArray(values, length);
    }  
    
    delete newHeap;

    cout << "\nArray After Sorting: \n";
    printArray(values, length);
}

/**
     * @brief Change the key of the element at position i to the new value.
     *        It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, T newValue) {
    heapArray[i] = newValue;

    heapify();
}
