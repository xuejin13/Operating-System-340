
#include "readyQueue.h"

// #include 

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