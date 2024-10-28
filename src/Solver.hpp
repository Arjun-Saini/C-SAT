#pragma once

#include <unordered_map>
#include <vector>

#include "Clause.hpp"

class Solver {
public:
    Solver(int _variable_count, std::vector<Clause> _clauses);

    std::unordered_map<int, bool> solve();

private:
    int variable_count;
    std::vector<Clause> clauses;
};
