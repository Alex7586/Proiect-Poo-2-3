#include "include/Meniu.h"
#include "include/Shape.h"
#include "include/Factory.h"
#include <vector>

int main()
{   
    std::unique_ptr<Creator2d> C = std::make_unique<CreatorCerc>();
    Creator2d* T = new CreatorTriunghi;
    Creator2d* R = new CreatorRectangle;
    
    std::vector<Shape<double>*> shapes;


    shapes.push_back(C->FactoryMethod(-10, -10, 30));
    shapes.push_back(R->FactoryMethod(2, 4));
    shapes.push_back(T->FactoryMethod({ std::make_pair(0,0),
        std::make_pair(2,3),
        std::make_pair(10,0) }));

    Cuboid cub(2, 2, 2);
    TwoDimensionalShape s({ std::make_pair(-5,-12), 
        std::make_pair(2,3), 
        std::make_pair(10,5), 
        std::make_pair(5,-10) });

    shapes.push_back(&cub);
    shapes.push_back(&s);

    Meniu* meniu = Meniu::GetInstance();
    while (!meniu->Close()) {
        meniu->Afisare();
        meniu->Alegere(shapes);
    }

    return 0;
}