#include "tester.hpp"

void print_title(std::string title, std::string subtitle)
{
	std::cout << std::endl;
  std::cout << YELLOW << title << ": " << SET << subtitle << "\n" << std::endl;
}

void print_header(std::string container_name)
{
	std::cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;
	std::cout << YELLOW << container_name << " TESTS:" << SET << " press enter to continue\n" << std::endl;
	std::cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;
}

int main()
{
	// print_header("VECTOR");
	// std::cout << std::endl;
	// while (std::cin.get() != '\n') {}
	test_vector();
	// print_header("STACK");
	// while (std::cin.get() != '\n') {}
	// test_stack();
	print_header("MAP");
	while (std::cin.get() != '\n') {}
	test_map();


	return 0;
}
