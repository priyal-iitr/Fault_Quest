# Fault_Quest
This is the README file for the project developed during the 2023 Girl Hackathon Ideathon Round. The project name is "Fault Quest" and it aims to implement an efficient and robust algorithm for Automatic Test Pattern Generation (ATPG) to identify structural faults in manufactured chips at specific nodes in a given circuit

## Github repository

```bash
https://github.com/priyal-iitr/Fault_Quest
```

## Installation
To run this project, follow the steps below:
1. Clone the repository to your local machine
```bash
git clone https://github.com/priyal-iitr/Fault_Quest
```
2. Change into the project directory
```bash
cd Fault_Quest
```
3. Compile the source files using a C++ compiler
```bash
g++ main.cpp -o main
```
Make sure you have a C++ compiler installed on your system.

## Features
- Efficient identification of structural faults in manufactured chips at specific nodes in a given circuit.
- Generating the input vector and the expected output required to identify the fault.
- Observability and Controllability on each circuit node

## Algorithm Working
The algorithm for automatic test vector generation is based on a comprehensive approach that involves tracing the entire circuit starting from the faulty node and assigning appropriate values to the nets. It follows a step-by-step procedure to identify and analyze the circuit's components. 

## Complexity Analysis
#### Time Complexity: 
In the general case, assuming the input circuit consists of N inputs and G nets and gates, the time complexity of this algorithm is `O(G)` [As every element is traversed twice, the complexity is of the order of  2*G ≡ O(G)]. This is because the algorithm makes recursive function calls for each of the G elements, resulting in a linear number of operations.

#### Space Comlexity:
The space complexity of the algorithm is `O(G)` as it utilizes vectors to store binary values for nets and to track visited cells and nets. The space requirements grow linearly with the number of nets and gates in the circuit.

## Future Work
The alternate design ideas which could be implemented are as follows:

- The design can be extended to gates with multiple inputs. To extend the code for gates with multiple inputs, minor modifications would be required in functions `gate_in()`,`AND()`,`OR()`,`XOR()`and `INV()` to handle the additional input connections.

- The design can be extended to the sequesntial logics. If memory elements were present in the input circuit, then it can be implemented using scan-chains. Minor adjustments could be made by incorporating the memory element outputs as inputs in the combinational logic, allowing for test vector generation in circuits with memory elements. 

- Testing of untestable faults can also be included in the algorithm by exploiting the observability and controllability of this algorithm.

## Contact Information
- Project Participant: Priyal Vyas
- Email Address: priyal_v@ece.iitr.ac.in
- Project Link: https://github.com/priyal-iitr/Fault_Quest
