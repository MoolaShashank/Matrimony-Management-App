// ================================================================
// Matrimony Management System
// Phase 6: Final Polished Version
// ================================================================
// OOP Concepts Applied:
//   1. Classes & Objects (CO1)
//   2. Encapsulation - private members, getters/setters (CO2)
//   3. Arrays of Objects - collections, searching (CO3)
//   4. Inheritance - UserRequest -> MatchRequest, UpgradeRequest (CO4)
//   5. UML Diagrams - documented separately (CO5)
//
// Team Members:
//   Kavish Bohra - RA2511056010236
//   Daksh Gupta - RA2511056010248
//   Moola Shashank - RA2511056010255
//
// ================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================================================================
// CONSTANTS
// ================================================================
const int MAX_PROFILES = 50;
const int MAX_PREFERENCES = 50;
const int MAX_MEMBERSHIPS = 50;
const int MAX_MATCH_REQUESTS = 100;
const int MAX_UPGRADE_REQUESTS = 100;

// ================================================================
// CLASS: Profile
// Demonstrates: Classes, Objects, Encapsulation
// ================================================================
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
    bool setProfileId(int id) {
        if (id > 0) { profileId = id; return true; }
        cout << "  [!] Profile ID must be positive." << endl;
        return false;
    }

    bool setName(string n) {
        if (n.length() > 0) { name = n; return true; }
        cout << "  [!] Name cannot be empty." << endl;
        return false;
    }

    bool setAge(int a) {
        if (a >= 18 && a <= 80) { age = a; return true; }
        cout << "  [!] Age must be between 18 and 80." << endl;
        return false;
    }

    bool setGender(string g) {
        if (g == "Male" || g == "Female") { gender = g; return true; }
        cout << "  [!] Gender must be Male or Female." << endl;
        return false;
    }

    bool setReligion(string r) {
        if (r.length() > 0) { religion = r; return true; }
        cout << "  [!] Religion cannot be empty." << endl;
        return false;
    }

    bool setPhone(string p) {
        if (p.length() == 10) {
            for (char c : p) if (c < '0' || c > '9') return false;
            phone = p; return true;
        }
        cout << "  [!] Phone must be exactly 10 digits." << endl;
        return false;
    }

    bool setEmail(string e) {
        if (e.find('@') != string::npos && e.find('.') != string::npos) {
            email = e; return true;
        }
        cout << "  [!] Invalid email format." << endl;
        return false;
    }

    void input() {
        int id, a; string n, g, r, p, e;
        cout << "  Enter Profile ID    : "; cin >> id; setProfileId(id);
        cout << "  Enter Full Name     : "; cin.ignore(); getline(cin, n); setName(n);
        cout << "  Enter Age (18-80)   : "; cin >> a; setAge(a);
        cout << "  Enter Gender (M/F)  : "; cin >> g; setGender(g);
        cout << "  Enter Religion      : "; cin >> r; setReligion(r);
        cout << "  Enter Phone (10 dig): "; cin >> p; setPhone(p);
        cout << "  Enter Email         : "; cin >> e; setEmail(e);
    }

    void display() {
        cout << "  | " << left << setw(6) << profileId
             << "| " << setw(18) << name
             << "| " << setw(4) << age
             << "| " << setw(8) << gender
             << "| " << setw(10) << religion
             << "| " << setw(12) << phone << "|" << endl;
    }

    void displayCard() {
        cout << "  +------------------------------------------+" << endl;
        cout << "  | PROFILE DETAILS                          |" << endl;
        cout << "  +------------------------------------------+" << endl;
        cout << "  | ID       : " << left << setw(30) << profileId << "|" << endl;
        cout << "  | Name     : " << left << setw(30) << name << "|" << endl;
        cout << "  | Age      : " << left << setw(30) << age << "|" << endl;
        cout << "  | Gender   : " << left << setw(30) << gender << "|" << endl;
        cout << "  | Religion : " << left << setw(30) << religion << "|" << endl;
        cout << "  | Phone    : " << left << setw(30) << phone << "|" << endl;
        cout << "  +------------------------------------------+" << endl;
    }
};

