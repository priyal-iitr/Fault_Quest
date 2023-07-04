#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>
#include "make_circuit.h"
#include "gate_input.h"
#include "test_generation.h"
#include "logic_gate.h"

using namespace std;

int main() {

	// Create instances of the structs
	Net* A = new Net();
	A->name = "A"; 
	A->cell_in = nullptr;
	netMap["A"]=A;
	//A->value=0;
	
	Net* B = new Net();
	B->name = "B"; 
	B->cell_in = nullptr;
	netMap["B"]=B;

	Net* C = new Net();
	C->name = "C"; 
	C->cell_in = nullptr;
	netMap["C"]=C;

	Net* D = new Net();
	D->name = "D"; 
	D->cell_in = nullptr;
	netMap["D"]=D;

	string input_file = "input.txt";
    make_circuit(input_file);
	
	netMap["Z"]->value=1;
	test_generation(netMap["Z"]);
	for(auto x:cellMap){
		cout << x.first <<": " <<x.second->type <<endl;
	}

	for(auto x:netMap){
		cout << x.first <<": " <<x.second->value <<endl;
	}
   	return 0;
}
