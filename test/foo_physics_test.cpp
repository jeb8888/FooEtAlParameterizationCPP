/**
 * Foo et al. Parameterization Package
 * Written by Jared Ebenstein
 * October 10, 2024
 * For UCAR
 */

#include <gtest/gtest.h>
#include "foo_physics.hpp"  // Assuming the implementation is in this header

class FooParameterizationTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FooParameterizationTest, ValidRadius) {
    FooParameterization param(5.0);
    ASSERT_NO_THROW(param.validate());
    EXPECT_DOUBLE_EQ(param.get_radius(), 5.0);
}

TEST_F(FooParameterizationTest, InvalidRadius) {
    FooParameterization param(-1.0);
    ASSERT_THROW(param.validate(), std::invalid_argument);
}

TEST_F(FooParameterizationTest, ZeroRadius) {
    FooParameterization param(0.0);
    ASSERT_THROW(param.validate(), std::invalid_argument);
}

TEST_F(FooParameterizationTest, CalculateVolume) {
    FooParameterization param(2.0);
    const double expected_volume = 33.510321638291124; // 4/3 * π * 2³
    EXPECT_NEAR(param.calculate_volume(), expected_volume, 1e-10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
