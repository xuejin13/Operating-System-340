/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <utility>
#include <vector>
// #include <unordered_map>
#include <map>

#include "process.h"

using namespace std;
using namespace ProcessNS;

// bool compareOperator(pair<int, int>& a, pair<int, int>& b);
bool compareOperator(pair<long, long>& a, pair<long, long>& b);

namespace memoryMange_NS{
    class Memory{
        
        private:
            //  freeMem_ is a range of possible memory
            // vector<pair<int,int>> freeMem_;

            // unordered_map<int, pair<int, int>> usedMem;

            //  
            // map<int, pair<int, int>> usedMem_;

            vector<pair<long,long>> freeMem_;
            map<int, pair<long, long>> usedMem_;
            
        public:
            Memory();
            // Memory(int capacity);
            // int HasSpace(Process& process); //  If the storage has space it returns the index of vector? else return -1
            void CombineSpaces();
            // void InsertMem(Process& process_elm, int vectorPos);
            // void DecreaseSpace(int vectorPos, int newStartPos);
            void RemoveProcess(Process process_id);
            void PrintUsedMem();

            Memory(long capacity);
            long HasSpace(Process& process);
            void InsertMem(Process& process_elm, long vectorPos);
            void DecreaseSpace(long vectorPos, long newStartPos);


            
            //  I realized I could just combine the insertMem and has space together to makeit more compact
            //  but i will continue as i thought this was easier to understand
            
    };
}

/*
    free 100 - 1000

    used:   p1 0 - 99
    free:   100 - 1000

    u:  p2 100 - 199
    f:  200 - 1000

*/

#endif