# Matrimony-Management-App
# Saanjh Matrimony Management System

**LLT1 — Application Development Using Design Concepts**
**B.Tech CSE (Data Science) — Semester 2**

A progressive C++ OOP project built phase-by-phase, demonstrating object-oriented design concepts through a unified Matrimony Management System. The project evolves into a full-stack web application featuring a C++ backend and a festive HTML/JS frontend.

---

## Team Members

| Name | Registration Number |
|------|-------------------|
| Kavish Bohra | RA2511056010236 |
| Daksh Jain | RA2511056010248 |
| Moola Shashank | RA2511056010255 |

---

## About the Project

Saanjh Matrimony is a comprehensive platform designed to manage member profiles and facilitate meaningful connections based on traditional values. The system tracks user profiles, preferences, connection requests, and premium memberships using proper object-oriented design principles.

The project was developed progressively across 6 phases — each phase introduces a new OOP concept as taught in class, building on top of the previous version. The final deliverable includes a fully functional C++ backend web server running a ceremonial web interface.

---

## Features

- **Profile Management:** Register, display, update, and search member profiles.
- **Advanced Filtering:** Core logic to filter profiles by gender, religion, age range, location, and mother tongue.
- **Connection Requests:** Send and manage "Interests" (Partner Match Requests) between members.
- **Membership Tiers:** Upgrade to premium memberships (Gold/Platinum) for enhanced visibility.
- **Input Validation:** Strict encapsulation ensures data integrity (e.g., age limits, valid phone numbers).
- **Interactive Interfaces:**
  - Console-driven menu system for basic phases.
  - Graphical UI using Raylib (Native C++ Window).
  - **Full-Stack Web Hub:** A C++ Winsock Server serving a beautiful HTML5 dashboard.

---

## OOP Concepts Demonstrated

| Phase | Concept | What Was Done |
|-------|---------|---------------|
| 1 | Classes & Objects (CO1) | Basic Profile, Preference, and Membership classes. |
| 2 | Encapsulation (CO2) | Private members, getters/setters, input validation logic. |
| 3 | Arrays & Collections (CO3) | Arrays of objects, CRUD operations, menu-driven interface. |
| 4 | Inheritance (CO4) | Base `UserRequest` class with derived Match and Upgrade requests. |
| 5 | UML Diagrams (CO5) | Use Case, Class, State, and Sequence diagrams. |
| 6 | Final & Web Integration | Polished console app + C++ Web Server + Festive Frontend. |

---

## Folder Structure

```
Matrimony-Management-App/
|
|-- README.md                          <-- You are here
|
|-- Phases/                            <-- Code for each C++ development phase
|   |-- phase1_basic.cpp               Phase 1: Basic classes & objects
|   |-- phase2_encapsulation.cpp       Phase 2: Encapsulation & validation
|   |-- phase3_arrays.cpp              Phase 3: Arrays, search, menu system
|   |-- phase4_inheritance.cpp         Phase 4: Base + derived requests
|   |-- final_matrimony_system.cpp     Phase 6: Final polished console version
|   |-- gui_matrimony.cpp              Bonus: Raylib graphical interface
|
|-- Saanjh_Matrimony_Web/              <-- Full-Stack Integration
|   |-- server.cpp                     C++ Web Server (Winsock, API Endpoints)
|   |-- index.html                     Festive Frontend Dashboard
|   |-- styles.css                     Indian ceremonial design system
|   |-- app.js                         Logic for filtering and C++ API calls
|
|-- UML/                               <-- UML Diagrams (Phase 5)
|   |-- use_case.md                    Actors & system actions (Mermaid)
|   |-- class_diagram.md               Classes, attributes, inheritance
|   |-- state_diagram.md               Profile lifecycle states
|   |-- sequence_diagram.md            Message flow for advanced filtering
```

---

## Class Structure

```
Profile           (standalone)    — Core entity for user details
Preference        (standalone)    — Specific partner requirements
Membership        (standalone)    — Premium tier management

UserRequest       (base class)    — Common properties for system requests
  |
  |-- PartnerMatchRequest        (derived) — Request to connect with another profile
  |-- MembershipUpgradeRequest   (derived) — Request to purchase a premium tier
```

**Key Relationships:**
- Profile → Preference (1 to 1)
- Profile → Membership (1 to 1)
- UserRequest acts as the base for all interactions.

---

---

## Web Interface Options (Saanjh Matrimony)

```
  STEP ONE: BEGIN THE JOURNEY
    - Register Profile (Sent to C++ Engine)

  STEP TWO: SEARCH & FILTER
    - Real-time filtering by Gender, Religion, Age, Location
    - Case-insensitive search
    
  PROJECT HISTORY
    - Retrieve Phase 1-4 source code dynamically from the backend
```

---

## UML Diagrams

All diagrams are written in Mermaid markdown within the `UML/` folder. They can be rendered in GitHub or compatible markdown viewers.

| Diagram | File | What It Shows |
|---------|------|---------------|
| Use Case | `use_case.md` | Member & Admin interactions with the portal |
| Class | `class_diagram.md` | Profile, Requests, and Server relationships |
| State | `state_diagram.md` | The journey from Unregistered to Match Accepted |
| Sequence | `sequence_diagram.md` | Detailed API flow for the C++ filtering engine |

---

## Progressive Development Summary

- **Phase 1**: Established the foundational `Profile` class.
- **Phase 2**: Applied encapsulation to protect age boundaries and format inputs.
- **Phase 3**: Handled multiple users with standard array management and menu navigation.
- **Phase 4**: Utilized inheritance to reduce redundancy across features like 'Matches' and 'Upgrades'.
- **Phase 5**: Documented system architecture visually.
- **Phase 6**: Built a live C++ web server and unified all phases under a beautiful interface.

---

## Tech Stack

- **Backend:** C++ (with Winsock API for HTTP Server)
- **Frontend:** HTML5, Vanilla JavaScript, CSS3
- **GUI Engine (Optional):** Raylib
- **Diagrams:** Mermaid.js 
