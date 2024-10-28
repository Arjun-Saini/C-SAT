#pragma once

#include <vector>
#include <fstream>

#include "Clause.hpp"

class Parser {
public:
    Parser(std::string path);

    bool read_contents();

    std::vector<int> get_variables();
    std::vector<Clause> get_clauses();

private:
    std::ifstream file;
    std::vector<int> variables;
    std::vector<Clause> clauses;
};
