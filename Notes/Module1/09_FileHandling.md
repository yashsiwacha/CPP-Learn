# File Handling in C++

## 📋 Study Plan

**Time Needed:** 4-5 hours  
**Difficulty:** ⭐⭐⭐ (Medium-Hard)  
**Prerequisites:** Structures, arrays, strings, loops

**What you'll learn:** Store and retrieve data permanently!

---

## 🔷 Definition (Memorize This!)

```
┌──────────────────────────────────────────────────────────┐
│ FILE HANDLING = Reading from and writing to files       │
│                 for permanent data storage               │
│                                                          │
│ Why Important:                                           │
│  • Data persists after program ends                      │
│  • Store large amounts of data                           │
│  • Share data between programs                           │
│  • Create logs and records                               │
└──────────────────────────────────────────────────────────┘
```

## 🎨 File Operations Flow [Draw This!]

```
Program ←→ File Stream ←→ File on Disk

ifstream (Input):  File → Program (Read)
ofstream (Output): Program → File (Write)
fstream:           Both directions
```

---

## Key Concepts

### 1. File Stream Classes

**Header:** `#include <fstream>`

| Class      | Purpose          | Common Use     |
| ---------- | ---------------- | -------------- |
| `ifstream` | Input (Reading)  | Read from file |
| `ofstream` | Output (Writing) | Write to file  |
| `fstream`  | Both             | Read and write |

### 2. Basic File Operations ([StudentRecord.cpp](../../Module1/09_FileHandling/StudentRecord.cpp))

**Opening:**

- Constructor: `ofstream fout("data.txt");`
- Method: `fout.open("data.txt");`

**Check if opened:** `if(!fout) { /* error */ }`

**Writing:**

- Text: `fout << "Hello" << endl;`
- Binary: `fout.write((char*)&data, sizeof(data));`

**Reading:**

- Text: `fin >> data;`
- Line: `getline(fin, line);`
- Binary: `fin.read((char*)&data, sizeof(data));`

**Closing:** `fout.close();` (or automatic when object destroyed)

### 3. File Modes

| Mode          | Purpose                 |
| ------------- | ----------------------- |
| `ios::in`     | Open for reading        |
| `ios::out`    | Open for writing        |
| `ios::app`    | Append to end           |
| `ios::trunc`  | Delete existing content |
| `ios::binary` | Binary mode             |

**Combine modes:** `ios::out | ios::app`

### 4. File Positioning

**Get position:**

- Reading: `streampos pos = fin.tellg();`
- Writing: `streampos pos = fout.tellp();`

**Set position:**

- `fin.seekg(0, ios::beg);` - Beginning
- `fin.seekg(0, ios::end);` - End
- `fin.seekg(10, ios::cur);` - From current

### 5. Common Patterns

**Read entire file:**

```cpp
while(getline(fin, line)) {
    // process line
}
```

**Check EOF:** `while(!fin.eof())`

**Copy file:** Read from one stream, write to another

### 6. Binary vs Text Files

| Aspect  | Text Files      | Binary Files       |
| ------- | --------------- | ------------------ |
| Reading | `fin >> data;`  | `fin.read(...);`   |
| Writing | `fout << data;` | `fout.write(...);` |
| Mode    | Default         | `ios::binary`      |
| Speed   | Slower          | Faster             |
| Size    | Larger          | Smaller            |

### 7. Practical Applications

**Attendance Log** ([AttendanceLog.cpp](../../Module1/09_FileHandling/AttendanceLog.cpp))

- Append mode to add new entries
- Read all to display records

**Employee Management** ([DeleteEmployee.cpp](../../Module1/09_FileHandling/DeleteEmployee.cpp), [EmployeeSlip.cpp](../../Module1/09_FileHandling/EmployeeSlip.cpp))

- Read from file, skip/modify record, write to temp file
- Replace original with temp file

**Student Marks** ([Studentmarks.cpp](../../Module1/09_FileHandling/Studentmarks.cpp))

- Store marks permanently
- Retrieve by roll number

---

## Common Mistakes

```
┌──────────────────────────────────────────────────────────┐
│ ❌ Not checking if file opened successfully               │
│ ❌ Forgetting to close files (resource leak)              │
│ ❌ Using ios::out without ios::app (overwrites file)      │
│ ❌ Reading after EOF without checking                     │
│ ❌ Mixing binary and text operations                      │
│ ❌ Using delete instead of delete[] for arrays            │
└──────────────────────────────────────────────────────────┘
```

---

## File Operations Comparison

| Operation | Text                | Binary                              |
| --------- | ------------------- | ----------------------------------- |
| Write     | `fout << data;`     | `fout.write((char*)&s, sizeof(s));` |
| Read      | `fin >> data;`      | `fin.read((char*)&s, sizeof(s));`   |
| Best For  | Human-readable data | Structures, fast I/O                |
| File Size | Larger              | Smaller                             |

---

## 🎯 Key Takeaways

1. **ifstream** for reading, **ofstream** for writing, **fstream** for both
2. Always check if file opened: `if(!file) { error }`
3. Use `ios::app` to append, default overwrites existing content
4. Close files to free resources (or use RAII - automatic cleanup)
5. Binary files are faster and smaller, text files are human-readable
6. To delete/update records: read all → write modified → replace original
   char ch;
   fin.get(ch); // Read single character

````

#### Using read():

```cpp
char buffer[100];
fin.read(buffer, 100);
````

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
