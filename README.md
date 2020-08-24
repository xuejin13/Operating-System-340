
# Operating System Simulator
CLI project simulates aspects of operating system with two different priority ready queues using Round Robin, I/O device management, 
and memory management using **C++**. 

#### Comments 
Inputs that are parsed incorrectly are handled however it does not **check if the numerical inputs are valid**.
	
### Steps to run this project:
```
1. make clean
2. make all
3. ./start
4. Enter <long> RAM Size
5. Enter <int> # of HDD
6. *Run commands*
```

### Commands:
```
- A <long>	// Ex: A 30  ; A tells the OS its a common process with a mem size 30 bytes.
- AR <long>	// Ex: AR 30 ; AR tells the OS its a real-time process with a mem size 30 bytes.
- Q		// Ex: Q     ; Q tells the OS the time slice is up and its the next process' turn.
- t		// Ex: t     ; t tells OS that the running process is done/terminating.
- d <int>	// Ex: d 3   ; d tells the OS the current running process is requesting the I/O device #3.
- D <int>	// Ex: D 3   ; D tells the OS process at HDD #3 is done reading/writing and ready for CPU.

// Visualizing purposes
- S r		// Ex: S r   ; S r shows the ready queues states and the process using CPU.
- S i 		// Ex: S i   ; S i shows the HDD queue.
- S m		// Ex: S m   ; S m shows the storage memory and bytes each process is taking up.
```

### Contributer: 
Xuejin Gao *https://github.com/xuejin13*
