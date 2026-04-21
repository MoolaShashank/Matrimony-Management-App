// ============================================
// Matrimony Management System
// Phase 2: Encapsulation
// OOP Concepts: Private Members, Getters/Setters,
//               Data Hiding, Input Validation
// ============================================

#include <iostream>
#include <string>
using namespace std;

// ============================================
// PROFILE CLASS (Encapsulated)
// ============================================
class Profile {
private:
    int profileId;
    string name;
    int age;
    string gender;
    string religion;
    string phone;
    string email;

public:
    // --- Getters ---
    int getProfileId() { return profileId; }
    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    string getReligion() { return religion; }
    string getPhone() { return phone; }
    string getEmail() { return email; }

    // --- Setters with Validation ---
    void setProfileId(int id) {
        if (id > 0) {
            profileId = id;
        } else {
            cout << "Error: Profile ID must be positive." << endl;
        }
    }

    void setName(string n) {
        if (n.length() > 0) {
            name = n;
        } else {
            cout << "Error: Name cannot be empty." << endl;
        }
    }

    void setAge(int a) {
        if (a >= 18 && a <= 80) {
            age = a;
        } else {
            cout << "Error: Age must be between 18 and 80." << endl;
        }
    }

    void setGender(string g) {
        if (g == "Male" || g == "Female") {
            gender = g;
        } else {
            cout << "Error: Gender must be Male or Female." << endl;
        }
    }

    void setReligion(string r) {
        if (r.length() > 0) {
            religion = r;
        } else {
            cout << "Error: Religion cannot be empty." << endl;
        }
    }

    void setPhone(string p) {
        if (p.length() == 10) {
            phone = p;
        } else {
            cout << "Error: Phone number must be exactly 10 digits." << endl;
        }
    }

    void setEmail(string e) {
        // Basic check: must contain @ and .
        if (e.find('@') != string::npos && e.find('.') != string::npos) {
            email = e;
        } else {
            cout << "Error: Invalid email format." << endl;
        }
    }

    // --- Input Method (uses setters for validation) ---
    void input() {
        int id, a;
        string n, g, r, p, e;

        cout << "Enter Profile ID: ";
        cin >> id;
        setProfileId(id);

        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, n);
        setName(n);

        cout << "Enter Age (18-80): ";
        cin >> a;
        setAge(a);

        cout << "Enter Gender (Male/Female): ";
        cin >> g;
        setGender(g);

        cout << "Enter Religion: ";
        cin >> r;
        setReligion(r);

        cout << "Enter Phone (10 digits): ";
        cin >> p;
        setPhone(p);

        cout << "Enter Email: ";
        cin >> e;
        setEmail(e);
    }

    // --- Display Method ---
    void display() {
        cout << "  Profile ID  : " << profileId << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Age         : " << age << endl;
        cout << "  Gender      : " << gender << endl;
        cout << "  Religion    : " << religion << endl;
        cout << "  Phone       : " << phone << endl;
        cout << "  Email       : " << email << endl;
    }
};

// ============================================
// PREFERENCE CLASS (Encapsulated)
// ============================================
class Preference {
private:
    int preferenceId;
    string preferredGender;
    int minAge;
    int maxAge;
    string preferredReligion;
    string preferredCity;

public:
    // --- Getters ---
    int getPreferenceId() { return preferenceId; }
    string getPreferredGender() { return preferredGender; }
    int getMinAge() { return minAge; }
    int getMaxAge() { return maxAge; }
    string getPreferredReligion() { return preferredReligion; }
    string getPreferredCity() { return preferredCity; }

    // --- Setters with Validation ---
    void setPreferenceId(int id) {
        if (id > 0) {
            preferenceId = id;
        } else {
            cout << "Error: Preference ID must be positive." << endl;
        }
    }

    void setPreferredGender(string g) {
        if (g == "Male" || g == "Female") {
            preferredGender = g;
        } else {
            cout << "Error: Preferred gender must be Male or Female." << endl;
        }
    }

    void setMinAge(int a) {
        if (a >= 18 && a <= 80) {
            minAge = a;
        } else {
            cout << "Error: Minimum age must be between 18 and 80." << endl;
        }
    }

