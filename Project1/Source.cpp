#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

/*
24. Написати програму «Моя записна книжка».
Передбачити можливість роботи з довільним числом записів, пошуку запису по
якій-небудь ознаці (наприклад, по прізвищу, даті народження або номеру
телефону), додавання і видалення записів, сортування за різними полях.
Збереження даних організувати з застосуванням контейнерного класу list.
*/

struct Date
{
	int day;
	int month;
	int year;
	bool operator==(Date other)
	{
		return(day == other.day && month == other.month && year == other.year);
	}
};

class Person
{
private:
	string name;
	string surname;
	Date date_of_birth;
	long int number;
	string residence;
public:
	Person() : name(""), surname(""), number(0), residence("")
	{
		date_of_birth.day = 0;
		date_of_birth.month = 0;
		date_of_birth.year = 0;
	}
	Person(string name, string surname, int day, int month, int year, long int number, string residence) : name(name), surname(surname), number(number), residence(residence)
	{
		date_of_birth.day = day;
		date_of_birth.month = month;
		date_of_birth.year = year;
	}

	string Get_name()
	{
		return name;
	}

	string Get_surname()
	{
		return surname;
	}

	long int Get_number()
	{
		return number;
	}

	string Get_residence()
	{
		return residence;
	}

	Date Get_date()
	{
		return date_of_birth;
	}

	void Show_Info_About_Person()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Date of birth: " << date_of_birth.day << ":" << date_of_birth.month << ":" << date_of_birth.year << endl;
		cout << "Number: " << number << endl;
		cout << "Residence: " << residence << endl;
	}
};

struct sortByName
{
	bool operator()(Person &s1, Person & s2)const
	{
		return s1.Get_name() < s2.Get_name();
	}
};

struct sortBySurname
{
	bool operator()(Person &s1, Person & s2)const
	{
		return s1.Get_surname() < s2.Get_surname();
	}
};

struct sortByNumber
{
	bool operator()(Person &s1, Person & s2)const
	{
		return s1.Get_number() < s2.Get_number();
	}
};

struct sortByResidence
{
	bool operator()(Person &s1, Person & s2)const
	{
		return s1.Get_residence() < s2.Get_residence();
	}
};

class Notebook
{
private:
	string name;
	list<Person> notebook;
public:
	Notebook() : name("") {}
	Notebook(string name) : name(name) {}

	void Find_Person_by_name(string name)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_name() == name)
			{
				(*iter).Show_Info_About_Person();
				cout << endl;
			}
		}
	}

	void Find_Person_by_surname(string surname)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_surname() == surname)
			{
				(*iter).Show_Info_About_Person();
				cout << endl;
			}
		}
	}

	void Find_Person_by_number(long int number)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_number() == number)
			{
				(*iter).Show_Info_About_Person();
				cout << endl;
			}
		}
	}

	void Find_Person_by_residence(string residence)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_residence() == residence)
			{
				(*iter).Show_Info_About_Person();
				cout << endl;
			}
		}
	}

	void Find_Person_by_date_of_birth(Date date)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_date() == date)
			{
				(*iter).Show_Info_About_Person();
				cout << endl;
			}
		}
	}

	void Add_Person_to_notebook(const Person& ps)
	{
		notebook.push_back(ps);
	}

	void Delete_front()
	{
		notebook.pop_front();
	}

	void Delete_back()
	{
		notebook.pop_back();
	}

	void Delete_all()
	{
		notebook.erase(notebook.begin(), notebook.end());
	}

	void Delete_Person_from_notebook_by_name(string name)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_name() == name)
			{
				notebook.erase(iter);
				break;
			}
		}
	}

	void Delete_Person_from_notebook_by_surname(string surname)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_surname() == surname)
			{
				notebook.erase(iter);
				break;
			}
		}
	}

	void Delete_Person_from_notebook_by_number(long int number)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_number() == number)
			{
				notebook.erase(iter);
				break;
			}
		}
	}

	void Delete_Person_from_notebook_by_residence(string residence)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_residence() == residence)
			{
				notebook.erase(iter);
				break;
			}
		}
	}

	void Delete_Person_from_notebook_by_date_of_birth(Date date)
	{
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			if ((*iter).Get_date() == date)
			{
				notebook.erase(iter);
				break;
			}
		}
	}

	void Show_notebook_info()
	{
		cout << "Name of notebook: " << name << endl;
		cout << "\t\t______Persons______" << endl;
		for (auto iter = notebook.begin(); iter != notebook.end(); iter++)
		{
			(*iter).Show_Info_About_Person();
			cout << endl;
		}
	}

	void Sort_notebook_by_name()
	{
		
		notebook.sort(sortByName());
	}

	void Sort_notebook_by_surname()
	{

		notebook.sort(sortBySurname());
	}

	void Sort_notebook_by_number()
	{

		notebook.sort(sortByNumber());
	}

	void Sort_notebook_by_resident()
	{

		notebook.sort(sortByResidence());
	}

};

