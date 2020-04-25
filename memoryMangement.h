



#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <utility>
#include <vector>
// #include <unordered_map>
#include <map>
/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include "process.h"

using namespace std;
using namespace ProcessNS;

bool compareOperator(pair<int, int>& a, pair<int, int>& b);

namespace memoryMange_NS{
    class Memory{
        
        private:
            vector<pair<int,int>> freeMem_;
            // unordered_map<int, pair<int, int>> usedMem;
            map<int, pair<int, int>> usedMem_;

            // vector<tuple<int,int,int>> usedMem;
            
        public:
            Memory();
            Memory(int capacity);
            int HasSpace(Process& process); //  If the storage has space it returns the index of vector? else return -1
            void CombineSpaces();
            void InsertMem(Process& process_elm, int vectorPos);
            void DecreaseSpace(int vectorPos, int newStartPos);
            void RemoveProcess(Process process_id);
            void PrintUsedMem();

            
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