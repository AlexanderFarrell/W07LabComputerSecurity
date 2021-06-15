#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <assert.h>

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
   //Substr added for convenience, as it prints super long otherwise!
   cout << "\nThere are now " << cartQuantities[selection] << " " << cartNames[selection].substr(0, 60) << endl;
}

void arrayWorking(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called arrayWorking()";
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
   cout << setw(30) << "\n -- Called arrayExploit()";
   arrayVulnerability(5);
}

/**************************************
 * ARC INJECTION
 *  1.  There must be a function pointer used in the code.
 *  2.  Through some vulnerability, there must be a way for user input to overwrite the function pointer. This
 *         typically happens through a stack buffer vulnerability.
 *  3.  After the memory is overwritten, the function pointer must be dereferenced.
 *************************************/
void help()
{
   cout << setw(30) << "Command "
        << "- quit - Quits \n";
   cout << setw(30) << "quit "
        << " - Quit app \n";
   cout << setw(30) << "info "
        << " - Gets info on app \n";
}
void quit()
{
   cout << "Quitting!";
}
void info()
{
   cout << "This is an application";
}
void invalid()
{
   cout << "Not a valid selection";
}
void dangerous()
{
   cout << "Dangerous Called. Should not be called from selections";
}
typedef void (*func)();
//Hint: This may look something like last week's assignment.
void arcVulnerability(istringstream iss)
{
   //The below code is caught by the debugger, and mitigated. It is similar to the example in the book. It may appear
   // this was a vulnerability at one point in C++'s history, but modern c++ runtimes catch it.

   /*char selection[1];
    auto command = invalid;
    iss >> selection[1];*/

   //Because of this, a different and more blatant vulnerability is written, simulating the above code on the heap.

   const char *data = new char[9];
   *((long *)(data + 1)) = (long)invalid;
   string strTmp;
   iss >> strTmp;
   data = strTmp.data();

   char selection[1];
   auto command = *((func *)&data[1]);
   selection[0] = data[0];

   switch (selection[0])
   {
   case 'q':
      command = quit;
      break;
   case 'i':
      command = info;
      break;
   case 'h':
      command = help;
      break;
   default:
      break;
   }

   command();
   cout << endl;
}

void arcWorking()
{
   cout << setw(30) << "\n -- Called arcWorking()" << endl;
   arcVulnerability(istringstream("i"));
}

/**************************************
 * ARC INJECTION
 *  1. The attacker must exploit a vulnerability allowing unintended access to the function pointer.
 *  2. The attacker must have the address to another function which is to be used to replace the existing
 *         function pointer.
 *************************************/
void arcExploit(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called arcExploit()" << endl;
   string s("........."); // = new char[9];
   char *c = reinterpret_cast<char *>(&s.at(0));
   long *l = reinterpret_cast<long *>(&s.at(1));

   *c = 'u';
   *l = (long)dangerous;

   arcVulnerability(istringstream(s));
}

/**************************************
 * VTABLE SPRAYING
 *For a V-Table smashing vulnerability to exist in the code, the following must be present:
 * 1. The vulnerable class must be polymorphic.
 * 2. The class must have a buffer as a member variable.
 * 3. Through some vulnerability, there must be a way for user input to overwrite parts of the V-Table.
 *************************************/
//Hint: You will need two classes to do this: a base class and a derived class.
//Hint: For extra credit, can you demonstrate VTable Smashing? -- Tried, was unsuccessful, continued to hit
// errors with modifying various parts of the vtable. It's possible the compiler might not let me.
class BadObject
{
public:
   virtual void set_name(string s)
   {
      sprayable = "All is well";
      char *data = &(name[0]);
      for (int i = 0; i < s.length(); ++i)
      {
         data[i] = s.at(i);
      }
      notify();
   }
   void notify()
   { //Method exploited.
      cout << "Your name has been set to " << name << endl;
      cout << "Have we been sprayed? " << sprayable << endl;
   }

private:
   char name[10];
   string sprayable;
};

