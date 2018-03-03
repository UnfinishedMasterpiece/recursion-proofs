/*
	File Name: recursion.cpp
	Written By: Sergio Flor
	Date Last Modified: 3/1/2018
	File Purpose: A couple proofs with recursive functions.
	This program was originally written as an in-class Computer Science assignment but cleaned up for publishing on GitHub. 
*/

#include <iostream>
#include <string>			//added for cin.ignore(2)

using namespace std;

void countUp(int num);
void countDown(int num);					//Prototyping the recursive functions for future referencing.
int factorial(int num);

int main() {

	int cUpInput;
	int cDownInput;						//variables for user input
	int factorialInput;
	
	cout << "Please enter an integer for the countUp Routine: "; //prompts user for an integer
	cin >> cUpInput;
	cout << endl; //This line here is just for formatting purposes because I hate not having a line break between commands.
	countUp(cUpInput); //calls the countUp recursive function, passing through the integer entered by the user as its parameter
	
	cout << "\nPlease enter another integer for the countDown Routine: "; //prompts user for another integer
	cin >> cDownInput;
	cout << endl; //This line here is just for formatting purposes because I hate not having a line break between commands.
	countDown(cDownInput); //calls the countDown recursive function, passing through the integer entered by the user as its parameter
	
	do {
		cout << "Enter an integer between 1 and 16 to recieve it's factorial: ";
		cin >> factorialInput;															//The do while loop here is to prevent integer overflow by restricting users to a range from 1 to 16.
		if (factorialInput > 16) {														//In an earlier build I had gotten around this by initializing an unsigned long long integer within the factorial function.
			cout << "\nThe number you entered is invalid. Please try again.\n" << endl; //This integer variable extended the rage from 1 to 50.
		}																				//Unfortunately, the way I had the function running would only work with even numbers so that if anyone could take a crack at extending the range, Be my guest!
	} while (factorialInput > 16); 
	
	cout <<'\n' << factorialInput << "!(Factorial) is: " << factorial(factorialInput) << endl; //prints output of the factorial recursive function
	
	cin.ignore(2); //pauses program before termination apparently works for non windows systems.
	//system("pause"); //pauses program for windows systems.
	return 0; //terminates program without a hitch!
}

void countUp(int num) {

	static int output = 0; //static variable so output isn't reset everytime the function is called...we don't want an infinite recursive function, lol XP.

	if (output == num) {
		cout << "We have reached " << num << '!' << endl; //if the output is equal to the integer passed in by the user, then yay! We can escape the function!
		return;
	}

	cout << "Output is at: " << output << '\n' << endl; //prints the current value of output
	output++; //then increment the value of output
	countUp(num); //call countUp function again
}

void countDown(int num) {

	if (num == 0) {
		cout << "Sucess! We're at " << num << '!' << endl; //if the input is equal to 0 then let's GTFOOTF (Get the F*** out of the function)!
		cout << "\nWe have Liftoff!\n" << endl;
		return;
	}

	cout << "T-" << num << " Seconds.\n" << endl; //prints out the current value of num
	countDown(num - 1); //calls the countDown function with a parameter of num subtracted by 1. ex: if initial num = 3 but when it hits this line countDown is called with a new initial num of 2.
}

int factorial(int num) {

	if (num == 1) {
		return 1; //if the value of num is equal to 1 then return from the function with the value of num (plus any updates to the value of num)
	} else {
		return num * factorial(num - 1); //if not return with num times a call to the factorial function with a parameter of num minus 1. ex: if 3 is initial num then this line returns the product of 4 * factorial(3), 3 * factorial(2), etc.
	}
}