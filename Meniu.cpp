#include "../include/Meniu.h"

void Meniu::Afisare() {
    std::cout << "\n\n----------------------Geometry Calculator----------------------\n";
    std::cout << "\tWhat do you want to do? (choose a number)\n";
    std::cout << "\t\t[1] Show in console all of your shapes\n";
    std::cout << "\t\t[2] Show in window your 2d shapes\n";
    std::cout << "\t\t[3] Calculate the area of a 2D shape\n";
    std::cout << "\t\t[4] Calculate the perimeter of a 2D shape\n";
    std::cout << "\t\t[5] Calculate the surface area of a 3D shape\n";
    std::cout << "\t\t[6] Calculate the sum of edges of a 3D shape\n";
    std::cout << "\t\t[7] Determine the volume of a 3D shape\n";
    std::cout << "\t\t[8] Determine the distance between 2 points in 2D\n";
    std::cout << "\t\t[9] Determine the distance between 2 points in 3D\n";
    std::cout << "\t\t[10] Close\n";
}

void Meniu::Alegere() {
    int choice;
    std::cin >> choice;
    switch (choice) {
    case DISPLAY:
        display(shapes);
        break;
    case VISUAL_DISPLAY:
        displayVisual(shapes);
        break;
    case AREA_2D:
        area2d();
        break;
    case PERIMETER_2D:
        perimeter2d();
        break;
    case SURFACE_AREA:
        surfaceArea();
        break;
    case PERIMETER_3D:
        perimeter3d();
        break;
    case VOLUME:
        volume();
        break;
    case DISTANCE_2D:
        distance2d();
        break;
    case DISTANCE_3D:
        distance3d();
        break;
    case CLOSE:
        ok = false;
        break;
    }
}