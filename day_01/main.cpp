/*
 *  Advent of Code 2019
 * day 01 part 1&2, 2019.12.09
 * Author: Stoycho Petrov
*/

#include <iostream>
#include <chrono>

// for vector container
#include <vector>
// for floor function
#include <cmath>
// for accumulator
#include <numeric>

std::vector<int> items_mass;
std::vector<int> fuels_mass;
std::vector<int> total_mass;

void do_part_2()
{
    for( int mass : fuels_mass )
    {
        total_mass.push_back(mass);
        
        // process the additional fuel's fuel masses, until greater than zero
        while( mass > 0 )
        {
            float additional_mass = mass / 3.0;
            mass = std::floor(additional_mass);
            mass -= 2;
            if( mass > 0 )
            {
                total_mass.push_back(mass);
            }
        }
    }
    
    int total_fuels_mass_sum = std::accumulate(total_mass.begin(), total_mass.end(), 0);
    std::cout << "Answer d01 p2: " << total_fuels_mass_sum << std::endl;    
}

void do_part_1()
{
    int mass = 0;
    while( std::cin >> mass )
    {
        items_mass.push_back(mass);
    }
    

    float fuel = 0.0;
    for( int mass : items_mass )
    {
        fuel = mass / 3.0;
        fuel = std::floor(fuel);
        fuel -= 2;
        fuels_mass.push_back(fuel);
    }
    
    int total_fuels_mass_sum = std::accumulate(fuels_mass.begin(), fuels_mass.end(), 0);
    std::cout << "Answer d01 p1: " << total_fuels_mass_sum << std::endl;
}

int main( void )
{
    auto start = std::chrono::system_clock::now();
    /////
    
    // part 1
    do_part_1();
    
    // part 2
    do_part_2();
    
    //
    std::cout.flush();
    
    ////
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Elapsed time: " << diff.count() << " sec." << std::endl;
    
    return 0;
}