#include "Solver.hpp"
#include <optional>
#include <stack>
#include <utility>

Solver::Solver(int _variable_count, std::vector<Clause> _clauses) : variable_count(_variable_count), clauses(_clauses) {}

std::unordered_map<int, bool> Solver::solve() {
    std::unordered_map<int, bool> assignment_map;
    std::stack<std::pair<int, bool>> assignment_stack;

    assignment_stack.push({0, false});
    assignment_map.insert({0, false});
    while (!assignment_stack.empty()) {
        // get value at top of stack
        // for each clause, check the current partial assignment
            // if ANY are unsatisfied, then backtrack
                // pop top of stack
                // if the value was false, then push the variable with true
                // if the value was true, then the previous variable assignment is infeasible, so pop it
                // keep popping the values that are true until one is false or the stack is empty
            // if ALL are satisfied, then return the assignment
            // if ANY are unresolved, continue with loop

        auto [current_variable, current_variable_assignment] = assignment_stack.top(); 
        std::pair<int, bool> next_decision = {current_variable + 1, false};
        bool all_clauses_satisfied = true;
        for (Clause clause : clauses) {
            auto clause_eval = clause.evaluate(assignment_map);
            if (!clause_eval.has_value()) { all_clauses_satisfied = false; }
            if (clause_eval.has_value() && !clause_eval.value()) {
                all_clauses_satisfied = false;

                assignment_stack.pop();
                assignment_map.erase(current_variable);

                if (current_variable_assignment == false) {
                    next_decision = {current_variable, true};
                } else {
                    // current decision path is infeasible, keep popping until new path is found
                    while (!assignment_stack.empty() && assignment_stack.top().second == true) {
                        assignment_map.erase(assignment_stack.top().first);
                        assignment_stack.pop();
                    } 
                    if (assignment_stack.empty()) {
                        return {};
                    }
                }
                break;
            }
        }

        if (all_clauses_satisfied) {
            return assignment_map;
        } 

        assignment_stack.push(next_decision);
        assignment_map.insert(next_decision);
    }
    return {};
}
