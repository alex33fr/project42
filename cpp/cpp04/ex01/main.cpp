#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const int n = 4;
	Animal* animals[n];

	if (n < 0 || n > 10000)
	{
		std::cout << "Error 1: N is too big" << std::endl;
		return (1);
	}
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < n; i++)
		delete animals[i];


	std::cout << "-------- Copy ---------" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "eat");
	Dog b(a);
	b.getBrain()->setIdea(0, "sleep");
	std::cout << "a: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "------ Dog operator = ------" << std::endl;
	{
		Dog c;
		c.getBrain()->setIdea(0, "play");
		Dog d;
		d = c;
		d.getBrain()->setIdea(0, "run");
		std::cout << "c: " << c.getBrain()->getIdea(0) << std::endl;
		std::cout << "d: " << d.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "------ Cat operator = ------" << std::endl;
	{
		Cat e;
		e.getBrain()->setIdea(0, "hunt");
		Cat f;
		f = e;
		f.getBrain()->setIdea(0, "sleep");
		std::cout << "e: " << e.getBrain()->getIdea(0) << std::endl;
		std::cout << "f: " << f.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "------ Brain limits ------" << std::endl;
	{
		Dog g;

		g.getBrain()->setIdea(0, "first"); 
		g.getBrain()->setIdea(99, "last"); 
		g.getBrain()->setIdea(150, "too far");
		g.getBrain()->setIdea(-1, "negative"); 

		std::cout << "0: "   << g.getBrain()->getIdea(0) << std::endl;
		std::cout << "99: "  << g.getBrain()->getIdea(99) << std::endl;
		std::cout << "150: " << g.getBrain()->getIdea(150);
		std::cout << "-1: "  << g.getBrain()->getIdea(-1);
		std::cout << "----------------------" << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	return (0);
}
