#pragma once

#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif
#include<ctime>
#include<iomanip>
#include<cassert>
#include"DataStructure.h"
#include"Hashing.h"
#include<sstream>
enum ActivityType { post, comment, like };
string  enumToString(ActivityType type);

ActivityType stringToEnum(string s);

class Activity {
private:
    ActivityType type;
    string name;
public:
    time_t time_added;//depend on the project creation
    tm* local_time;
public:

    Activity() {
        time_added = time(0);
        local_time = localtime(&time_added);

    }
    void setActivityType(ActivityType t) {
        type = t;
    }

    ActivityType getActivityType() {
        return type;
    }

    void printActivityType() {
        cout << enumToString(type) << endl;
    }

    void setActivityName(string s) {
        name = s;
    }

    string getActivityName() {
        return name;
    }

    void printActivityDetails() {
        cout << "Activity type : " << enumToString(type) << " || Activity name: "
            << name<<" || Time added: "<< put_time(local_time, "%F %T") << endl;

    }

    friend ostream& operator<<(ostream& os, const Activity& activity) {
        cout << "Activity type : " << enumToString(activity.type) << " || Activity name: " 
            << activity.name<< " || Time added: " << put_time(activity.local_time, "%F %T") << endl;
        return os;
    }

   friend  istream& operator>>(istream& input, Activity& activity) {
        cout << "\nEnter activity type(post-comment-like) and content: ";
        string s;
        input >>s>>activity.name;
        activity.type = stringToEnum(s);
        return input;
    }

   operator string() const {
       ostringstream os;
       os << "Name: " << name << " || Type: " << enumToString(type)
           << " || Time added: " << std::put_time(local_time, "%F %T");
       return os.str();
   }

   bool operator==(const Activity& other) const {
       return name == other.name && type == other.type;
   }

   bool operator!=(const Activity& other) const {
       return name != other.name && type != other.type;
   }

   Activity& operator=(const Activity& other) {
       if (this != &other) {
           name = other.name;
           type = other.type;
           time_added = other.time_added;
       }
       return *this;
   }

 
};


class User {
public:
    User();

    int getId();

    string getName();

    void enterData();
  
    void displayData();

    User operator*();

    Activity enterAnActivity();

    Activity DeleteAnActivity();


   void displayActivities();

    string displayStringActivities()const;
    ~User();
  
    User& operator=(const User& other);//to insert the user in the datastructure by indexing with the key attribute
   
    bool operator==(const User& other)const;

    bool operator<(const User& other)const;

    bool operator>(const User& other)const;

    bool operator==(const int other)const {//for hashing in the hash table
        return id == other;
    }
    bool operator==(string other)const {//to use it in function find in the datastructure to search by name
        return name.compare( other)==0;//better than normal equalaty
    }

    bool operator<(string other)const {
        return name.compare( other)<0;
    }

    bool operator>(string other)const {
        return name.compare( other)>0;
    }

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "Name: " << user.name << " || Id: " << user.id << " || Age: " << user.age << " || Gender: " << user.gender;
        os << user.displayStringActivities();
        return os;
    }
  
    int getNumOfActivities() {
        return numActivities;
    }

private:
    string name;
    int id;
    int age;   
    char gender;//m->male f->femal
    Queue<Activity>* activities;//pointer to a queue
    HashTable<int>hashTable;
    int numActivities;
public:
    User* next;
    int key;
};
