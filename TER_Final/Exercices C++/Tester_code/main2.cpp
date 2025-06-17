#include <iostream>
int add(int x, int y)
{
return x + y;
}
double add(double x, int y)
{
return x + y;
}
double add(double x, double y)
{
return x + y;
}
int main()
{
// appel à add(int, int)
std::cout << add(1.5, 2);
std::cout << '\n';
// appel à add(double, double)
std::cout << add(1.2, 3.4);
return 0;
}