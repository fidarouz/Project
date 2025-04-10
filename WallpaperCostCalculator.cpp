/*
Name				: MUHAMMAD FIDAROUS BIN ABDUL HADI
Sid			    	: 2023167637
Course			    : CSC126 
Group				: A4CDCS1101B
Due Date			: 14 June 2023 5:00 pm
Question No	    	: 1
Program Description	: C++
*/

#include <iostream>
using namespace std;

int main() {
    double roomWidth, roomHeight, doorWidth, doorHeight;
    double rollSize = 5.0;
    double wallpaperCost = 100.00;
    double laborCost = 10.00;

    cout << "Enter the width of the room (in meters): ";
    cin >> roomWidth;

    cout << "Enter the height of the room (in meters): ";
    cin >> roomHeight;

    cout << "Enter the width of the door (in meters): ";
    cin >> doorWidth;

    cout << "Enter the height of the door (in meters): ";
    cin >> doorHeight;

    double totalWallArea = 2 * (roomWidth + roomHeight) * roomHeight;
    
    double doorArea = doorWidth * doorHeight;

    double rollsNeeded = totalWallArea / rollSize;

    double totalCost = (rollsNeeded * wallpaperCost) + (rollsNeeded * laborCost);

    cout << "\nNumber of wallpaper rolls you needed: " << rollsNeeded << endl;
    cout << "\nTotal cost: RM" << totalCost << endl;

    return 0;
}

