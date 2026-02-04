# File Handling in C++

## Overview

File handling allows programs to store data permanently and read it back later. Files persist beyond program execution.

## Topics Covered

### Files Reference:

- [AttendanceLog.cpp](../../Module1/09_FileHandling/AttendanceLog.cpp)
- [DeleteEmployee.cpp](../../Module1/09_FileHandling/DeleteEmployee.cpp)
- [EmployeeSlip.cpp](../../Module1/09_FileHandling/EmployeeSlip.cpp)
- [Studentmarks.cpp](../../Module1/09_FileHandling/Studentmarks.cpp)
- [StudentRecord.cpp](../../Module1/09_FileHandling/StudentRecord.cpp)

## File Stream Classes

### Header File:

```cpp
#include <fstream>
```

### Three Main Classes:

#### 1. ifstream (Input File Stream):

```cpp
ifstream fin;  // For reading from file
```

#### 2. ofstream (Output File Stream):

```cpp
ofstream fout;  // For writing to file
```

#### 3. fstream (File Stream):

```cpp
fstream file;  // For both reading and writing
```

## File Operations

### 1. Opening a File:

#### Method 1: Using open():

```cpp
ofstream fout;
fout.open("data.txt");
```

#### Method 2: Constructor:

```cpp
ofstream fout("data.txt");
```

#### With File Modes:

```cpp
fout.open("data.txt", ios::out | ios::app);
```

### 2. Checking if File Opened:

```cpp
if(!fout) {
    cout << "File could not be opened!";
    return;
}

// Or
if(!fout.is_open()) {
    cout << "File could not be opened!";
}
```

### 3. Writing to File:

#### Using << operator:

```cpp
ofstream fout("data.txt");
fout << "Hello World" << endl;
fout << 123 << " " << 45.67 << endl;
```

#### Using write():

```cpp
char data[] = "Binary data";
fout.write(data, sizeof(data));
```

#### Using put():

```cpp
fout.put('A');
```

### 4. Reading from File:

#### Using >> operator:

```cpp
ifstream fin("data.txt");
string word;
int num;
fin >> word >> num;
```

#### Using getline():

```cpp
string line;
getline(fin, line);  // Read entire line
```

#### Using get():

```cpp
char ch;
fin.get(ch);  // Read single character
```

#### Using read():

```cpp
char buffer[100];
fin.read(buffer, 100);
```

### 5. Closing a File:

```cpp
fout.close();
fin.close();
```

- Important to close files
- Flushes buffered data
- Releases system resources

## File Open Modes

```cpp
ios::in     // Open for input (reading)
ios::out    // Open for output (writing)
ios::app    // Append to end of file
ios::ate    // Go to end of file on opening
ios::trunc  // Delete file contents if exists
ios::binary // Binary mode
```

### Combining Modes:

```cpp
fstream file;
file.open("data.txt", ios::in | ios::out | ios::app);
```

### Mode Examples:

```cpp
// Write, overwrite if exists
ofstream fout("data.txt", ios::out);

// Write, append to existing content
ofstream fout("data.txt", ios::app);

// Read and write
fstream file("data.txt", ios::in | ios::out);

// Binary file
ofstream fout("data.bin", ios::binary);
```

## File Positioning

### Get Current Position:

```cpp
// For reading
streampos pos = fin.tellg();

// For writing
streampos pos = fout.tellp();
```

### Set Position:

```cpp
// For reading
fin.seekg(0, ios::beg);  // Beginning
fin.seekg(0, ios::end);  // End
fin.seekg(10, ios::cur); // 10 bytes from current

// For writing
fout.seekp(0, ios::beg);
fout.seekp(-5, ios::cur);  // 5 bytes backward
```

### Reference Points:

- `ios::beg` - Beginning of file
- `ios::cur` - Current position
- `ios::end` - End of file

## Common File Operations

### 1. Check End of File:

```cpp
while(!fin.eof()) {
    string line;
    getline(fin, line);
    cout << line << endl;
}
```

### 2. Read Entire File:

```cpp
ifstream fin("data.txt");
string line;
while(getline(fin, line)) {
    cout << line << endl;
}
fin.close();
```

### 3. Count Lines:

```cpp
int count = 0;
string line;
while(getline(fin, line)) {
    count++;
}
```

### 4. Copy File:

```cpp
ifstream fin("source.txt");
ofstream fout("dest.txt");

string line;
while(getline(fin, line)) {
    fout << line << endl;
}
```

### 5. Append to File:

```cpp
ofstream fout("data.txt", ios::app);
fout << "New line" << endl;
```

## Binary Files

### Writing Binary:

```cpp
struct Student {
    int roll;
    char name[50];
    float marks;
};

Student s = {101, "John", 85.5};
ofstream fout("data.bin", ios::binary);
fout.write((char*)&s, sizeof(Student));
```

