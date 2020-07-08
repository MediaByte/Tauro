## Tauro
[![Coverity Scan Build Status](https://scan.coverity.com/projects/16116/badge.svg)](https://scan.coverity.com/projects/uldaq)

**Info:** Contains a NodeJS interface to access and control supported Measurement Computing [DAQ devices](https://www.mccdaq.com/PDFs/Manuals/Linux-hw.pdf) over the Linux and macOS platforms. 

**Author:** Mario Martin

## About
The **Tauro** package contains programming libraries and components for developing applications using C/C++ on Linux and macOS Operating Systems. An API (Application Programming Interface) for interacting with the library in Python is available as an additional installation. This package was created and is supported by MCC. 

### Prerequisites:
---------------
Building the **Tauro** package requires Typescript/C/C++ compilers, node-gyp, make tool, uldaq and the development package for libusb. The following describes how these prerequisites can be installed on different Linux distributions and macOS.
  
  - Debian-based Linux distributions such as Ubuntu, Raspbian
  
  ```
     $ sudo apt-get install gcc g++ make
     $ sudo apt-get install libusb-1.0-0-dev
  ```
  - Arch-based Linux distributions such as Manjaro, Antergos
  
  ```
     $ sudo pacman -S gcc make
     $ sudo pacman -S libusb
  ```
  - Red Hat-based Linux distributions such as Fedora, CentOS
  
  ```
     $ sudo yum install gcc gcc-c++ make
     $ sudo yum install libusbx-devel
  ``` 
  - OpenSUSE 
  
  ```
     $ sudo zypper install gcc gcc-c++ make
     $ sudo zypper install libusb-devel
  ```
  - macOS (Version 10.11 or later recommended)
  
  ```
     $ xcode-select --install
     $ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
     $ brew install libusb
  ```

### Build Instructions
---------------------

1. Download the latest version of **uldaq**:

```
  Linux
     $ wget -N https://github.com/mccdaq/uldaq/releases/download/v1.2.0/libuldaq-1.2.0.tar.bz2

  macOS
     $ curl -L -O https://github.com/mccdaq/uldaq/releases/download/v1.2.0/libuldaq-1.2.0.tar.bz2
``` 
2. Extract the tar file:
 
```
  $ tar -xvjf libuldaq-1.2.0.tar.bz2
```
  
3. Run the following commands to build and install the library:

```
  $ cd libuldaq-1.2.0
  $ ./configure && make
  $ sudo make install
```

### Uninstall Instructions
Run the following command to uninstall the library

``` sh
  $ sudo make uninstall
``` 

### Documentation
Online help for the Universal Library for Linux is available for [C/C++](https://www.mccdaq.com/PDFs/Manuals/UL-Linux/c/index.html).
