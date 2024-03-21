#include <stdexcept> 

// Clase para arrojar un mensaje de error personalizado
class StackEmpty : public std::runtime_error {
public:
    StackEmpty(const std::string& message) : std::runtime_error(message) {}
};

