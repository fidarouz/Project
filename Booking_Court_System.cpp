#include <iostream>
#include <cstring>

using namespace std;

// Function prototypes
void Day();
void BookHour();
void CourtSelection();
double CalculatePrice(int bookHour, double price);
void Display(int ReceiptNo);
double CourtPrice(int courtNames);
void Membership(double TotalPrice[]);

char bookingCourtName[5][50], bookingDay[5][20];
int bookingStartHour[5], bookingMinute[5], bookingHour[5];
double TotalPrice[5];
int NoOfBook = 0;
const int maxcourt = 5;

int main()
{
    int choice = 0, ReceiptNo;
    char member;
    double PriceCourt = 0; // Declare PriceCourt outside the switch statement
	
	cout << "====================================================================" <<endl;
	cout << ">                       COURT BOOKING SYSTEM                       <" <<endl;
	cout << "====================================================================" <<endl;
	
    while (choice != 3)
	{
		cout << "\n--------------------------------------------------------------------"<<endl;
		cout << "\nMAIN MENU"<<endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" <<endl;
		cout << "|PRICE FOR EACH COURT:                                              |" <<endl;
		cout << "|                                                                   |" <<endl;
		cout << "|FUTSAL     = RM 80 Per hour                                        |" <<endl;
		cout << "|BADMINTON  = RM 20 Per hour                                        |" <<endl;
		cout << "|TENNIS     = RM 50 Per hour                                        |" <<endl;
		cout << "|                                                                   |" <<endl;
		cout << "|MEMBERS WILL GET 10% DISCOUNT                                      |" <<endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" <<endl;
		
        cout << "[1] Book a court" << endl;
        cout << "[2] Display bookings" << endl;
        cout << "[3] Exit" << endl;
        cout << "Please enter your choice(Insert code): ";
        cin >> choice; // Move the input statement for 'choice' inside the loop

        int count = 0, courtNames, dayName, startHour, startMinute, bookHour;
  	    switch (choice)
		{

	        case 1:
	           	if (NoOfBook < maxcourt)
				{
	           		CourtSelection();
		            cin >> courtNames;
					while (courtNames > 3 || courtNames < 1)
					{
					cout << "\nINVALID CODE !!! ";
					CourtSelection();
					cin >> courtNames;
					}
					Day();
					cin >> dayName;
					while (dayName > 7 || dayName < 1)
					{
						cout << "\nINVALID CODE !!! ";
						Day();
						cin >> dayName;
		            }
		            
					BookHour();
		            cin >> bookHour;
		            while (bookHour > 3 || bookHour < 1)
					{
		                cout << "\nINVALID CODE !!! ";
		                BookHour();
		                cin >> bookHour;
		            }
		
		            cout << "\nEnter start playing time ( 24 hour format, HH:MM) : ";
		            cin >> startHour;
		            char colon;
		            cin >> colon >> startMinute;
		            while (colon != ':' || startHour > 23 || startMinute > 59)
					{
		                cout << "Invalid input format. Please use the format \"HH:MM\"." << endl;
		                cout << "Enter start playing time (HH:MM) : ";
		                cin >> startHour >> colon >> startMinute;
		            }
		            PriceCourt = CourtPrice(courtNames);
		            TotalPrice[NoOfBook] = CalculatePrice(bookHour, PriceCourt);
					
					//Determine Type of court in the array
					if (courtNames == 1)
					{
		                strcpy(bookingCourtName[NoOfBook], "Futsal");
		            }
		            else if (courtNames == 2)
					{
		                strcpy(bookingCourtName[NoOfBook], "Badminton");
		            }
		            else if (courtNames == 3)
					{
		                strcpy(bookingCourtName[NoOfBook], "Tennis");
		            }
		
		        	// Storing the day of booking in the array
		            if (dayName == 1)
					{
		                strcpy(bookingDay[NoOfBook], "Monday");
		            }
		            else if (dayName == 2)
					{
		                strcpy(bookingDay[NoOfBook], "Tuesday");
		            }
		            else if (dayName == 3)
					{
		                strcpy(bookingDay[NoOfBook], "Wednesday");
		            }
		            else if (dayName == 4)
					{
		                strcpy(bookingDay[NoOfBook], "Thursday");
		            }
		            else if (dayName == 5)
					{
		                strcpy(bookingDay[NoOfBook], "Friday");
		            }
		            else if (dayName == 6)
					{
		                strcpy(bookingDay[NoOfBook], "Saturday");
		            }
		            else if (dayName == 7)
					{
		                strcpy(bookingDay[NoOfBook], "Sunday");
		            }
		
		            // Storing the time
		            bookingStartHour[NoOfBook] = startHour;
		            bookingMinute[NoOfBook] = startMinute;
		            bookingHour[NoOfBook] = bookHour;
		                
		            cout << "\nDo you have membership? (Y for Yes, N for No): ";
					cin >> member;
					while (member != 'Y' && member != 'N')
					{
						cout << "\nInvalid Answer. ";
						cout << "Do you have membership? (Y for Yes, N for No): ";
					    cin >> member;
					}
					if (member == 'Y')
					{
						Membership(TotalPrice);
					}
		
		            NoOfBook++;
		            break;
				}
				else
				{
	            cout << "\nYou have exceeded max court bookings" << endl;
	        	}
	                
	
	        case 2:
	            if (NoOfBook == 0)
				{
	                cout << "\nNo bookings made yet!" << endl;
	            }
	            else
				{
	                // Display the list of bookings with Total Price
	                cout << "\n-------------------------------------------------------------------"<<endl; 
					cout << "\nList of Bookings with Total Price:" << endl;
					for (int i = 0; i < NoOfBook; i++)
					{
					    cout << "[" << i + 1 << "] Book " << i + 1 << " - Total Price: RM " << TotalPrice[i] << endl;
					}
	
	                cout << "\nPlease enter your choice(Insert code): ";
	                cin >> ReceiptNo;
	                while (ReceiptNo < 1 || ReceiptNo > NoOfBook)
					{
	                    cout << "INVALID CODE !!! " << endl;
	                    cout << "Please enter your choice(Insert code): "<< endl;
	                    cin >> ReceiptNo;
	                }
	
	                Display(ReceiptNo);
	            }
	            break;

            case 3:
                break;

            default:
                cout << "\nInvalid code " << endl;
                break;
        }
        
    }

    

    cout << "\nThank You For Booking" << endl;
    return 0;
}

