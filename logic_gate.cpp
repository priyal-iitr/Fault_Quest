#include "logic_gate.h"

//To determine the inputs of AND gate for a known output
std::vector<int> AND(int SA, int net_in) {
    std::vector<int> in(2, 0);
    if (SA == 0) {
        in[0] = 1;
        in[1] = 1;
    } else {
        //To have a specific order of inputs
        if (net_in == 1) {
            in[0] = 0;
            in[1] = 1;
        } else {
            in[0] = 1;
            in[1] = 0;
        }
    }
    return in;
}

//To determine the inputs of OR gate for a known output
std::vector<int> OR(int SA, int net_in) {
    std::vector<int> in(2, 0);
    if (SA == 1) {
        in[0] = 0;
        in[1] = 0;
    } else {
        if (net_in == 1) {
            in[0] = 1;
            in[1] = 0;
        } else {
            in[0] = 0;
            in[1] = 1;
        }
    }
    return in;
}

//To determine the inputs of XOR gate for a known output
std::vector<int> XOR(int SA, int net_in) {
    std::vector<int> in(2, 0);
    if (SA == 0) {
        in[0] = 1;
        in[1] = 1;
    }
    return in;
}

//To determine the inputs of INV gate for a known output
int INV(int SA, int net_in) {
    int in = 0;
    if (SA == 0) {
        in = 0;
    }
    return in;
}
