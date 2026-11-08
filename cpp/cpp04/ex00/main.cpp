#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "-------------------------------" << std::endl;

	std::cout << j->getType() << "            <- Normally expected Dog" << std::endl;
	std::cout << i->getType() << "            <- Normally expected Cat" << std::endl;
	std::cout << meta->getType() << " <- Normally expected Default Animal" << std::endl;
	std::cout << wrong_cat->getType() << "       <- Normally expected WrongCat" << std::endl;

	std::cout << std::endl;

	j->makeSound();
	i->makeSound();
	meta->makeSound();
	wrong_cat->makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete wrong_cat;

	std::cout << std::endl;

	std::cout << "-- Copy constructor --" << std::endl;
	{
		Dog dog1;
		Dog dog2(dog1);
		std::cout << dog2.getType() << std::endl;
		dog2.makeSound();
	}
	std::cout << "-------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-- Copy assignment --" << std::endl;
	{
		Cat cat1;
		Cat cat2;
		cat2 = cat1;
		std::cout << cat2.getType() << std::endl;
		cat2.makeSound();
	}
	std::cout << "-------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-- Polymorphism through Animal --" << std::endl;
	{
		Dog dog;
		const Animal& ref = dog;
		ref.makeSound();
	}
	std::cout << "-------------------------------" << std::endl;
	return (0);
}
