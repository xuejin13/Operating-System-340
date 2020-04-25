/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include <iostream>

#include "cpu.h"

using namespace std;
using namespace ProcessNS;

namespace CPU_NS{
    CPUnit::CPUnit(){}

    void CPUnit::PrintRunningProcess(){
        if(runningP.GetId() == 0){
            cout << "(Empty)" << endl;
        }
        else{
            cout << runningP.GetId() << endl;
        }
    }

    Process CPUnit::GetRunningProcess(){
        return runningP;
    }

    void CPUnit::ChangeRunningProcess(Process process){
        runningP = process;
    }
}
