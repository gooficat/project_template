#include <iostream>
#include <print>

int main() 
{
	// traditional way
   std::cout << "Hello, World! " << 2026 <<"\n";
	// modern c++ way
	constexpr int version = 23;
   std::println("Hello from C++ version {}", version );

   return 0;
}
