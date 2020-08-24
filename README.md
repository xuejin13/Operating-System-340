
# Operating System Simulator

This project simulates aspects of operating system with two different priority ready queues using Round Robin, I/O device management, and memory management.

### Steps to run this project:
```
1. make clean
2. make all
3. ./start
4. Enter <long> RAM Size
5. Enter <int> # of HDD
```
### Commands:
```
- A <int>	// Ex: A 30  ; A tells the OS its a common process with a mem size 30 bytes.
- AR <int>	// Ex: AR 30 ; AR tells the OS its a real-time process with a mem size 30 bytes.
- Q		// Ex: Q     ; Q tells the OS the time slice is up and its the next process' turn.
- t		// Ex: t     ; t tells OS that the running process is done/terminating.
- d <int>	// Ex: A 30 ; A tells the os its a common process with a mem size 30 bytes
- D <int>	// Ex: A 30 ; A tells the os its a common process with a mem size 30 bytes
- S r		// Ex: A 30 ; A tells the os its a common process with a mem size 30 bytes
- S i 		// Ex: A 30 ; A tells the os its a common process with a mem size 30 bytes
- S m		// Ex: A 30 ; A tells the os its a common process with a mem size 30 bytes
```
	Then you can run commands.
	This program does not check if the numerical inputs are valid but
	it checks for correct command such as A, AR, ... 
	also checks for valid parsing.
	


