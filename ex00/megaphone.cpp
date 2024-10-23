#include <iostream>

int	megaphone_off(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (EXIT_FAILURE);
}

int	megaphone_on(char argc, char **argv)
{
	for(int i = 1; i < argc; i ++)
	{
		for (int j = 0; argv[i][j]; j ++)
			std::cout << (char)std::toupper(argv[i][j]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	return (argc < 2 ? megaphone_off() : megaphone_on(argc, argv));
}