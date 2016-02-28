//Spencer McCracken
// 2/25/15
/*Purpose: This program is suppose to have a menu for the user to select four possible options that will convert either decimal, binary, or hex numbers. Depending on what selection they make
is what the conversion will do. It will continue to run until they enter q to stop the program.*/

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

//function to convert binary to decimal
void  BinaryToDecimal(int n)
{
	//initialize output
	int output = 0;
	
	//for loop to do the calculations to convert the binary to decimal
	for (int i = 0; n > 0; i++)
	{	
		//if statement to allow for the iterations to go through the binary number
		if (n % 10 == 1)
		{
			output += (1 << i);

		}

		n /= 10;
	}
	
	//prints out to the screen the final result which is in decimal form
	cout <<"Binary --> " << "Decimal: " << output;
}

//function to convert decimal numbers to binary
void DecimalToBinary(int n)
{
	//initialize remainder
	int rem;

	//if statement in case the input is less than 1 so that it will output that like 0
	if (n <= 1)
	{
		cout << n;
		return;
	}
	//calculations to convert the decimal to binary
	rem = n % 2;
	DecimalToBinary(n / 2);
	//print out to the screen the new binary number from the user inputed decimal
	cout << rem;
	
}
// function to convert binary to hex
void BinaryToHex()
{
	//initialize all my variables for the function
	cout << "Enter a binary number: ";
	string n = "";
	cin >> n;
	string result = "";
	string ans = "y";

	//add zeros so that you can divide by 4
	if (n.length() % 4 == 1) { n = "000" + n; }
	else if (n.length() % 4 == 2) { n = "00" + n; }
	else if (n.length() % 4 == 3) { n = "0" + n; }

	//for loop to do that conversion to hex
	for (int i = 0; i < n.length(); i += 4)
	{
		string num = n.substr(i, 4);
		if (num == "0000") { result = result + "0"; }
		else if (num == "0001") { result = result + "1"; }
		else if (num == "0010") { result = result + "2"; }
		else if (num == "0011") { result = result + "3"; }
		else if (num == "0100") { result = result + "4"; }
		else if (num == "0101") { result = result + "5"; }
		else if (num == "0110") { result = result + "6"; }
		else if (num == "0111") { result = result + "7"; }
		else if (num == "1000") { result = result + "8"; }
		else if (num == "1001") { result = result + "9"; }
		else if (num == "1010") { result = result + "A"; }
		else if (num == "1011") { result = result + "B"; }
		else if (num == "1100") { result = result + "C"; }
		else if (num == "1101") { result = result + "D"; }
		else if (num == "1110") { result = result + "E"; }
		else if (num == "1111") { result = result + "F"; }
		else { ans = "n"; }
	}

	//print out the answer to the user
	if (ans == "y")
	{
		cout << "Binary: " << n << "--> " << " " << "Hexadecimal: " << result << endl;
	}
	else
	{
		cout << "You entered an invalid number" << endl;
	}
}

//function for Hex to Binary
void HexToBinary(string Hex)
{
	//set the vaule to a string
	string binaryValue;   

	//for loop for the iterations that are needed
	for (int n = 0; n < Hex.size(); ++n)
	{
		//switch statements to see where numbers need to be placed and the letters are the end
		switch (Hex[n])
		{
		//what each value in Hex is equal to so that they combine to a Hex number at the end
		case '0':
			binaryValue += "0000"; break;
		case '1':
			binaryValue += "0001"; break;
		case '2':
			binaryValue += "0010"; break;
		case '3':
			binaryValue += "0011"; break;
		case '4':
			binaryValue += "0100"; break;
		case '5':
			binaryValue += "0101"; break;
		case '6':
			binaryValue += "0110"; break;
		case '7':
			binaryValue += "0111"; break;
		case '8':
			binaryValue += "1000"; break;
		case '9':
			binaryValue += "1001"; break;
		case 'A': case 'a':
			binaryValue += "1010"; break;
		case 'B': case 'b':
			binaryValue += "1011"; break;
		case 'C': case 'c':
			binaryValue += "1100"; break;
		case 'D': case 'd':
			binaryValue += "1101"; break;
		case 'E': case 'e':
			binaryValue += "1110"; break;
		case 'F': case 'f':
			binaryValue += "1111"; break;
		}
	}

	//print out the Hex value after the calculations are made
	cout << binaryValue;
}

int main()
{	
	//initialize all the variables
	int n;
	int choice;
	string hex;
	string bin;
		
	//print the menu so the user knows his options
	cout << "===================================================" << endl;
	cout << "";
	cout << "1: Binary --> Decimal" << endl;
	cout << "2: Decimal --> Binary" << endl;
	cout << "3: Binary --> Hexadecimal" << endl;
	cout << "4: Hexadecimal --> Binary" << endl;
	cout << "Other options: Enter Q to quit the program" << endl;
	cout << "";
	cout << "===================================================" << endl;
	cin >> choice;
	cout << "";

	//if statement to see if the user has entered q to quit the program
	if (cin.fail())
	{
		cout << "" << endl;
		cout << "You have quit thanks for using the conversion program!" << endl;
		cout << "" << endl;
		system("pause");
		return 1;

	}

	//else if statement to see if the user has entered a number that isnt a selection to quit the program
	else if (choice < 1 || choice > 4)
	{
		cout << "" << endl;
		cout << "You have quit thanks for using the program!" << endl;
		cout << "" << endl;
		system("pause");
		return 1;
	}


	//while loop to make sure the user doesnt input an invalid input and it will continue to run until they want to stop the program
	while (choice == 1 || choice == 2 || choice == 3 || choice == 4)
	{

		//if statement for option 1 so that it does the binary to decimal conversion
		if (choice == 1)
		{
			cout << "Enter a binary nubmer (1s and 0s only): ";
			cin >> n;
			BinaryToDecimal(n);
		}

		//if statement for option 2 so that it does decimal to binary
		if (choice == 2)
		{
			cout << "Enter a decimal number: ";
			cin >> n;
			DecimalToBinary(n);
		}

		//if statement for option 3 so that it does binary to hex
		if (choice == 3)
		{
			BinaryToHex();
		}

		//if statement for option 4 so that it does hex to binary
		if (choice == 4)
		{
			cout << "Enter a Hexadecimal number: ";
			cin >> hex;
			HexToBinary(hex);

		}

		if (cin.fail())
		{
			cout << "Please enter a correct selection";
		}

		


		//print out the menu again at the bottom of the while loop so that it will continue to loop the menu for the user
		cout << endl;
		cout << "===================================================" << endl;
		cout << "";
		cout << "1: Binary --> Decimal" << endl;
		cout << "2: Decimal --> Binary" << endl;
		cout << "3: Binary --> Hexadecimal" << endl;
		cout << "4: Hexadecimal --> Binary" << endl;
		cout << "Other options: Enter Q to quit the program" << endl;
		cout << "";
		cout << "===================================================" << endl;
		cin >> choice;
		cout << "";

		// if statement to tell if the user has entered q to quit the program
		if (cin.fail())
		{
			cout << "" << endl;
			cout << "You have quit thanks for using the conversion program!" << endl;
			cout << "" << endl;
			system("pause");
			return 1;

		}

		//else if statement to see if the user has entered a option that isnt possible to quit the program
		else if (choice < 1 || choice > 4)
		{
			cout << "" << endl;
			cout << "You have quit thanks for using the program!" << endl;
			cout << "" << endl;
			system("pause");
			return 1;
		}
	}

	cout << "Thanks for using the program!"<< endl;
	system("pause");
	return 0;

}
