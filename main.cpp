#include <bits/stdc++.h>

using namespace std;

class Details
{
private:
    // Json object which contains details of different users, Use File Handling here.
    string username;
    string password; // Hidden from view 
    string email;
    string firstname;
    string lastname;

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
        // Check if the user is new or not from json
        // Return true if new, false otherwise
        // If new user redirect to login page to sign up
        // else continue
    }
    void displayUserdetails()
    {
        // Display specific user details in the system
    }
};

class HolidayType
{
private:
    int choice;
    int noOfPeople;

public:
    void setChoice(int choice)
    {
        this->choice = choice;
    }
    void setNoOfPeople(int noOfPeople)
    {
        this->noOfPeople = noOfPeople;
    }
    int getChoice()
    {
        return choice;
    }
    int getNoOfPeople()
    {
        return noOfPeople;
    }
    void menu()
    {
        // Display menu options and get user choice
    }
};

class Location
{
private:
    string sourceName;
    string destinationName;
    string description;

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
    vector<string> shortestPath()
    {
        // Calculate the shortest path and return a vector containing the best mode of transport
    }
    void viewDestinationName()
    {
        // Display the description of the destination
    }
};

class Itineraries
{
private:
    string nameOfPlan;
    int noOfDays;
    double planCost;
    string comments;
    vector<string> facilities;

public:
    void setNameOfPlan(string nameOfPlan)
    {
        this->nameOfPlan = nameOfPlan;
    }
    void setNoOfDays(int noOfDays)
    {
        this->noOfDays = noOfDays;
    }
    void setPlanCost(double planCost)
    {
        this->planCost = planCost;
    }
    void setComments(string comments)
    {
        this->comments = comments;
    }
    void setFacilities(vector<string> facilities)
    {
        this->facilities = facilities;
    }
    string getNameOfPlan()
    {
        return nameOfPlan;
    }
    int getNoOfDays()
    {
        return noOfDays;
    }
    double getPlanCost()
    {
        return planCost;
    }
    string getComments()
    {
        return comments;
    }
    vector<string> getFacilities()
    {
        return facilities;
    }
    void viewPlan()
    {
        // Display different plans according to facilities and no of days
    }
};

class Facilities
{
protected:
    string choosefacility;
    float fcost;

public:
    void setChooseFacility(string facility)
    {
        choosefacility = facility;
    }

    string getChooseFacility()
    {
        return choosefacility;
    }

    void setFCost(float cost)
    {
        fcost = cost;
    }

    float getFCost()
    {
        return fcost;
    }

    virtual void facilitiesMenu() = 0;
};

class Transport : public Facilities
{
private:
    string modeOfTransport;
    float tplancost;
    string sname;
    string dname;
    bool tip;

public:
    void setModeOfTransport(string mode)
    {
        modeOfTransport = mode;
    }

    string getModeOfTransport()
    {
        return modeOfTransport;
    }

    void setTPLanCost(float cost)
    {
        tplancost = cost;
    }

    float getTPLanCost()
    {
        return tplancost;
    }

    void setSName(string s)
    {
        sname = s;
    }

    string getSName()
    {
        return sname;
    }

    void setDName(string d)
    {
        dname = d;
    }

    string getDName()
    {
        return dname;
    }

    void setTIP(bool val)
    {
        tip = val;
    }

    bool getTIP()
    {
        return tip;
    }

    void facilitiesMenu()
    {
        cout << "Choose mode of transport: " << endl;
        // provide options
    }

    vector<string> timetakenforeachmodeoftransport()
    {
        vector<string> transportModes;
        // calculate travel duration and add to transportModes
        return transportModes;
    }

    void cancelbooking()
    {
        // code to cancel booking
    }

    void viewbooking()
    {
        // code to view booking
    }

    float calctotaltplancost()
    {
        return tplancost;
    }

    bool tipon()
    {
        // code to add or remove transport from plan
    }
};

class Accomodation : public Facilities
{
private:
    vector<string> typeofacc;
    float aplancost;
    string checkindate;
    string checkoutdate;
    int noofpeople;
    bool aip;

public:
    void setTypeOfAcc(vector<string> acc)
    {
        typeofacc = acc;
    }

    vector<string> getTypeOfAcc()
    {
        return typeofacc;
    }

    void setAPLanCost(float cost)
    {
        aplancost = cost;
    }

    float getAPLanCost()
    {
        return aplancost;
    }

    void setCheckInDate(string date)
    {
        checkindate = date;
    }

    string getCheckInDate()
    {
        return checkindate;
    }

    void setCheckOutDate(string date)
    {
        checkoutdate = date;
    }

    string getCheckOutDate()
    {
        return checkoutdate;
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
        cout << "Choose type of accommodation: " << endl;
        // provide options
    }

    void setACost(vector<string> types)
    {
        typeofacc = types;
        vector <string> facilities_list;
        vector <int> facilities;
        for (int i = 0; i < types.size(); i++)
        {
            if (types[i] == "3 Star Hotel")
            {
                facilities_list.push_back("Air conditioning");
                facilities.push_back(100);
                facilities_list.push_back("Television");
                facilities.push_back(50);
                facilities_list.push_back("Free WiFi");
                facilities.push_back(20);
                aplancost += 200;
            }
            else if (types[i] == "5 Star Hotel")
            {
                facilities_list.push_back("Air conditioning");
                facilities.push_back(150);
                facilities_list.push_back("Television");
                facilities.push_back(75);
                facilities_list.push_back("Free WiFi");
                facilities.push_back(30);
                facilities_list.push_back("Swimming Pool");
                facilities.push_back(100);
                facilities_list.push_back("Gym");
                facilities.push_back(75);
                aplancost += 500;
            }
            // Similarly add more options and facilities
        }
        fcost += aplancost;
    }

