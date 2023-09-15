/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Nathaniel VandenBerg & Salman Burhan
 * @brief This is the header file for the PCBTable class, an array(list) of all PCB elements in the system..
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code
#pragma once

#include "pcb.h"

typedef PCB* T;

/**
 * @brief PCTable is an array of all PCB's in the system
 * 
 */
class PCBTable {
private:
    T indexArray;
    int tableSize;
    int PCBcount = 0;

public:
    /**
     * @brief Construct a new PCBTable object of the given size (number of PCBs)
     *
     * @param size: the capacity of the PCBTable
     */
    PCBTable(int size = 100);

    /**
     * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
     *
     */
    ~PCBTable();

    /**
     * @brief Get the PCB at index "idx" of the PCBTable.
     *
     * @param idx: the index of the PCB to get
     * @return PCB*: pointer to the PCB at index "idx"
     */
    T getPCB(unsigned int idx);

    /**
     * @brief Overload of the operator [] that returns the PCB at idx
     *
     * @param idx
     * @return PCB*
     */
     T operator[](unsigned int idx) {
        return getPCB(idx);
    }

    int PCBTableSize() {
        return tableSize;
    }

    /**
     * @brief Add a PCB pointer to the PCBTable at index idx.
     *
     * @param pcb: the PCB pointer to add
     * @param idx: the index to add the PCB at
     */
    void addPCB(T val, unsigned int idx);

    /**
     * @brief Add a new PCB to the PCBTable.
     * @param pid Id of the new PCB
     * @param priority Priority of the new PCB
     * @param idx The index of the new PCB in the PCBTable
     */
    void addNewPCB(unsigned int pid, unsigned int priority, unsigned int idx) {
        PCB *pcb = new PCB(pid, priority);
        addPCB(pcb, idx);
    }

    void displayPCBTable() {
        if(PCBcount>0){
            for(int i =0; i < tableSize; i++) {
                T pcbPtr = &indexArray[i];
                if(pcbPtr != nullptr)
                    {
                        cout << endl;
                        pcbPtr->display();
                    }
            }
        }
        else
        cout << "\nPCBTable is empty";
    }
};
