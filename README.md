# simple_sc_examples

## Simple SystemC examples to make sure your SystemC is installed correctly.
### Makefile-based Example
```{bash}
cd makefile-based
make all
./first_systemc
```

### CMake-based Example
```{bash}
cd cmake-based
source source.me
mkdir build
cd build
cmake ..
make
./first_systemc
```
