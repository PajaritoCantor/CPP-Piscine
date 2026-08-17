#include "Inc/AAnimal.hpp"
#include "Inc/Dog.hpp"
#include "Inc/Cat.hpp"
#include "Inc/Brain.hpp"

int main()
{
    std::cout << "========== ABSTRACT CLASS TEST ==========" << std::endl;

    // UNCOMMENTING THE FOLLOWING LINE WILL CAUSE A COMPILATION ERROR
    // AAnimal* meta = new AAnimal();
    // Error: cannot allocate an object of abstract type 'AAnimal'

    std::cout << "--- Creating Dog ---" << std::endl;
    AAnimal *j = new Dog(); // Polymorphism still works perfectly

    std::cout << "\n--- Creating Cat ---" << std::endl;
    AAnimal *i = new Cat();

    std::cout << "\n--- Making Sounds ---" << std::endl;
    j->makeSound(); // Outputs the dog bark
    i->makeSound(); // Outputs the cat meow

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    delete j;
    delete i;

    std::cout << "\n========== BRAIN & DEEP COPY TEST ==========" << std::endl;

    std::cout << "--- Creating a basic Dog ---" << std::endl;
    Dog basicDog;
    // Setting ideas in the basic Dog's brain
    basicDog.getBrain()->setIdea(0, "I want a bone!");
    basicDog.getBrain()->setIdea(1, "I should bark at the mailman!");

    std::cout << "\n--- Copying Dog ---" << std::endl;
    Dog copyDog = basicDog; // Calls the copy constructor

    std::cout << "\n--- Modifying Copy's Brain ---" << std::endl;
    // Changing the first idea of the copied Dog
    copyDog.getBrain()->setIdea(0, "I want to chase a squirrel!");

    std::cout << "\n--- Checking Ideas ---" << std::endl;
    // If the deep copy works, basicDog's idea 0 should remain unchanged
    std::cout << "Basic Dog Idea 0: " << basicDog.getBrain()->getIdea(0) << std::endl; // Should be "I want a bone!"
    std::cout << "Basic Dog Idea 1: " << basicDog.getBrain()->getIdea(1) << std::endl; // Should be "I should bark..."

    // The copyDog should have its own modified idea 0, but retain the copied idea 1
    std::cout << "Copy Dog Idea 0:  " << copyDog.getBrain()->getIdea(0) << std::endl; // Should be "I want to chase a squirrel!"
    std::cout << "Copy Dog Idea 1:  " << copyDog.getBrain()->getIdea(1) << std::endl; // Inherited idea 1

    std::cout << "\n--- End of Scope (Destructors for basicDog and copyDog) ---" << std::endl;
}