// ============================================
// Matrimony Management System
// Phase 3: Arrays & Object Collections
// OOP Concepts: Array of Objects, Searching,
//               Menu-Driven Interface, Collections
// ============================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================
// PROFILE CLASS
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
    // Constructor
    Profile() : profileId(0), name(""), age(0), gender(""), religion(""), phone(""), email("") {}

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
        if (id > 0) profileId = id;
        else cout << "  [!] Profile ID must be positive." << endl;
    }

    void setName(string n) {
        if (n.length() > 0) name = n;
        else cout << "  [!] Name cannot be empty." << endl;
    }

    void setAge(int a) {
        if (a >= 18 && a <= 80) age = a;
        else cout << "  [!] Age must be between 18 and 80." << endl;
    }

    void setGender(string g) {
        if (g == "Male" || g == "Female") gender = g;
        else cout << "  [!] Gender must be Male or Female." << endl;
    }

    void setReligion(string r) {
        if (r.length() > 0) religion = r;
        else cout << "  [!] Religion cannot be empty." << endl;
    }

    void setPhone(string p) {
        if (p.length() == 10) phone = p;
        else cout << "  [!] Phone must be exactly 10 digits." << endl;
    }

    void setEmail(string e) {
        if (e.find('@') != string::npos && e.find('.') != string::npos) email = e;
        else cout << "  [!] Invalid email format." << endl;
    }

    // --- Input ---
    void input() {
        int id, a;
        string n, g, r, p, e;

        cout << "  Enter Profile ID: ";
        cin >> id;
        setProfileId(id);

        cout << "  Enter Full Name: ";
        cin.ignore();
        getline(cin, n);
        setName(n);

        cout << "  Enter Age (18-80): ";
        cin >> a;
        setAge(a);

        cout << "  Enter Gender (Male/Female): ";
        cin >> g;
        setGender(g);

        cout << "  Enter Religion: ";
        cin >> r;
        setReligion(r);

        cout << "  Enter Phone (10 digits): ";
        cin >> p;
        setPhone(p);

        cout << "  Enter Email: ";
        cin >> e;
        setEmail(e);
    }

    // --- Display (Table Row) ---
    void display() {
        cout << "  | " << left << setw(6) << profileId
             << "| " << setw(18) << name
             << "| " << setw(4) << age
             << "| " << setw(8) << gender
             << "| " << setw(10) << religion
             << "| " << setw(12) << phone << "|" << endl;
    }
};

// ============================================
// PREFERENCE CLASS
// ============================================
class Preference {
private:
    int preferenceId;
    int linkedProfileId;    // Links to which profile this preference belongs
    string preferredGender;
    int minAge;
    int maxAge;
    string preferredReligion;
    string preferredCity;

public:
    // Constructor
    Preference() : preferenceId(0), linkedProfileId(0), preferredGender(""),
                   minAge(0), maxAge(0), preferredReligion(""), preferredCity("") {}

    // --- Getters ---
    int getPreferenceId() { return preferenceId; }
    int getLinkedProfileId() { return linkedProfileId; }
    string getPreferredGender() { return preferredGender; }
    int getMinAge() { return minAge; }
    int getMaxAge() { return maxAge; }
    string getPreferredReligion() { return preferredReligion; }
    string getPreferredCity() { return preferredCity; }

    // --- Setters with Validation ---
    void setPreferenceId(int id) {
        if (id > 0) preferenceId = id;
        else cout << "  [!] Preference ID must be positive." << endl;
    }

    void setLinkedProfileId(int id) {
        if (id > 0) linkedProfileId = id;
        else cout << "  [!] Linked Profile ID must be positive." << endl;
    }

    void setPreferredGender(string g) {
        if (g == "Male" || g == "Female") preferredGender = g;
        else cout << "  [!] Preferred gender must be Male or Female." << endl;
    }

    void setMinAge(int a) {
        if (a >= 18 && a <= 80) minAge = a;
        else cout << "  [!] Minimum age must be between 18 and 80." << endl;
    }

