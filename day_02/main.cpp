/*
 *  Advent of Code 2019
 * day 2 part 1 & 2, 2019.12.09
 * Author: Stoycho Petrov
*/

#include <iostream>
#include <chrono>

// for vector container
#include <vector>


// GLOBAL variables
std::vector<int> data;
std::vector<int> memory;

int noun = 0;
int verb = 0;

const int C_ADD = 1;
const int C_MLTPL = 2;
const int C_HALT = 99;

void print_vec( std::vector<int> vec)
{
    std::cout << "printing vector:\n";
    int idx = 1;
    for( auto it = vec.begin() ; it != vec.end() ; it++ )
    {
        std::cout << *it;
        
        if( idx % 4 != 0 && ( *it != 99 || idx % 4 != 1) ) std::cout << ",";
        else
        {
            std::cout << std::endl;
            idx = 0;
        }
        
        idx++;
    }
    std::cout << "------------------\n";
}

void do_part_2()
{
    size_t cur_pos = 0;
    bool halt = false;
    int res_b = 0;
    int processed_opcodes = 0;
    
    // get the initial input in place
    data = memory;
    // set noun and verb values
    data[1] = noun;
    data[2] = verb;
    
    while( !halt )
    {
        int command = data[cur_pos];
        int op1 = data[cur_pos+1];
        int op2 = data[cur_pos+2];
        int res = data[cur_pos+3];
        
        // DEBUG
        //std::cout << "CMD(" << command << "), OP1(" << op1 << "), OP2(" << op2 << "), RES_REG(" << res << ")\n";
        
        int val = 0;
        
        if( command == C_HALT )
        {
            halt = true;
            continue;
        }
        else if( command == C_ADD )
        {
            val = data[op1] + data[op2];
            data[res] = val;
        }
        else // assume it's C_MLTPL
        {
            val = data[op1] * data[op2];
            data[res] = val;
        }
        
        // DEBUG
        //print_vec(data);
        //std::cout << processed_opcodes << ":\tcur_pos(" << cur_pos << ") \t==> \tdata[0](" << data[0] << ") \t| \tdata[" << res << "](" << data[res] << ")\n";
        
        // check if the result is 19690720 after each opcode processed
        if( data[0] == 19690720 )
        {
//            noun = data[op1];
//            verb = data[op2];
            res_b = noun * 100 + verb;
            halt = true;
            continue;
        }
        
        processed_opcodes++;
        // reset the data back to initial memory's state
//        if( processed_opcodes % 4 == 0 )
//        {
//            data = memory;
//        }
        
        
        // move forward to next opcode
        cur_pos += 4;
        if( cur_pos > data.size() )
        {
            halt = true; // something went wrong, stop processing
            std::cout << "\n\tBLAH :(\n";
        }
    }
    
    if( res_b != 0 )
    {
        std::cout << "Answer p2: " << res_b << std::endl;    
    }
}

void do_part_1()
{
    int tmp_imp = 0;
    
    // discard the inputs at position 1 and 2 and replace them with values 12 and 2;
    std::cin >> tmp_imp;
    data.push_back(tmp_imp);
    std::getchar(); // consume the ,
    std::cin >> tmp_imp;
    data.push_back(12);
    std::getchar();
    std::cin >> tmp_imp;
    data.push_back(2);
    std::getchar();
        
    // continue with the rest (after 3rd)
    while( std::cin >> tmp_imp )
    {
        data.push_back(tmp_imp);
        std::getchar();
    }
    
    // DEBUG
    //print_vec(data);
    //return;
    
    // save the initial input
    memory = data;
    
    // DEBUG
    //print_vec(memory);
    
    // we got the input, now process it...
    size_t cur_pos = 0;
    bool halt = false;
    
    if( data.size() < 4 )
    {
        halt = true; // something went wrong, stop processing
        std::cout << "\n\tBLAH :(\n";
    }
    
    while( !halt )
    {
        int command = data[cur_pos];
        int op1 = data[cur_pos+1];
        int op2 = data[cur_pos+2];
        int res = data[cur_pos+3];
        
        // DEBUG
        //std::cout << "CMD(" << command << "), OP1(" << op1 << "), OP2(" << op2 << "), RES_REG(" << res << ")\n";
        
        int val = 0;
        
        if( command == C_HALT )
        {
            halt = true;
            continue;
        }
        else if( command == C_ADD )
        {
            val = data[op1] + data[op2];
            data[res] = val;
        }
        else // assume it's C_MLTPL
        {
            val = data[op1] * data[op2];
            data[res] = val;
        }
        
        // DEBUG
        //print_vec(data);
        //std::cout << "cur_pos(" << cur_pos << ") ==> data[0](" << data[0] << ") | data[" << res << "](" << data[res] << ")\n";
        
        // move forward to next opcode
        cur_pos += 4;
        if( cur_pos > data.size() )
        {
            halt = true; // something went wrong, stop processing
            std::cout << "\n\tBLAH :(\n";
        }
    }
    
    // all processed, the answer is whatever we have at position 0
    std::cout << "\nAnswer p1: " << data[0] << std::endl;
}

int main( void )
{
    auto start = std::chrono::system_clock::now();
    /////
    
    // part 1
    do_part_1();
    
    // part 2
    for( noun = 0 ; noun < 100 ; noun++ )
        for( verb = 0 ; verb < 100 ; verb++ )
            do_part_2();
    
    //
    std::cout.flush();
    
    ////
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Elapsed time: " << diff.count() << " sec." << std::endl;
    
    return 0;
}