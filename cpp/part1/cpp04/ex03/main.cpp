#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "===== TESTS =====" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Undefined type ------" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		Character Toto("Toto");
		AMateria* tmp = src.createMateria("fire");	
		Toto.equip(tmp);							
		Toto.use(0, Toto);						
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Full inventory ------" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character Toto("Toto");
		Toto.equip(src.createMateria("ice"));
		Toto.equip(src.createMateria("cure"));
		Toto.equip(src.createMateria("ice"));
		Toto.equip(src.createMateria("cure"));

		AMateria* extra = src.createMateria("ice");
		Toto.equip(extra);							
		delete extra;					
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Full MateriaSource ------" << std::endl;
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());				
		src.learnMateria(NULL);						
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Invalid index ------" << std::endl;
	{
		Character Toto("Toto");
		Character bob("bob");
		Toto.equip(new Ice());

		Toto.use(-1, bob);							
		Toto.use(4, bob);							
		Toto.use(1, bob);							
		Toto.unequip(-1);							
		Toto.unequip(3);							
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Unequip ------" << std::endl;
	{
		Character Toto("Toto");
		Character bob("bob");
		AMateria* ice = new Ice();
		Toto.equip(ice);
		Toto.use(0, bob);							

		Toto.unequip(0);							
		Toto.use(0, bob);							
		delete ice;									
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Copy constructor ------" << std::endl;
	{
		Character bob("bob");
		Character Toto("Toto");
		AMateria* ice = new Ice();
		Toto.equip(ice);

		Character copy(Toto);
		Toto.unequip(0);							
		delete ice;									
		Toto.equip(new Cure());					
		copy.use(0, bob);							
		Toto.use(0, bob);						
	}
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------ Character operator = ------" << std::endl;
	{
		Character bob("bob");
		Character Toto("Toto");
		Toto.equip(new Cure());

		Character other("other");
		other.equip(new Ice());						
		other = Toto;
		std::cout << "name: " << other.getName() << std::endl;
		other.use(0, bob);							
	}
	std::cout << "----------------------" << std::endl;
	return 0;
}
