#include <iostream>
#include "readyqueue.h"
#include "pcbtable.h"
#include "pcb.h"
#include "heap.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     Heap* readyQueue = new Heap;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    readyQueue->~Heap();
    delete readyQueue;
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(T pcbPtr) {
    pcbPtr->setState(ProcState::READY);
    readyQueue->insert(pcbPtr);
    // When adding a PCB to the queue, you must change its state to READY.
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
T ReadyQueue::removePCB() {
    T pcb = readyQueue->removeMax();
    pcb->setState(ProcState::RUNNING);
    // When removing a PCB from the queue, you must change its state to RUNNING.
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    return readyQueue->size();
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    int queueSize = readyQueue->size();

    for(int i = 0; i < queueSize; i++) {
        T val = readyQueue->removeMax();
        cout << endl;
        val->display();
    }
}