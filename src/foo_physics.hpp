#ifndef FOO_PHYSICS_HPP
#define FOO_PHYSICS_HPP

/**
 * Foo et al. Parameterization Package
 * Written by Jared Ebenstein
 * October 10, 2024
 * For UCAR
 */

#include <stdexcept>
#include <cmath>

class FooParameterization {
public:
    /**
     * Constructs a FooParameterization object with the given radius
     * @param r The radius of the sphere
     */
    explicit FooParameterization(double r);

    /**
     * Validates that the radius is positive
     * @throws std::invalid_argument if radius is not positive
     */
    void validate();

    /**
     * Uses Foo et al. Parameterization to take the radius of a sphere and return its volume
     * @return The volume of the sphere
     */
    double calculate_volume();

    /**
     * Gets the current radius value
     * @return The radius of the sphere
     */
    double get_radius() const;

private:
    double radius;
    static constexpr double PI = 3.14159265358979323846;
};

inline FooParameterization::FooParameterization(double r) : radius(r) {}

inline void FooParameterization::validate() {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be a positive number");
    }
}

inline double FooParameterization::calculate_volume() {
    return (4.0 / 3.0) * PI * std::pow(radius, 3);
}

inline double FooParameterization::get_radius() const {
    return radius;
}

#endif // FOO_PHYSICS_HPP
