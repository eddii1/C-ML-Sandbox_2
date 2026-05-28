#ifndef MLSANDBOX_HISTORY_H
#define MLSANDBOX_HISTORY_H

#include <cstddef>
#include <vector>

template <typename T>
class History {
    std::vector<T> values;

public:
    void add(const T& value) {
        values.push_back(value);
    }

    std::size_t size() const {
        return values.size();
    }

    const std::vector<T>& all() const {
        return values;
    }
};

#endif // MLSANDBOX_HISTORY_H
