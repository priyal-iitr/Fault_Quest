#ifndef LOGIC_GATE_H
#define LOGIC_GATE_H

#include <vector>

std::vector<int> AND(int SA, int net_in);
std::vector<int> OR(int SA, int net_in);
std::vector<int> XOR(int SA, int net_in);
int INV(int SA, int net_in);

#endif
