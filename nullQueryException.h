#include <exception>
#include <string>

class nullQueryException : public std::exception {

    // Sobrescrevendo o método what() para retornar a mensagem de erro
    const char* what() const noexcept override {
        return mensagem_.c_str();
    }

public:
    explicit nullQueryException(const char* mensagem) : mensagem_(mensagem) {}

private:
    std::string mensagem_{};

};



