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
void intVulnerability(int numberInArray){
    // This give us some bounds that we need to disrupt as per the assignment this is holding credit cards and the corresponding accounts
    // Let's image they are filled up.
    char creditcard[254] = {"1"};
    char account[254] = {"j"};
    
    // We take the user input and use it to the corresponding account and credit card number
    cout << creditcard[numberInArray] << endl;
    cout << account[numberInArray] << endl;
    
}

void integarWorking(){
    cout << setw(30) << "Called integarWorking()";
    // This will return a 1 and a J
    intVulnerability(0);

}

void intExploit(/* feel free to add parameters */){
    cout << setw(30) << "Called intExploit()";
    // This returns a random integer
    intVulnerability(256);

}

/**************************************
 * ANSI-UNICODE CONVERSION
 *
 *************************************/

// Get this where the number we loop on is the one received. The size off will ruin it.ß
void ansiUnicode(int passwordLength){
    string realPasswordLength = "This is a test";
    if (realPasswordLength.size() == passwordLength){
        cout << "Password matches" << endl;
    }
    else{
        cout << "wrong password"  << endl;
    }
}

void ansiWorking(){
    cout << setw(30) << "Called ansiWorking()";
    // this will check for number of elements
    string testing1 = "This is a test";
    ansiUnicode(testing1.length());
}

void ansiExploit(){
    cout << setw(30) << "Called ansiExploit()";
    string testing2 = "This is a test";
     // By using the sizeof, we aren't chekcing the length like we're supposed to
    ansiUnicode(sizeof(testing2));

}

/**************************************
 * MAIN
 *
 *************************************/
int main() {

    arrayWorking();
    arrayExploit();
    ansiWorking();
    ansiExploit();
}
