#ifndef CD1F0FFD_EBB1_4A3C_80DE_32EE0A6C6BD9
#define CD1F0FFD_EBB1_4A3C_80DE_32EE0A6C6BD9
#include "test.h"

// tuple
void test_tuple() {
  // constructor
  auto t1 = std::make_tuple(Item{1, "n1", 100}, 1, std::string{"hongkong"});  // make_tuple
  std::tuple<Item, int, std::string> t2(t1);                                  // copy
  std::tuple<std::string, int> t3;                                            // default
  std::tuple<int, int> t4 = {10, 1};                                          // implicit conversion
  std::tuple<int, int> t5{10, 1};                                             // implicit conversion
  // std::cout << std::get<int>(t4) << "\n";    // error

  auto p1 = std::make_pair("p", 1);
  std::tuple<std::string, int> t6(p1);

  // std::invaild_argument
  auto func = [](int id) -> std::tuple<double, char, std::string> {
    if (id == 0) return std::make_tuple(1.1, 'A', "Lisa");
    if (id == 1) return std::make_tuple(1.2, 'C', "Jack");
    if (id == 2) return std::make_tuple(1.3, 'B', "Rose");
    throw std::invalid_argument("id");
  };

  try {
    func(4);  // error, throw
  } catch (std::invalid_argument& e) {
    std::cerr << "Error:" << e.what() << std::endl;
  }

  // read, three ways
  auto s1 = func(0);
  std::cout << "ID(0),"
            << "GPA:" << std::get<0>(s1)
            << ","
            // << "grade:" << std::get<1>(s1) << ","
            << "grade:" << std::get<char>(s1) << ","  // only type can apply
            << "name:" << std::get<2>(s1) << "\n";

  double gpa1;
  char grade1;
  std::string name1;
  std::tie(gpa1, grade1, name1) = func(1);  // assignment
  // std::tie(gpa1, std::ignore, name1 ) = func(1);
  std::cout << "ID(1),"
            << "GPA:" << gpa1 << ","
            << "grade:" << grade1 << ","
            << "name:" << name1 << "\n";

  auto [gpa2, grade2, name2] = func(2);
  std::cout << "ID(2),"
            << "GPA:" << gpa2 << ","
            << "grade:" << grade2 << ","
            << "name:" << name2 << "\n";

  // compare
  std::cout << std::boolalpha << (func(0) < func(1)) << "\n";
  std::cout << (std::tie(gpa1, grade1, name1) < func(2)) << "\n";
  std::cout << (std::tie(grade1, gpa1, name1) < std::tie(grade2, gpa2, name2))
            << "\n";  // make an order for compare
}

#endif /* CD1F0FFD_EBB1_4A3C_80DE_32EE0A6C6BD9 */
