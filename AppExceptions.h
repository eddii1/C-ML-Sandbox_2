#ifndef MLSANDBOX_APPEXCEPTIONS_H
#define MLSANDBOX_APPEXCEPTIONS_H

#include <stdexcept>
#include <string>

class AppException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class DatasetException : public AppException {
public:
    explicit DatasetException(const std::string& message)
        : AppException("Dataset error: " + message) {}
};

class ModelException : public AppException {
public:
    explicit ModelException(const std::string& message)
        : AppException("Model error: " + message) {}
};

#endif // MLSANDBOX_APPEXCEPTIONS_H
