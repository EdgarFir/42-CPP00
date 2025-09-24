#include <iostream>
#include <cctype>

std::string to_uppercase(char *str) {
    std::string uppercaseString = str;

    for (size_t i = 0; i < uppercaseString.length(); i++)
        uppercaseString[i] = toupper(uppercaseString[i]);
    
    return uppercaseString;
}

int main (int argc, char **argv) {
    
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
            std::cout << to_uppercase(argv[i]);
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}