    void setMaxAge(int a) {
        if (a >= 18 && a <= 80) {
            if (a >= minAge) {
                maxAge = a;
            } else {
                cout << "Error: Maximum age must be >= minimum age (" << minAge << ")." << endl;
            }
        } else {
            cout << "Error: Maximum age must be between 18 and 80." << endl;
        }
    }

    void setPreferredReligion(string r) {
        if (r.length() > 0) {
            preferredReligion = r;
        } else {
            cout << "Error: Preferred religion cannot be empty." << endl;
        }
    }

    void setPreferredCity(string c) {
        if (c.length() > 0) {
            preferredCity = c;
        } else {
            cout << "Error: Preferred city cannot be empty." << endl;
        }
    }

    // --- Check if a Profile Matches Preferences ---
    bool isMatch(string gender, int age, string religion) {
        if (gender == preferredGender && age >= minAge && age <= maxAge && religion == preferredReligion) {
            return true;
        } else {
            return false;
        }
    }

    // --- Input Method ---
    void input() {
        int id, mn, mx;
        string g, r, c;

        cout << "Enter Preference ID: ";
        cin >> id;
        setPreferenceId(id);

        cout << "Enter Preferred Gender (Male/Female): ";
        cin >> g;
        setPreferredGender(g);

        cout << "Enter Minimum Age (18-80): ";
        cin >> mn;
        setMinAge(mn);

        cout << "Enter Maximum Age (18-80): ";
        cin >> mx;
        setMaxAge(mx);

        cout << "Enter Preferred Religion: ";
        cin >> r;
        setPreferredReligion(r);

        cout << "Enter Preferred City: ";
        cin.ignore();
        getline(cin, c);
        setPreferredCity(c);
    }

    // --- Display Method ---
    void display() {
        cout << "  Preference ID    : " << preferenceId << endl;
        cout << "  Preferred Gender : " << preferredGender << endl;
        cout << "  Age Range        : " << minAge << " - " << maxAge << endl;
        cout << "  Preferred Religion: " << preferredReligion << endl;
        cout << "  Preferred City   : " << preferredCity << endl;
    }
};

// ============================================
// MEMBERSHIP CLASS (Encapsulated)
// ============================================
class Membership {
private:
    int memberId;
    string plan;        // Free, Silver, Gold, Platinum
    float price;
    int durationMonths;
    bool isActive;

public:
    // --- Getters ---
    int getMemberId() { return memberId; }
    string getPlan() { return plan; }
    float getPrice() { return price; }
    int getDurationMonths() { return durationMonths; }
    bool getIsActive() { return isActive; }

    // --- Setters with Validation ---
    void setMemberId(int id) {
        if (id > 0) {
            memberId = id;
        } else {
            cout << "Error: Member ID must be positive." << endl;
        }
    }

    void setPlan(string p) {
        if (p == "Free" || p == "Silver" || p == "Gold" || p == "Platinum") {
            plan = p;
        } else {
            cout << "Error: Plan must be Free, Silver, Gold, or Platinum." << endl;
        }
    }

    void setPrice(float p) {
        if (p >= 0) {
            price = p;
        } else {
            cout << "Error: Price cannot be negative." << endl;
        }
    }

    void setDurationMonths(int d) {
        if (d >= 1 && d <= 24) {
            durationMonths = d;
        } else {
            cout << "Error: Duration must be between 1 and 24 months." << endl;
        }
    }

    void setIsActive(bool a) {
        isActive = a;
    }

    // --- Activate Membership ---
    void activate() {
        if (!isActive) {
            isActive = true;
            cout << "Membership activated successfully." << endl;
        } else {
            cout << "Error: Membership is already active." << endl;
        }
    }

    // --- Deactivate / Expire Membership ---
    void deactivate() {
        if (isActive) {
            isActive = false;
            cout << "Membership deactivated." << endl;
        } else {
            cout << "Error: Membership is already inactive." << endl;
        }
    }

