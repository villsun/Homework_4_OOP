#include <iostream>

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
		int difference_date = this->day - date_2.day;
		if (difference_date < 0)
		{
			difference_date = -difference_date;
		}

		return difference_date;
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
			this-month++;
			if (this -> month > MAX_MONTH)
			{
				this->month = 1;
				this->year++;
			}
		}

		return *this;
	}


};

int main()
{
	// Завдання 1

	/*Date d;
	d.Add_Date();
	d.Show_Date();*/

	/*Date d_1(1, 12, 12), d_2(3, 4, 5), d_3;*/

	/*d_3 = d_1;
	d_3.Show_Date();*/

	/*int difference_date = d_1 - d_2;

	cout << "The difference of two dates = " << difference_date << endl;*/

	/*d_3 = d_1 + 100;
	d_3.Show_Date();*/

	/*d_1 + 100;

	d_1.Show_Date();*/

	return 0;
}