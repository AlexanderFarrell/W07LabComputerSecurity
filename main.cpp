#include <iostream>

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(/* feel free to add parameters */)
{

}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
    arrayVulnerability(/* parameters with malicious data */);
}

/**************************************
 * ARC INJECTION
 *
 *************************************/
//Hint: This may look something like last week's assignment.
void arcInjection(/* feel free to add parameters */)
{

}

/**************************************
 * VTABLE SPRAYING
 *
 *************************************/
//Hint: You will need two classes to do this: a base class and a derived class.
//Hint: For extra credit, can you demonstrate VTable Smashing?
class Vulnerability{


};

void vtableWorking(/* feel free to add parameters */){

}

void vTableExploit(/* feel free to add parameters */){

}

/**************************************
 * STACK SPRAYING
 *
 *************************************/
//Hint: Stack smashing must involve a buffer overrun.
//Hint: The exploit must provide a new and valid stack pointer. If it does not, then we have a stack spraying
// exploit instead of stack smashing.
//Hint: Some compilers drop a canary just before the return address. If you overwrite the canary, then the program will
// terminate with a "stack violation" error message. You can get around this by hopping over the canary using an array
// index vulnerability.
void stackVulnerability(){

}

void stackWorking(){

}

void stackExploit(){

}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void heapVulnerability(/* feel free to add parameters */){

}

void heapWorking(/* feel free to add parameters */){

}

void heapExploit(/* feel free to add parameters */){

}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void intVulnerability(/* feel free to add parameters */){

}

void integarWorking(/* feel free to add parameters */){

}

void intExploit(/* feel free to add parameters */){

}

/**************************************
 * ANSI-UNICODE CONVERSION
 *
 *************************************/
void ansiUnicode(/* feel free to add parameters */){

}

void ansiWorking(/* feel free to add parameters */){

}

void ansiExploit(/* feel free to add parameters */){

}

/**************************************
 * MAIN
 *
 *************************************/
int main() {

}
