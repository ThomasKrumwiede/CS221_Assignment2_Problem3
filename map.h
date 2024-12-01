#pragma once
#include <iostream>
#include <vector>
#include <List>

using namespace std;

class map {
public:
    // Default constructor: initializes an empty hash table
    map() : table(TABLE_SIZE), num_elements(0) {}

    // Destructor
    ~map() = default;

    // Function to return the number of key-value pairs in the map
    int size() const;

    // Function to return the number of elements with a specific key
    int count(const string& key) const;

    // Function to erase a key-value pair identified by the key
    void erase(const string& key);

    // Function to return a key comparison object
    //function<bool(const string&, const string&)> key_compare() const;

    // Function to insert a key-value pair into the map
    void set(const string& key, int value);

    // Function to display the contents of the hash map (for testing purposes)
    void display() const;

private:
    const int TABLE_SIZE = 10; // Fixed size for hash table
    vector<list<pair<string, int>>> table; // Hash table
    int num_elements; // Tracks the number of key-value pairs in the map

    // Hash function for strings
    size_t hash(const string& key) const;
};