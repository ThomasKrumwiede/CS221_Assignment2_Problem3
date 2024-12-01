#include "map.h"
#include <stdexcept>

using namespace std;



// Default constructor: initializes an empty hash table
//map::map() : table(TABLE_SIZE), num_elements(0) {}

// Destructor
//map::~map() = default;

size_t map::hash(const string& key) const{
    int sum = 0;

    // Sum up ASCII values of characters in the key
    for (size_t i = 0; i < key.length(); ++i) {
        char ch = key[i];
        sum += static_cast<int>(ch);
    }

    // Return the bucket index (modulus operation)
    return sum % TABLE_SIZE;
}
// Function to return the number of key-value pairs in the map
int map::size() const {
    return num_elements;
}

// Function to return the number of elements with a specific key
int map::count(const string & key) const {
    size_t index = hash(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            return 1; // Key found
        }
    }
    return 0; // Key not found
}

// Function to erase a key-value pair identified by the key
void map::erase(const string & key) {
    size_t index = hash(key);
    auto& chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it);
            --num_elements;
            return;
        }
    }
    throw out_of_range("Key not found: " + key);
}

// Function to return a key comparison object
//std::function<bool(const std::string&, const std::string&)> key_compare() const {
    // Compare keys by lexicographical order
   // return [](const std::string& key1, const std::string& key2) {
     //   return key1 < key2;
   // };
//}

// Function to insert a key-value pair into the map
void map::set(const string& key, int value) {
    size_t index = hash(key);
    auto& chain = table[index];

    // Check if the key already exists
    for (auto& pair : chain) {
        if (pair.first == key) {
            pair.second = value; // Update the value if key exists
            return;
        }
    }

    // Key does not exist, insert a new key-value pair
    chain.emplace_back(key, value);
    ++num_elements;
}

// Function to display the contents of the hash map (for testing purposes)
void map::display() const {
    for (size_t i = 0; i < table.size(); ++i) {
        cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]) {
            cout << "{" << pair.first << ": " << pair.second << "} ";
        }
        cout << endl;
    }
}