    void setMaxAge(int a) {
        if (a >= 18 && a <= 80) {
            if (a >= minAge) maxAge = a;
            else cout << "  [!] Maximum age must be >= minimum age (" << minAge << ")." << endl;
        } else {
            cout << "  [!] Maximum age must be between 18 and 80." << endl;
        }
    }

    void setPreferredReligion(string r) {
        if (r.length() > 0) preferredReligion = r;
        else cout << "  [!] Preferred religion cannot be empty." << endl;
    }

    void setPreferredCity(string c) {
        if (c.length() > 0) preferredCity = c;
        else cout << "  [!] Preferred city cannot be empty." << endl;
    }

    // --- Check if a Profile Matches ---
    bool isMatch(string gender, int age, string religion) {
        return (gender == preferredGender && age >= minAge && age <= maxAge && religion == preferredReligion);
    }

    // --- Input ---
    void input() {
        int id, lid, mn, mx;
        string g, r, c;

        cout << "  Enter Preference ID: ";
        cin >> id;
        setPreferenceId(id);

        cout << "  Enter Linked Profile ID: ";
        cin >> lid;
        setLinkedProfileId(lid);

        cout << "  Enter Preferred Gender (Male/Female): ";
        cin >> g;
        setPreferredGender(g);

        cout << "  Enter Minimum Age (18-80): ";
        cin >> mn;
        setMinAge(mn);

        cout << "  Enter Maximum Age (18-80): ";
        cin >> mx;
        setMaxAge(mx);

        cout << "  Enter Preferred Religion: ";
        cin >> r;
        setPreferredReligion(r);

        cout << "  Enter Preferred City: ";
        cin.ignore();
        getline(cin, c);
        setPreferredCity(c);
    }

    // --- Display (Table Row) ---
    void display() {
        cout << "  | " << left << setw(6) << preferenceId
             << "| " << setw(10) << linkedProfileId
             << "| " << setw(8) << preferredGender
             << "| " << setw(7) << minAge << "-" << setw(4) << maxAge
             << "| " << setw(10) << preferredReligion
             << "| " << setw(14) << preferredCity << "|" << endl;
    }
};

// ============================================
// MEMBERSHIP CLASS
// ============================================
class Membership {
private:
    int memberId;
    int linkedProfileId;    // Links to which profile this membership belongs
    string plan;            // Free, Silver, Gold, Platinum
    float price;
    int durationMonths;
    bool isActive;

public:
    // Constructor
    Membership() : memberId(0), linkedProfileId(0), plan(""), price(0), durationMonths(0), isActive(true) {}

    // --- Getters ---
    int getMemberId() { return memberId; }
    int getLinkedProfileId() { return linkedProfileId; }
    string getPlan() { return plan; }
    float getPrice() { return price; }
    int getDurationMonths() { return durationMonths; }
    bool getIsActive() { return isActive; }

    // --- Setters with Validation ---
    void setMemberId(int id) {
        if (id > 0) memberId = id;
        else cout << "  [!] Member ID must be positive." << endl;
    }

    void setLinkedProfileId(int id) {
        if (id > 0) linkedProfileId = id;
        else cout << "  [!] Linked Profile ID must be positive." << endl;
    }

    void setPlan(string p) {
        if (p == "Free" || p == "Silver" || p == "Gold" || p == "Platinum") plan = p;
        else cout << "  [!] Plan must be Free, Silver, Gold, or Platinum." << endl;
    }

    void setPrice(float p) {
        if (p >= 0) price = p;
        else cout << "  [!] Price cannot be negative." << endl;
    }

    void setDurationMonths(int d) {
        if (d >= 1 && d <= 24) durationMonths = d;
        else cout << "  [!] Duration must be between 1 and 24 months." << endl;
    }

    void setIsActive(bool a) { isActive = a; }

    // --- Activate / Deactivate ---
    void activate() {
        if (!isActive) {
            isActive = true;
            cout << "  [+] Membership activated." << endl;
        } else {
            cout << "  [!] Membership is already active." << endl;
        }
    }

    void deactivate() {
        if (isActive) {
            isActive = false;
            cout << "  [+] Membership deactivated." << endl;
        } else {
            cout << "  [!] Membership is already inactive." << endl;
        }
    }

