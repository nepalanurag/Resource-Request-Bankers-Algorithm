# Banker's Algorithm

An implementation of Dijkstra's Banker's algorithm for resource allocation and deadlock avoidance, written in C.

The program simulates resource requests from several processes and grants a request only when the system stays in a safe state.

## Files

- `OS_Proj.c` - the implementation
- `OS la2 Report.docx`, `21OSLA10_TEAM_DAZE_PROJECT.pdf` - the project report

## Running

```bash
gcc OS_Proj.c -o banker
./banker
```

You enter the number of processes and resources, the allocation matrix, then either the max matrix or the need matrix, then the available resources. The program prints the matrices it computed and whether a safe sequence exists. If one does, you can then simulate resource requests: a request is granted only if the system stays safe afterwards.

## Sample run

Real output using the textbook 5-process, 3-resource example:

```
 Enter total no. of processes: 5
 Enter total no. of resources: 3
 Enter the Allocation Matrix:
Do you want to enter the max matrix or the need matrix?: max
Enter the Maximum Matrix:
Enter the Available resources:
 Allocation Matrix:
0	1	0	
2	0	0	
3	0	2	
2	1	1	
0	0	2	
 Maximum Matrix:
7	5	3	
3	2	2	
9	0	2	
2	2	2	
4	3	3	
 Need Matrix:
7	4	3	
1	2	2	
6	0	0	
0	1	1	
4	3	1	
 A safe sequence has been detected
Do you want to request for any processes(YES||NO): yes
Enter your request:
 Enter Process no.: 2
 Enter request :- 1 0 2

 A safe sequence has been detected.No Deadlocks
P1--->P3--->P4--->P0--->P2
```

A request that would leave the system unsafe is denied instead of granted:

```
Do you want to request for any processes(YES||NO): yes
Enter your request:
 Enter Process no.: 1
 Enter request :- 3 3 0

 Request denied: granting it would leave the system in an unsafe state.
```
