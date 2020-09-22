// CS 136 - lab 1.cpp
/*  Paolo Barone
    CS 136 Data Structures - Thurs. 9:00 am
    Lab 1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Line
{
public:
    string itemID, itemName;
    int quantityOnHand = 0;
    double price = 0.0;

    void printRecordUnsorted(Line lineA[], int numLines)
    {
        //cout << "Entering function printRecordUnsorted." << endl;

        cout << left;
        cout << "                     INVENTORY\n";
        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;

        for (int i = 0; i < numLines; i++)
        {
           

            cout << setw(15) << lineA[i].itemID << setw(15) << lineA[i].itemName << setw(15) << lineA[i].quantityOnHand << "$" << setw(15) << lineA[i].price << endl;
        }

        //cout << "Exiting function printRecordUnsorted." << endl;
    }

    void printRecord(Line lineA[], int numLines)
    {
    
        //cout << "Entering function printRecord()." << endl;

        cout << left;
        cout << "                     INVENTORY\n";
        
        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;

        for (int i = 0; i < numLines; i++)
        {


            cout << setw(15) << lineA[i].itemID << setw(15) << lineA[i].itemName << setw(15) << lineA[i].quantityOnHand << "$" << setw(15) << lineA[i].price << endl;
        }

        //cout << "Exiting function printRecord()." << endl;
    }

    void printOneLine(Line lineA[], int lineNumber)
    {
        int i = lineNumber;
        cout << left;
        cout << "                     INVENTORY\n";

        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;
        cout << setw(15) << lineA[i].itemID << setw(15) << lineA[i].itemName << setw(15) << lineA[i].quantityOnHand << "$" << setw(15) << lineA[i].price << endl;

    }

    void printReport(Line lineA[], int numLines)
    {
        int totalQuantity = 0;
        double totalValue = 0.0;

        for (int i = 0; i < numLines; i++)
        {
            totalQuantity += lineA[i].quantityOnHand;
            totalValue += (lineA[i].quantityOnHand * lineA[i].price);
        }

        /*
        print a report with the following details
            number of  unique items in the inventory
            the total worth of the inventoryand the total count of all items in the inventory
        */
        cout << "                    REPORT\n";
        cout << "Number of  unique items in the inventory: " << numLines << endl;
        cout << "Total count of all items in the inventory: " << totalQuantity << endl;
        cout << "Total worth of the inventory: $" << totalValue << endl;
    
    }

private:
};

void mySort(Line* inventory, int size, int sortBy);
void swap1(Line *x, Line *y);

void PrintMenu()
{
    cout << "\n                   INVENTORY\n\n";
    cout << "1 -- Print the inventory unsorted" << endl;
    cout << "2 -- Sort by item ID" << endl;
    cout << "3 -- Sort by item name" << endl;
    cout << "4 -- Sort by quantity on hand" << endl;
    cout << "5 -- Sort by price" << endl;
    cout << "6 -- Search by item ID" << endl;
    cout << "7 -- Search by item name" << endl;
    cout << "8 -- Print a report\n" << endl;
    cout << "9 -- Quit the program\n" << endl;
}

void ClearScreen()
{
    for (int i = 0; i < 30; i++)
    {
        cout << endl;
    }
}

//Swap function
void swap1(Line *x, Line *y)
{
    Line temp = *x;
    *x = *y;
    *y = temp;
}

