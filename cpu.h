/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#ifndef CPU_H
#define CPU_H

#include "process.h"
using namespace std;
using namespace ProcessNS;

namespace CPU_NS{
    class CPUnit{
        private: 
            Process runningP;
        public:
            CPUnit();
            void PrintRunningProcess();
            Process GetRunningProcess();
            void ChangeRunningProcess(Process process);
    };
}

#endif