    // --- Input ---
    void input() {
        int id, lid, d;
        string p;
        float pr;

        cout << "  Enter Member ID: ";
        cin >> id;
        setMemberId(id);

        cout << "  Enter Linked Profile ID: ";
        cin >> lid;
        setLinkedProfileId(lid);

        cout << "  Enter Plan (Free/Silver/Gold/Platinum): ";
        cin >> p;
        setPlan(p);

        cout << "  Enter Price (Rs.): ";
        cin >> pr;
        setPrice(pr);

        cout << "  Enter Duration in Months (1-24): ";
        cin >> d;
        setDurationMonths(d);

        isActive = true; // New memberships are active by default
    }

    // --- Display (Table Row) ---
    void display() {
        cout << "  | " << left << setw(6) << memberId
             << "| " << setw(10) << linkedProfileId
             << "| " << setw(10) << plan
             << "| Rs." << setw(9) << fixed << setprecision(0) << price
             << "| " << setw(8) << durationMonths
             << "| " << setw(10) << (isActive ? "Active" : "Expired") << "|" << endl;
    }
};

// ============================================
// GLOBAL ARRAYS & COUNTERS
// ============================================
const int MAX_PROFILES = 50;
const int MAX_PREFERENCES = 50;
const int MAX_MEMBERSHIPS = 50;

Profile profiles[MAX_PROFILES];
Preference preferences[MAX_PREFERENCES];
Membership memberships[MAX_MEMBERSHIPS];

int profileCount = 0;
int preferenceCount = 0;
int membershipCount = 0;

// ============================================
// UTILITY FUNCTIONS
// ============================================

void printLine() {
    cout << "  ";
    for (int i = 0; i < 68; i++) cout << "-";
    cout << endl;
}

void printDoubleLine() {
    cout << "  ";
    for (int i = 0; i < 68; i++) cout << "=";
    cout << endl;
}

// ============================================
// PROFILE MANAGEMENT FUNCTIONS
// ============================================

void addProfile() {
    if (profileCount >= MAX_PROFILES) {
        cout << "  [!] Maximum profiles reached (" << MAX_PROFILES << ")." << endl;
        return;
    }

    cout << endl << "  --- Add New Profile ---" << endl;
    profiles[profileCount].input();

    // Check for duplicate ID
    int newId = profiles[profileCount].getProfileId();
    for (int i = 0; i < profileCount; i++) {
        if (profiles[i].getProfileId() == newId) {
            cout << "  [!] Profile ID " << newId << " already exists. Cancelled." << endl;
            return;
        }
    }

    profileCount++;
    cout << "  [+] Profile added successfully! Total: " << profileCount << endl;
}

void viewAllProfiles() {
    if (profileCount == 0) {
        cout << "  [!] No profiles registered yet." << endl;
        return;
    }

    cout << endl << "  --- All Profiles (" << profileCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(18) << "Name"
         << "| " << setw(4) << "Age"
         << "| " << setw(8) << "Gender"
         << "| " << setw(10) << "Religion"
         << "| " << setw(12) << "Phone" << "|" << endl;
    printLine();

    for (int i = 0; i < profileCount; i++) {
        profiles[i].display();
    }
    printLine();
}

void searchProfile() {
    if (profileCount == 0) {
        cout << "  [!] No profiles to search." << endl;
        return;
    }

    int id;
    cout << "  Enter Profile ID to search: ";
    cin >> id;

    for (int i = 0; i < profileCount; i++) {
        if (profiles[i].getProfileId() == id) {
            cout << "  [+] Profile found:" << endl;
            printLine();
            cout << "  | " << left << setw(6) << "ID"
                 << "| " << setw(18) << "Name"
                 << "| " << setw(4) << "Age"
                 << "| " << setw(8) << "Gender"
                 << "| " << setw(10) << "Religion"
                 << "| " << setw(12) << "Phone" << "|" << endl;
            printLine();
            profiles[i].display();
            printLine();
            return;
        }
    }
    cout << "  [!] Profile ID " << id << " not found." << endl;
}