    int getAplancost()
    {
        return aplancost;
    }
    void cancelacc()
    {
        // Cancel Accomodation
        vector<string> facilities_list;
        vector<int> facilities;
        cout << "Accommodation Cancelled.\n";
        fcost -= aplancost;
        aplancost = 0;
        typeofacc.clear();
        checkindate = "";
        checkoutdate = "";
        noofpeople = 0;
        facilities.clear();
        facilities_list.clear();
    }
    void viewacc()
    {
        // View Accomodation Details
        vector<string> facilities_list;
        vector<int> facilities;
        cout << "Accomodation Details:\n";
        cout << "Check-in Date: " << checkindate << endl;
        cout << "Check-out Date: " << checkoutdate << endl;
        cout << "Number of People: " << noofpeople << endl;
        cout << "Type of Accomodation:\n";
        for (int i = 0; i < typeofacc.size(); i++)
        {
            cout << i + 1 << ") " << typeofacc[i] << endl;
        }
        cout << "Facilities:\n";
        for (int i = 0; i < facilities_list.size(); i++)
        {
            cout << facilities_list[i] << " - " << facilities[i] << endl;
        }
        cout << "Accomodation Cost: " << aplancost << endl;
    }
    void aipon()
    {
        // Add Accomodation in Plan
        char ch;
        cout << "Add Accomodation to Plan? (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            fcost += aplancost;
            cout << "Accomodation Added to Plan.\n";
        }
        else
        {
            cout << "Accomodation Not in Plan";
        }
    }
};

class TourGuide : public Facilities
{
private:
    bool tourg;
    float tgplancost;
    string name;
    string language;
    bool availability;
    float rating;

public:
    // Constructor
    TourGuide()
    {
        tourg = false;
        tgplancost = 0.0f;
        name = "";
        language = "";
        availability = false;
        rating = 0.0f;
    }

    // Getter and setter functions
    void setTourg(bool value)
    {
        tourg = value;
    }
    bool getTourg()
    {
        return tourg;
    }

    void setTgPlanCost(float value)
    {
        tgplancost = value;
    }
    float getTgPlanCost()
    {
        return tgplancost;
    }

    void setName(string value)
    {
        name = value;
    }
    string getName()
    {
        return name;
    }

    void setLanguage(string value)
    {
        language = value;
    }
    string getLanguage()
    {
        return language;
    }

    void setAvailability(bool value)
    {
        availability = value;
    }
    bool getAvailability()
    {
        return availability;
    }

    void setRating(float value)
    {
        rating = value;
    }
    float getRating()
    {
        return rating;
    }

    // Member functions
    void manageBooking();
    void offerRecommendation();
    void languageTranslation();
    void calcTgPlanCost();
    void tgIpon();
};

class Meals : public Facilities
{
private:
    string typeofmeal;
    double mcost;
    Accomodation *a;

public:
    Meals(Accomodation *a)
    {
        this->a = a;
    }

    // Set functions
    void setMealType(string typeofmeal)
    {
        this->typeofmeal = typeofmeal;
    }

    void setMealCost(double mcost)
    {
        this->mcost = mcost;
    }

    // Get functions
    string getMealType()
    {
        return typeofmeal;
    }

    double getMealCost()
    {
        return mcost;
    }

    // Add meal service to accomodation
    /*void addMealServiceToAcc()
    {
        a->setAccService("Meal Service");
    }*/

    // View available meals
    void viewMeals()
    {
        cout << "Available Meals: Breakfast, Lunch, Dinner, Snacks" << endl;
    }

    // Calculate total cost
    double calc()
    {
        return mcost;
    }
};

;

class Transaction
{
private:
    int transaction_id;
    float amount;
    string method;
    string status;
    Details customer_details;
    Itineraries plan;

public:
    // Constructors
    Transaction() {}

    Transaction(int id, float cost, string pay_method, string stat, Details det, Itineraries pl)
    {
        transaction_id = id;
        amount = cost;
        method = pay_method;
        status = stat;
        customer_details = det;
        plan = pl;
    }

    // Setters and Getters
    void setTransactionId(int id) { transaction_id = id; }
    void setAmount(float cost) { amount = cost; }
    void setMethod(string pay_method) { method = pay_method; }
    void setStatus(string stat) { status = stat; }
    void setCustomerDetails(Details det) { customer_details = det; }
    void setPlan(Itineraries pl) { plan = pl; }

    int getTransactionId() const { return transaction_id; }
    float getAmount() const { return amount; }
    string getMethod() const { return method; }
    string getStatus() const { return status; }
    Details getCustomerDetails() const { return customer_details; }
    Itineraries getPlan() const { return plan; }

    // Other member functions
    bool checkNewUser()
    {
        bool new_user = customer_details.checkNewUser();
        if (new_user)
        {
            cout << "You need to login first to book a plan." << endl;
            // Redirect to login page
        }
        return new_user;
    }

    void confirmTransaction()
    {
        // Check if user is logged in
        if (checkNewUser())
        {
            return;
        }

        // Make payment
        cout << "Transaction successful. Plan booked!" << endl;
        setStatus("Success");
    }

    void cancelTransaction()
    {
        setStatus("Cancelled");
        cout << "Transaction cancelled." << endl;
    }

    void viewTransaction()
    {
        cout << "Transaction ID: " << getTransactionId() << endl;
        cout << "Amount: " << getAmount() << endl;
        cout << "Payment Method: " << getMethod() << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "Customer Details:" << endl;
        customer_details.displayUserdetails();
        cout << "Plan Details:" << endl;
        plan.viewPlan();
    }
};

