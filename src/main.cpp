#include <cassert>
#include <iostream>
#include <set>

#include "Clause.hpp"
#include "Literal.hpp"
#include "Solver.hpp"
#include "Parser.hpp"

int main(int argc, char **argv) {
    int variable_count = 3;
    std::vector<Clause> clause_set;

    clause_set.push_back(Clause({Literal(0, false)}));
    clause_set.push_back(Clause({Literal(1, true)}));
    clause_set.push_back(Clause({Literal(2, false)}));

    Solver s = Solver(variable_count, clause_set);
    auto a = s.solve();
    for (auto [k, v] : a) {
        std::cout << "v: " << k << " -> " << v << std::endl;
    }
}
