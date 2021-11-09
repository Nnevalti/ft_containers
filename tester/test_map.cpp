// TEST for Map:
//	Constructors
//		default, range, copy, assignation operator
//	Accessors, iterators, getters, setters:
//		iterator, const_iterator, reverse_iterator, const_reverse_iterator, begin, end, rbegin, rend
//		size, max_size, empty
//		operator[], at
//		insert, erase, swap, clear
//    key_comp, value_comp
// find count lower_bound upper_bound equal_range


#include "tester.hpp"


void print_map(ft::map<char, int> map, std::string name)
{
  std::cout << name << ":\n";
  for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
      std::cout << (*it).first << " = " << (*it).second << ", ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void print_map(std::map<char, int> map, std::string name)
{
  std::cout << name << ":\n";
  for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
    std::cout << (*it).first << " = " << (*it).second << ", ";
  std::cout << std::endl;
  std::cout << std::endl;
}

void print_size(ft::map<char, int> map, std::string name)
{
  std::cout << name << " size: " << map.size() << ", max_size: " << map.max_size() << std::endl;
  std::cout << name << " empty() (1: true 0:false): " << map.empty() << std::endl;
  std::cout << std::endl;
}

void print_size(std::map<char, int> map, std::string name)
{
  std::cout << name << " size: " << map.size() << ", max_size: " << map.max_size() << std::endl;
  std::cout << name << " empty() (1: true 0:false): " << map.empty() << std::endl;
  std::cout << std::endl;
}

void test_map()
{
  print_title("CONSTRUCTOR", "ft::map & std::map");
  ft::map<char, int> ft_map;
  std::map<char, int> std_map;
  print_size(ft_map, "ft_map");
  print_size(std_map, "std_map");

  char c = 'a';
  for (int i = 1; i <= 13; i++, c++)
  {
    ft_map[c] = i;
    std_map[c] = i;
  }
  print_map(ft_map, "ft_map");
  print_map(std_map, "std_map");
  print_size(ft_map, "ft_map");
  print_size(std_map, "std_map");

  print_title("RANGE", "ft::map & std::map");
  ft::map<char, int> ft_map_range(ft_map.begin(), ft_map.end());
  std::map<char, int> std_map_range(std_map.begin(), std_map.end());
  print_size(ft_map_range, "ft_map_range");
  print_size(std_map_range, "std_map_range");
  print_map(ft_map_range, "ft_map_range");
  print_map(std_map_range, "std_map_range");

  print_title("COPY CONSTRUCTOR (copy of range)", "ft::map & std::map");
  ft::map<char, int> ft_map_copy(ft_map_range);
  std::map<char, int> std_map_copy(std_map_range);
  print_size(ft_map_copy, "ft_map_copy");
  print_size(std_map_copy, "std_map_copy");
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");


  print_title("ASSIGNATION OPERATOR", "ft::map & std::map");
  ft::map<char, int> ft_map_assignation;
  std::map<char, int> std_map_assignation;
  ft_map_assignation = ft_map_copy;
  std_map_assignation = std_map_copy;
  print_size(ft_map_assignation, "ft_map_assignation");
  print_size(std_map_assignation, "std_map_assignation");
  print_map(ft_map_assignation, "ft_map_assignation");
  print_map(std_map_assignation, "std_map_assignation");


  print_title("ITERATORS TESTS");
  std::cout << "ft_map (iterator): ";
  for (ft::map<char, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
    std::cout << (*it).first << " = " << (*it).second << ", ";
  std::cout << std::endl;
  std::cout << "std_map (iterator): ";
  for (std::map<char, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
    std::cout << (*it).first << " = " << (*it).second << ", ";
  std::cout << "\n" << std::endl;
  std::cout << "ft_map (const_iterator): ";
  for (ft::map<char, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); it++)
    std::cout << (*it).first << " = " << (*it).second << ", ";
  std::cout << std::endl;
  std::cout << "std_map (const_iterator): ";
  for (std::map<char, int>::const_iterator it = std_map.begin(); it != std_map.end(); it++)
    std::cout << (*it).first << " = " << (*it).second << ", ";
  std::cout << "\n" << std::endl;
  std::cout << "ft_map (reverse_iterator): ";
  for (ft::map<char, int>::reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
    std::cout << (*rit).first << " = " << (*rit).second << ", ";
  std::cout << std::endl;
  std::cout << "std_map (reverse_iterator): ";
  for (std::map<char, int>::reverse_iterator rit = std_map.rbegin(); rit != std_map.rend(); rit++)
    std::cout << (*rit).first << " = " << (*rit).second << ", ";
  std::cout << "\n" << std::endl;
  std::cout << "ft_map (const_reverse_iterator): ";
  for (ft::map<char, int>::const_reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
    std::cout << (*rit).first << " = " << (*rit).second << ", ";
  std::cout << std::endl;
  std::cout << "std_map (const_reverse_iterator): ";
  for (std::map<char, int>::const_reverse_iterator rit = std_map.rbegin(); rit != std_map.rend(); rit++)
    std::cout << (*rit).first << " = " << (*rit).second << ", ";
  std::cout << "\n" << std::endl;

  print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty");
  print_size(ft_map, "ft_map");
  print_size(std_map, "std_map");

  print_title("MAP INSERT(val)");
  for (int i = 14; i <= 19; i++, c++)
  {
    ft_map.insert(ft::make_pair(c, i));
    std_map.insert(std::make_pair(c, i));
  }
  print_map(ft_map, "ft_map");
  print_map(std_map, "std_map");
  print_size(ft_map, "ft_map");
  print_size(std_map, "std_map");

  print_title("MAP INSERT(position, val)");
  for (int i = 20; i <= 26; i++, c++)
  {
    ft_map.insert(ft::make_pair(c, i));
    std_map.insert(std::make_pair(c, i));
  }
  print_map(ft_map, "ft_map");
  print_map(std_map, "std_map");
  print_size(ft_map, "ft_map");
  print_size(std_map, "std_map");

  print_title("MAP INSERT(first, last)", "map -> map_copy");
  print_title("BEFORE INSERT");
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");

  print_title("AFTER INSERT");
  ft_map_copy.insert(ft_map.begin(), ft_map.end());
  std_map_copy.insert(std_map.begin(), std_map.end());
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");
  print_size(ft_map_copy, "ft_map_copy");
  print_size(std_map_copy, "std_map_copy");

  print_title("MAP ERASE(position)", "erasing first half of map_copy");
  ft::map<char, int>::iterator ft_it_half = ft_map_copy.find('n');
  std::map<char, int>::iterator std_it_half = std_map_copy.find('n');
  for (ft::map<char, int>::iterator it = ft_map_copy.begin(); it != ft_it_half; it++)
    ft_map_copy.erase(it);
  for (std::map<char, int>::iterator it = std_map_copy.begin(); it != std_it_half; it++)
    std_map_copy.erase(it);
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");
  print_size(ft_map_copy, "ft_map_copy");
  print_size(std_map_copy, "std_map_copy");

  print_title("MAP ERASE(key)", "erasing another half of map_copy");
  c = 'n';
  for (int i = 0; i < 6; i++, c++)
  {
    ft_map_copy.erase(c);
    std_map_copy.erase(c);
  }
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");
  print_size(ft_map_copy, "ft_map_copy");
  print_size(std_map_copy, "std_map_copy");

  print_title("MAP ERASE(first, last)", "finishing the job map_copy");
  ft_map_copy.erase(ft_map_copy.begin(), ft_map_copy.end());
  std_map_copy.erase(std_map_copy.begin(), std_map_copy.end());
  print_map(ft_map_copy, "ft_map_copy");
  print_map(std_map_copy, "std_map_copy");
  print_size(ft_map_copy, "ft_map_copy");
  print_size(std_map_copy, "std_map_copy");

  print_title("MAP SWAP() (MEMBER)", "swaping map_range and map_copy");
  print_title("BEFORE SWAP");
  print_map(ft_map_range, "ft_map_range");
  print_map(ft_map_copy, "ft_map_copy");
  ft_map_range.swap(ft_map_copy);
  print_title("AFTER SWAP");
  print_map(ft_map_range, "ft_map_range");
  print_map(ft_map_copy, "ft_map_copy");

  print_title("MAP CLEAR", "clearing map copy again");
  print_title("BEFORE");
  print_map(ft_map_copy, "ft_map_copy");
  print_size(ft_map_copy, "ft_map_copy");
  ft_map_copy.clear();
  print_title("AFTER");
  print_map(ft_map_copy, "ft_map_copy");
  print_size(ft_map_copy, "ft_map_copy");

  print_title("MAP FIND(key) const and non_const");
  ft::map<char, int>::iterator find_a = ft_map.find('a');
  ft::map<char, int>::const_iterator find_z = ft_map.find('z');
  std::cout << "find('a'): " << (*find_a).first << " = " << (*find_a).second << '\n';
  std::cout << "find('z'): " << (*find_z).first << " = " << (*find_z).second << '\n';

  print_title("MAP COUNT(key)");
  std::cout << 'a';
  if (ft_map.count('a') > 0)
    std::cout << " is an element of ft_map.\n";
  else
    std::cout << " is not an element of ft_map.\n";
  std::cout << '1';
  if (ft_map.count('1') > 0)
    std::cout << " is an element of ft_map.\n";
  else
    std::cout << " is not an element of ft_map.\n";

  print_title("MAP LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g");
  ft::map<char,int>::iterator itlow = ft_map.lower_bound('b');
  ft::map<char,int>::iterator itup = ft_map.upper_bound('g');
  ft_map.erase(itlow, itup);
  print_map(ft_map, "ft_map");
  print_size(ft_map, "ft_map");

  print_title("MAP EQUAL_RANGE", "for h");
  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = ft_map.equal_range('h');
  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';
  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  print_title("MAP KEY_COMP AND VALUE_COMP", "display everything lower than m");
  ft::map<char,int>::key_compare mycomp = ft_map.key_comp();

  char highest_key = 'm';
  ft::pair<char,int> highest = *ft_map.find('m');

  ft::map<char,int>::iterator it = ft_map.begin();
  while (ft_map.value_comp()(*it, highest) \
    && mycomp((*it).first, highest_key))
  {
    std::cout << it->first << " => " << it->second << '\n';
    it++;
  }
}
