/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
*/

#include "memoryMangement.h"

#include <iostream>

using namespace std;
// using namespace memoryMange_NS;

// bool compareOperator(pair<int, int>& a, pair<int, int>& b){
//         return a.second + 1 <= b.first;
//     }
bool compareOperator(pair<long, long>& a, pair<long, long>& b){
        return a.second + 1 <= b.first;
    }

namespace memoryMange_NS{

    // Memory::Memory(int capacity){
    //     freeMem_.push_back(make_pair(0, capacity - 1));
    // }

    // int Memory::HasSpace(Process& process){
    //     // int memReq = process.GetMemSize();
    //     ll memReq = process.GetMemSize();

    //     for(int i = 0; i < freeMem_.size(); ++i){
    //         const auto & a_pair = freeMem_[i];
    //         if(a_pair.second - a_pair.first + 1 >= memReq)
    //             return i;
    //     }
    //     return -1;
    // }

    void Memory::CombineSpaces(){
        for(auto itr = freeMem_.end(); itr != freeMem_.begin(); --itr){
            auto itr2 = itr - 1;
            if(itr != freeMem_.end() && itr2->second + 1 == itr->first){
                itr2->second = itr->second;
                freeMem_.erase(itr);
            }
        }
    }

    // void Memory::InsertMem( Process& process_elm, int vectorPos){
    //     int startingIndex = freeMem_[vectorPos].first;
    //     int endingIndex = startingIndex + process_elm.GetMemSize();
    //     usedMem_[process_elm.GetId()] = make_pair( startingIndex, endingIndex - 1);
    //     DecreaseSpace(vectorPos, endingIndex);
    // }

    // void Memory::DecreaseSpace(int vectorPos, int newStartPos){
    //     auto & updatePair = freeMem_[vectorPos];
    //     updatePair.first = newStartPos;
    // }

    void Memory::RemoveProcess(Process process){
        long process_id = process.GetId();
        auto x = usedMem_[process_id];
        freeMem_.push_back(x);
        usedMem_.erase(process_id);
        sort(freeMem_.begin(), freeMem_.end(), compareOperator);
        CombineSpaces();
    }

    void Memory::PrintUsedMem(){
        cout << "State of Memory: " << endl;
            cout << "   Process ID | Memory Location" << endl;
        for(auto& x: usedMem_){
            cout << "            " << x.first << " | " << x.second.first << " - " << x.second.second << endl;
        }
        // cout << endl;
    }
    

    //  FIXES FOR LARGE INPUT VALUES
    Memory::Memory(long capacity){
        freeMem_.push_back(make_pair(0, capacity - 1));
    }

    long Memory::HasSpace(Process& process){
        // int memReq = process.GetMemSize();
        long memReq = process.GetMemSize();

        for(int i = 0; i < freeMem_.size(); ++i){
            const auto & a_pair = freeMem_[i];
            if(a_pair.second - a_pair.first + 1 >= memReq)
                return i;
        }
        return -1;
    }

    void Memory::InsertMem( Process& process_elm, long vectorPos){
        long startingIndex = freeMem_[vectorPos].first;
        long endingIndex = startingIndex + process_elm.GetMemSize();
        usedMem_[process_elm.GetId()] = make_pair( startingIndex, endingIndex - 1);
        DecreaseSpace(vectorPos, endingIndex);
    }

    void Memory::DecreaseSpace(long vectorPos, long newStartPos){
        auto & updatePair = freeMem_[vectorPos];
        updatePair.first = newStartPos;
    }

}




