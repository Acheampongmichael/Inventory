#include <iostream>
#include <iomanip>
using namespace std;

struct InventoryBin
{
    string partDesc;        /* Inventory bin part description  */
    int    numParts;        /* Number of parts in the invetory bins */

    InventoryBin(string pD = "N/A", int nP = 30)
    {
        partDesc = pD;
        numParts = nP;
    }

    ~InventoryBin()
    {
    }
};

enum options
{
    ADD_PARTS = 1, REMOVE_PARTS = 2, QUIT = 3
};

void menu(InventoryBin[], const int);
void display_Bins(InventoryBin[], const int);
int  getBinID(const int);
void add_Parts(InventoryBin[], const int, const int, const int);
void remove_Parts(InventoryBin[], const int, const int, const int);

int main()
{
    const int BINS = 10;


    InventoryBin invBins[BINS] = { { "Valve" ,10 },    { "Bearing",  5 },
                                       { "Bushing",  15 },   { "Coupling", 21 },
                                        { "Flange",  7 }, { "Gear",  5 },
                                       { "Gear Housing",    5 }, { "Vacuum Gripper", 25 },
                                        { "Cable", 18 },{ "Rod", 12 } };

    menu(invBins, BINS);


    return 0;
}



void menu(InventoryBin invBins[], const int BINS)
{
    const int MAX_PARTS = 30;
    const int MIN_PARTS = 0;
    int selection = 0;
    int binID = 0;

    display_Bins(invBins, BINS);

    do
    {

        cout << "\n\tChoose [1] to add items\n"
            << "\tChoose [2] to remove items\n"
            << "\tChoose [3] to quit\n\n"
            << "\tChoose: ";
        cin >> selection;

        while (selection < ADD_PARTS || selection > QUIT)
        {
            cout << "\tChoose : ";
            cin >> selection;
        }

        switch (selection)
        {
        case ADD_PARTS:
        {
            binID = getBinID(BINS);

            if (invBins[binID].numParts != MAX_PARTS)
            {
                add_Parts(invBins, binID, MAX_PARTS, BINS);
            }

            display_Bins(invBins, BINS);
        } break;

        case REMOVE_PARTS:
        {
            binID = getBinID(BINS);

            if (invBins[binID].numParts != MIN_PARTS)
            {
                remove_Parts(invBins, binID, MIN_PARTS, BINS);
            }

            display_Bins(invBins, BINS);
        } break;

        case QUIT:
        {
            cout << "\n\tMICHAEL's WAREHOUSE-- WHERE EVERYONE SHOPS";
        }
        }
    } while (selection != QUIT);
}


void display_Bins(InventoryBin invBins[], const int BINS)
{
    cout << "\t\t    MICHAEL's WAREHOUSE INVENTORY\n\n"
        << "\tBin\t    Part Description"
        << setw(25) << right << "Number of parts\n\n";

    for (int index = 0; index < BINS; index++)
    {
        cout << "\t";
        cout << setw(12) << left << (index + 1)
            << setw(15) << left << invBins[index].partDesc
            << setw(30) << right << invBins[index].numParts << "\n";
    }
}



int getBinID(const int BINS)
{
    int binID = 0;

    cout << "\n\tEnter Bin Number: ";
    cin >> binID;

    while (binID < 1 || binID > BINS)
    {
        cout << "\n\tEnter Bin Number: ";
        cin >> binID;
    }

    return binID -= 1;
}



void add_Parts(InventoryBin invBins[], const int selection,
    const int MAX_PARTS, const int BINS)
{
    int add = 0;

    cout << "\n\tEnter number of parts to add: ";
    cin >> add;

    while (add < 0)
    {
        cout << "\tEnter number of parts to add: ";
        cin >> add;
    }

    while (invBins[selection].numParts + add > MAX_PARTS)
    {
        cout << "\n\tMaximum Part Number 30 items\n\n"
            << "\tEnter number of parts: ";
        cin >> add;
    }

    if (invBins[selection].numParts + add <= MAX_PARTS)
    {
        invBins[selection].numParts += add;
    }
}


void remove_Parts(InventoryBin invBins[], const int selection,
    const int MIN_PARTS, const int BINS)
{
    int take = 0;

    cout << "\n\tEnter number of parts to remove: ";
    cin >> take;

    while (take < 0)
    {
        cout << "\tEnter number of parts to remove: ";
        cin >> take;
    }

    while (invBins[selection].numParts - take < MIN_PARTS)
    {
        cout << "\n\tToo many parts selected\n\n"
            << "\tEnter number of parts to remove: ";
        cin >> take;
    }

    if (invBins[selection].numParts - take >= MIN_PARTS)
    {
        invBins[selection].numParts -= take;
    }
}
