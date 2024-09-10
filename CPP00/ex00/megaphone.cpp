#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{  
    int x;
    
    if (argc == 1)
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (x = 1; argv[x]; x++)
        {
            int i;
            for (i = 0; argv[x][i]; i++)
                std::cout << (char)std::toupper(argv[x][i]);
        }
    }
    std::cout << std::endl;
    return (0);
}
