#ifndef TEST_GENERATION_H
#define TEST_GENERATION_H

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

struct Net;
struct Cell;

extern std::unordered_map<std::string, Net*> netMap;
extern std::unordered_map<std::string, Cell*> cellMap;

void test_generation(Net* netPt);

#endif
