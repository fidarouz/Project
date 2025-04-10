/*
Name				: MUHAMMAD FIDAROUS BIN ABDUL HADI
Sid			    	: 2023167637
Course			    : CSC126 
Group				: A4CDCS1101B
Due Date			: 14 June 2023 5:00 pm
Question No	    	: 2
Program Description	: C++
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    char membershipStatus;
    char packageCode;
    int hoursBooked;
    double pricePerHour = 0.0, discount = 0.0, totalPrice = 0.0;

    cout << "Welcome to Bloom & Care Services!" << endl;
    cout << "\nEnter your membership status (M for member, N for non-member): ";
    cin >> membershipStatus;
     if (membershipStatus != 'M' && membershipStatus != 'm' && membershipStatus != 'N' && membershipStatus != 'n')
	{
	cout<<"Invalid membership status."<<endl;
	return 0;
	}
    
    cout << "Enter the package code (G for Galaxy, S for Star, N for Normal): ";
    cin >> packageCode;
     if (packageCode != 'G' && packageCode != 'g' && packageCode != 'S' && packageCode != 's' && packageCode != 'N' && packageCode != 'n')
	{
	cout<<"Wrong package code."<<endl;
	return 0;
	}
	
    cout << "Enter the number of hours you will book for this service: ";
    cin >> hoursBooked;
    
   

    switch (membershipStatus)
    {
        case 'M':
        case 'm':
            cout << "\nWelcome! You are part of our member and you get 5% discount!." << endl;
         

            if (packageCode == 'G' || packageCode == 'g')
            {
                pricePerHour = 70.00;
                discount = 0.23;
            }
            else if (packageCode == 'S' || packageCode == 's')
            {
                pricePerHour = 45.00;
                discount = 0.20;
            }
            else if (packageCode == 'N' || packageCode == 'n')
            {
                pricePerHour = 30.00;
                discount = 0.15;
            }
            else
            {
                cout << "Invalid type of package or package code" << endl;
                return 0;
            }

            totalPrice = pricePerHour * hoursBooked * (1 - discount);

            cout << "\nCongratulations! You have booked " << hoursBooked << " hours of service." << endl;
             cout << "The total price for your package is RM" << totalPrice << endl;
             cout << "\nTHANK YOU FOR CHOOSING BLOOM AND CARE SERVICES!" << endl;
            break;

        case 'N':
        case 'n':
            cout << "\nWelcome! You are a non-member." << endl;
        
            if (packageCode == 'G' || packageCode == 'g')
            {
                pricePerHour = 78.00;
                discount = 0.18;
            }
            else if (packageCode == 'S' || packageCode == 's')
            {
                pricePerHour = 55.00;
                discount = 0.15;
            }
            else if (packageCode == 'N' || packageCode == 'n')
            {
                pricePerHour = 35.00;
                discount = 0.10;
            }
            else
            {
                cout << "Invalid type of package or package code" << endl;
                return 0;
            }

            totalPrice = pricePerHour * hoursBooked * (1 - discount);

            
            cout << "You have booked " << hoursBooked << " hours of service." << endl;
            cout << "The total price for your package is RM" << totalPrice << endl;
            cout << "\nTHANK YOU FOR CHOOSING BLOOM AND CARE SERVICES!" << endl;
            break;

        default:
            cout << "Invalid membership status" << endl;
            break;
    }

    return 0;
}
