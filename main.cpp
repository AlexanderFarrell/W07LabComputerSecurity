#include <iostream>
#include <iomanip>

using namespace std;

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(int selection)
{
    int cartQuantities[3];
    cartQuantities[0] = 5;
    cartQuantities[1] = 2;
    cartQuantities[2] = 10;

    string cartNames[3];
    cartNames[0] = "Apples";
    cartNames[1] = "Oranges";
    cartNames[2] = "Bananas";

    //Remove item
    cartQuantities[selection] -= 1;
    cout << " -- There are now " << cartQuantities[selection] << " " << cartNames[selection] << endl;
}

void arrayWorking(/* feel free to add parameters */){
    cout << setw(30) << "Called arrayWorking()";
    arrayVulnerability(2);
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
    cout << setw(30) << "Called arrayExploit()";
    arrayVulnerability(5);
}

/**************************************
 * ARC INJECTION
 *
 *************************************/
//Hint: This may look something like last week's assignment.
void arcVulnerability(/* feel free to add parameters */)
{

}

void arcWorking(/* feel free to add parameters */)
{
    cout << setw(30) << "Called arcWorking()";

}

void arcExploit(/* feel free to add parameters */)
{
    cout << setw(30) << "Called arcExploit()";

}

/**************************************
 * VTABLE SPRAYING
 *
 *************************************/
//Hint: You will need two classes to do this: a base class and a derived class.
//Hint: For extra credit, can you demonstrate VTable Smashing?
class vTableVulnerability{

};

void vtableWorking(/* feel free to add parameters */){
    cout << setw(30) << "Called vtableWorking()";

}

void vTableExploit(/* feel free to add parameters */){
    cout << setw(30) << "Called vTableExploit()";

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
    cout << setw(30) << "Called stackWorking()";

}

void stackExploit(){
    cout << setw(30) << "Called stackExploit()";

}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void heapVulnerability(/* feel free to add parameters */){

}

void heapWorking(/* feel free to add parameters */){
    cout << setw(30) << "Called heapWorking()";

}

void heapExploit(/* feel free to add parameters */){
    cout << setw(30) << "Called heapExploit()";

}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void intVulnerability(/* feel free to add parameters */){

}

void integarWorking(/* feel free to add parameters */){
    cout << setw(30) << "Called integarWorking()";

}

void intExploit(/* feel free to add parameters */){
    cout << setw(30) << "Called intExploit()";

}

/**************************************
 * ANSI-UNICODE CONVERSION
 *
 *************************************/
void ansiUnicode(/* feel free to add parameters */){

}

void ansiWorking(/* feel free to add parameters */){
    cout << setw(30) << "Called ansiWorking()";

}

void ansiExploit(/* feel free to add parameters */){
    cout << setw(30) << "Called ansiExploit()";

}

/**************************************
 * MAIN
 *
 *************************************/
int main() {

    arrayWorking();
    arrayExploit();
}
