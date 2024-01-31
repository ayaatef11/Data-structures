#include "User.h"


ActivityType stringToEnum(string s) {
    if (s == "post")return post;
    else if (s == "comment")return comment;
    return like;
}

string  enumToString(ActivityType type) {
    if (type == post)return  "post";
    else if (type == comment)return  "commnet";
    return "like";
}

 User::User() : activities(new Queue<Activity>()) {
      next = nullptr;
      id = key = 0;
  }

  int User::getId() {
      return id;
  }

  string User::getName() {
      return name;
  }

  void User::enterData() {
      cout << "Enter user name : ";
      cin >> name;
      cout << "Enter user id : ";
      cin >> id;
      key = hashTable.hash(id);
      cout << "Enter user age : ";
      cin >> age;
      cout << "Enter gender (m->male::f->female) : ";
      cin >> gender;
      while ((gender != 'm'&&  gender != 'f') || !cin >> gender) {
          cout << "You must enter only 'f or m'>>> " << endl;
          cin.clear();
          cin.ignore(123, '\n');
          cin >> gender;
      }
  }

    void User::displayData() {
        cout << "Name: " << name << " || Id: " << id << " || Age: " << age << " || Gender: " << gender << endl;
    }

    User User::operator*() {
        return *this;
    }

    Activity User::enterAnActivity() {
            Activity s;
            cout << "*~~~~~~ Activity: ";
            cin >> s;
            activities->enqueue(s);
            numActivities++;
            return s;
    }

     Activity User::DeleteAnActivity() {
       string s;
       Activity t;
        try {
            if (activities->isFull()) {
                 t = activities->dequeue();
                s = t.getActivityName();
                cout << "Activity " << s;
                numActivities--;
            }
        }
        catch (const underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        return t;
    }

     User::~User() {
       //if(activities) delete activities;
    }
    string User::displayStringActivities()const {
        return activities->displayOutput();
    }

    void User::displayActivities() {
        cout << "Activities: ";
        activities->display();
    }

    User& User::operator=(const User& other) {
        if (this != &other) {
            id = other.id;
            key = other.key;
            name = other.name;
            age = other.age;
            gender = other.gender;
            activities = other.activities;
        }
        return *this;
    }
    
     bool User::operator==( const User& other)const   {
        return key == other.key;
    }

    bool User::operator<( const User& other)const  {
        return key < other.key;
    }

    bool User::operator>(const  User& other) const {
        return key > other.key;
    }