#ifndef LITERALS_H
#define LITERALS_H
#include <algorithm>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;

static void sort_array(json &arr) {
    if (!arr.is_array()) {
        return;
    }
    for (auto &i: arr) {
        sort_array(i);
    }
    std::sort(arr.begin(), arr.end());
}

template<typename E>
static std::string str(const std::vector<E> &vec) {
    json j = vec;
    sort_array(j);
    return j.dump();
}

// Compact
static std::string operator""_C(const char *s, size_t) {
    json data = json::parse(s);
    return data.dump();
}

// Sort
static std::string operator""_S(const char *s, size_t) {
    json data = json::parse(s);
    sort_array(data);
    return data.dump();
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

