#include "gate_input.h"

using namespace std;

//Gate wise Input detection 
void get_in(Cell* cellPt){
	
  //If the pointer doesn't point to any of the four gates then return
	if(cellPt==nullptr){
		return;
	}
  
  //Input detection for AND gate  
	if(cellPt->type=="AND"){
		if(cellPt->net_out->value==1){
			cellPt->net_in_1->value=1;
			cellPt->net_in_2->value=1;
		} else {
			if(cellPt->net_in_1->value==-1 && cellPt->net_in_2->value!=-1){
				cellPt->net_in_1->value=0;
			} else if(cellPt->net_in_1->value!=-1 && cellPt->net_in_2->value==-1){
				cellPt->net_in_2->value=0;
			} else{
				cellPt->net_in_1->value=0;
				cellPt->net_in_2->value=0;
			}
		}
	}

  //Input detection for OR gate  
	if(cellPt->type=="OR"){
		if(cellPt->net_out->value==0){
			cellPt->net_in_1->value=0;
			cellPt->net_in_2->value=0;
			
		} else {
			if(cellPt->net_in_1->value==-1 && cellPt->net_in_2->value!=-1){
				cellPt->net_in_1->value=1;
			} else if(cellPt->net_in_1->value!=-1 && cellPt->net_in_2->value==-1){
				cellPt->net_in_2->value=1;
			} else{
				cellPt->net_in_1->value=1;
				cellPt->net_in_2->value=1;
			}
			
		}
	}

  //Input detection for XOR gate  
	if(cellPt->type=="XOR"){
		if(cellPt->net_in_1->value==-1 && cellPt->net_in_2->value!=-1){
			cellPt->net_in_1->value=cellPt->net_in_2->value^cellPt->net_out->value;
		} else if(cellPt->net_in_1->value!=-1 && cellPt->net_in_2->value==-1) {
			cellPt->net_in_2->value=cellPt->net_in_1->value^cellPt->net_out->value;
		} else {
			if (cellPt->net_out->value==0){
				cellPt->net_in_2->value=1;
				cellPt->net_in_1->value=1;
			} else {
				cellPt->net_in_2->value=0;
				cellPt->net_in_1->value=1;
			}
		}
	}

  //Input detection for INV gate 
	if(cellPt->type=="INV"){
		if(cellPt->net_out->value==0){
			cellPt->net_in_1->value=1;
		} else {
			cellPt->net_in_1->value=0;
		}
	}
}

