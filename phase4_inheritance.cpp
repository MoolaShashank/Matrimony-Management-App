// ============================================
// Matrimony Management System
// Phase 4: Inheritance
// OOP Concepts: Base & Derived Classes,
//               Code Reuse, Method Overriding
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
    Profile() : profileId(0), name(""), age(0), gender(""), religion(""), phone(""), email("") {}

    int getProfileId() { return profileId; }
    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    string getReligion() { return religion; }

    void setProfileId(int id) { if (id > 0) profileId = id; }
    void setName(string n) { name = n; }
    void setAge(int a) { if (a >= 18) age = a; }
    void setGender(string g) { gender = g; }
    void setReligion(string r) { religion = r; }
    void setPhone(string p) { phone = p; }
    void setEmail(string e) { email = e; }

    void input() {
        int id, a; string n, g, r, p, e;
        cout << "  Enter Profile ID: "; cin >> id; setProfileId(id);
        cout << "  Enter Full Name: "; cin.ignore(); getline(cin, n); setName(n);
        cout << "  Enter Age (18+): "; cin >> a; setAge(a);
        cout << "  Enter Gender (Male/Female): "; cin >> g; setGender(g);
        cout << "  Enter Religion: "; cin >> r; setReligion(r);
        cout << "  Enter Phone: "; cin >> p; setPhone(p);
        cout << "  Enter Email: "; cin >> e; setEmail(e);
    }

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
// USER REQUEST - BASE CLASS (Phase 4)
// Demonstrates: Code Reuse, Common attributes
// ============================================
class UserRequest {
protected:
    int requestId;
    int profileId;     // The user making the request
    string date;
    string status;     // Pending, Approved, Rejected
    string requestType;

public:
    UserRequest() : requestId(0), profileId(0), date(""), status("Pending"), requestType("") {}

    int getRequestId() { return requestId; }
    int getProfileId() { return profileId; }
    string getStatus() { return status; }
    string getRequestType() { return requestType; }

    void setRequestId(int id) { requestId = id; }
    void setProfileId(int id) { profileId = id; }
    void setDate(string d) { date = d; }
    void setStatus(string s) { status = s; }

    // Base display
    void display() {
        cout << "  Request ID   : " << requestId << endl;
        cout << "  Profile ID   : " << profileId << endl;
        cout << "  Date         : " << date << endl;
        cout << "  Type         : " << requestType << endl;
        cout << "  Status       : " << status << endl;
    }
};

// ============================================
// PARTNER MATCH REQUEST - DERIVED FROM USERREQUEST
// Demonstrates: Inheritance, Method Overriding
// ============================================
class PartnerMatchRequest : public UserRequest {
private:
    int targetProfileId; // Profile user wants to connect with
    string message;

public:
    PartnerMatchRequest() : targetProfileId(0), message("") {
        requestType = "Connect";
    }

    void input(int rId, int pId) {
        setRequestId(rId);
        setProfileId(pId);
        string d;
        cout << "  Enter Date (DD/MM/YYYY): "; cin >> d; setDate(d);
        cout << "  Enter ID of Profile to connect with: "; cin >> targetProfileId;
        cout << "  Enter a short message: "; cin.ignore(); getline(cin, message);
    }

    // Overridden display
    void display() {
        cout << "  +-----------------------------------------+" << endl;
        cout << "  |        MATCH CONNECTION REQUEST         |" << endl;
        cout << "  +-----------------------------------------+" << endl;
        cout << "  | Request ID   : " << left << setw(25) << requestId << "|" << endl;
        cout << "  | From Profile : " << left << setw(25) << profileId << "|" << endl;
        cout << "  | To Profile   : " << left << setw(25) << targetProfileId << "|" << endl;
        cout << "  | Date         : " << left << setw(25) << date << "|" << endl;
        cout << "  | Status       : " << left << setw(25) << status << "|" << endl;
        cout << "  | Msg: " << left << setw(35) << message.substr(0, 30) + "..." << "|" << endl;
        cout << "  +-----------------------------------------+" << endl;
    }
};

// ============================================
// MEMBERSHIP UPGRADE REQUEST - DERIVED FROM USERREQUEST
// Demonstrates: Inheritance, Code Reuse
// ============================================
class MembershipUpgradeRequest : public UserRequest {
private:
    string targetPlan;
    float amountPaid;

public:
    MembershipUpgradeRequest() : targetPlan(""), amountPaid(0) {
        requestType = "Upgrade";
    }

    void input(int rId, int pId) {
        setRequestId(rId);
        setProfileId(pId);
        string d;
        cout << "  Enter Date (DD/MM/YYYY): "; cin >> d; setDate(d);
        cout << "  Enter Target Plan (Silver/Gold/Platinum): "; cin >> targetPlan;
        cout << "  Enter Amount Paid (Rs.): "; cin >> amountPaid;
        status = "Approved"; // Typically auto-approved on payment
    }