void deleteProfile() {
    if (profileCount == 0) {
        cout << "  [!] No profiles to delete." << endl;
        return;
    }

    int id;
    cout << "  Enter Profile ID to delete: ";
    cin >> id;

    for (int i = 0; i < profileCount; i++) {
        if (profiles[i].getProfileId() == id) {
            cout << "  Deleting: " << profiles[i].getName() << " (ID: " << id << ")" << endl;

            // Shift remaining profiles left
            for (int j = i; j < profileCount - 1; j++) {
                profiles[j] = profiles[j + 1];
            }
            profileCount--;
            cout << "  [+] Profile deleted. Remaining: " << profileCount << endl;
            return;
        }
    }
    cout << "  [!] Profile ID " << id << " not found." << endl;
}

// ============================================
// PREFERENCE MANAGEMENT FUNCTIONS
// ============================================

void addPreference() {
    if (preferenceCount >= MAX_PREFERENCES) {
        cout << "  [!] Maximum preferences reached (" << MAX_PREFERENCES << ")." << endl;
        return;
    }

    cout << endl << "  --- Add Partner Preferences ---" << endl;
    preferences[preferenceCount].input();

    // Check for duplicate Preference ID
    int newId = preferences[preferenceCount].getPreferenceId();
    for (int i = 0; i < preferenceCount; i++) {
        if (preferences[i].getPreferenceId() == newId) {
            cout << "  [!] Preference ID " << newId << " already exists. Cancelled." << endl;
            return;
        }
    }

    // Verify linked profile exists
    int linkedId = preferences[preferenceCount].getLinkedProfileId();
    bool profileFound = false;
    for (int i = 0; i < profileCount; i++) {
        if (profiles[i].getProfileId() == linkedId) {
            profileFound = true;
            break;
        }
    }
    if (!profileFound) {
        cout << "  [!] Warning: Profile ID " << linkedId << " not found. Preference saved anyway." << endl;
    }

    preferenceCount++;
    cout << "  [+] Preference added successfully! Total: " << preferenceCount << endl;
}

void viewAllPreferences() {
    if (preferenceCount == 0) {
        cout << "  [!] No preferences registered yet." << endl;
        return;
    }

    cout << endl << "  --- All Preferences (" << preferenceCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(10) << "ProfileID"
         << "| " << setw(8) << "Gender"
         << "| " << setw(12) << "Age Range"
         << "| " << setw(10) << "Religion"
         << "| " << setw(14) << "City" << "|" << endl;
    printLine();

    for (int i = 0; i < preferenceCount; i++) {
        preferences[i].display();
    }
    printLine();
}

void findMatches() {
    if (profileCount == 0 || preferenceCount == 0) {
        cout << "  [!] Need at least one profile and one preference to find matches." << endl;
        return;
    }

    int profileId;
    cout << "  Enter Profile ID to find matches for: ";
    cin >> profileId;

    // Find the preference linked to this profile
    int prefIndex = -1;
    for (int i = 0; i < preferenceCount; i++) {
        if (preferences[i].getLinkedProfileId() == profileId) {
            prefIndex = i;
            break;
        }
    }

    if (prefIndex == -1) {
        cout << "  [!] No preferences found for Profile ID " << profileId << "." << endl;
        return;
    }

    cout << endl << "  --- Matching Profiles for ID " << profileId << " ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(18) << "Name"
         << "| " << setw(4) << "Age"
         << "| " << setw(8) << "Gender"
         << "| " << setw(10) << "Religion"
         << "| " << setw(12) << "Phone" << "|" << endl;
    printLine();

    int matchCount = 0;
    for (int i = 0; i < profileCount; i++) {
        // Skip the same profile
        if (profiles[i].getProfileId() == profileId) continue;

        // Check if this profile matches the preferences
        if (preferences[prefIndex].isMatch(profiles[i].getGender(),
                                            profiles[i].getAge(),
                                            profiles[i].getReligion())) {
            profiles[i].display();
            matchCount++;
        }
    }

    if (matchCount == 0) {
        cout << "  | No matching profiles found.                                    |" << endl;
    }
    printLine();
    cout << "  Total Matches: " << matchCount << endl;
}

