#include "make_circuit.h"
#include "gate_input.h"
#include "test_generation.h"
#include "logic_gate.h"

using namespace std;

//This function is used to traverse the circuit from primary outputs to the primary inputs
//Recursive calls are made from the stuck at gates to the outputs as well as to the inputs to generate the test vector

void test_generation(Net* netPt){
  
  //If the net is already visited then return out of the function call
	if(netPt->visited==1){
		return;
	}

  //Base Case 
	if(netPt->cell_out.size()==0){
		netPt->visited=1;
		if(netPt->cell_in==nullptr){
			cout<<"nullptre cellin"<<endl;
		}
		else{
			get_in(netPt->cell_in);
			test_generation(netPt->cell_in->net_in_1);
			test_generation(netPt->cell_in->net_in_2);
		}
		return;
	}

  //Update visited array
	netPt->visited=1;

  //Assign the value to the gate output
	int sa_val=netPt->value;
	
	for (auto x:netPt->cell_out){

    // If gate type is inverter, simply assign the inverter logic
		if(x->type=="INV"){
			x->net_out->value=~x->net_in_1->value;
			netPt->value=INV(sa_val,1);
			get_in(x->net_in_1->cell_in);
			continue;
		}

    //If gate type is AND, make a call for the AND function for possible set of inputs for the given output
		if(x->type=="AND"){
			vector<int> in=AND(sa_val,1);
			netPt->value=in[0];
			if(x->net_in_1!=netPt){
				x->net_in_1->value=in[1];
				test_generation(x->net_in_1);
				x->net_out->value=x->net_in_1->value & sa_val;
			} else{
				x->net_in_2->value=in[1];
				test_generation(x->net_in_2);
				x->net_out->value=sa_val & x->net_in_2->value;
			}
		}

    //If gate type is XOR, make a call for the XOR function for possible set of inputs for the given output
		if(x->type=="XOR"){
			vector<int> in=XOR(sa_val,1);
			netPt->value=in[0];
			if(x->net_in_1!=netPt){
				x->net_in_1->value=in[1];
				test_generation(x->net_in_1);
				x->net_out->value=x->net_in_1->value ^ sa_val;
			} else{
				x->net_in_2->value=in[1];
				test_generation(x->net_in_2);
				x->net_out->value=sa_val ^ x->net_in_2->value;
			}
		}

    //If gate type is OR, make a call for the OR function for possible set of inputs for the given output
		if(x->type=="OR"){
			vector<int> in=OR(sa_val,1);
			netPt->value=in[0];
			if(x->net_in_1!=netPt){
				x->net_in_1->value=in[1];
				test_generation(x->net_in_1);
				x->net_out->value=x->net_in_1->value | sa_val;
			} else{
				x->net_in_2->value=in[1];
				test_generation(x->net_in_2);
				x->net_out->value=sa_val | x->net_in_2->value;
			}
		}
    
		if(netPt->cell_in==nullptr){}
		else{
			get_in(netPt->cell_in);
		}
    //Recursive Call
		test_generation(x->net_out);
	}
}
