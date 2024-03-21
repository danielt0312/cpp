#include <stdexcept> 

// Clase para arrojar un mensaje de error personalizado
class DequeEmpty : public std::runtime_error {
public:
    DequeEmpty(const std::string& message) : std::runtime_error(message) {}
};

