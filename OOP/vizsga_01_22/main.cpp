#include <iostream>

// a megoldott plusz feladatoknal allitsa 1-re a megfelelo pelda kodreszek bekapcsolasahoz
#define PLUS1 0
#define PLUS3 0

// adjon hozza tovabbi include-okat, ha kell
#include "vehicles.h"
#include "parts.h"

int main()
{
    // Vehicle v;
	// absztrakt osztaly, nem megy!!

	Vehicle* c1 = new Car("Oliver's Ferrari");
    Vehicle* c2 = new Car("Erno's Porsche");
    Vehicle* c3 = new Car("Adam's Mercedes");
    Vehicle* mb1 = new MotorBike("Mate's Harley");

	c1->addPart(new Part("Air conditioner", 2));
    c2->addPart(new Part("Engine", 6));
    c3->addPart(new Part("Piston", 7));
    c3->addPart(new Part("Spark plug", 3));

	VehiclePark vehiclepark;
	vehiclepark.addVehicle(c1);
	vehiclepark.addVehicle(c2);

    vehiclepark.amortize();
    std::cout << "After 1 year:\n";
    vehiclepark.printVehicles();

	vehiclepark.addVehicle(c3);
	vehiclepark.addVehicle(mb1);

    for (int y = 2; y < 10; ++y) {
        vehiclepark.amortize();
        std::cout << "After " << y << " years:\n";
        vehiclepark.printVehicles();
        if (y == 6) vehiclepark.repairCars();
        else if (y == 7) vehiclepark.repairBikes();
#if PLUS1
        else if (y == 8) vehiclepark.repairVehicles<Vehicle>();
#endif
    }

#if PLUS3
    VehiclePark parkcopy{ vehiclepark }, another = vehiclepark;
#else
    for (auto obj : { c1, c2, c3, mb1 }) delete obj;
#endif

    std::cout << "\nPress Enter to exit...\n";
    std::cin.get();

    return 0;
}

