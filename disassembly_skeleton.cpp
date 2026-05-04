#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings, string member functions
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          This is a limited disassembler: we can safely assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti, sltiu
//          c) has ONLY registers $t0 thru $t7, or $s0 thru $s7 in the instruction
//
string disassemble( string hex ) {
    string instruct = "";
    string opcode = "";
    string rs = "";
    string rt = "";
    int hexNum = stoi(hex, 0, 16);
    cout << hexNum << endl;
    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the 
    //      different parts of the hex instruction!
    
    //all the opcode options
    if(opcode == "01000"){
        instruct += "addi ";
    }
    else if(opcode == "01000"){
        instruct += "addiu ";
    }
    else if(opcode == "01000"){
        instruct += "andi ";
    }
    else if(opcode == "01000"){
        instruct += "ori ";
    }
    else if(opcode == "01000"){
        instruct += "slti ";
    }
    else if(opcode == "01000"){
        instruct += "sltiu ";
    }
    
   
    //all the register options for rt then rs
    

    
    return instruct;  // remove stub and replace it with correct variable
}

int main() {
// Do NOT change ANY code in main() function!!
//      or you will fail this task (get a zero)

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
