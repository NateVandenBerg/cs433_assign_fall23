/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Nathaniel VandenBerg & Salman Burhan
 * @brief This is the implementation file for the PCBTable class.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
    tableSize = size;
    T* indexArray = new T[size];
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
        delete[] indexArray;
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
T PCBTable::getPCB(unsigned int idx) {
    T pcbPtr = &indexArray[idx];
    return pcbPtr;
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(T pcb, unsigned int idx) {
    indexArray[idx] = *pcb;
    PCBcount++;
    // Add a PCB pointer to the PCBTable at index idx.
}
