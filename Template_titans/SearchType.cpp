#include "SearchType.h"
bool  SearchType::checkFound(Book& object, const string& attributeName, const string& wanted) {


	if (wanted == static_cast<string>(object.get(attributeName))) {
		return true;
	}

	return false;
}

string  SearchType:: getObject(Book& object, string attributeName) {
	return object.get(attributeName);
}