// ================================================================
// CLASS: Preference
// ================================================================
class Preference {
private:
    int profileId;
    string prefGender;
    int minAge;
    int maxAge;
    string prefReligion;

public:
    Preference() : profileId(0), prefGender(""), minAge(18), maxAge(80), prefReligion("") {}

    int getProfileId() { return profileId; }
    string getPrefGender() { return prefGender; }
    int getMinAge() { return minAge; }
    int getMaxAge() { return maxAge; }
    string getPrefReligion() { return prefReligion; }

    void setProfileId(int id) { profileId = id; }
    void setPrefGender(string g) { prefGender = g; }
    void setMinAge(int a) { minAge = a; }
    void setMaxAge(int a) { maxAge = a; }
    void setPrefReligion(string r) { prefReligion = r; }

    void input(int pId) {
        profileId = pId;
        cout << "  Preferred Gender (Male/Female): "; cin >> prefGender;
        cout << "  Minimum Age: "; cin >> minAge;
        cout << "  Maximum Age: "; cin >> maxAge;
        cout << "  Preferred Religion: "; cin >> prefReligion;
    }

    void display() {
        cout << "  | " << left << setw(8) << profileId
             << "| " << setw(8) << prefGender
             << "| " << right << setw(3) << minAge << "-" << left << setw(4) << maxAge
             << "| " << setw(12) << prefReligion << "|" << endl;
    }
};

// ================================================================
// BASE CLASS: UserRequest (Phase 4 - Inheritance)
// ================================================================
class UserRequest {
protected:
    int requestId;
    int profileId;
    string profileName;
    string date;
    float cost;
    string status;
    string requestType;

public:
    UserRequest() : requestId(0), profileId(0), profileName(""), 
                    date(""), cost(0), status("Pending"), requestType("") {}

    int getRequestId() { return requestId; }
    int getProfileId() { return profileId; }
    float getCost() { return cost; }
    string getRequestType() { return requestType; }

    void setRequestId(int id) { requestId = id; }
    void setProfileId(int id) { profileId = id; }
    void setProfileName(string n) { profileName = n; }
    void setDate(string d) { date = d; }
    void setCost(float c) { cost = c; }
    void setStatus(string s) { status = s; }

    void display() {
        cout << "  Req #" << requestId << " | " << requestType 
             << " | Profile: " << profileName << " (ID:" << profileId << ")"
             << " | Status: " << status << endl;
    }
};

// ================================================================
// DERIVED CLASS: MatchRequest (inherits UserRequest)
// ================================================================
class MatchRequest : public UserRequest {
private:
    int targetId;
    string targetName;
    string message;

public:
    MatchRequest() : targetId(0), targetName(""), message("") {
        requestType = "Match";
    }

    void input(int rId, int pId, string pName, int tId, string tName) {
        setRequestId(rId);
        setProfileId(pId);
        setProfileName(pName);
        targetId = tId;
        targetName = tName;
        cout << "  Enter Date (DD/MM/YYYY): "; cin >> date;
        cout << "  Enter a short message: "; cin.ignore(); getline(cin, message);
        cost = 0; // Requests are usually free or based on limits
    }

    void display() {
        cout << "  +--------------------------------------------+" << endl;
        cout << "  |          ** MATCH REQUEST TICKET **         |" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Request ID  : " << left << setw(29) << requestId << "|" << endl;
        cout << "  | From        : " << left << setw(29) << profileName << "|" << endl;
        cout << "  | To          : " << left << setw(29) << targetName << "|" << endl;
        cout << "  | Date        : " << left << setw(29) << date << "|" << endl;
        cout << "  | Status      : " << left << setw(29) << status << "|" << endl;
        cout << "  | Msg: " << left << setw(38) << message.substr(0, 35) << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
    }

    void displayRow() {
        cout << "  | " << left << setw(6) << requestId
             << "| " << setw(10) << profileId
             << "| " << setw(12) << profileName.substr(0, 11)
             << "| To: " << setw(10) << targetId
             << "| " << setw(10) << status << "|" << endl;
    }
};

// ================================================================
// DERIVED CLASS: UpgradeRequest (inherits UserRequest)
// ================================================================
class UpgradeRequest : public UserRequest {
private:
    string plan;
    int months;

public:
    UpgradeRequest() : plan(""), months(0) {
        requestType = "Upgrade";
        status = "Approved";
    }

