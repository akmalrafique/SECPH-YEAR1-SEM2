//this is based on programmed 1
//a) aggregation bcause the student class contain a vector<Course *> courses
// the sudent class strores a collection of cource object using a vector of pointer vector<Course* >
//this indicates that the student have a "has a " relationship with course object rather than owning them directly

//b)efficiesnt dearching: a map allows for fast lookup by key, a map allows you to requires searching for a sstudent
// using their matrics number,a map allows you to store students with the matric number as key, amking the search operation
// much more efficient compared to a linear search through a vector
//uniques keys: a map automatically ensures that each key is uniques. this is ideal for student records , as it guarentees 
//that no two student can share the same matric number, effectively preventing duplicate entries for the same ID
//organized data: a map maintains its elements in a sorted order based on the keys. this provides an organized structure
// for storing and retriving student information systematically