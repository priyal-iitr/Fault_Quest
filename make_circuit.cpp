#include "make_circuit.h"
#include "gate_input.h"
#include "test_generation.h"
#include "logic_gate.h" 

using namespace std;

//Unordered map between name and pointer of Net 
std::unordered_map<std::string, Net*> netMap;

//Unordered map between name and pointer of Cell
std::unordered_map<std::string, Cell*> cellMap;

void make_circuit(string input_file) {

	std::ifstream file(input_file);  // Open the input file
    	if (!file) {
        	std::cout << "Failed to open the file." << std::endl;
        	return ;
    	}

    	string line;
	    int i=0;
    	while (std::getline(file, line)) {
        	istringstream iss(line);
        	string leftSide, rightSide;
		
        	if (getline(iss, leftSide, '=') && getline(iss, rightSide)) {
            		// Strings on both sides of the equal sign extracted successfully
            		//cout << "Left side: " << leftSide << std::endl;
            		//cout << "Right side: ";

            		istringstream rightIss(rightSide);
            		vector<string> tokens;
            		string token;

					leftSide.erase(std::remove_if(leftSide.begin(), leftSide.end(), ::isspace),leftSide.end());  //remove whitespace

            		while (rightIss >> token) {
                		tokens.push_back(token);
            		}
			
			string cell_name_gen = "cell"+to_string(i);
			i++;
			
			//Make call pointer , new cell
			Cell* cellPtr = new Cell();

			//make structs when length is 2
			if(tokens.size()==2){
				Net* netPtr = netMap[tokens[1]];

				if(tokens[0]=="~"){
					cellPtr->name=cell_name_gen;
					cellMap[cell_name_gen]=cellPtr;
					cellPtr->type = "INV";
					cellPtr->net_in_1 = netPtr;
					netPtr->cell_out.push_back(cellPtr);
				}
			}	
			
			//make structs when length is 3
			if(tokens.size()==3){
				//cout << tokens[0]<<" "<<tokens[2];	
				Net* netPtr1 = netMap[tokens[0]];
				Net* netPtr2 = netMap[tokens[2]];
				
				cellPtr->name=cell_name_gen;
				cellMap[cell_name_gen]=cellPtr;
				cellPtr->net_in_1 = netPtr1;
				cellPtr->net_in_2 = netPtr2;
				netPtr1->cell_out.push_back(cellPtr);
				netPtr2->cell_out.push_back(cellPtr);

				if(tokens[1]=="&"){
					cellPtr->type = "AND";
				} else if (tokens[1]=="|"){
					cellPtr->type = "OR";
				} else{
					cellPtr->type = "XOR";
				}
			}

			//Processing leftSide , making new net 
			Net* netPtr = new Net();
			netPtr->name=leftSide;
			netMap[leftSide]=netPtr;
			netPtr->cell_in=cellPtr;
			//cout<<"netPtr->cell_in"<<netPtr->name<<netPtr->cell_in->name;
			cellPtr->net_out=netPtr;
            		
        	} else {
            		// Failed to extract both sides
            		cout << "Invalid line: " << line << endl;
        	}
    	}

    	file.close();  // Close the file
    	return ;	
}

