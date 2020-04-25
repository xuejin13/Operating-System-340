

#include "hardDD.h"

using namespace std;

namespace HDD_NS{
    Process HDD::GetHDDProcess(){
        return run_io_process_;
    }

    void HDD::SetHDDProcess(Process process){
        run_io_process_ = process;
    }
}