    void input(int rId, int pId, string pName) {
        setRequestId(rId);
        setProfileId(pId);
        setProfileName(pName);
        cout << "  Enter Date (DD/MM/YYYY): "; cin >> date;
        cout << "  Enter Plan (Silver/Gold/Platinum): "; cin >> plan;
        cout << "  Enter Duration (months): "; cin >> months;
        
        float rate = (plan == "Platinum") ? 999 : (plan == "Gold" ? 599 : 299);
        cost = rate * months;
        cout << "  >> Total Amount: Rs." << fixed << setprecision(0) << cost << endl;
    }

    void display() {
        cout << "  +--------------------------------------------+" << endl;
        cout << "  |         ** MEMBERSHIP UPGRADE **           |" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | Request ID  : " << left << setw(29) << requestId << "|" << endl;
        cout << "  | Profile     : " << left << setw(29) << profileName << "|" << endl;
        cout << "  | Plan        : " << left << setw(29) << plan << "|" << endl;
        cout << "  | Duration    : " << left << setw(22) << months << " months |" << endl;
        cout << "  | Date        : " << left << setw(29) << date << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
        cout << "  | TOTAL PAID  : Rs." << left << setw(25) << fixed << setprecision(0) << cost << "|" << endl;
        cout << "  +--------------------------------------------+" << endl;
    }

    void displayRow() {
        cout << "  | " << left << setw(6) << requestId
             << "| " << setw(10) << profileId
             << "| " << setw(12) << profileName.substr(0, 11)
             << "| " << setw(10) << plan
             << "| Rs." << setw(8) << fixed << setprecision(0) << cost << "|" << endl;
    }
};

// ================================================================
// GLOBAL DATA
// ================================================================
Profile profiles[MAX_PROFILES];
Preference preferences[MAX_PREFERENCES];
MatchRequest matchRequests[MAX_MATCH_REQUESTS];
UpgradeRequest upgradeRequests[MAX_UPGRADE_REQUESTS];

int profileCount = 0;
int preferenceCount = 0;
int matchRequestCount = 0;
int upgradeRequestCount = 0;
int nextRequestId = 7001;

// ================================================================
// SEARCH UTILITIES
// ================================================================
int findProfile(int id) {
    for (int i = 0; i < profileCount; i++) if (profiles[i].getProfileId() == id) return i;
    return -1;
}
int findPrefIndex(int pId) {
    for (int i = 0; i < preferenceCount; i++) if (preferences[i].getProfileId() == pId) return i;
    return -1;
}

// ================================================================
// CORE FUNCTIONS
// ================================================================

void addProfile() {
    if (profileCount >= MAX_PROFILES) return;
    cout << endl << "  --- Add New Profile ---" << endl;
    profiles[profileCount].input();
    profileCount++;
    cout << "  [+] Profile created!" << endl;
}

void viewProfiles() {
    if (profileCount == 0) return;
    cout << endl << "  --- All Profiles ---" << endl;
    cout << "  " << string(65, '-') << endl;
    for (int i = 0; i < profileCount; i++) profiles[i].display();
    cout << "  " << string(65, '-') << endl;
}

void setPreferences() {
    int id; cout << "  Enter Profile ID: "; cin >> id;
    int idx = findProfile(id);
    if (idx == -1) return;
    
    int pIdx = findPrefIndex(id);
    if (pIdx == -1) {
        preferences[preferenceCount].input(id);
        preferenceCount++;
    } else {
        preferences[pIdx].input(id);
    }
    cout << "  [+] Preferences saved." << endl;
}

