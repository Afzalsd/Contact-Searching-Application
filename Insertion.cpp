#include<bits/stdc++.h>
using namespace std;

// Define a Class for contact information
class Contact {
    public:
        string name, phoneNumber, email;
};

// Define a Class for a Hash Table
class HashTable {
    public:
        int size;
        vector<Contact> *table;
};

// Insert a contact into the hash table
void insertContact(HashTable *ht, Contact c) {
    int index = c.name.length() % ht->size;
    ht->table[index].push_back(c);
}


int main()
{
    // Create a Hash Table
    HashTable *ht = new HashTable();
    Contact c;
    ht->size = 10;
    ht->table = new vector<Contact>[ht->size];

    // Insert the Contacts in a File into the Hash Table
    ifstream file("contacts.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, c.name, ',');
        getline(ss, c.phoneNumber, ',');
        getline(ss, c.email, ',');
        insertContact(ht, c);
    }

    // Choice for the User
    int choice;
    cout << "1. Add a Contact" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Enter the Name: ";
            cin.ignore();
            getline(cin, c.name);
            cout << "Enter the Phone Number: ";
            getline(cin, c.phoneNumber);
            cout << "Enter the Email: ";
            cin>>c.email;
            insertContact(ht, c);
            break;
        default:
        cout<<"Invalid choice"<<endl;
            break;
    }

    // Store the Contacts in the Hash Table into a File
    ofstream outfile("contacts.txt");
    for (int i = 0; i < ht->size; i++) 
    {
        for (int j = 0; j < ht->table[i].size(); j++) {
            outfile << ht->table[i][j].name << "," << ht->table[i][j].phoneNumber << "," << ht->table[i][j].email << endl;
        }
    }

    file.close(); 
}

/* To Do - Insertion */
// Collision Handling using Linear Probing - if the Index is Already Occupied
// Re Hash the Hash Table - if More than 70% of the Hash Table is Filled
// Should Not Allow Duplicate Entries
