#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = -1;
		month = -1;
		year = -1;
	}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date(Date& old_date)
	{
		this->day = old_date.day;
		this->month = old_date.month;
		this->year = old_date.year;
	}

	int Get_Day()
	{
		return day;
	}

	int Get_Month()
	{
		return month;
	}

	int Get_Year()
	{
		return year;
	}

	void Set_Day(int day)
	{
		this->day = day;
	}

	void Set_Month(int month)
	{
		this->month = month;
	}

	void Set_Year(int year)
	{
		this->year = year;
	}

	void Show_Date()
	{
		cout << day << "." << month << "." << year << endl;;
	}

	void Add_Date()
	{
		cout << "Enter day:\n";
		cin >> day;
		cout << "Enter month:\n";
		cin >> month;
		cout << "Enter year:\n";
		cin >> year;
	}

	int operator - (Date date_2)
	{
		const int MAX_DAY = 30;
		int difference_day = (this->day) - (date_2.day);
		if (difference_day < 0)
		{
			difference_day = -difference_day;
		}
		int difference_month = (this->month) - (date_2.month);
		if (difference_month < 0)
		{
			difference_month = -difference_month;
		}

		int result = (difference_month * MAX_DAY) + difference_day;

		return result;
	}

	/*Date operator + (int day)
	{
		Date date_temp;

		const int MAX_DAY = 30;
		const int MAX_MONTH = 12;
		date_temp.day = this->day;
		date_temp.month = this->month;
		date_temp.year = this->year;
		if ((this->day + day) > MAX_DAY)
		{
			for (int i = day + date_temp.day; i > MAX_DAY;)
			{
				date_temp.day = i - MAX_DAY;
				date_temp.month++;
				i -= MAX_DAY;
			}
			if (date_temp.month > MAX_MONTH)
			{
				for (int j = date_temp.month; j > MAX_MONTH;)
				{
					date_temp.month = j - MAX_MONTH;
					date_temp.year++;
					j -= MAX_MONTH;
				}
			}
		}
		else
		{
			date_temp.day = this->day + day;
			date_temp.month = this->month;
		}

		return date_temp;
	}*/

	Date operator + (int day)
	{
		const int MAX_DAY = 30;
		const int MAX_MONTH = 12;
		this->day = this->day + day;
		while (this->day > MAX_DAY)
		{
			this->day -= MAX_DAY;
			this->month++;
			if (this -> month > MAX_MONTH)
			{
				this->month = 1;
				this->year++;
			}
		}

		return *this;
	}
};

class Intersection_Lines
{
private:
	string str_1;
public:
	Intersection_Lines()
	{
		str_1 = "None";
	}
	Intersection_Lines(Intersection_Lines &old_lines)
	{
		this->str_1 = old_lines.str_1;;
	}
	void Show_Lines()
	{
		cout << str_1 << endl;
	}

	string Get_Line()
	{
		return str_1;
	}

	void Set_Line(string str_1)
	{
		this->str_1 = str_1;
	}

	void Add_Line()
	{
		cout << "Enter line:\n";
		cin >> str_1;
	}

	char* operator * (Intersection_Lines line_2)
	{
		int counter = 0;
		for (int i = 0; i < this->str_1.size(); i++)
		{
			for (int j = 0; j < line_2.str_1.size(); j++)
			{
				if (this->str_1[i] == line_2.str_1[j])
				{
					counter++;
					break;
				}
			}
		}

		char* str_intersection = new char[counter + 1];
		counter = 0;
		for (int i = 0; i < this->str_1.size(); i++)
		{
			for (int j = 0; j < line_2.str_1.size(); j++)
			{
				if (this->str_1[i] == line_2.str_1[j])
				{
					str_intersection[counter++] = this->str_1[i];
					break;
				}
			}
		}

		str_intersection[counter] = '\0';
		return str_intersection;
	}
};

int main()
{
	// Завдання 1

	/*Date d;
	d.Add_Date();
	d.Show_Date();*/

	/*Date d_1(10, 1, 12), d_2(23, 3, 5), d_3;*/

	/*d_3 = d_1;
	d_3.Show_Date();*/

	/*int difference_date = d_1 - d_2;

	cout << "The difference of two dates = " << difference_date << endl;*/

	/*d_3 = d_1 + 100;
	d_3.Show_Date();*/

	/*d_1 + 100;

	d_1.Show_Date();*/

	// Завдання 2

	Intersection_Lines str_1, str_2;

	str_1.Set_Line("Yoopa");
	str_2.Set_Line("Alrolo");

	char* str_intersection = str_1 * str_2;
	cout << str_intersection;
	delete[] str_intersection;

	return 0;
}