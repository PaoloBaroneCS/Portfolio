// CS 136 - lab 1.cpp
/*  Paolo Barone CS136 data Structures - Thurs. 9:00 am
    Lab 1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;



struct InventoryItem
{
    string itemID, itemName;
    int quantityOnHand;
    double price;
};

void ReadFile(InventoryItem item[] , int& count);
void mySort(InventoryItem* inventory, int size, int sortBy);
void swap1(InventoryItem* x, InventoryItem* y);
void PrintMenu();
void ClearScreen();
int BinarySearch(InventoryItem numbers[], int numbersSize, int searchCode, string key);
void printRecord(InventoryItem item[], int count);
void printReport(InventoryItem item[], int count);
void printRecordUnsorted(InventoryItem item[], int count);
void printOneLine(InventoryItem item[], int lineNumber);

int main()
{
    char menuChoice = '0'; // Menu input choice
    InventoryItem Line[100];
    InventoryItem* ptr[100];

    int i = 0, x = 0;
    //Line item[100];
    int count = 0;
    string searchKey = "", searchKeyLowerCase = "";

    /*
    for (int i = 0; i <= 99; i++)
    {
        item[i].itemID = "";
        item[i].itemName = "";
        item[i].quantityOnHand = 0;
        item[i].price = 0.0;
    }
    */

    //Read file
    ReadFile(Line, count);
    //To do: Fill pointer array here
    
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
            printRecordUnsorted(&Line[0], count);
            break;

        case '2':
            // Sort by item ID
            ClearScreen();
            //cout << "2 pressed\n";
            //cout << "count: " << count << endl;
            mySort(Line, count, 0);
            printRecord(Line, count);

            break;

        case '3':
            // Sort by itemName
            ClearScreen();
            //cout << "3 pressed\n";
            mySort(Line, count, 1);
            printRecord(&Line[0], count);
            break;

        case '4':
            // Sort by quantityOnHand
            ClearScreen();
            //cout << "4 pressed\n";
            mySort(&Line[0], count, 2);
            printRecord(&Line[0], count);
            break;

        case '5':
            // Sort by price
            ClearScreen();
            //cout << "5 pressed\n";
            mySort(&Line[0], count, 3);
            printRecord(&Line[0], count);
            break;

        case '6':
            // Search by itemID
            //ClearScreen();
            //cout << "6 pressed\n";
            cout << "Search by item ID\nEnter an item ID to search for: ";
            cin >> searchKey;
            cout << endl;

            mySort(Line, count, 0);

            x = BinarySearch(Line, count, 0, searchKey);
            //cout << "x: " << x << endl; 
            if (x >= 0)
            {
                printOneLine(Line, x);
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

            searchKeyLowerCase = "";
            cout << "searchKey: " << searchKey << endl;
            //searchKey = tolower(searchKey);
            for (unsigned i = 0; i < searchKey.length(); i++)
            {
                searchKeyLowerCase += tolower(searchKey[i]);
            }
            //cout << "searchKeyLowerCase: " << searchKeyLowerCase << endl;
            //cout << "count: " << count << endl;

            mySort(Line, count, 1);

            x = BinarySearch(Line, count, 1, searchKeyLowerCase);
            //cout << "x: " << x << endl;
            if (x >= 0)
            {
                printOneLine(Line, x);
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
            printReport(Line, count);
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

//void ReadFile(Line* item, int& count)
void ReadFile(InventoryItem item[], int& count)
{
    //cout << "Entering ReadFile.\n";

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

        inFS >> item[count].itemID;
        inFS >> item[count].itemName;
        inFS >> item[count].quantityOnHand;

        /*
        if (item[count].quantityOnHand < 0)
        {
            cout << "***ERROR: quantity on hand, " << item[count].quantityOnHand << ", is negative.\n";
            system("pause");
        }
        */

        inFS >> item[count].price;
        /*
        if (item[count].price < 0)
        {
            cout << "***ERROR: price, $" << item[count].price << " is negative\n";
            system("pause");
        }
        */

        /*
        //Debug output
        cout << "item[" << count << "].itemID: " << item[count].itemID << endl;
        cout << "item[" << count << "].itemName: " << item[count].itemName << endl;
        cout << "item[" << count << "].quantityOnHand: " << item[count].quantityOnHand << endl;
        cout << "item[" << count << "].price: " << item[count].price << endl;
        */

        //        system("pause");
    }
    while (!inFS.fail())
    {
        //count++;
        count++;

        inFS >> item[count].itemID;
        inFS >> item[count].itemName;
        inFS >> item[count].quantityOnHand;
        
        /*
        if (item[count].quantityOnHand < 0)
        {
            cout << "***ERROR: quantity on hand, " << item[count].quantityOnHand << ", is negative.\n";
            system("pause");
        }
        */

        inFS >> item[count].price;
        /*
        if (item[count].price < 0)
        {
            cout << "***ERROR: price, $" << item[count].price << " is negative.\n";
            system("pause");
        }
        */

        //            system("pause");
    }

    //cout << "Closing file inventory_items.txt.\n" << endl;
    inFS.close();

    //cout << "count: " << count << endl;
    //cout << "count: " << count << endl;

    //cout << "Exiting ReadFile.\n";
    return;
}

    void printRecordUnsorted(InventoryItem item[], int count)
    {
        //cout << "Entering function printRecordUnsorted." << endl;

        cout << left;
        cout << "                     INVENTORY\n";
        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;

        for (int i = 0; i < count; i++)
        {
            //double twoDecimalPlaces = ceil(item[i].price * 100.0) / 100.0;
            //cout << "twoDecimalPlaces: " << twoDecimalPlaces << endl;
            cout << setw(15) << item[i].itemID << setw(15) << item[i].itemName << setw(15) << item[i].quantityOnHand << "$" << setw(15) << item[i].price << endl;
            //cout << setw(15) << item[i].itemID << setw(15) << item[i].itemName << setw(15) << item[i].quantityOnHand << "$" << setw(15) << twoDecimalPlaces << endl;
            //string displayPrice = item[i].price.ToString("0.00");
            //out << setw(15) << item[i].itemID << setw(15) << item[i].itemName << setw(15) << item[i].quantityOnHand << "$" << setw(15) << String.Format("{0:0.00}", item[i].price) << endl;
        }

        //cout << "Exiting function printRecordUnsorted." << endl;
    }

    void printRecord(InventoryItem item[], int count)
    {

        //cout << "Entering function printRecord()." << endl;

        cout << left;
        cout << "                     INVENTORY\n";

        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;

        for (int i = 0; i < count; i++)
        {


            cout << setw(15) << item[i].itemID << setw(15) << item[i].itemName << setw(15) << item[i].quantityOnHand << "$" << setw(15) << item[i].price << endl;
        }

        //cout << "Exiting function printRecord()." << endl;
    }

    void printOneLine(InventoryItem item[], int lineNumber)
    {
        int i = lineNumber;
        cout << left;
        cout << "                     INVENTORY\n";

        cout << setw(15) << "Item ID" << setw(15) << "Item Name" << setw(15) << setw(15) << "Qty. on Hand" << setw(15) << "Price" << endl;
        cout << setw(15) << item[i].itemID << setw(15) << item[i].itemName << setw(15) << item[i].quantityOnHand << "$" << setw(15) << item[i].price << endl;

    }

    
        /*
        print a report with the following details
            number of  unique items in the inventory
            the total worth of the inventoryand the total count of all items in the inventory
        */

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
    /*
    for (int i = 0; i < 30; i++)
    {
        cout << endl;
    }
    */
    cout << endl << endl;
}

