#include <cassert>
#include <set>
#include <string>
#include <vector>
namespace lc0022 {
/*
 * f(1)   = ()
 * f(2)   = f(f(1)) = (())
 *        = f(1)+f(1)
 * f(n+1) = f(f(n))
 *        = f(1)+f(n)
 *        = f(2)+f(n-1)
 *        = ...
 *        = f(n)+f(1)
 */
std::set<std::string> cache[] = {
        /*0*/
        {},
        /*1*/
        {
                "()", // f(1)
        },
        /*2*/
        {
                "(())", // f(f(1))
                "()()", // f(1)+f(1)
        },
        /*3*/
        {
                "((()))", "(()())", // f(f(2))
                "()(())", "()()()", // f(1) + f(2)
                "(())()" /*, "()()()"*/, // f(2) + f(1)
        },
        /*4*/
        {},
        /*5*/
        {},
        /*6*/
        {},
        /*7*/
        {},
        /*8*/
        {},
};

static const std::set<std::string> &aux(int n) {
    const auto &ref = cache[n];
    if (!ref.empty())
        return ref;
    std::set<std::string> result;
    const auto &prev = aux(n - 1);
    for (auto &i: prev) {
        result.insert("(" + i + ")");
    }
    for (int i = 1; i < n; ++i) {
        const auto &l = cache[i];
        const auto &r = cache[n - i];
        for (auto &li: l) {
            for (auto &ri: r) {
                result.insert(li + ri);
            }
        }
    }
    cache[n] = result;
    return cache[n];
}

std::vector<std::string> generateParenthesis(int n) {
    assert(n >= 1 && n <= 8);
    auto &dedup = aux(n);
    return std::vector<std::string>{dedup.begin(), dedup.end()};
}
} // namespace lc0022