//Another Bubble sort that works
//sorting using bubble sort.
void mySort(Line *inventory, int size, int sortBy)
{
    /* OPTIMIZED BUBBLE SORT PSEUDOCODE
    procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        newn := 0
        for i := 1 to n - 1 inclusive do
            if A[i - 1] > A[i] then
                swap(A[i - 1], A[i])
                newn := i
            end if
        end for
        n := newn
    until n ≤ 1
    end procedure
    */

    int n = size, newn = 0;

    //cout << "Entering sort()\n";

    do  // ***, itemID, itemName, quantityOnHand, price
    {
        newn = 0;
        for (int i = 1; i <= (n - 1); i++)
        {
            switch (sortBy) 
            {
            case 0: // sort by itemID
                if (inventory[i - 1].itemID > inventory[i].itemID)
                {
                    swap1(&inventory[i - 1], &inventory[i]);
                    newn = i;
                }
                break;
            case 1:
                if (inventory[i - 1].itemName > inventory[i].itemName)
                {
                    swap1(&inventory[i - 1], &inventory[i]);
                    newn = i;
                }
                break;
            case 2:
                if (inventory[i - 1].quantityOnHand > inventory[i].quantityOnHand)
                {
                    //swap1(inventory[i - 1].quantityOnHand, inventory[i].quantityOnHand); 
                    swap1(&inventory[i - 1], &inventory[i]); 
                    newn = i;
                }
                break;
            case 3:
                if (inventory[i - 1].price > inventory[i].price)
                {
                    //swap1(inventory[i - 1].price, inventory[i].price); 
                    swap1(&inventory[i - 1], &inventory[i]);
                    newn = i;
                }
                break;
            default:
                cout << "Error: Improper sortBy code: " << sortBy << endl;
                break;
            }
        }
        n = newn;
    } while (!(n <= 1));  //until n ≤ 1
     
    //cout << "Exiting sort()\n";
}

/*
you should allow a user sort by any field : item ID, item name(one word), quantity on hand, or price.Write one function, that can sort by any field using array of pointers.Do not copy and paste sort code five times into the same function.Bubble sort  is the easiest to modify.
search  for an item by ID or name; a user should be able to enter the name of the item using any case, (for example, sTRolleR).You may wish to store items in all lower / upper case to expedite the search.
print a report with the following details
number of  unique items in the inventory
the total worth of the inventoryand the total count of all items in the inventory
quit the program
*/

void ReadFile(Line* lineA, int& count, int& numLines)
{
    ifstream inFS;  // Input file stream
        
    //string fileInventory;  // Input file stream
    string itemID = "", itemName = "";
    int quantityOnHand = 0;
    double price = 0.0;
    //int fractionalQty;
    

    inFS.open("inventory_items.txt");

    if (!inFS.is_open()) 
    {
        cout << "Could not open file inventory_items.txt." << endl;
    }
    else
    {
        /*
        cout << "Reading two strings, an integer, and a double." << endl;
        cout << "Count: " << count << endl;
        */

        inFS >> lineA[count].itemID;
        inFS >> lineA[count].itemName;
        inFS >> lineA[count].quantityOnHand;
        
        if (lineA[count].quantityOnHand < 0)
        {
            cout << "***ERROR: quantity on hand, " << lineA[count].quantityOnHand << ", is negative.\n";
            system("pause");
        }

        /*
        cout << "whole part: " << (int)pi << "\n";
        cout << "fractional part: " << (int)((pi - (int)pi) * 100) << "\n";
        fractionalQty = (int)( ( (quantityOnHand)-(int)quantityOnHand ) * 100 );
                     // (int)( ( (1.2345 - 1) ) * 100 )
                     // (int)
        cout << "fractional part of quantity on hand: " << fractionalQty << endl;
                
        if (fractionalQty > 0)
        {
            cout << "***ERROR: quantity on hand, " << quantityOnHand << ", is not an integer value.\n";
            system("pause");
        }
        */
        
        inFS >> lineA[count].price;
        if (lineA[count].price < 0)
        {
            cout << "***ERROR: price, $" << lineA[count].price << " is negative\n";
            system("pause");
        }

        /*
        //Debug output
        cout << "lineA[" << count << "].itemID: " << lineA[count].itemID << endl;
        cout << "lineA[" << count << "].itemName: " << lineA[count].itemName << endl;
        cout << "lineA[" << count << "].quantityOnHand: " << lineA[count].quantityOnHand << endl;
        cout << "lineA[" << count << "].price: " << lineA[count].price << endl;

        //        system("pause");
        */

        while (!inFS.fail())
        {
            numLines++;
            count++;

            inFS >> lineA[count].itemID;
            inFS >> lineA[count].itemName;
            inFS >> lineA[count].quantityOnHand;
            if (lineA[count].quantityOnHand < 0)
            {
                cout << "***ERROR: quantity on hand, " << lineA[count].quantityOnHand << ", is negative.\n";
                system("pause");
            }

            inFS >> lineA[count].price;
            if (lineA[count].price < 0)
            {
                cout << "***ERROR: price, $" << lineA[count].price << " is negative\n";
                system("pause");
            }

            //            system("pause");
        }

        //cout << "Closing file inventory_items.txt.\n" << endl;
        inFS.close();

        //cout << "count: " << count << endl;
        //cout << "numLines: " << numLines << endl;
    }

}