//Swap function
void swap1(InventoryItem* x, InventoryItem* y)
{
    InventoryItem temp = *x;
    *x = *y;
    *y = temp;
}

//Another Bubble sort that works
//sorting using bubble sort.
void mySort(InventoryItem* inventory, int size, int sortBy)
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
            case 1: // sort by itemName
                if (inventory[i - 1].itemName > inventory[i].itemName)
                {
                    swap1(&inventory[i - 1], &inventory[i]);
                    newn = i;
                }
                break;
            
            case 3: // sort by price
                if (inventory[i - 1].price > inventory[i].price)
                {
                    swap1(&inventory[i - 1], &inventory[i]);
                    newn = i;
                }
                break;

            case 2: // sort by quantityOnHand
                if (inventory[i - 1].quantityOnHand > inventory[i].quantityOnHand)
                {
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

int BinarySearch(InventoryItem numbers[], int numbersSize, int searchCode, string key) {
    int mid;
    int low;
    int high;

    low = 0;
    high = numbersSize - 1;

    if (searchCode == 0) // Search by itemID
    {
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (numbers[mid].itemID < key)
            {
                low = mid + 1;
            }
            else if (numbers[mid].itemID > key)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    else if (searchCode == 1) //Search by itemName
    {
        string keyLowerCase = "";
        for (unsigned i = 0; i < key.size(); i++)
        {
            keyLowerCase += tolower(key[i]);
        }

        while (high >= low)
        {
            mid = (high + low) / 2;
            if (numbers[mid].itemName < keyLowerCase)
            {
                low = mid + 1;
            }
            else if (numbers[mid].itemName > keyLowerCase)
            {
                high = mid - 1;
            }
            else
            {
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

void printReport(InventoryItem item[], int count)
{
    int totalQuantity = 0;
    double totalValue = 0.0;

    for (int i = 0; i < count; i++)
    {
        totalQuantity += item[i].quantityOnHand;
        totalValue += (item[i].quantityOnHand * item[i].price);
    }

    /*
    print a report with the following details
        number of  unique items in the inventory
        the total worth of the inventoryand the total count of all items in the inventory
    */
     

            cout << "                    REPORT\n";
            cout << "Number of unique items in the inventory: " << count << endl;
            cout << "Total count of all items in the inventory: " << totalQuantity << endl;
            cout << "Total worth of the inventory: $" << totalValue << endl;

        }

/*
OUTPUT:


                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 1



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00200          pens           78             $3.99
10123          stapler        15             $5.49
10301          tablet_PC      12             $1000
10401          iPhone_X       25             $999.99
10124          staples        99             $2.59
10201          desktop_PC     10             $599.99
00100          pencils        89             $12.49
00050          paper          35             $5.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 2



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00050          paper          35             $5.99
00100          pencils        89             $12.49
00200          pens           78             $3.99
10123          stapler        15             $5.49
10124          staples        99             $2.59
10201          desktop_PC     10             $599.99
10301          tablet_PC      12             $1000
10401          iPhone_X       25             $999.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 3



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
10201          desktop_PC     10             $599.99
10401          iPhone_X       25             $999.99
00050          paper          35             $5.99
00100          pencils        89             $12.49
00200          pens           78             $3.99
10123          stapler        15             $5.49
10124          staples        99             $2.59
10301          tablet_PC      12             $1000

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 4



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
10201          desktop_PC     10             $599.99
10301          tablet_PC      12             $1000
10123          stapler        15             $5.49
10401          iPhone_X       25             $999.99
00050          paper          35             $5.99
00200          pens           78             $3.99
00100          pencils        89             $12.49
10124          staples        99             $2.59

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 5



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
10124          staples        99             $2.59
00200          pens           78             $3.99
10123          stapler        15             $5.49
00050          paper          35             $5.99
00100          pencils        89             $12.49
10201          desktop_PC     10             $599.99
10401          iPhone_X       25             $999.99
10301          tablet_PC      12             $1000

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 6

Search by item ID
Enter an item ID to search for: 00050

                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00050          paper          35             $5.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 6

Search by item ID
Enter an item ID to search for: 09

Item ID 09 not found.

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 1



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00050          paper          35             $5.99
00100          pencils        89             $12.49
00200          pens           78             $3.99
10123          stapler        15             $5.49
10124          staples        99             $2.59
10201          desktop_PC     10             $599.99
10301          tablet_PC      12             $1000
10401          iPhone_X       25             $999.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 7

Search by item name
Enter an item name to search for: PEns
searchKey: PEns
                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00200          pens           78             $3.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 1



                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
10201          desktop_PC     10             $599.99
10401          iPhone_X       25             $999.99
00050          paper          35             $5.99
00100          pencils        89             $12.49
00200          pens           78             $3.99
10123          stapler        15             $5.49
10124          staples        99             $2.59
10301          tablet_PC      12             $1000

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 7

Search by item name
Enter an item name to search for: PaPeR
searchKey: PaPeR
                     INVENTORY
Item ID        Item Name      Qty. on Hand   Price
00050          paper          35             $5.99

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 8

                    REPORT
Number of unique items in the inventory: 8
Total count of all items in the inventory: 363
Total worth of the inventory: $44970.9

                   INVENTORY

1 -- Print the inventory unsorted
2 -- Sort by item ID
3 -- Sort by item name
4 -- Sort by quantity on hand
5 -- Sort by price
6 -- Search by item ID
7 -- Search by item name
8 -- Print a report

9 -- Quit the program

Enter your choice: 9
*/

    