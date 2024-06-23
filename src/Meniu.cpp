#include "../include/Meniu.h"

Meniu* Meniu::instance = nullptr;

bool Meniu::Close() {
    return closed;
}

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

void Meniu::Alegere(std::vector<Shape<double>*>& shapes) {
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
        closed = true;
        break;
    }
}

void Meniu::display(std::vector<Shape<double>*> shapes) {
    for (int i = 0; i < shapes.size(); i++) {
        std::cout << "\n--------------------------------------------\n";
        shapes[i]->Afisare();
        std::cout << "\n--------------------------------------------\n";
    }
}

void Meniu::displayVisual(std::vector<Shape<double>*> shapes) {
    int width = 500, height = 500;
    sf::RenderWindow window(sf::VideoMode(width, height), "Geometry Calculator");
    sf::View view(sf::FloatRect(-width / 2.f, -height / 2.f, width, height));
    window.setView(view);
    sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color(50, 50, 50));
    shape.setOrigin(sf::Vector2f(0.5f, 0.5f));
    shape.setPosition(sf::Vector2f(0, 0));

    sf::Vector2f oldPos;
    bool moving = false;
    float zoom = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::Resized:
            {
                sf::FloatRect visibleArea(-width / 2.f, -height / 2.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                if (event.mouseButton.button == 0) {
                    moving = true;
                    oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                break;
            }
            case sf::Event::MouseButtonReleased:
            {
                if (event.mouseButton.button == 0) {
                    moving = false;
                }
                break;
            }
            case sf::Event::MouseMoved:
            {
                if (!moving) break;

                const sf::Vector2f newPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                const sf::Vector2f deltaPos = oldPos - newPos;

                view.setCenter(view.getCenter() + deltaPos);
                window.setView(view);

                oldPos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                break;
            }
            case sf::Event::MouseWheelScrolled:
            {
                if (moving)
                    break;

                if (event.mouseWheelScroll.delta <= -1)
                    zoom = std::min(2.f, zoom + .1f);
                else if (event.mouseWheelScroll.delta >= 1)
                    zoom = std::max(.5f, zoom - .1f);

                view.setSize(window.getDefaultView().getSize());
                view.zoom(zoom);
                window.setView(view);
                break;
            }
            }
        }

        window.clear();

        //Sectiunea draw-------------
        //axele de coordonate
        for (float i = 0; i <= 10000; i++) {
            shape.setPosition(sf::Vector2f(0, i));
            window.draw(shape);
            shape.setPosition(sf::Vector2f(0, -i));
            window.draw(shape);
            shape.setPosition(sf::Vector2f(i, 0));
            window.draw(shape);
            shape.setPosition(sf::Vector2f(-i, 0));
            window.draw(shape);
        }

        for (int i = 0; i < shapes.size(); i++) {
            shapes[i]->display(window);
        }

        //---------------------------
        window.display();
    }
}

void Meniu::area2d() {
    std::cout << "\tWhich shape do you want to know the area of? (choose a number)\n";
    std::cout << "\t\t[1] Triangle\n";
    std::cout << "\t\t[2] Rectangle\n";
    std::cout << "\t\t[3] Circle\n";
    std::cout << "\t\t[4] Other\n";
    std::cout << "\tYour choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case triangle:
    {
        Triangle ABC;
        std::cin >> ABC;
        std::cout << ABC;
        std::cout << "\nArea: " << ABC.area();
        break;
    }
    case rectangle:
    {
        Rectangle ABCD;
        std::cin >> ABCD;
        std::cout << ABCD;
        std::cout << "\nArea: " << ABCD.area();
        break;
    }
    case circle:
    {
        Circle cerc;
        std::cin >> cerc;
        std::cout << cerc;
        std::cout << "\nArea: " << cerc.area();
        break;
    }
    case other2D:
    {
        TwoDimensionalShape polygon;
        std::cin >> polygon;
        std::cout << polygon;
        std::cout << "\nArea: " << polygon.area();
        break;
    }
    }
    std::cout << '\n';
}

void Meniu::perimeter2d() {
    std::cout << "\tWhich shape do you want to know the perimeter of? (choose a number)\n";
    std::cout << "\t\t[1] Triangle\n";
    std::cout << "\t\t[2] Rectangle\n";
    std::cout << "\t\t[3] Circle\n";
    std::cout << "\t\t[4] Other\n";
    std::cout << "\tYour choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case triangle:
    {
        Triangle ABC;
        std::cin >> ABC;
        std::cout << ABC;
        std::cout << "\nPerimeter: " << ABC.perimeter();
        break;
    }
    case rectangle:
    {
        Rectangle ABCD;
        std::cin >> ABCD;
        std::cout << ABCD;
        std::cout << "\nPerimeter: " << ABCD.perimeter();
        break;
    }
    case circle:
    {
        Circle cerc;
        std::cin >> cerc;
        std::cout << cerc;
        std::cout << "\nPerimeter: " << cerc.perimeter();
        break;
    }
    case other2D:
    {
        TwoDimensionalShape polygon;
        std::cin >> polygon;
        std::cout << polygon;
        std::cout << "\nPerimeter: " << polygon.perimeter();
        break;
    }
    }
    std::cout << '\n';
}

