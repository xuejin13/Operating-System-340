/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#ifndef OS_READY_QUEUE_H
#define OS_READY_QUEUE_H

#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>

#include "process.h"
using namespace std;
using namespace ProcessNS;

namespace ReadyQueueNS{
    class ReadyQueue
    {
        protected:
            // stack<Process> s;

            // queue<Process> q;
            deque<Process> deq;
        public:
            ReadyQueue();
            // ~ReadyQueue();

            void PrintReadyQueue();
            // vector<int> VectorReadyQueue();
            vector<long> VectorReadyQueue();


            void InsertProcess(Process process);
            Process PopProcess();
            bool isEmpty();

            //  Extra features for the common queue : could make it inherit
            void FrontInsertProcess(Process process);
            // Process GetFirstProcess();
        };
        
        // ReadyQueue::ReadyQueue(/* args */)
        // {
        // }
        
        // ReadyQueue::~ReadyQueue()
        // {
        // }
    

}


#endif