class Vulnerability : BadObject
{
public:
   void set_name(string s) override
   {
      BadObject::set_name(s);
   }
};

void vtableWorking(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called vtableWorking()" << endl;
   auto v = new Vulnerability();

   v->set_name("Alexander");
}

void vTableExploit(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called vTableExploit()" << endl;

   auto v = new Vulnerability();
   string s("Hahahahaha       Sprayed!!!");
   v->set_name(s);
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
void stackVulnerability(char *text)
{
   
   cout << "Enter your text: ";
   cin >> text;   //N validation on buffer size
   cin.ignore(1,'\n'); //a large amount of characters will cause a fatal error.
     
}

void stackWorking()
{
   cout << setw(30) << "\n -- Called stackWorking()\n";

   char text[10];
   stackVulnerability(text);

}

void stackExploit()
{
   cout << setw(30) << "\n -- Called stackExploit()\n";

   char badText[10];
   cout << setw(20) << "Time to insert a large amount of characters...\n";
   stackVulnerability(badText); 
}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void heapVulnerability(char input[], int size)
{
   char *buffer1 = new char[4];
   char *buffer2 = new char[4];
   assert(buffer1 < buffer2);
   for (int i = 0; i < size; i++)
   {
      buffer1[i] = input[i];
   }
   cout << buffer1;
   delete[] buffer2;
   delete[] buffer1;
}

void heapWorking(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called heapWorking()\n";
   const int size = 4;
   char input[size] = "Hey";
   heapVulnerability(input, size);
}

void heapExploit(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called heapExploit()\n";
   // This crashes the program
   const int size = 20;
   char input[size] = "Prepare to crash";
   heapVulnerability(input, size);
}

/**************************************
 * HEAP SPRAYING
 *
 *************************************/
void intVulnerability(int numberInArray)
{
   // This give us some bounds that we need to disrupt as per the assignment this is holding credit cards and the corresponding accounts
   // Let's image they are filled up.
   char creditcard[254] = {"1"};
   char account[254] = {"j"};

   // We take the user input and use it to the corresponding account and credit card number
   cout << creditcard[numberInArray] << endl;
   cout << account[numberInArray] << endl;
}

void integarWorking()
{
   cout << setw(30) << "\n -- Called integarWorking()\n";
   // This will return a 1 and a J
   intVulnerability(0);
}

void intExploit(/* feel free to add parameters */)
{
   cout << setw(30) << "\n -- Called intExploit()\n";
   // This returns a random integer
   intVulnerability(256);
}

/**************************************
 * ANSI-UNICODE CONVERSION
 *
 *************************************/

// Get this where the number we loop on is the one received. The size off will ruin it.ß
void ansiUnicode(int passwordLength)
{
   string realPasswordLength = "This is a test";
   if (realPasswordLength.size() == passwordLength)
   {
      cout << "Password matches" << endl;
   }
   else
   {
      cout << "wrong password" << endl;
   }
}

void ansiWorking()
{
   cout << setw(30) << "\n -- Called ansiWorking()\n";
   // this will check for number of elements
   string testing1 = "This is a test";
   ansiUnicode(testing1.length());
}

void ansiExploit()
{
   cout << setw(30) << "\n -- Called ansiExploit()\n";
   string testing2 = "This is a test";
   // By using the sizeof, we aren't chekcing the length like we're supposed to
   ansiUnicode(sizeof(testing2));
}

/**************************************
 * MAIN
 *
 *************************************/
int main()
{
   arrayWorking();
   arrayExploit();
   /*try {
        arrayWorking();
        arrayExploit();
    } catch (exception e) {
        cout << e.what();
    }*/
   heapWorking();
   heapExploit();

   arcWorking();
   arcExploit();

   vtableWorking();
   vTableExploit();

   integarWorking();
   intExploit();

   ansiWorking();
   ansiExploit();

   stackWorking();
   stackExploit();
}
