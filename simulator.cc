/*
    Xuejin Gao
    Pavel Shostak
    Operation System 340
    
    // This program simulates simulates some aspects of operating systems.
        There are two levels of ready queue : Real time and common,
        input output: first come first serve, and memory management: First Fit approach
    
*/

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <unordered_set>

#include "process.h"
#include "readyQueue.h"
#include "cpu.h"
#include "memoryMangement.h"

using namespace ProcessNS;
using namespace ReadyQueueNS;
using namespace CPU_NS;
using namespace memoryMange_NS;

vector<string> ParseString(string str){
    istringstream ss(str);
    vector<string> strArr; 
    // Traverse through all words 
    do { 
        // Read a word 
        string word; 
        ss >> word; 
        strArr.push_back(word);
        // Print the read word 
        // cout << word << endl; 
        // While there is more to read 
    } while (ss); 

    strArr.pop_back();
    return strArr;
}

void PrintError(){
    cout << "Problem with input. Please check and re-try" << endl;
}

void PrintArr(const vector<long> &arr){
    if(arr.size() == 0)
        cout << "(Empty) " << endl;
    else{
        cout << "End -> ";
        for(long i = arr.size() - 1 ; i >= 0; --i){
            cout << arr[i] << " -> ";
        }
        cout << "Front" << endl;
    }
    
}

void PrintHardDD(int label,vector<long> arr){
    // cout << "HDD #" << label << " ";
    cout << "HDD #" << label;
    if(arr.size() > 0){
        auto currently = arr[0];
        cout << " accessed by: " << currently << endl; 
        cout << "    I/O queue: ";
        if(arr.size() != 1){
            cout << "End -> ";
            for(auto i = arr.size() - 1; i > 0; --i){
                cout << arr[i] << " -> ";
            }
            cout << "Front" << endl;
        }
        else{
            cout << "(Empty)" << endl;
        }
    }
    else{
        cout << ": (Empty)" << endl;
    }
}

bool isANumber(string s){
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
}

void PrintCPUProcess(Process& cpu_process){
    if(cpu_process.GetId() == 0)
        cout << "(Empty)";
    else{
        cout << cpu_process.GetId() << " is Running";
    }
    cout << endl;
}

void PrintMemoryError(){
    cout << "    DANGER: NO SPACE IN MEMORY" << endl;
    cout << "    DANGER: NO SPACE IN MEMORY" << endl;
}

