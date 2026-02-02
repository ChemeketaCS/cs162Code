#include <vector>
#include <string>

// Converts the vector to a string representation
// if start and end are provided, only that range is displayed,
//   values outside that range are replaced with '_'
template<typename T>
std::string vectorToString(const std::vector<T>& vec, 
                           size_t start = 0, size_t end = -1) {
    if (vec.empty()) {
        return "[]";
    }
    if (static_cast<int>(end) == -1) {
        end = vec.size() - 1;
    }
    std::string result = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if( i >= start && i <= end) {
            result += std::to_string(vec[i]);
        } else {
            result += "_";
        }
        if (i < vec.size() - 1)
          result += ", ";
    }
    result += "]";
    return result;
}