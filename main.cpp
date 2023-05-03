#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <iomanip>
using namespace std;
bool b = true;

class Details
{
private:
    // Json object which contains details of different users, Use File Handling here.
    string username;
    string password; // Hidden from view
    string email;
    string firstname;
    string lastname;

protected:
    string getPassword()
    {
        return password;
    }

public:
    void setUsername(string username)
    {
        this->username = username;
    }
    void setPassword(string password) // Set password without other seeing or set so that only stars appear when you type password
    {
        this->password = password;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setFirstname(string firstname)
    {
        this->firstname = firstname;
    }
    void setLastname(string lastname)
    {
        this->lastname = lastname;
    }
    string getUsername()
    {
        return username;
    }
    string getEmail()
    {
        return email;
    }
    string getFirstname()
    {
        return firstname;
    }
    string getLastname()
    {
        return lastname;
    }
    bool checkNewUser()
    {
        ifstream file("users.txt");
        string line;
        while (getline(file, line))
        {
            if (line.find(username) != string::npos)
            {
                // user found
                file.close();
                return false;
            }
        }
        file.close();
        // user not found
        ofstream outfile("users.txt", ios::app);
        outfile << username << " " << password << " " << email << " " << firstname << " " << lastname << endl;
        outfile.close();
        return true;
    }
};

void signup()
{
    Details newUser;
    string username, password, email, firstname, lastname;
    cout << "\033[0;36m";
    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your desired username: ";
    getline(cin, username);
    newUser.setUsername(username);

    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your desired password: ";
    password = "";
    char ch = getch();
    while (ch != 13)
    { // 13 is the ASCII code for Enter key
        password.push_back(ch);
        cout << "*";
        ch = getch();
    }
    cout << endl;
    newUser.setPassword(password);

    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your email: ";
    getline(cin, email);
    newUser.setEmail(email);

    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your first name: ";
    getline(cin, firstname);
    newUser.setFirstname(firstname);

    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your last name: ";
    getline(cin, lastname);
    newUser.setLastname(lastname);
    cout<<"\033[0m";

    if (newUser.checkNewUser())
    {
        cout << "\033[0;32m";
        cout << "Congratulations! Your account has been created." << endl;
        cout << "\033[0m";
    }
    else
    {
        cout << "\033[0;31m";
        cout << "Error: Username already exists. Please choose a different one." << endl;
        cout << "\033[0m";
    }
}
void signin()
{
    string username, password;
    bool userFound = false;
    cout << "\n\t\t\t\t\t\t\t\t\t\t_________________________________________________________\n\n";
    cout << " \033[93m";
    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your username: ";
    
    getline(cin, username);

    cout << "\n\t\t\t\t\t\t\t\t\t\tPlease enter your password: ";
    password = "";
    
    char ch = getch();
    while (ch != 13)
    { // 13 is the ASCII code for Enter key
        password.push_back(ch);
        cout << "*";
        ch = getch();
    }
    cout << endl;

    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        if (line.find(username + " " + password) != string::npos)
        {
            userFound = true;
            break;
        }
    }
    file.close();

    if (userFound)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tWelcome back, " << username << "!" << endl;
        cout << "\033[0m";
        b = false;
    }
    else
    {
        cout << "\033[91m";
         cout << "\n\t\t\t\t\t\t\t\t\t\tError: Invalid username or password." << endl;
        cout << "\033[0m";
    }
}

