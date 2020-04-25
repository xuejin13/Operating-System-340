/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#ifndef OS_PROCESS_H
#define OS_PROCESS_H

#include <cstdlib>
#include <string>

enum ProcessType { RT, C, N};

namespace ProcessNS {
    class Process {
        private: 
            int process_id_;
            int mem_size_;
            ProcessType process_type_;
        public:
            Process(): process_id_{0}, mem_size_{0}, process_type_{N} { } 
            Process(int id, int memorySize, ProcessType type);
            int GetId();
            int GetMemSize();
            ProcessType GetProcessType();
    };  // namespace OperatingSys

}

#endif  // OS_PROCESS_H
