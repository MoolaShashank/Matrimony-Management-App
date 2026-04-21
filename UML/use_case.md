# Use Case Diagram - Matrimony Management System

This diagram illustrates the primary interactions between the different actors and the system's core functionalities.

```mermaid
useCaseDiagram
    actor Member
    actor Admin
    actor System

    package "Saanjh Matrimony Hub" {
        usecase "Register Profile" as UC1
        usecase "Login & Authentication" as UC2
        usecase "Search & Filter Profiles" as UC3
        usecase "Send Connection Interest" as UC4
        usecase "Accept/Reject Match" as UC5
        usecase "Seed Demo Data" as UC6
        usecase "Generate Revenue Reports" as UC7
        usecase "Validate Data (C++ Engine)" as UC8
    }

    Member --> UC1
    Member --> UC2
    Member --> UC3
    Member --> UC4
    Member --> UC5

    Admin --> UC6
    Admin --> UC7

    UC1 ..> UC8 : <<include>>
    UC4 ..> UC8 : <<include>>
    UC6 ..> System : "Populate Memory"
    UC7 ..> UC8 : "Scan Vector"
```