int BinarySearch(Line numbers[], int numbersSize, int searchCode, string key) {
    int mid;
    int low;
    int high;

    low = 0;
    high = numbersSize - 1;

    if (searchCode == 0) // Search by itemID
    {
        while (high >= low) {
            mid = (high + low) / 2;
            if (numbers[mid].itemID < key) {
                low = mid + 1;
            }
            else if (numbers[mid].itemID > key) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
    }
    else if (searchCode == 1) //Search by itemName
    {
        while (high >= low) {
            mid = (high + low) / 2;
            if (numbers[mid].itemName < key) {
                low = mid + 1;
            }
            else if (numbers[mid].itemName > key) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
    }
    else
    {
        cout << "ERROR: improper searchCode value of " << searchCode << endl;
    }
    
    return -1; // not found
}

int main()
{
    char menuChoice = '0'; // Menu input choice
   
    int i = 0, x = 0;
    Line lineA[100];
    int numLines = 0, count = 0;
    string searchKey = "";

    for (int i = 0; i <= 99; i++)
    {
        lineA[i].itemID = "";
        lineA[i].itemName = "";
        lineA[i].quantityOnHand = 0;
        lineA[i].price = 0.0;
    }

    //Read file
    ReadFile(lineA, count, numLines);
    
    //cout << "numLines: " << numLines;
 
    // parse menu choice
    do
    {
        PrintMenu();
        cout << "Enter your choice: ";
        cin >> menuChoice;
        cout << endl;

        //cout << "\n" << menuChoice << " was pressed.\n";

        switch (menuChoice)
        {
        case '1':
            // Print the inventory unsorted
            ClearScreen();
            //cout << "1 pressed\n";
            lineA[0].printRecordUnsorted(lineA, numLines);
            break;

        case '2':
            // Sort by item ID
            ClearScreen();
            //cout << "2 pressed\n";
            //cout << "numlines: " << numLines << endl;
            mySort(lineA, numLines, 0);
            lineA[0].printRecord(lineA, numLines);

            break;

        case '3':
            // Sort by itemName
            ClearScreen();
            //cout << "3 pressed\n";
            mySort(lineA, numLines, 1);
            lineA[0].printRecord(lineA, numLines);
            break;

        case '4':
            // Sort by quantityOnHand
            ClearScreen();
            //cout << "4 pressed\n";
            mySort(lineA, numLines, 2);
            lineA[0].printRecord(lineA, numLines);
            break;

        case '5':
            // Sort by price
            ClearScreen();
            //cout << "5 pressed\n";
            mySort(lineA, numLines, 3);
            lineA[0].printRecord(lineA, numLines);
            break;

        case '6':
            // Search by itemID
            //ClearScreen();
            //cout << "6 pressed\n";
            cout << "Search by item ID\nEnter an item ID to search for: ";
            cin >> searchKey;
            cout << endl;

            x = BinarySearch(lineA, numLines, 0, searchKey);
            //cout << "x: " << x << endl; 
            if (x >= 0)
            {
                lineA[x].printOneLine(lineA, x);
            }
            else
            {
                cout << "Item ID " << searchKey << " not found.\n";
            }
            break;

        case '7':
            // Search by itemName
            //ClearScreen();
            //cout << "7 pressed\n";
            cout << "Search by item name\nEnter an item name to search for: ";
            cin >> searchKey;

            x = BinarySearch(lineA, numLines, 1, searchKey);
            //cout << "x: " << x << endl;
            if (x >= 0)
            {
                lineA[x].printOneLine(lineA, x);
            }
            else
            {
                cout << "Item ID " << searchKey << " not found.";
            }
            
            break;

        case '8':
            //Print a report
            //ClearScreen();
            //cout << "8 pressed\n";
            lineA[0].printReport(lineA, numLines);
            break;

        case '9':
            // Exit the program 
            //cout << "9 pressed\n";
            break;

        default:
            // Print "unknown"
            cout << "\nPlease only input a character of value between 1 and 9.\n";
            system("pause");
            ClearScreen();
            break;
        }
    } while (menuChoice != '9');

    cout << endl;

    //system("pause");
    return 0;
}
