/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "process.h"

using namespace std;

namespace ProcessNS {
    // Process::Process(int id, int memorySize, ProcessType type){
    //     process_id_ = id;
    //     mem_size_ = memorySize;
    //     process_type_ = type;
    // }

    // int Process::GetId(){
    //     return process_id_;
    // }

    // int Process::GetMemSize(){
    //     return mem_size_;
    // }
    
    //  0 = RT, 1 = common
    ProcessType Process::GetProcessType(){
        return process_type_;
    }

    //  Large nums

    Process::Process(long id, long memorySize, ProcessType type){
        process_id_ = id;
        mem_size_ = memorySize;
        process_type_ = type;
    }

    long Process::GetId(){
        return process_id_;
    }
    long Process::GetMemSize(){
        return mem_size_;
    }
}