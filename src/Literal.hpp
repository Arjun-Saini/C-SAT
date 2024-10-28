#pragma once

struct Literal {
    Literal(int _variable, bool _positive) : variable(_variable), positive(_positive) {};

    int variable;
    bool positive;

    bool operator<(const Literal& rhs) const { return variable < rhs.variable; }
};