void findMatches() {
    int id; cout << "  Enter Profile ID to find matches for: "; cin >> id;
    int pIdx = findPrefIndex(id);
    if (pIdx == -1) { cout << "  [!] Please set preferences first (Option 5)." << endl; return; }

    cout << endl << "  --- Potential Matches ---" << endl;
    int found = 0;
    for (int i = 0; i < profileCount; i++) {
        if (profiles[i].getProfileId() == id) continue;
        
        bool genderMatch = (profiles[i].getGender() == preferences[pIdx].getPrefGender());
        bool ageMatch = (profiles[i].getAge() >= preferences[pIdx].getMinAge() && profiles[i].getAge() <= preferences[pIdx].getMaxAge());
        bool religionMatch = (profiles[i].getReligion() == preferences[pIdx].getPrefReligion());

        if (genderMatch && ageMatch && religionMatch) {
            profiles[i].display();
            found++;
        }
    }
    if (found == 0) cout << "  No matches found based on your criteria." << endl;
}

void sendMatchRequest() {
    int myId, targetId;
    cout << "  Enter your Profile ID: "; cin >> myId;
    int myIdx = findProfile(myId);
    if (myIdx == -1) return;

    cout << "  Enter Target Profile ID: "; cin >> targetId;
    int tIdx = findProfile(targetId);
    if (tIdx == -1) return;

    matchRequests[matchRequestCount].input(nextRequestId++, myId, profiles[myIdx].getName(), targetId, profiles[tIdx].getName());
    matchRequestCount++;
    cout << "  [+] Match request sent!" << endl;
}

void upgradeMembership() {
    int id; cout << "  Enter Profile ID: "; cin >> id;
    int idx = findProfile(id);
    if (idx == -1) return;

    upgradeRequests[upgradeRequestCount].input(nextRequestId++, id, profiles[idx].getName());
    upgradeRequestCount++;
}

void viewSystemReports() {
    cout << endl << "  ====================================================" << endl;
    cout << "              MATRIMONY SYSTEM REPORTS" << endl;
    cout << "  ====================================================" << endl;
    
    if (matchRequestCount > 0) {
        cout << endl << "  RECENT MATCH REQUESTS:" << endl;
        for (int i = 0; i < matchRequestCount; i++) matchRequests[i].displayRow();
    }
    
    float totalRev = 0;
    if (upgradeRequestCount > 0) {
        cout << endl << "  MEMBERSHIP UPGRADES:" << endl;
        for (int i = 0; i < upgradeRequestCount; i++) {
            upgradeRequests[i].displayRow();
            totalRev += upgradeRequests[i].getCost();
        }
    }
    
    cout << endl << "  TOTAL PLATFORM REVENUE: Rs." << fixed << setprecision(0) << totalRev << endl;
    cout << "  TOTAL PROFILES: " << profileCount << endl;
    cout << "  ====================================================" << endl;
}

// ================================================================
// MAIN
// ================================================================
int main() {
    int choice;
    cout << endl << "  " << string(60, '=') << endl;
    cout << "      Welcome to the Matrimony Management System" << endl;
    cout << "      Final Polished Version | B.Tech CSE (DS)" << endl;
    cout << "      Developed by: Kavish Bohra, Daksh Gupta, Moola Shashank" << endl;
    cout << "  " << string(60, '=') << endl;

    do {
        cout << endl << "  --- MAIN MENU ---" << endl;
        cout << "  1. Add Profile     2. View Profiles    3. Search Profile" << endl;
        cout << "  4. Delete Profile  5. Set Preferences  6. Find Matches" << endl;
        cout << "  7. Send Request    8. Upgrade Plan     9. System Reports" << endl;
        cout << "  0. Exit" << endl;
        cout << "  Choice: "; cin >> choice;

        switch (choice) {
            case 1: addProfile(); break;
            case 2: viewProfiles(); break;
            case 3: { int id; cout<<"ID: "; cin>>id; int i=findProfile(id); if(i!=-1) profiles[i].displayCard(); break; }
            case 4: { int id; cout<<"ID: "; cin>>id; int i=findProfile(id); if(i!=-1) { for(int j=i;j<profileCount-1;j++) profiles[j]=profiles[j+1]; profileCount--; } break; }
            case 5: setPreferences(); break;
            case 6: findMatches(); break;
            case 7: sendMatchRequest(); break;
            case 8: upgradeMembership(); break;
            case 9: viewSystemReports(); break;
            case 0: 
                cout << endl << "  Finalizing System..." << endl;
                cout << "  Team Members: Kavish Bohra | Daksh Gupta | Moola Shashank" << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}