int main(){
    cout << endl;

    long ram_amt;
    int hdd_amt;
// How much RAM memory is there on the simulated computer? Your program receives the number in bytes (no kilobytes or words). I can enter any number up to 4000000000 (4 billions).
// How many hard disks does the simulated computer have? The enumeration of the hard disks starts with 0.
    cout << "How much RAM memory is there on the simulated computer?" << endl;
    cin >> ram_amt;
    cout << "How many hard disks does the simulated computer have?" << endl;
    // cin >> hdd_amt_str;
    cin >> hdd_amt;

    unordered_set<string> valid_input {"A", "AR", "Q", "t", "d", "D", "S"};
    unordered_set<string> s_inputs {"r", "i", "m"};


    //  CPU contains the running process' info
    CPUnit cpu = CPUnit();
    //  defaultEmpty is a placeholder for no process
    const Process defaultEmpty = Process();

    //  The two levels of Ready Queue
    ReadyQueue real_time_rq = ReadyQueue();
    ReadyQueue common_time_rq = ReadyQueue();

    //  The hdd
    vector<ReadyQueue> hard_disk_drive(hdd_amt);
    // ReadyQueue hard_disk_drive[1] = ReadyQueue();

    //  The RAM
    Memory ram_mem = Memory(ram_amt);

//  TEST
    // Process p1 = Process(1, 10, C);
    // Process p2 = Process(2, 50, RT);
    // Process p3 = Process(3, 10, C);
    // Process p4 = Process(4, 20, C);

    // int pos = ram_mem.HasSpace(p1);
    // if(pos != -1){
    //     ram_mem.InsertMem(p1, pos);
    // }
    // pos = ram_mem.HasSpace(p2);
    // if(pos != -1){
    //     ram_mem.InsertMem(p2, pos);
    // }
    // pos = ram_mem.HasSpace(p3);
    // if(pos != -1){
    //     ram_mem.InsertMem(p3, pos);
    // }

    // ram_mem.AddSpace(p2);
    // pos = ram_mem.HasSpace(p4);
    // if(pos != -1){
    //     ram_mem.InsertMem(p4, pos);
    // }

//  END TEST


    // vector<Process> ProcessArr;
    // int processId = 1;
    long processId = 1;

    cout << "Enter Commands" << endl << endl;
    //  The Start
    string command;
    getline(cin, command);
    while(true){
        getline(cin, command);
        //  check command if its a valid input
        vector<string> commandArr = ParseString(command);
        
        if(commandArr.size() > 0){
            string action = commandArr[0];
            if(valid_input.find(action) != valid_input.end()){
                if(action == "A"){
                    //  Insert into common q
                    Process new_common_p = Process(processId, stol(commandArr[1]), C);

                    //  Checks if memory allows process
                    // int mem_location = ram_mem.HasSpace(new_common_p);
                    long mem_location = ram_mem.HasSpace(new_common_p);

                    if(mem_location != -1){
                        ram_mem.InsertMem(new_common_p, mem_location);

                        //  Inserts into common
                        if(cpu.GetRunningProcess().GetId() == 0){
                            cpu.ChangeRunningProcess(new_common_p);
                        }
                        else{
                            common_time_rq.InsertProcess(new_common_p);
                        }
                        ++processId;
                    }
                    else{
                        PrintMemoryError();
                    }
                }
                else if(action == "AR"){
                    //  Insert into rt q
                    Process new_rt_p = Process(processId, stol(commandArr[1]), RT);
                    //  Checks if memory is full
                    // int mem_location = ram_mem.HasSpace(new_rt_p);
                    long mem_location = ram_mem.HasSpace(new_rt_p);
                    if(mem_location != -1){
                        ram_mem.InsertMem(new_rt_p, mem_location);

                        //  Insert into real time queue
                        if(cpu.GetRunningProcess().GetId() == 0){
                            cpu.ChangeRunningProcess(new_rt_p);
                        }   
                        //  Also got to preempt the common process if it is running in cpu
                        else if(cpu.GetRunningProcess().GetProcessType() == C){
                            common_time_rq.FrontInsertProcess(cpu.GetRunningProcess());
                            cpu.ChangeRunningProcess(new_rt_p);
                        }
                        else
                            real_time_rq.InsertProcess(new_rt_p);
                        ++processId;

                        // for(auto x : real_time_rq.VectorReadyQueue()){
                        //     cout << x << " ";
                        // }
                        // cout << endl;

                    }
                    else{
                        PrintMemoryError();
                    }
                }
                else if(action == "Q"){
                    //  Round Robin
                    Process cpu_process = cpu.GetRunningProcess();
                    auto process_type = cpu.GetRunningProcess().GetProcessType();
                    // auto process_type = cpu_process.GetProcessType();
                    if(process_type == RT){
                        real_time_rq.InsertProcess(cpu_process);
                        cpu.ChangeRunningProcess(real_time_rq.PopProcess());
                    }
                    else{
                        common_time_rq.InsertProcess(cpu_process);
                        cpu.ChangeRunningProcess(common_time_rq.PopProcess());
                    }
                }
                else if(action == "t"){
                    // Terminate in cpu
                    //  Delete Of RAM !!!!!!!!!!!!
                    // 
                    if(cpu.GetRunningProcess().GetId() != 0)
                        ram_mem.RemoveProcess(cpu.GetRunningProcess());

                    if(!real_time_rq.isEmpty()){
                        //  Remove process from RAM
                        // ram_mem.RemoveProcess(cpu.GetRunningProcess());
                        //  Update to next process
                        cpu.ChangeRunningProcess(real_time_rq.PopProcess());
                    }
                    else if(!common_time_rq.isEmpty()){
                        //  Remove process from RAM
                        // ram_mem.RemoveProcess(cpu.GetRunningProcess());
                        // cpu_process = common_time_rq.PopProcess();
                        cpu.ChangeRunningProcess(common_time_rq.PopProcess());
                    } 
                    else{
                        //  CPU should be empty
                        cpu.ChangeRunningProcess(defaultEmpty);
                    }
                }
                // else if(action == "d" && isANumber(commandArr[1])){
                else if(action == "d"){
                    //  one param
                    if(cpu.GetRunningProcess().GetId() != 0){
                        hard_disk_drive[stoi(commandArr[1])].InsertProcess(cpu.GetRunningProcess());
                        //  Run the process the rq or common q to the cpu
                        if(!real_time_rq.isEmpty()){
                            cpu.ChangeRunningProcess(real_time_rq.PopProcess());
                        }
                        else if(!common_time_rq.isEmpty()){
                            // cpu_process = common_time_rq.PopProcess();
                            cpu.ChangeRunningProcess(common_time_rq.PopProcess());
                        } 
                        else{
                            //  CPU should be empty
                            cpu.ChangeRunningProcess(defaultEmpty);
                        }
                    }
                }
                else if(action == "D"){
                    if(!hard_disk_drive[stoi(commandArr[1])].isEmpty()){
                        Process io_process = hard_disk_drive[stoi(commandArr[1])].PopProcess();
                        Process currProcess = cpu.GetRunningProcess();
                        ProcessType io_Type = io_process.GetProcessType();
                        ProcessType curr_type = currProcess.GetProcessType();
                        if(io_Type == RT && curr_type == RT){
                            real_time_rq.InsertProcess(io_process);
                        }
                        else if(  (io_Type == RT && (curr_type == C || curr_type == N))  ||  curr_type == N ){
                            if(curr_type != N)
                                common_time_rq.FrontInsertProcess(currProcess);
                            cpu.ChangeRunningProcess(io_process);
                        }
                        else{
                            common_time_rq.InsertProcess(io_process);
                        }
                    }
                }
                else if(action == "S" && (s_inputs.find(commandArr[1]) != s_inputs.end())){
                    string s_command = commandArr[1];
                    if(s_command == "r"){
                        cout << "CPU: ";
                        cpu.PrintRunningProcess();
                        cout << "Real-Time Queue : "; 
                        // cout << endl;
                        PrintArr(real_time_rq.VectorReadyQueue());
                        cout << "Common Queue    : "; 
                        // cout << endl;
                        PrintArr(common_time_rq.VectorReadyQueue());
                        // cout << endl;
                    }
                    else if(s_command == "i"){
                        for(int i = 0; i < hdd_amt; ++i){
                            // cout << "HDD #" << i << "           : ";
                            PrintHardDD(i, hard_disk_drive[i].VectorReadyQueue());    
                        }
                        // cout << endl;
                    }
                    else if(s_command == "m"){
                        ram_mem.PrintUsedMem();
                
                    }
                }
            }
            else{
                PrintError();
            }
        }
        else{
            PrintError();
        }

        cout << endl;

    }

   return 0;
}