class Location
{
private:
    string sourceName;
    string destinationName;
    string description;
    friend class Transport;
    friend class Itineraries;

public:
    void setSourceName(string sourceName)
    {
        this->sourceName = sourceName;
    }
    void setDestinationName(string destinationName)
    {
        this->destinationName = destinationName;
    }
    void setDescription(string description)
    {
        this->description = description;
    }
    string getSourceName()
    {
        return sourceName;
    }
    string getDestinationName()
    {
        return destinationName;
    }
    string getDescription()
    {
        return description;
    }
    void viewDestinationName(string destinationName)
    {
        // Display the description of the destination
        ifstream infile("destinations.txt");
        map<string, string> destinations;
        string line;
        while (getline(infile, line))
        {
            int pos = line.find(":");
            string destination = line.substr(0, pos);
            string description = line.substr(pos + 1);
            destinations[destination] = description;
        }
        infile.close();
        // Display the description of the destination
        if (destinations.find(destinationName) != destinations.end())
        {
            cout << destinationName << ":" << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t"<< destinations[destinationName] << endl;
        }
        else
        {   cout<<"\033[91m";
            cout << "Destination description not found." << endl;
            cout<< "\033[0m";
        }
    }
};

class Itineraries
{
private:
    string nameOfPlan;
    int noOfDays;
    int planCost;
    int no_of_people;
    string acc;
    string tra;

public:
    vector<bool> facilities;
    void setNameOfPlan(string nameOfPlan)
    {
        this->nameOfPlan = nameOfPlan;
    }
    void setNoOfDays(int noOfDays)
    {
        this->noOfDays = noOfDays;
    }
    void setPlanCost(int pc)
    {
        this->planCost = pc;
    }
    void setno_of_people(int nop)
    {
        this->no_of_people = nop;
    }
    void setFacilities(vector<bool> facilities)
    {
        this->facilities = facilities;
    }
    void setAccomodation(string accomod)
    {
        this->acc = accomod;
    }
    void setTransport(string t)
    {
        this->tra = t;
    }
    string getNameOfPlan()
    {
        return nameOfPlan;
    }
    int getNoOfDays()
    {
        return noOfDays;
    }
    int getPlanCost()
    {
        return planCost;
    }
    int getno_of_people()
    {
        return no_of_people;
    }
    vector<bool> getFacilities()
    {
        return facilities;
    }
    string getAccomodation()
    {
        return acc;
    }
    string getTransport()
    {
        return tra;
    }
};

class Facilities
{
protected:
    vector<bool> choosefacility;
    int fcost;

public:
    void setChooseFacility(vector<bool> facility)
    {
        choosefacility = facility;
    }

    vector<bool> getChooseFacility()
    {
        return choosefacility;
    }

    void setFCost(int cost)
    {
        fcost = cost;
    }

    int getFCost()
    {
        return fcost;
    }

    virtual void facilitiesMenu() = 0;
};

class Transport : public Facilities
{
private:
    int tplancost;

public:
    void setTPLanCost(int cost)
    {
        tplancost = cost;
    }

    int getTPLanCost()
    {
        return tplancost;
    }

    void facilitiesMenu()
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tChoose mode of transport: " << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t1. Flights" << endl;
        cout << "\t\t\t\t\t\t\t\t\t2. Trains" << endl;
        cout << "\t\t\t\t\t\t\t\t\t3. Bus" << endl;
    }

    bool tipon(Itineraries plans[])
    {
        // code to add or remove transport from plan
        char ch;
        cout << "\n\n\t\t\t\t\t\t\t\t\tAdd Transport to Plan? (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            facilitiesMenu();
            int ctot;
            cout << "\n\t\t\t\t\t\t\t\t\tPlese enter SR. no :- \t";
            cin >> ctot;
            srand(time(0));
            string flights[] = {"Business class", "Premium Class", "Helicopter"};
            string trains[] = {"AC class", "Sleeper Class", "General Class"};
            string buses[] = {"AC Bus", "Volvo Bus", "Luxury Bus"};
            if (ctot == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setTransport(flights[rand() % 3]);
                }
                tplancost += 300;
            }
            else if (ctot == 2)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setTransport(trains[rand() % 3]);
                }
                tplancost += 200;
            }
            else if (ctot == 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setTransport(buses[rand() % 3]);
                }
                tplancost += 150;
            }
            cout << "\n\t\t\t\t\t\t\t\t\tTransport Selected and Added to Plan.\n";
            fcost += tplancost;
            return 1;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\tTransport Not Added to Plan\n";
            return 0;
        }
    }
};