### Reading Binary:

```cpp
Student s;
ifstream fin("data.bin", ios::binary);
fin.read((char*)&s, sizeof(Student));
```

### Benefits of Binary Files:

- Faster read/write
- Smaller file size
- Preserves data structure
- No text conversion needed

## Practical Applications

### 1. Attendance Log:

```cpp
class Attendance {
    string name;
    string date;
    bool present;
public:
    void markAttendance(string n, bool p) {
        ofstream fout("attendance.txt", ios::app);
        fout << n << " " << date << " " << (p ? "Present" : "Absent") << endl;
        fout.close();
    }
};
```

### 2. Employee Records:

```cpp
struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee(Employee &e) {
    ofstream fout("employees.dat", ios::binary | ios::app);
    fout.write((char*)&e, sizeof(Employee));
    fout.close();
}
```

### 3. Student Marks:

```cpp
void saveMarks(int roll, float marks) {
    ofstream fout("marks.txt", ios::app);
    fout << roll << " " << marks << endl;
    fout.close();
}

float getMarks(int roll) {
    ifstream fin("marks.txt");
    int r;
    float m;
    while(fin >> r >> m) {
        if(r == roll) {
            fin.close();
            return m;
        }
    }
    fin.close();
    return -1;  // Not found
}
```

### 4. Delete Record:

```cpp
void deleteEmployee(int id) {
    ifstream fin("employees.txt");
    ofstream fout("temp.txt");

    int empId;
    string name;

    while(fin >> empId >> name) {
        if(empId != id) {
            fout << empId << " " << name << endl;
        }
    }

    fin.close();
    fout.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");
}
```

### 5. Update Record:

```cpp
void updateSalary(int id, float newSalary) {
    fstream file("employees.dat", ios::in | ios::out | ios::binary);
    Employee e;

    while(file.read((char*)&e, sizeof(Employee))) {
        if(e.id == id) {
            e.salary = newSalary;
            file.seekp(-sizeof(Employee), ios::cur);
            file.write((char*)&e, sizeof(Employee));
            break;
        }
    }
    file.close();
}
```

## Error Handling

### Check File State:

```cpp
if(fin.fail()) {
    cout << "Read/Write operation failed";
}

if(fin.bad()) {
    cout << "Fatal error";
}

if(fin.eof()) {
    cout << "End of file reached";
}

if(fin.good()) {
    cout << "No errors";
}
```

### Clear Error Flags:

```cpp
fin.clear();  // Clear error flags
```

## Best Practices

1. **Always Check if File Opened**:

```cpp
if(!fin.is_open()) {
    cerr << "Error opening file";
    return;
}
```

2. **Close Files**:

```cpp
fin.close();  // Free resources
```

3. **Use RAII** (Resource Acquisition Is Initialization):

```cpp
{
    ifstream fin("data.txt");
    // Use file
}  // Automatically closed
```

4. **Handle Errors**:

```cpp
try {
    ifstream fin("data.txt");
    if(!fin) throw runtime_error("Can't open file");
    // Process file
} catch(exception &e) {
    cerr << e.what() << endl;
}
```

5. **Use Appropriate Modes**:

```cpp
ios::trunc  // When overwriting
ios::app    // When appending
ios::binary // For binary data
```

6. **Flush Output**:

```cpp
fout << data << flush;  // Write immediately
```

## Common Pitfalls

1. **Forgetting to Close**:

```cpp
ofstream fout("data.txt");
fout << "Data";
// Forgot fout.close() - data may not be written
```

2. **Not Checking if Opened**:

```cpp
ifstream fin("nonexistent.txt");
fin >> data;  // May cause undefined behavior
```

3. **Wrong Mode**:

```cpp
ofstream fout("data.txt");  // Truncates file by default!
// Use ios::app to append
```

4. **Reading After EOF**:

```cpp
while(!fin.eof()) {
    fin >> data;
    process(data);  // May process garbage on last iteration
}

// Better:
while(fin >> data) {
    process(data);
}
```

5. **Binary vs Text Confusion**:

```cpp
// Don't mix binary and text operations
fout.write(...);  // Binary
fout << ...;      // Text
```

## File System Operations

### Check if File Exists:

```cpp
#include <fstream>
bool fileExists(string filename) {
    ifstream file(filename);
    return file.good();
}
```

### Delete File:

```cpp
#include <cstdio>
remove("data.txt");
```

### Rename File:

```cpp
rename("old.txt", "new.txt");
```

### Get File Size:

```cpp
ifstream fin("data.txt", ios::ate);
streampos size = fin.tellg();
```

## Related Concepts

- Serialization
- Database operations
- Logging
- Configuration files
- CSV/JSON parsing
- Buffering and streams
