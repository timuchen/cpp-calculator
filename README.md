# cpp-calculator
The program implements a primitive calculator.

## Quick start
Compilation in MacOS for 20 'version of compiler.
1) Install LLVM: ```brew install llvm``` .

2) Compilation

``` 
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -c -Xclang -emit-module-interface calculator.cpp -o calculator.pcm
/opt/homebrew/opt/llvm/bin/clang++ -std=c++20 -fmodules -c -fprebuilt-module-path=. main.cpp -o main.o
/opt/homebrew/opt/llvm/bin/clang++ -std=c++2a -fmodules -o main main.o *.pcm
```

3) Run: ```./main```.