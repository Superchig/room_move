#ifndef INVALID_KEY_HPP_
#define INVALID_KEY_HPP_

#include <stdexcept>

class InvalidKey : std::runtime_error {
public:
	InvalidKey(const std::string& what) : runtime_error(what) {};
};

#endif