void Meniu::surfaceArea() {
    std::cout << "\tWhich shape do you want to know the surface area of? (choose a number)\n";
    std::cout << "\t\t[1] Cuboid\n";
    std::cout << "\t\t[2] Cylinder\n";
    std::cout << "\t\t[3] Cone\n";
    std::cout << "\t\t[4] Sphere\n";
    std::cout << "\t\t[5] Other\n";
    std::cout << "\tYour choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case cuboid:
    {
        Cuboid cube;
        std::cin >> cube;
        std::cout << cube;
        std::cout << "\nSurface area is: " << cube.area();
        break;
    }
    case cylinder:
    {
        Cylinder cil;
        std::cin >> cil;
        std::cout << cil;
        std::cout << "\nSurface area is: " << cil.area();
        break;
    }
    case cone:
    {
        Cone con;
        std::cin >> con;
        std::cout << con;
        std::cout << "\nSurface area is: " << con.area();
        break;
    }
    case sphere:
    {
        Sphere sfer;
        std::cin >> sfer;
        std::cout << sfer;
        std::cout << "\nSurface area is: " << sfer.area();
        break;
    }
    case other3d:
    {
        ThreeDimensionalShape sha;
        std::cin >> sha;
        std::cout << sha;
        std::cout << "\nSurface area is: " << sha.area();
        break;
    }
    }
}

void Meniu::perimeter3d() {
    std::cout << "\tWhich shape do you want to know the perimeter of? (choose a number)\n";
    std::cout << "\t\t[1] Cuboid\n";
    std::cout << "\t\t[2] Cylinder\n";
    std::cout << "\t\t[3] Cone\n";
    std::cout << "\t\t[4] Sphere\n";
    std::cout << "\t\t[5] Other\n";
    std::cout << "\tYour choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case cuboid:
    {
        Cuboid cube;
        std::cin >> cube;
        std::cout << cube;
        std::cout << "\nPerimeter is: " << cube.perimeter();
        break;
    }
    case cylinder:
    {
        Cylinder cil;
        std::cin >> cil;
        std::cout << cil;
        std::cout << "\nPerimeter is: " << cil.perimeter();
        break;
    }
    case cone:
    {
        Cone con;
        std::cin >> con;
        std::cout << con;
        std::cout << "\nPerimeter is: " << con.perimeter();
        break;
    }
    case sphere:
    {
        std::cout << "\n The sphere does not have a peremiter :)";
        break;
    }
    case other3d:
    {
        ThreeDimensionalShape sha;
        std::cin >> sha;
        std::cout << sha;
        std::cout << "\nPerimeter is: " << sha.perimeter();
        break;
    }
    }
}

void Meniu::volume() {
    std::cout << "\tWhich shape do you want to know the surface area of? (choose a number)\n";
    std::cout << "\t\t[1] Cuboid\n";
    std::cout << "\t\t[2] Cylinder\n";
    std::cout << "\t\t[3] Cone\n";
    std::cout << "\t\t[4] Sphere\n";
    std::cout << "\t\t[5] Other\n";
    std::cout << "\tYour choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case cuboid:
    {
        Cuboid cube;
        std::cin >> cube;
        std::cout << cube;
        std::cout << "\nVolume is: " << cube.volume();
        break;
    }
    case cylinder:
    {
        Cylinder cil;
        std::cin >> cil;
        std::cout << cil;
        std::cout << "\nVolume is: " << cil.volume();
        break;
    }
    case cone:
    {
        Cone con;
        std::cin >> con;
        std::cout << con;
        std::cout << "\nVolume is: " << con.volume();
        break;
    }
    case sphere:
    {
        Sphere sfer;
        std::cin >> sfer;
        std::cout << sfer;
        std::cout << "\nVolume is: " << sfer.volume();
        break;
    }
    case other3d:
    {
        std::cout << "\nIs hard to determine the volume of an irregular shape";
        break;
    }
    }
}

void Meniu::distance2d() {
    std::pair<double, double> A, B;
    std::cout << "\nPrimul punct:\n";
    std::cout << "xA: ";
    std::cin >> A.first;
    std::cout << "yA: ";
    std::cin >> A.second;
    std::cout << "\nAl doilea punct:\n";
    std::cout << "xB: ";
    std::cin >> B.first;
    std::cout << "yB: ";
    std::cin >> B.second;
    std::cout << "\nDistanta dintre punctele A si B: ";
    std::cout << TwoDimensionalShape::getDistance(A, B);
}

void Meniu::distance3d() {
    std::tuple<double, double, double> A, B;
    std::cout << "\nPrimul punct:\n";
    std::cout << "xA: ";
    std::cin >> std::get<0>(A);
    std::cout << "yA: ";
    std::cin >> std::get<1>(A);
    std::cout << "zA: ";
    std::cin >> std::get<2>(A);
    std::cout << "\nAl doilea punct:\n";
    std::cout << "xB: ";
    std::cin >> std::get<0>(B);
    std::cout << "yB: ";
    std::cin >> std::get<1>(B);
    std::cout << "zB: ";
    std::cin >> std::get<2>(B);
    std::cout << "\nDistanta dintre punctele A si B: ";
    std::cout << ThreeDimensionalShape::getDistance<double>(A, B);
}