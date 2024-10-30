#include <iostream>

/**
 * @brief Takes the argument vector and changes to UPPER.
 * @return 1 for failure, 0 for success.
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE*" << std::endl;
        return (1);
    }
    for(int i = 1; i < argc; i ++)
    {
        for (int j = 0; argv[i][j]; j ++)
            std::cout << (char)std::toupper(argv[i][j]);
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
