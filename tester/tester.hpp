#ifndef TESTER_HPP
# define TESTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "../vector.hpp"
#include <vector>
#include "../stack.hpp"
#include <stack>
#include "../map.hpp"
#include <map>

#include "../set.hpp"
#include <set>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define SET "\033[0m"

void print_title(std::string title, std::string subtitle = "");
void test_vector();
void test_stack();
void test_map();
void test_set();


#endif
