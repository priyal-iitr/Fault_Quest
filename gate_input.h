#ifndef GATE_INPUT_H
#define GATE_INPUT_H

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

// Forward declaration of struct Net
struct Net;

// Define the struct Cell
struct Cell {
    std::string type;// To identify the type of logic Gate: 'AND','OR','XOR','INV' 
    std::string name;
    Net* net_in_1;
    Net* net_in_2 = nullptr;// Initialising this net input as null as INV is a single input gate
    Net* net_out;
};

// Define the struct Net
struct Net {
    int value = -1; //Initially -1 means that no value assigned till now 
    std::string name;
    Cell* cell_in;
    std::vector<Cell*> cell_out; //Vector includes the case of fan out
    int visited = 0;//To keep track if the net has been visited or not
};

void get_in(Cell* cellPt);

#endif
