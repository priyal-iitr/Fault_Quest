#ifndef MAKE_CIRCUIT_H
#define MAKE_CIRCUIT_H

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

struct Net;
struct Cell;

extern std::unordered_map<std::string, Net*> netMap;
extern std::unordered_map<std::string, Cell*> cellMap;

void make_circuit(string input_file);

#endif