// ============================================
// MEMBERSHIP MANAGEMENT FUNCTIONS
// ============================================

void addMembership() {
    if (membershipCount >= MAX_MEMBERSHIPS) {
        cout << "  [!] Maximum memberships reached (" << MAX_MEMBERSHIPS << ")." << endl;
        return;
    }

    cout << endl << "  --- Add New Membership ---" << endl;
    memberships[membershipCount].input();

    // Check for duplicate Member ID
    int newId = memberships[membershipCount].getMemberId();
    for (int i = 0; i < membershipCount; i++) {
        if (memberships[i].getMemberId() == newId) {
            cout << "  [!] Member ID " << newId << " already exists. Cancelled." << endl;
            return;
        }
    }

    membershipCount++;
    cout << "  [+] Membership added successfully! Total: " << membershipCount << endl;
}

void viewAllMemberships() {
    if (membershipCount == 0) {
        cout << "  [!] No memberships registered yet." << endl;
        return;
    }

    cout << endl << "  --- All Memberships (" << membershipCount << ") ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(10) << "ProfileID"
         << "| " << setw(10) << "Plan"
         << "| " << setw(13) << "Price"
         << "| " << setw(8) << "Months"
         << "| " << setw(10) << "Status" << "|" << endl;
    printLine();

    for (int i = 0; i < membershipCount; i++) {
        memberships[i].display();
    }
    printLine();
}

void viewActiveMemberships() {
    if (membershipCount == 0) {
        cout << "  [!] No memberships registered yet." << endl;
        return;
    }

    cout << endl << "  --- Active Memberships ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID"
         << "| " << setw(10) << "ProfileID"
         << "| " << setw(10) << "Plan"
         << "| " << setw(13) << "Price"
         << "| " << setw(8) << "Months"
         << "| " << setw(10) << "Status" << "|" << endl;
    printLine();

    int found = 0;
    for (int i = 0; i < membershipCount; i++) {
        if (memberships[i].getIsActive()) {
            memberships[i].display();
            found++;
        }
    }

    if (found == 0) {
        cout << "  | No active memberships at the moment.                           |" << endl;
    }
    printLine();
    cout << "  Active: " << found << " / " << membershipCount << " memberships" << endl;
}

// ============================================
// MAIN MENU
// ============================================

void displayMenu() {
    cout << endl;
    printDoubleLine();
    cout << "         Matrimony Management System" << endl;
    cout << "        Phase 3 - Menu-Driven Interface" << endl;
    printDoubleLine();
    cout << endl;
    cout << "  PROFILE MANAGEMENT" << endl;
    cout << "    1.  Add Profile" << endl;
    cout << "    2.  View All Profiles" << endl;
    cout << "    3.  Search Profile" << endl;
    cout << "    4.  Delete Profile" << endl;
    cout << endl;
    cout << "  PREFERENCE MANAGEMENT" << endl;
    cout << "    5.  Add Partner Preferences" << endl;
    cout << "    6.  View All Preferences" << endl;
    cout << "    7.  Find Matching Profiles" << endl;
    cout << endl;
    cout << "  MEMBERSHIP MANAGEMENT" << endl;
    cout << "    8.  Add Membership" << endl;
    cout << "    9.  View All Memberships" << endl;
    cout << "    10. View Active Memberships" << endl;
    cout << endl;
    cout << "    0.  Exit" << endl;
    printDoubleLine();
    cout << "  Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "  [!] Invalid input. Please enter a number." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1:  addProfile(); break;
            case 2:  viewAllProfiles(); break;
            case 3:  searchProfile(); break;
            case 4:  deleteProfile(); break;
            case 5:  addPreference(); break;
            case 6:  viewAllPreferences(); break;
            case 7:  findMatches(); break;
            case 8:  addMembership(); break;
            case 9:  viewAllMemberships(); break;
            case 10: viewActiveMemberships(); break;
            case 0:
                cout << "  Thank you for using Matrimony Management System!" << endl;
                cout << "  Phase 3 Complete!" << endl;
                printDoubleLine();
                break;
            default:
                cout << "  [!] Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
