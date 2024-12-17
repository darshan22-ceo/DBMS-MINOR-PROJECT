import java.io.BufferedReader; 
import java.io.FileReader; 
import java.io.IOException; 
import java.util.ArrayList; 
import java.util.List; 
 
// Class representing a Record with ID, Name, and Age 
class Record { 
private int id; 
private String name; 
private int age; 
 
public Record(int id, String name, int age) { 
this.id = id; 
this.name = name; 
this.age = age; 
} 
 
// Getters 
public int getId() { 
return id;
 } 
public String getName() { 
return name; 
} 
public int getAge() { 
return age; 
} 
@Override 
public String toString() { 
return "ID: " + id + ", Name: " + name + ", Age: " + age; 
} 
} 
public class FileAccessDemo { 
// Method to read a file and parse its contents into a list of Records 
public static List<Record> readRecordsFromFile(String filePath) { 
List<Record> records = new ArrayList<>(); 
try (BufferedReader br = new BufferedReader(new FileReader(filePath))) { 
String line; 
while ((line = br.readLine()) != null) { 
String[] parts = line.split(", "); 
if (parts.length == 3) { 
int id = Integer.parseInt(parts[0]); 
String name = parts[1]; 
int age = Integer.parseInt(parts[2]); 
records.add(new Record(id, name, age)); 
} else { 
System.out.println("Skipping malformed line: " + line); 
} 
} 
} catch (IOException e) { 
System.out.println("Error reading file: " + e.getMessage()); 
} 
return records; 
} 
 
// Main method to demonstrate file access and record parsing 
public static void main(String[] args) { 
String filePath = "data.txt";  // Path to the file 
List<Record> records = readRecordsFromFile(filePath); 
 
// Display the parsed records 
System.out.println("Parsed Records:"); 
for (Record record : records) { 
System.out.println(record); 
} 
} 
} 
