#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap Statham("Statham");
 
  // for (int i = 0; i < 15; i++) Statham.attack("The_Rock");

  // for (int i = 0; i < 3; i++)  Statham.takeDamage(5);

  // for (int i = 0; i < 3; i++)  Statham.beRepaired(5);

  for (int i = 0; i < 1; i++)  Statham.takeDamage(5);  for (int i = 0; i < 3; i++)  Statham.beRepaired(3); for (int i = 0; i < 4; i++)  Statham.takeDamage(5);
  return (0);

}