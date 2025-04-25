# simple_sc_examples

## Simple SystemC examples to make sure your SystemC is installed correctly (see instructions below)
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

## SystemC Installation Instructions

#### Download SystemC from the Accellera SystemC web site:
https://www.accellera.org/downloads/standards/systemc
###### Unzip or untar it for installation


### For SystemC 2.3.3:
```{bash}
export CXX=/usr/bin/g++
mkdir objdir
cd objdir
# Set the prefix to where you want it installed
../configure --prefix=$HOME/Tools/Accellera/SystemC/systemc/2.3.3
gmake
make check # optional: run tests
gmake install
```

### For SystemC 2.3.4:
```{bash}
export CXX=/usr/bin/g++
cmake -B build
cmake --build build
# Set the prefix to where you want it installed
# install
cmake --install build --prefix $HOME/Tools/Accellera/SystemC/systemc/2.3.4

# doesn't install all the directories. Only include/, lib/ & shared/
```

### For SystemC 3.0.1:
```{bash}
export CXX=/usr/bin/g++
mkdir objdir
cd objdir
# Set the prefix to where you want it installed
../configure 'CXXFLAGS=-std=c++17' --prefix=$HOME/Tools/Accellera/SystemC/systemc/3.0.1
# Make sure docs/DEVELOPMENT.md exists. If not, get it from github otherwise gmake will fail
gmake
make check # optional: run tests
gmake install
```

### For the latest SystemC from github:
```{bash}
git clone https://github.com/accellera-official/systemc
```
