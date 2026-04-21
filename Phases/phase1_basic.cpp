
// ============================================
// Matrimony Management System
// Phase 1: Basic Classes & Objects
// OOP Concepts: Classes, Objects, Methods, I/O
// ============================================

#include <iostream>
#include <string>
using namespace std;

// ---- Class 1: Profile ----
// Stores personal details of a person registering on the matrimony platform
class Profile {
public:
    int profileId;
    string name;
    int age;
    string gender;
    string religion;
    string phone;

    void input() {
        cout << "Enter Profile ID: ";
        cin >> profileId;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender (Male/Female): ";
        cin >> gender;
        cout << "Enter Religion: ";
        cin >> religion;
        cout << "Enter Phone Number: ";
        cin >> phone;
    }

    void display() {
        cout << "Profile ID: " << profileId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Religion: " << religion << endl;
        cout << "Phone: " << phone << endl;
    }
};

// ---- Class 2: Preference ----
// Stores the partner preferences of a registered profile
class Preference {
public:
    int preferenceId;
    string preferredGender;
    int minAge;
    int maxAge;
    string preferredReligion;
    string preferredCity;

    void input() {
        cout << "Enter Preference ID: ";
        cin >> preferenceId;
        cout << "Enter Preferred Gender (Male/Female): ";
        cin >> preferredGender;
        cout << "Enter Minimum Age: ";
        cin >> minAge;
        cout << "Enter Maximum Age: ";
        cin >> maxAge;
        cout << "Enter Preferred Religion: ";
        cin >> preferredReligion;
        cout << "Enter Preferred City: ";
        cin.ignore();
        getline(cin, preferredCity);
    }

    void display() {
        cout << "Preference ID: " << preferenceId << endl;
        cout << "Preferred Gender: " << preferredGender << endl;
        cout << "Age Range: " << minAge << " - " << maxAge << endl;
        cout << "Preferred Religion: " << preferredReligion << endl;
        cout << "Preferred City: " << preferredCity << endl;
    }
};

// ---- Class 3: Membership ----
// Stores the membership/subscription plan details
class Membership {
public:
    int memberId;
    string plan;        // Free, Silver, Gold, Platinum
    float price;
    int durationMonths;
    bool isActive;

    void input() {
        cout << "Enter Member ID: ";
        cin >> memberId;
        cout << "Enter Plan (Free/Silver/Gold/Platinum): ";
        cin >> plan;
        cout << "Enter Price (Rs.): ";
        cin >> price;
        cout << "Enter Duration (months): ";
        cin >> durationMonths;
        isActive = true; // New memberships are active by default
    }

    void display() {
        cout << "Member ID: " << memberId << endl;
        cout << "Plan: " << plan << endl;
        cout << "Price: Rs." << price << endl;
        cout << "Duration: " << durationMonths << " months" << endl;
        cout << "Status: " << (isActive ? "Active" : "Expired") << endl;
    }
};

int main() {
    cout << "========================================" << endl;
    cout << "   Matrimony Management System" << endl;
    cout << "   Phase 1 - Basic Classes & Objects" << endl;
    cout << "========================================" << endl << endl;

    // --- Profile ---
    Profile p;
    cout << "--- Enter Profile Details ---" << endl;
    p.input();
    cout << endl;

    // --- Preference ---
    Preference pref;
    cout << "--- Enter Partner Preferences ---" << endl;
    pref.input();
    cout << endl;

    // --- Membership ---
    Membership m;
    cout << "--- Enter Membership Details ---" << endl;
    m.input();
    cout << endl;

    // --- Display All ---
    cout << "========================================" << endl;
    cout << "            Summary" << endl;
    cout << "========================================" << endl;

    cout << endl << "--- Profile Info ---" << endl;
    p.display();

    cout << endl << "--- Partner Preferences ---" << endl;
    pref.display();

    cout << endl << "--- Membership Info ---" << endl;
    m.display();

    cout << endl << "========================================" << endl;
    cout << "   Phase 1 Complete!" << endl;
    cout << "========================================" << endl;

    return 0;
}