class Accomodation : public Facilities
{
private:
    int aplancost;
    int noofpeople;

public:
    void setAPLanCost(int cost)
    {
        aplancost = cost;
    }
    void setNoOfPeople(int people)
    {
        noofpeople = people;
    }
    int getNoOfPeople()
    {
        return noofpeople;
    }
    void facilitiesMenu()
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tChoose type of Accomodation: " << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t1. Hotels" << endl;
        cout << "\t\t\t\t\t\t\t\t\t2. Resorts" << endl;
        cout << "\t\t\t\t\t\t\t\t\t3. GuestHouse" << endl;
    }
    int getAplancost()
    {
        return aplancost;
    }
    bool aipon(Itineraries plans[])
    {
        // Add Accomodation in Plan
        char ch;
        cout << "\n\t\t\t\t\t\t\t\t\tAdd Accomodation to Plan? (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            facilitiesMenu();
            int ctoa;
            cout << "\n\t\t\t\t\t\t\t\t\tPlese enter SR. no :- \t";
            cin >> ctoa;
            srand(time(0));
            string hotels[] = {"Luxury Hotel", "5-Star Hotel", "3-Star Hotel"};
            string resorts[] = {"Beach Resort", "Raaga Mayuri Resort", "Entertainment Resorts"};
            string ghouses[] = {"AC GuestHouse", "Single - Room", "Shared - Rooms"};
            if (ctoa == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setAccomodation(hotels[rand() % 3]);
                }
                aplancost += 300;
            }
            else if (ctoa == 2)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setAccomodation(resorts[rand() % 3]);
                }
                aplancost += 150;
            }
            else if (ctoa == 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    plans[i].setAccomodation(ghouses[rand() % 3]);
                }
                aplancost += 100;
            }
            cout << "\n\t\t\t\t\t\t\t\t\tAccomodation Plan Selected and Added to Plan.\n";
            fcost += aplancost;
            return 1;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\tAccomodation Not Added to Plan";
            return 0;
        }
    }
};

class Transaction : public Details
{
private:
    int transaction_id;
    int amount;
    string method;
    string status;
    Details customer_details;
    Itineraries plan;

public:
    // Constructors
    Transaction() {}

    // Setters and Getters
    void setTransactionId(int id) { transaction_id = id; }
    void setAmount(int cost) { amount = cost; }
    void setMethod(string pay_method) { method = pay_method; }
    void setStatus(string stat) { status = stat; }
    void setCustomerDetails(Details det) { customer_details = det; }
    void setPlan(Itineraries pl) { plan = pl; }

    int getTransactionId() const { return transaction_id; }
    int getAmount() const { return amount; }
    string getMethod() const { return method; }
    string getStatus() const { return status; }
    Details getCustomerDetails() const { return customer_details; }
    

    void cancelTransaction()
    {
        setStatus("Cancelled");
        cout << "\n\t\t\t\t\t\t\t\t\t\t\tTransaction cancelled.\n\n" << endl;
    }

    void viewTransaction()
    {
        cout << "Transaction ID: " << getTransactionId() << endl;
        cout << "Amount: " << getAmount() << endl;
        cout << "Payment Method: " << getMethod() << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Customer Details:" << endl;
        // customer_details.displayUserdetails();
        cout << "Plan Details:" << endl;
    }
    friend class Itineraries;
};

