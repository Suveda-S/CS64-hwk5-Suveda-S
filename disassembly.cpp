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
    int hexNum = stoi(hex, 0, 16);
    int opcodeNum = hexNum >> 26;
    int rsNum = hexNum >> 21;
    rsNum = rsNum & 0x1F;
    int rtNum = hexNum >> 16;
    rtNum = rtNum & 0x1F;
    int immediateNum = hexNum & 0xFFFF;
    
    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the 
    //      different parts of the hex instruction!
    
    //all the opcode options
    if(opcodeNum == 0x01000){
        instruct += "addi ";
    }
    else if(opcodeNum == 0x01001){
        instruct += "addiu ";
    }
    else if(opcodeNum == 0x01100){
        instruct += "andi ";
    }
    else if(opcodeNum == 0x01101){
        instruct += "ori ";
    }
    else if(opcodeNum == 0x01010){
        instruct += "slti ";
    }
    else if(opcodeNum == 0x01011){
        instruct += "sltiu ";
    }

    string registersArray[24] ={"","","","","","","","","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7"};
    instruct += registersArray[rtNum] +", ";
    instruct += registersArray[rsNum] +", ";
    instruct += to_string(immediateNum);
    
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
