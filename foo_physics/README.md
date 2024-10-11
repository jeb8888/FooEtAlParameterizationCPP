# Foo et al. Parameterization

> Uses Foo et al. parameterization to take the radius of a sphere and return its volume

## Setup

```
make
```


## Unit Testing

```
brew install googletest
g++ -std=c++17 test/foo_physics_test.cpp -lgtest -lgtest_main -pthread -o foo_physics_test
```

## Contributing

If you have suggestions for how Foo et al. Parameterization could be improved, or want to report a bug, open an issue! We'd love all and any contributions.

For more, check out the [Contributing Guide](CONTRIBUTING.md).

## Python API

```
from foo_param.parameterization import FooParameterization

param = FooParameterization(5)
param.validate()
volume = param.calculate_volume()
print(f"Volume: {volume}")
```

## License

This project is licensed under the MIT License.