int main()
{
    std::cout << "\033[35m";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t......< WELCOME TO TOURIGO >......" << endl;
    std::cout << "\033[0m";
    cout << "\n\t\t\t\t\t\t\t\t\t\t_________________________________________________________\n\n\n";
    std::cout << "\033[1m\033[36m"; // sets the text to bold and cyan color
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t__ __    __     ____\n"
                 "\t\t\t\t\t\t\t\t\t\t\t\t|_   _| / _|   / __ \\ \n"
                 "\t\t\t\t\t\t\t\t\t\t\t\t  | |  | | __  | | | |\n"
                 "\t\t\t\t\t\t\t\t\t\t\t\t  | |  | || || | |_| |\n"
                 "\t\t\t\t\t\t\t\t\t\t\t\t  |_|   \\___/   \\____/\n";
    std::cout << "\033[0m";
    Details d;
    Location l;
    while(b){
        int choice;
        std::cout << "\033[31m";
        cout << "\n\t\t\t\t\t\t\t\t\t\t1. Sign up" << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t2. Sign in" << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t3. Exit" << endl;
        std::cout << "\033[0m";
        std::cout << "\033[32m";
        cout << "\n\t\t\t\t\t\t\t\t\t\tPlease select an option: \t";
        cin >> choice;
        std::cout << "\033[0m";
        cin.ignore(); // ignore any remaining input after the integer
        switch (choice)
        {
        case 1:
            signup();
            break;
        case 2:
            signin();
            break;
        case 3:
            cout << "\033[35m";
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Thank You for Using our Services" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Be Sure to Visit Again" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\033[0m";
    exit(0);
    break;
        default:
            cout << "\n\t\t\t\t\t\t\t\t\tInvalid choice. Please try again." << endl;
            break;
        }
    }
    system("pause");
    system("CLS");
    string source, destination;
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    std::cout << "\033[32m";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Source Location : ";
    cin >> source;
    l.setSourceName(source);
    std::cout << "\033[0m";
    cout << "\033[0;35m";
    cout << "\n\n\t\t\t\t\t\t\t\t\tSelect one of the following: \n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t1. Himachal Pradesh\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t2. Kerala\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t3. Delhi\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t4. Tamil Nadu\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t5. Jaipur\n";
    std::cout << "\033[0m";
    cout << "\033[96m";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Destination Location : ";
    cin >> destination;
    l.setDestinationName(destination);
    
    cout << "\n\n\t\t\t\t\t\t\t\t\tDescription of the Destination Location: ";
    l.viewDestinationName(l.getDestinationName());
    std::cout << "\033[0m";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    system("pause");
    system("CLS");
    
    Itineraries plans[3];
    Transport t;
    Accomodation a;
    int nopeople;
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Number of People : ";
    cin >> nopeople;
    for (int i = 0; i < 3; i++)
    {
        plans[i].setno_of_people(nopeople);
    }
    a.aipon(plans);
    t.tipon(plans);
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    system("pause");
    system("CLS");
    plans[0].setNameOfPlan("Monthly Plan");
    plans[1].setNameOfPlan("Weekly Plan");
    plans[2].setNameOfPlan("Holiday Plan");
    plans[0].setNoOfDays(30);
    plans[1].setNoOfDays(7);
    plans[2].setNoOfDays(10);

    for (int i = 0; i < 3; i++)
    {
        plans[i].setPlanCost(plans[i].getNoOfDays() * plans[i].getno_of_people() * (a.getAplancost() + t.getTPLanCost()));
    }
    // plans[i].plancost = plans[i].noofdays * plans[i].noofpeople * fcost
    // where fcost = aplancost + tplancost

    const int field_width = 35; // set column width for each field
    const int space_width = 5;  // set width of space between columns
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tPLANS\n\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n\n";
    // Print information for Plan 1, Plan 2, and Plan 3 side by side
    cout << left << setw(field_width) << "\t\tPlan 1: " + plans[0].getNameOfPlan();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tPlan 2: " + plans[1].getNameOfPlan();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tPlan 3: " + plans[2].getNameOfPlan();
    cout << endl;

    cout << left << setw(field_width) << "\t\tSource name: " + l.getSourceName();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tSource name: " + l.getSourceName();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tSource name: " + l.getSourceName();
    cout << endl;

    cout << left << setw(field_width) << "\t\tDestination name: " + l.getDestinationName();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tDestination name: " + l.getDestinationName();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tDestination name: " + l.getDestinationName();
    cout << endl;

    cout << left << setw(field_width) << "\t\tNumber of days: " + to_string(plans[0].getNoOfDays());
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tNumber of days: " + to_string(plans[1].getNoOfDays());
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tNumber of days: " + to_string(plans[2].getNoOfDays());
    cout << endl;

    cout << left << setw(field_width) << "\t\tTotal Cost: " + to_string(plans[0].getPlanCost()) + " Rs";
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tTotal Cost: " + to_string(plans[1].getPlanCost()) + " Rs";
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tTotal Cost: " + to_string(plans[2].getPlanCost()) + " Rs";
    cout << endl;

    cout << left << setw(field_width) << "\t\tNumber of people: " + to_string(plans[0].getno_of_people());
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tNumber of people: " + to_string(plans[1].getno_of_people());
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tNumber of people: " + to_string(plans[2].getno_of_people());
    cout << endl;

    cout << left << setw(field_width) << "\t\tAccomodation Facility: " + plans[0].getAccomodation();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tAccomodation Facility: " + plans[1].getAccomodation();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tAccomodation Facility: " + plans[2].getAccomodation();
    cout << endl;

    cout << left << setw(field_width) << "\t\tTransport Facility: " + plans[0].getTransport();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tTransport Facility: " + plans[1].getTransport();
    cout << left << setw(space_width) << "\t\t ";
    cout << left << setw(field_width) << "\t\tTransport Facility: " + plans[2].getTransport();
    cout << endl;
    int ch;
    Transaction tx;
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tChoose Plan :  ";
    cin >> ch;
    // if ch==1 then transaction.amount = plan[0].getplancost(), Similar for other plans.
    if (ch == 1)
    {
        tx.setAmount(plans[0].getPlanCost());
    }
    else if (ch == 2)
    {
        tx.setAmount(plans[1].getPlanCost());
    }
    else if (ch == 3)
    {
        tx.setAmount(plans[2].getPlanCost());
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tSelect a Valid Plan!!";
    }
    system("pause");
    system("CLS");
    // Transaction code
    char p;
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\tDo you want to proceed with the transaction? (Y/N): ";
    cin >> p;
    if (toupper(p) == 'Y')
    {
        // Ask for payment method
        string method;
        cout << "\n\t\t\t\t\t\t\t\t\tEnter payment method (Credit Card/Debit Card/UPI): ";
        cin >> method;
        if (method == "UPI")
        {
            int id;
            cout << "\n\t\t\t\t\t\t\t\t\tEnter UPI ID : ";
            cin >> id;
        }
        else if (method == "Credit Card" || method == "cc")
        {
            int cn, cv;
            cout << "\n\t\t\t\t\t\t\t\t\tEnter Credit Card Number : ";
            cin >> cn;
            cout << "\n\t\t\t\t\t\t\t\t\tEnter CVV : ";
            cin >> cv;
        }
        else if (method == "Debit Card")
        {  
            int pin;
            cout << "\n\t\t\t\t\t\t\t\t\tEnter PIN Number : ";
            cin >> pin;
        }
        
        std::cout << "\033[1m\033[36m";
        std::cout << "\033[50m";
        std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tPAY\n\n";
        std::cout << "\033[0m";
        system("pause");
        system("CLS");
        cout << "\n\n\t\t\t\t\t\tYour Payment is being Processed\n\n" ;
        system("pause");
        system("CLS");
        tx.setMethod(method);
        tx.setStatus("Success");
        cout << "\n\n\t\t\t\t\t\t\t\t\t Billing Deatils : " << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
        cout << "\n\t\t\t\t\t\t\t\t\t\tTransaction ID: " << tx.getTransactionId() << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\tAmount: " << tx.getAmount() << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\tPayment Method: " << tx.getMethod() << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\tStatus: " << tx.getStatus() << endl;
    }
    else if (toupper(p) == 'N')
    {
        // Cancel transaction
        tx.cancelTransaction();
    }else{
        cout << "\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION" << endl;
    }
    system("pause");
    system("CLS");
    cout << "\033[35m";
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t Thank You for Using our Services" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t Be Sure to Visit Again" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------------\n";
    cout << "\033[0m";
}