//Display list of day
void Day()
{
	cout << "\n-------------------------------------------------------------------"<<endl;
    cout << "[1] Monday" << endl;
    cout << "[2] Tuesday" << endl;
    cout << "[3] Wednesday" << endl;
    cout << "[4] Thursday" << endl;
    cout << "[5] Friday" << endl;
    cout << "[6] Saturday" << endl;
    cout << "[7] Sunday" << endl;
    cout << "Select day(Insert code): ";
}

//Display List of booking hour
void BookHour()
{
	cout << "\n-------------------------------------------------------------------"<<endl;
    cout << "You can only choose 3 hours only " << endl;
    cout << "[1] 1 Hour" << endl;
    cout << "[2] 2 Hours" << endl;
    cout << "[3] 3 Hours" << endl;
    cout << "Enter package hour(Insert code): ";
}

//Displaying selection of court
void CourtSelection()
{
	cout << "\n-------------------------------------------------------------------"<<endl;
    cout << "[1] Futsal" << endl;
    cout << "[2] Badminton" << endl;
    cout << "[3] Tennis" << endl;
    cout << "Select court(Insert code): ";
}

// Calculate the price for the booking
double CalculatePrice(int bookHour, double price)
{
    double totalPrice = bookHour * price; 
    return totalPrice; // Return the calculated totalPrice
}

// Displaying Print Slip
void Display(int ReceiptNo)
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "Book " << ReceiptNo << endl;
    cout << "Day booked: " << bookingDay[ReceiptNo - 1] << endl;
    cout << "Court booked: " << bookingCourtName[ReceiptNo - 1] << endl;
    cout << "Booking Time: " << bookingHour[ReceiptNo - 1] << " Hours" << endl;
    cout << "Start playing time: " << bookingStartHour[ReceiptNo - 1] << ":" << bookingMinute[ReceiptNo - 1] << endl;
    cout << "Total Price: RM " << TotalPrice[ReceiptNo - 1] << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

// Declaring price per hour of each court
double CourtPrice(int courtNames)
{
    double price;
    if (courtNames == 1)
	{
        price = 80;
    }
    else if (courtNames == 2)
	{
        price = 20;
    }
    else if (courtNames == 3)
	{
        price = 50;
    }
    return price;
}

// Calculate 10% discount to the total price for member
void Membership(double TotalPrice[])
{
    TotalPrice[NoOfBook] *= 0.90;
}