    // --- Input Method ---
    void input() {
        int id, d;
        string p;
        float pr;

        cout << "Enter Member ID: ";
        cin >> id;
        setMemberId(id);

        cout << "Enter Plan (Free/Silver/Gold/Platinum): ";
        cin >> p;
        setPlan(p);

        cout << "Enter Price (Rs.): ";
        cin >> pr;
        setPrice(pr);

        cout << "Enter Duration in Months (1-24): ";
        cin >> d;
        setDurationMonths(d);

        isActive = true; // New memberships are active by default
    }

    // --- Display Method ---
    void display() {
        cout << "  Member ID   : " << memberId << endl;
        cout << "  Plan        : " << plan << endl;
        cout << "  Price       : Rs." << price << endl;
        cout << "  Duration    : " << durationMonths << " months" << endl;
        cout << "  Status      : " << (isActive ? "Active" : "Expired") << endl;
    }
};

// ============================================
// MAIN - Demonstrating Encapsulation
// ============================================
int main() {
    cout << "========================================" << endl;
    cout << "   Matrimony Management System" << endl;
    cout << "   Phase 2 - Encapsulation" << endl;
    cout << "========================================" << endl << endl;

    // --- Profile Demo ---
    Profile p;
    cout << "--- Enter Profile Details ---" << endl;
    p.input();
    cout << endl;

    // Demonstrate that validation works
    cout << "--- Testing Validation ---" << endl;
    cout << "Setting phone to '123' (should fail):" << endl;
    p.setPhone("123");  // Will print error

    cout << "Setting phone to '9876543210' (should pass):" << endl;
    p.setPhone("9876543210");  // Will succeed
    cout << "Phone is now: " << p.getPhone() << endl;

    cout << "Setting age to 15 (should fail):" << endl;
    p.setAge(15);  // Will print error

    cout << "Setting gender to 'Other' (should fail):" << endl;
    p.setGender("Other");  // Will print error
    cout << endl;

    // --- Preference Demo ---
    Preference pref;
    cout << "--- Enter Partner Preferences ---" << endl;
    pref.input();
    cout << endl;

    // Demonstrate match checking
    cout << "--- Testing Match Check ---" << endl;
    cout << "Checking if (Female, 25, Hindu) matches preferences: ";
    if (pref.isMatch("Female", 25, "Hindu")) {
        cout << "MATCH FOUND!" << endl;
    } else {
        cout << "No match." << endl;
    }

    cout << "Checking if (Male, 45, Christian) matches preferences: ";
    if (pref.isMatch("Male", 45, "Christian")) {
        cout << "MATCH FOUND!" << endl;
    } else {
        cout << "No match." << endl;
    }
    cout << endl;

    // --- Membership Demo ---
    Membership m;
    cout << "--- Enter Membership Details ---" << endl;
    m.input();
    cout << endl;

    // Demonstrate membership activation/deactivation
    cout << "--- Testing Membership Status ---" << endl;
    cout << "Status: " << (m.getIsActive() ? "Active" : "Expired") << endl;
    m.deactivate();
    cout << "After deactivating: " << (m.getIsActive() ? "Active" : "Expired") << endl;
    m.activate();
    cout << "After re-activating: " << (m.getIsActive() ? "Active" : "Expired") << endl;
    cout << endl;

    // Demonstrate invalid plan
    cout << "--- Testing Invalid Plan ---" << endl;
    cout << "Setting plan to 'Diamond' (should fail):" << endl;
    m.setPlan("Diamond");  // Will print error
    cout << endl;

    // --- Display All ---
    cout << "========================================" << endl;
    cout << "         Final Summary" << endl;
    cout << "========================================" << endl;

    cout << endl << "--- Profile Info ---" << endl;
    p.display();

    cout << endl << "--- Partner Preferences ---" << endl;
    pref.display();

    cout << endl << "--- Membership Info ---" << endl;
    m.display();

    cout << endl << "========================================" << endl;
    cout << "   Phase 2 Complete!" << endl;
    cout << "   Encapsulation Applied:" << endl;
    cout << "   - All attributes are now PRIVATE" << endl;
    cout << "   - Access only through getters/setters" << endl;
    cout << "   - Input validation in setters" << endl;
    cout << "   - Match checking with data hiding" << endl;
    cout << "========================================" << endl;

    return 0;
}
