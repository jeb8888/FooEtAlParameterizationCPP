#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <string>

class FooParameterization {
private:
    double radius;
    const double PI = 3.14159265358979323846;

public:
    FooParameterization(double r) : radius(r) {}

    void validate() const
    {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

    double calculate_volume() const
    {
        return (4.0 / 3.0) * PI * std::pow(radius, 3);
    }

    double get_radius() const
    {
        return radius;
    }
};

void print_usage()
{
    std::cout << "Usage: foo_physics --radius <value>\n";
    std::cout << "Options:\n";
    std::cout << "  --radius\tRadius of the sphere (required)\n";
}

int main(int argc, char* argv[])
{
    if (argc != 3 || std::string(argv[1]) != "--radius")
    {
        print_usage();
        return 1;
    }

    try {
        double radius = std::stod(argv[2]);
        auto parameterization = std::make_unique<FooParameterization>(radius);
        
        parameterization->validate();
        double volume = parameterization->calculate_volume();
        
        std::cout << "Calculated Volume: " << volume << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
