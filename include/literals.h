#ifndef LITERALS_H
#define LITERALS_H
#include <algorithm>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;

template<typename E>
static bool unordered_eq(const std::vector<std::vector<E>> &v1, const std::vector<std::vector<E>> &v2) {
    if (v1.size() != v2.size())
        return false;
    auto s1(v1), s2(v2);
    for (size_t i = 0; i < v1.size(); ++i) {
        std::sort(s1[i].begin(), s1[i].end());
        std::sort(s2[i].begin(), s2[i].end());
    }
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}

static std::vector<int> operator""_VI(const char *s, size_t) {
    std::vector<int> result;
    json data = json::parse(s);
    for (const auto &i: data) {
        result.push_back(i);
    }
    return result;
}

static std::vector<std::string> operator""_VS(const char *s, size_t) {
    std::vector<std::string> result;
    json data = json::parse(s);
    for (const auto &i: data) {
        result.push_back(i);
    }
    return result;
}

static std::vector<std::vector<int>> operator""_VVI(const char *s, size_t) {
    std::vector<std::vector<int>> result;
    json data = json::parse(s);
    for (const auto &i: data) {
        std::vector<int> in;
        for (const auto &j: i) {
            in.push_back(j);
        }
        result.push_back(in);
    }
    return result;
}

#endif

