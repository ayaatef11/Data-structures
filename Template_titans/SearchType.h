#pragma once
#include<cstring>
#include"BooK.h"

template<class T>
class ISearchType {
	bool virtual  checkFound(T& object, const string& attributeName, const string& wanted) = 0;
	string virtual  getObject(T& object, string attributeName) = 0;
};

class SearchType:ISearchType<Book>
{
public : 

	bool static checkFound(Book& object, const string& attributeName, const string& wanted);

	string static getObject(Book& object, string attributeName);

};

