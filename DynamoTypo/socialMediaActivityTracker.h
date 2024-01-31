#pragma once
#include<vector>
#include"User.h"
#include<algorithm>

bool compareActivities( Activity*& a1,  Activity*& a2);

class socialMediaActivityTracker
{
public:
	socialMediaActivityTracker();
	
	void addActivity();

	User* removeActivity();

	void printActivities();
	
	void addUser();

	void removeUser();

	void printUser();

	User* searchUser() {
		string item;//name ,id,activity
		User*c=new User;
		cout << "Do you want to search by 1-name ~ 2-id ~ 3-activities:\n";
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
	Q:
		switch (choice) {
		case 1:
			*c=users.find(item);
			break;
		case 2:
			int id;
			cout << "Enter user id: ";
			cin >> id;
			//*c = hs.find(id);
			break;
		case 3:
			//string activity;
			//search by activities
			//for (auto& user : users) {

			//}
			break;
		default:
			cout << "wrong choice";
			cin.clear();
			cin.ignore(123, '\n');
			cin >> choice;
			goto Q;
		}
		return c;
	}

	void popularPosts() {//the most repeated name of a post
		/*for (auto i : hs) {
			if()
		}*/
	}

	User activeUsers() {
		User s;
		/*int m = 0;
		for (auto i : hs) {
			if (i->getNumOfActivities() > m) {
				m = i->getNumOfActivities();
				s = &i;
			}
		}*/
		return s;
	}

	void SortAactivitiesBasedOnTime();

	void trends();

	size_t numOfActivities();

	size_t numOfPosts();

private:
	Container<User>users;
	vector<Activity*>usersActivities;	
	int numOfUsers;
	vector<Activity*>posts;
	//HashTable<User> hs;
};

