#include <iostream>
using namespace std;

// Function to modify a string based on certain conditions
string test(string str)
{
    // Check if the length of the string is less than 2
    return str.length() < 2 ? str : // If the length is less than 2, return the string as it is
        str.substr(0, 2) + str.substr(0, 2) + str.substr(0, 2) + str.substr(0, 2); // If the length is 2 or more, concatenate the first two characters of the string four times
}

// Main function
int main() 
{
    cout << test("C Sharp") << endl;  // Output the result of test function with string "C Sharp"
    cout << test("JS") << endl;       // Output the result of test function with string "JS"
    cout << test("a") << endl;        // Output the result of test function with string "a"
    return 0;    // Return 0 to indicate successful execution of the program
}
