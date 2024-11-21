# CS221_Assignment2_Problem3
P3.	Write a class template for a map implemented by a hash table with a fixed type for the keys – std::string  and a template type parameter for the values. Do NOT make the type of the keys a type parameter. Use open hashing (chaining) with an array or vector of STL linked lists (this is a fixed requirement. Do NOT make your own list).
a) Provide the necessary constructors/destructor and following public member functions. Please do not change their names:                               
o	Function size that returns the number of key-value pairs in the map
o	Function count that returns the number of elements with a specific key
o	Function erase with an argument key k that removes a key-value pair identified with the key k. If k does not match the key of any element in the map, the function should throw an out_of_range exception.
Example: erase("Harry");
o	Function key_compare without arguments that returns a “key comparison” object - a function object comparing two keys and returning true if the first argument (a key) is less than the second argument (also a key) in some order chosen by you (for example lexicographical, or by the length of the key, or another order chosen by you)  and false otherwise. In a comment specify what is being compared.                                                                       
o	The default constructor should create an empty map.                          


b)	Overload the [] operator to return the value associated with the key provided as argument. If the key does not exist, the operator should throw an out_of_range exception                                                                                            
Examples: 
testMap["Harry"] = 2; 
will set the value corresponding to "Harry" to 2.
cout << testMap["Harry"]; 
will print 2, which is the value corresponding to the key "Harry" in the map.
If the key "Harry" does not exist, the operator should throw an out_of_range exception.
c)	Provide a function set with arguments string (a key) and the type of the value, that will enter the key-value pair specified by its arguments into the map. 
Example:                                                                                    
testMap.set("Harry", 2)
will enter the pair ("Harry",2) into the map. If the key "Harry" already exists, its corresponding value will be set to 2. 
d)   Overload the operator == .                            
e) Provide a test program to thoroughly test your template with at least two different types of values.                                                                                                        
Hint: First implement a class for values of some fixed data type, for example integer or string, and then convert it to a class template. It makes sense to submit both the non-template and the template versions.
Hint: For storing key-value pairs you can use our class template Pair which we used in class exercises, or the STL class template std::pair (documented at https://en.cppreference.com/w/cpp/utility/pair).
