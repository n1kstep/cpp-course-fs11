#pragma once

#include <iostream>

template <class IterType>
concept IterConcept = requires(IterType i, IterType j) {
    { ++i } -> std::same_as<IterType &>;
    { --i } -> std::same_as<IterType &>;
    { i++ } -> std::same_as<IterType>;
    { i-- } -> std::same_as<IterType>;
    i = j;
    { i == j } -> std::same_as<bool>;
    { i != j } -> std::same_as<bool>;
    { *i } -> std::same_as<std::iter_reference_t<IterType>>;
    *i = *j;
};

template<typename IterType, typename Predicate>
requires IterConcept<IterType>
IterType findIf(IterType beg, IterType end, Predicate pred) {
    IterType res = beg;
    for (; beg != end; ++beg) {
        if (pred(*beg)) {
            res = beg;
        }
    }
    return res;
}

template<typename IterType, typename Function>
requires IterConcept<IterType>
IterType minElement(IterType beg, IterType end, Function comp) {
    IterType res = beg;
    while (beg != end) {
        if (comp(*beg, *res)) {
            res = beg;
        }
        ++beg;
    }
    return res;
}

template<typename IterType, typename Function>
requires IterConcept<IterType>
IterType maxElement(IterType beg, IterType end, Function comp) {
    IterType res = beg;
    while (beg != end) {
        if (comp(*beg, *res)) {
            res = beg;
        }
        ++beg;
    }
    return res;
}


template<typename IterType, typename Operation>
requires IterConcept<IterType>
void forEach(IterType beg, IterType end, Operation op) {
    for (; beg != end; ++beg) {
        op(*beg);
    }
}

template <typename IterType, typename Function>
requires IterConcept<IterType>
void Sort(IterType beg, IterType end, Function func) {
    for (; beg != end; ++beg) {
        std::iter_swap(beg, minElement(beg, end, func));
    }
}

template<typename IterType, typename Predicate>
requires IterConcept<IterType>
IterType copyIf(IterType sourceBeg, IterType sourceEnd, IterType destBeg, Predicate pred) {
    for (; sourceBeg != sourceEnd; ++sourceBeg) {
        if (pred(*sourceBeg)) {
            *destBeg = *sourceBeg;
            ++destBeg;
        }
    }
    return destBeg;
}
