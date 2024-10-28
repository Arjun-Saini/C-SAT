#include "Clause.hpp"
#include <optional>

Clause::Clause(std::set<Literal> _literals) : literals(_literals) {}

std::optional<bool> Clause::evaluate(std::unordered_map<int, bool>& assignments) {
    bool all_vars_assigned = true;
    for (Literal lit : literals) {
        if (assignments.contains(lit.variable)) {
            if (assignments[lit.variable] == lit.positive) {
                return true;
            }
        } else {
            all_vars_assigned = false;
        }
    }
    return all_vars_assigned ? std::optional(false) : std::nullopt;
};
