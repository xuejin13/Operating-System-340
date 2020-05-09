/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include "readyQueue.h"


using namespace std;
using namespace ProcessNS;
using namespace ReadyQueueNS;

namespace HDD_NS{
    class HDD : public ReadyQueue{
        private:
            Process run_io_process_;
        public:
            Process GetHDDProcess();
            void SetHDDProcess(Process process);
    };
}