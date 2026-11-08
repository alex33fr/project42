#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const int n = 4;
	Animal* animals[n];

	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < n; i++)
		delete animals[i];

	std::cout << "===== deep copy =====" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "eat");
	Dog b(a);
	b.getBrain()->setIdea(0, "sleep");
	std::cout << "a: " << a.getBrain()->getIdea(0) << std::endl; // expected?

	return 0;
}