// Pelda kimenet
/*
After 1 year:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (1 years old)
        Front right wheel (1 years old)
        Rear left wheel (1 years old)
        Rear right wheel (1 years old)
        Air conditioner (1 years old)
Car named Erno's Porsche with 5 parts:
        Front left wheel (1 years old)
        Front right wheel (1 years old)
        Rear left wheel (1 years old)
        Rear right wheel (1 years old)
        Engine (1 years old)
After 2 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (2 years old)
        Front right wheel (2 years old)
        Rear left wheel (2 years old)
        Rear right wheel (2 years old)
        Air conditioner (2 years old)
Car named Erno's Porsche with 5 parts:
        Front left wheel (2 years old)
        Front right wheel (2 years old)
        Rear left wheel (2 years old)
        Rear right wheel (2 years old)
        Engine (2 years old)
Car named Adam's Mercedes with 6 parts:
        Front left wheel (1 years old)
        Front right wheel (1 years old)
        Rear left wheel (1 years old)
        Rear right wheel (1 years old)
        Piston (1 years old)
        Spark plug (1 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (1 years old)
        Rear wheel (1 years old)
After 3 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (3 years old)
        Front right wheel (3 years old)
        Rear left wheel (3 years old)
        Rear right wheel (3 years old)
        Air conditioner (3 years old) - Needs repair!
Car named Erno's Porsche with 5 parts:
        Front left wheel (3 years old)
        Front right wheel (3 years old)
        Rear left wheel (3 years old)
        Rear right wheel (3 years old)
        Engine (3 years old)
Car named Adam's Mercedes with 6 parts:
        Front left wheel (2 years old)
        Front right wheel (2 years old)
        Rear left wheel (2 years old)
        Rear right wheel (2 years old)
        Piston (2 years old)
        Spark plug (2 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (2 years old)
        Rear wheel (2 years old)
After 4 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (4 years old)
        Front right wheel (4 years old)
        Rear left wheel (4 years old)
        Rear right wheel (4 years old)
        Air conditioner (4 years old) - Needs repair!
Car named Erno's Porsche with 5 parts:
        Front left wheel (4 years old)
        Front right wheel (4 years old)
        Rear left wheel (4 years old)
        Rear right wheel (4 years old)
        Engine (4 years old)
Car named Adam's Mercedes with 6 parts:
        Front left wheel (3 years old)
        Front right wheel (3 years old)
        Rear left wheel (3 years old)
        Rear right wheel (3 years old)
        Piston (3 years old)
        Spark plug (3 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (3 years old)
        Rear wheel (3 years old)
After 5 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (5 years old)
        Front right wheel (5 years old)
        Rear left wheel (5 years old)
        Rear right wheel (5 years old)
        Air conditioner (5 years old) - Needs repair!
Car named Erno's Porsche with 5 parts:
        Front left wheel (5 years old)
        Front right wheel (5 years old)
        Rear left wheel (5 years old)
        Rear right wheel (5 years old)
        Engine (5 years old)
Car named Adam's Mercedes with 6 parts:
        Front left wheel (4 years old)
        Front right wheel (4 years old)
        Rear left wheel (4 years old)
        Rear right wheel (4 years old)
        Piston (4 years old)
        Spark plug (4 years old) - Needs repair!
Motorbike named Mate's Harley with 2 parts:
        Front wheel (4 years old)
        Rear wheel (4 years old)
After 6 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (6 years old) - Needs repair!
        Front right wheel (6 years old) - Needs repair!
        Rear left wheel (6 years old) - Needs repair!
        Rear right wheel (6 years old) - Needs repair!
        Air conditioner (6 years old) - Needs repair!
Car named Erno's Porsche with 5 parts:
        Front left wheel (6 years old) - Needs repair!
        Front right wheel (6 years old) - Needs repair!
        Rear left wheel (6 years old) - Needs repair!
        Rear right wheel (6 years old) - Needs repair!
        Engine (6 years old)
Car named Adam's Mercedes with 6 parts:
        Front left wheel (5 years old)
        Front right wheel (5 years old)
        Rear left wheel (5 years old)
        Rear right wheel (5 years old)
        Piston (5 years old)
        Spark plug (5 years old) - Needs repair!
Motorbike named Mate's Harley with 2 parts:
        Front wheel (5 years old) - Needs repair!
        Rear wheel (5 years old) - Needs repair!
After 7 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (1 years old)
        Front right wheel (1 years old)
        Rear left wheel (1 years old)
        Rear right wheel (1 years old)
        Air conditioner (1 years old)
Car named Erno's Porsche with 5 parts:
        Front left wheel (1 years old)
        Front right wheel (1 years old)
        Rear left wheel (1 years old)
        Rear right wheel (1 years old)
        Engine (7 years old) - Needs repair!
Car named Adam's Mercedes with 6 parts:
        Front left wheel (6 years old) - Needs repair!
        Front right wheel (6 years old) - Needs repair!
        Rear left wheel (6 years old) - Needs repair!
        Rear right wheel (6 years old) - Needs repair!
        Piston (6 years old)
        Spark plug (1 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (6 years old) - Needs repair!
        Rear wheel (6 years old) - Needs repair!
After 8 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (2 years old)
        Front right wheel (2 years old)
        Rear left wheel (2 years old)
        Rear right wheel (2 years old)
        Air conditioner (2 years old)
Car named Erno's Porsche with 5 parts:
        Front left wheel (2 years old)
        Front right wheel (2 years old)
        Rear left wheel (2 years old)
        Rear right wheel (2 years old)
        Engine (8 years old) - Needs repair!
Car named Adam's Mercedes with 6 parts:
        Front left wheel (7 years old) - Needs repair!
        Front right wheel (7 years old) - Needs repair!
        Rear left wheel (7 years old) - Needs repair!
        Rear right wheel (7 years old) - Needs repair!
        Piston (7 years old)
        Spark plug (2 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (1 years old)
        Rear wheel (1 years old)
After 9 years:
Vehicles in park are:
Car named Oliver's Ferrari with 5 parts:
        Front left wheel (3 years old)
        Front right wheel (3 years old)
        Rear left wheel (3 years old)
        Rear right wheel (3 years old)
        Air conditioner (3 years old) - Needs repair!
Car named Erno's Porsche with 5 parts:
        Front left wheel (3 years old)
        Front right wheel (3 years old)
        Rear left wheel (3 years old)
        Rear right wheel (3 years old)
        Engine (9 years old) - Needs repair!
Car named Adam's Mercedes with 6 parts:
        Front left wheel (8 years old) - Needs repair!
        Front right wheel (8 years old) - Needs repair!
        Rear left wheel (8 years old) - Needs repair!
        Rear right wheel (8 years old) - Needs repair!
        Piston (8 years old) - Needs repair!
        Spark plug (3 years old)
Motorbike named Mate's Harley with 2 parts:
        Front wheel (2 years old)
        Rear wheel (2 years old)

Press Enter to exit...
*/