int main()
{

	//*map<string, int> map_c;
	//map_c["One"] = 1;
	//map_c.insert(make_pair("one", 1));
	//map_c.insert(make_pair("four", 4));
	//map_c.insert(make_pair("zero", 0));
	//map_c.insert(make_pair("three", 3));
	//map_c.insert(make_pair("Five", 5));
	//cout << "_______________MAp_______________" << endl;
	//for (auto i: map_c)
	//{
	//	cout << "Item: " << i.first << "\tValue: " << i.second << endl;
	//}
	//multimap<string, int> multimap_c;
	//multimap_c.insert(make_pair("one", 1));
	//multimap_c.insert(make_pair("one", 11));
	//multimap_c.insert(make_pair("four", 4));
	//multimap_c.insert(make_pair("four", 44));
	//multimap_c.insert(make_pair("three", 3));
	//multimap_c.insert(make_pair("three", 33));
	//cout << "_______________Find_______________" << endl;
	//auto iter = multimap_c.find("One");
	//while (iter != multimap_c.end())
	//{
	//	cout << "Item: " << (*iter).first << "\tValue: " << (*iter).second << endl;
	//	++iter;
	//}
	//cout << "_______________MultiMAp_______________" << endl;
	//for (auto i : multimap_c)
	//{
	//	cout << "Item: " << i.first << "\tValue: " << i.second << endl;
	//}*/
	////////////set
	//set<int, greater<int>> set_c;
	//cout << "----------------Set-----------------" << endl;
	//set_c.insert({ 1,2,3 });
	//for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;
	//set_c.clear();
	//set_c.insert({ 1,1,2,2,3,3 });
	//for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;
	//set_c.clear();
	//set_c.insert({ 4,4,2,2,1,1,3,3 });
	//for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;
	//////////////////
	//unordered_set<int> unorderedset_c;
	//cout << "----------------UnorderedSet-----------------" << endl;
	//unorderedset_c.insert({ 1,2,3 });
	//for_each(unorderedset_c.begin(), unorderedset_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;
	//unorderedset_c.clear();
	//unorderedset_c.insert({ 1,1,2,2,3,3 });
	//for_each(unorderedset_c.begin(), unorderedset_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;
	//unorderedset_c.clear();
	//unorderedset_c.insert({ 4,4,2,2,1,1,3,3 });
	//for_each(unorderedset_c.begin(), unorderedset_c.end(), [](int v) {cout << v << " "; });
	//cout << endl;

	Notebook notebook("frst");
	Person p1("Vlad", "Zhomyruk", 10,10,10,05050505050,"kek");
	Person p2("Vika", "qwseq", 12, 10, 10, 05050505050, "lol");
	Person p3("Kol9", "ghjjkk", 10, 6, 7, 05050505050, "4ebyrek");
	Person p4("Ura", "qqqqqqqq", 6, 8, 16, 05050505050, "mdaaaaa, wo 9 delay");

	notebook.Add_Person_to_notebook(p1);
	notebook.Add_Person_to_notebook(p2);
	notebook.Add_Person_to_notebook(p3);
	notebook.Add_Person_to_notebook(p4);

	notebook.Show_notebook_info();
	notebook.Sort_notebook_by_name();
	cout << endl;
	notebook.Show_notebook_info();

	system("pause");
	return 0;
}