#ifndef LITERALS_H
#define LITERALS_H
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

static std::vector<int> operator""_VI(const char *s, size_t) {
    std::vector<int> result;
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

