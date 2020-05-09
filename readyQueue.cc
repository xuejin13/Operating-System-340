/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include <iostream>

#include "readyQueue.h"

using namespace std;
using namespace ProcessNS;

namespace ReadyQueueNS{
    

    ReadyQueue::ReadyQueue(){ }

    void ReadyQueue::PrintReadyQueue(){
        for(auto& processUnit : deq){
            cout << processUnit.GetId() << " ";
        }
    }

    // vector<int> ReadyQueue::VectorReadyQueue(){
    //     vector<int> arr;
    //     for(auto& processUnit : deq){
    //         arr.push_back(processUnit.GetId());
    //     }
    //     return arr;
    // }
    vector<long> ReadyQueue::VectorReadyQueue(){
        vector<long> arr;
        for(auto& processUnit : deq){
            arr.push_back(processUnit.GetId());
        }
        return arr;
    }

    void ReadyQueue::InsertProcess(Process process){
        deq.push_back(process);
    }

    //  User has to check if it is empty before popping
    Process ReadyQueue::PopProcess(){
        Process front = deq.front();
        deq.pop_front();
        return front;
    }

    bool ReadyQueue::isEmpty(){
        return deq.empty();
    }
    
    //  Only for common ready queue
    void ReadyQueue::FrontInsertProcess(Process process){
        deq.push_front(process);
    }

}