    // Overridden display
    void display() {
        cout << "  +-----------------------------------------+" << endl;
        cout << "  |        MEMBERSHIP UPGRADE RECEIPT       |" << endl;
        cout << "  +-----------------------------------------+" << endl;
        cout << "  | Request ID   : " << left << setw(25) << requestId << "|" << endl;
        cout << "  | Profile ID   : " << left << setw(25) << profileId << "|" << endl;
        cout << "  | Plan Chosen  : " << left << setw(25) << targetPlan << "|" << endl;
        cout << "  | Amount Paid  : Rs." << left << setw(21) << fixed << setprecision(0) << amountPaid << "|" << endl;
        cout << "  | Date         : " << left << setw(25) << date << "|" << endl;
        cout << "  | Status       : " << left << setw(25) << status << "|" << endl;
        cout << "  +-----------------------------------------+" << endl;
    }
};

// ============================================
// GLOBAL DATA
// ============================================
const int MAX = 50;
Profile profiles[MAX];
PartnerMatchRequest matchRequests[MAX];
MembershipUpgradeRequest upgradeRequests[MAX];

int profileCount = 0;
int matchRequestCount = 0;
int upgradeRequestCount = 0;
int nextRequestId = 5001;

// ============================================
// UTILITIES
// ============================================
void printLine() { cout << "  " << string(68, '-') << endl; }
void printDoubleLine() { cout << "  " << string(68, '=') << endl; }

int findProfile(int id) {
    for (int i = 0; i < profileCount; i++)
        if (profiles[i].getProfileId() == id) return i;
    return -1;
}

// ============================================
// MANAGEMENT FUNCTIONS
// ============================================

void addProfile() {
    if (profileCount >= MAX) return;
    cout << endl << "  --- Create New Profile ---" << endl;
    profiles[profileCount].input();
    profileCount++;
}

void viewAllProfiles() {
    if (profileCount == 0) { cout << "  [!] No profiles." << endl; return; }
    cout << endl << "  --- All Registered Profiles ---" << endl;
    printLine();
    cout << "  | " << left << setw(6) << "ID" << "| " << setw(18) << "Name" << "| " << setw(4) << "Age" << "| " << setw(8) << "Gender" << "| " << setw(10) << "Religion" << "| " << setw(12) << "Phone" << "|" << endl;
    printLine();
    for (int i = 0; i < profileCount; i++) profiles[i].display();
    printLine();
}

void createMatchRequest() {
    if (profileCount < 2) { cout << "  [!] Need at least 2 profiles to match." << endl; return; }
    int pId; cout << "  Enter your Profile ID: "; cin >> pId;
    if (findProfile(pId) == -1) { cout << "  [!] Profile not found." << endl; return; }

    matchRequests[matchRequestCount].input(nextRequestId++, pId);
    cout << endl << "  [+] Match request sent!" << endl;
    matchRequests[matchRequestCount].display();
    matchRequestCount++;
}

void createUpgradeRequest() {
    if (profileCount == 0) return;
    int pId; cout << "  Enter your Profile ID: "; cin >> pId;
    if (findProfile(pId) == -1) { cout << "  [!] Profile not found." << endl; return; }

    upgradeRequests[upgradeRequestCount].input(nextRequestId++, pId);
    cout << endl << "  [+] Membership upgraded successfully!" << endl;
    upgradeRequests[upgradeRequestCount].display();
    upgradeRequestCount++;
}

void viewAllRequests() {
    int total = matchRequestCount + upgradeRequestCount;
    if (total == 0) { cout << "  [!] No requests found." << endl; return; }

    cout << endl;
    printDoubleLine();
    cout << "        All System Requests (" << total << " total)" << endl;
    printDoubleLine();

    if (matchRequestCount > 0) {
        cout << endl << "  MATCH REQUESTS:" << endl;
        for (int i = 0; i < matchRequestCount; i++) matchRequests[i].display();
    }
    if (upgradeRequestCount > 0) {
        cout << endl << "  UPGRADE REQUESTS:" << endl;
        for (int i = 0; i < upgradeRequestCount; i++) upgradeRequests[i].display();
    }
    printDoubleLine();
}

// ============================================
// MAIN MENU
// ============================================
int main() {
    int choice;
    do {
        cout << endl;
        printDoubleLine();
        cout << "         Matrimony Management System" << endl;
        cout << "         Phase 4 - Inheritance" << endl;
        printDoubleLine();
        cout << "  1. Add Profile" << endl;
        cout << "  2. View All Profiles" << endl;
        cout << "  3. Send Match Request (Inheritance: PartnerMatchRequest)" << endl;
        cout << "  4. Upgrade Membership (Inheritance: MembershipUpgradeRequest)" << endl;
        cout << "  5. View All System Requests (Base: UserRequest)" << endl;
        cout << "  0. Exit" << endl;
        printDoubleLine();
        cout << "  Enter Choice: "; cin >> choice;

        switch (choice) {
            case 1: addProfile(); break;
            case 2: viewAllProfiles(); break;
            case 3: createMatchRequest(); break;
            case 4: createUpgradeRequest(); break;
            case 5: viewAllRequests(); break;
            case 0: cout << "  Exiting Phase 4..." << endl; break;
        }
    } while (choice != 0);
    return 0;
}
