#include "socialMediaActivityTracker.h"

bool compareActivities( Activity*& u1,  Activity*& u2) {
    return u1->time_added < u2->time_added;
}


	void socialMediaActivityTracker::addUser() {
		User c;
		c.enterData();
		users.insert(c);
		numOfUsers++;
	}

	void socialMediaActivityTracker::removeUser() {
		User* c=searchUser();
		users.Delete(*c);
		if(c)numOfUsers--;
	}

	void socialMediaActivityTracker::printUser() {
		users.print();
	}

	void socialMediaActivityTracker::SortAactivitiesBasedOnTime() {
	sort(usersActivities.begin(), usersActivities.end(), compareActivities);
	}

	void socialMediaActivityTracker::trends() {
		for (int i = 0; i < usersActivities.size(); i++)
			if (usersActivities[i]->getActivityName()[0] == '#') {
				cout << "Trend #" << i + 1<<":\n";
				cout << "\t"<<usersActivities[i]->getActivityName() << endl;
			}
	}

	size_t socialMediaActivityTracker::numOfActivities() {
		return usersActivities.size();
	}

	size_t socialMediaActivityTracker::numOfPosts() {
		return posts.size();
	}
	socialMediaActivityTracker::socialMediaActivityTracker() {
		numOfUsers = 0;
	}

	void socialMediaActivityTracker::addActivity() {
		User* s = removeActivity();
		Activity c = s->enterAnActivity();
		usersActivities.push_back(&c);
		if (c.getActivityType() == post)posts.push_back(&c);
	}

	User* socialMediaActivityTracker::removeActivity() {
		User* s = searchUser();
		Activity v = s->DeleteAnActivity();
		if (v != Activity{}) {
			auto it = find(usersActivities.begin(), usersActivities.end(), &v);
			if (it != usersActivities.end()) {
				usersActivities.erase(it);
			}
			if (v.getActivityType() == post) {
				auto i = find(posts.begin(), posts.end(), &v);
				if (i != posts.end()) {
					posts.erase(i);
				}
			}
		}
		return s;
	}

	void socialMediaActivityTracker::printActivities() {
		for (auto i : usersActivities) {
			cout << i << " ";
		}
	}