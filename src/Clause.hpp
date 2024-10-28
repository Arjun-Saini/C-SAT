#pragma once

#include <optional>
#include <unordered_map>
#include <set>

#include "Literal.hpp"

class Clause {
public:
    Clause(std::set<Literal> _literals);

    std::optional<bool> evaluate(std::unordered_map<int, bool>& assignments);

private:
    std::set<Literal> literals;
};
