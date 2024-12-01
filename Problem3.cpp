#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

#include "map.h"

/*
class HashMap {
private:
    static const int TABLE_SIZE = 10; // Fixed size for hash table
    std::vector<std::list<std::pair<std::string, int>>> table; // Hash table
    int num_elements; // Tracks the number of key-value pairs in the map

    // Hash function for strings
    size_t hash(const std::string& key) const {
        std::hash<std::string> hash_fn;
        return hash_fn(key) % TABLE_SIZE;
    }

public:
    // Default constructor: initializes an empty hash table
    HashMap() : table(TABLE_SIZE), num_elements(0) {}

    // Destructor
    ~HashMap() = default;

    // Function to return the number of key-value pairs in the map
    int size() const {
        return num_elements;
    }

    // Function to return the number of elements with a specific key
    int count(const std::string& key) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return 1; // Key found
            }
        }
        return 0; // Key not found
    }

    // Function to erase a key-value pair identified by the key
    void erase(const std::string& key) {
        size_t index = hash(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                --num_elements;
                return;
            }
        }
        throw std::out_of_range("Key not found: " + key);
    }

    // Function to return a key comparison object
    std::function<bool(const std::string&, const std::string&)> key_compare() const {
        // Compare keys by lexicographical order
        return [](const std::string& key1, const std::string& key2) {
            return key1 < key2;
        };
    }

    // Function to insert a key-value pair into the map
    void insert(const std::string& key, int value) {
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
    void display() const {
        for (size_t i = 0; i < table.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            std::cout << std::endl;
        }
    }
};
*/
int main() {
    map test1;

    // Test insertion
    test1.set("Alice", 30);
    test1.set("Bob", 25);
    test1.set("Charlie", 35);
    test1.set("Alice", 40); // Update value for existing key

    // Display map
    test1.display();

    // Test size
    std::cout << "Size: " << test1.size() << std::endl;

    // Test count
    std::cout << "Count for 'Alice': " << test1.count("Alice") << std::endl;
    std::cout << "Count for 'David': " << test1.count("David") << std::endl;

    // Test erase
    test1.erase("Bob");
    std::cout << "After erasing 'Bob':" << std::endl;
    test1.display();

    // Test key comparison
    //auto comp = map.key_compare();
    //std::cout << "Key comparison ('Alice' < 'Charlie'): " << comp("Alice", "Charlie") << std::endl;

    try {
        test1.erase("Bob"); // Attempt to erase non-existing key
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}