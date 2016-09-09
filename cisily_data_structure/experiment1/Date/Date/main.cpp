#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int leap_year[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int common_year[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string month[12] = { "January ","February","March","April","May","June","July","August","September","October","November","December" };
int calculate_week(int y, int m, int d) {
	if (m == 1 || m == 2)   
	{
		m += 12;
		y--;
	}
	return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}
void query_calander() {
	cout << "[calendar] [Year]" << endl;
	cout << "[Year] :";
	string year_str;
	getline(cin, year_str);
	int year = atoi(year_str.c_str());
	for (auto i = 0; i < 12; ++i) {
		cout << month[i] << ": " << endl;
		cout << std::setiosflags(std::ios::left) << std::setw(10) << "Sun" << std::setw(10) << "Mon" << std::setw(10) << "Tue" << std::setw(10) << "Wed" << std::setw(10) << "Thr" << std::setw(10) << "Fri" << std::setw(10) << "Sat" << endl;
		int week = calculate_week(year, i + 1, 1);
		int first_low = 6 - week;
		bool first = false;
		if (week != 6) {
			for (auto i = 0; i <= week; ++i) {
				cout << std::setiosflags(std::ios::left) << std::setw(10) << " ";
			}
			int m_count = 0;
			bool flag = false;
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) flag = true;
			for (auto j = 0; j < leap_year[i]; ++j) {
				if (flag == false && i == 1 && j == leap_year[i] - 1) break;
				cout << std::setiosflags(std::ios::left) << std::setw(10) << j + 1;
				m_count++;
				if (first == false && m_count == first_low) {
					cout << endl;
					m_count = 0;
					first = true;
				}
				if (first == true && m_count == 7) {
					cout << endl;
					m_count = 0;
				}
			}
			cout << endl << endl;
		}
		else
		{
			int m_count = 0;
			bool flag = false;
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) flag = true;
			for (auto j = 0; j < leap_year[i]; ++j) {
				if (flag == false && i == 1 && j == leap_year[i] - 1) break;
				cout << std::setiosflags(std::ios::left) << std::setw(10) << j + 1;
				m_count++;
				if (m_count == 7) {
					cout << endl;
					m_count = 0;
				}
			}
			cout << endl << endl;
		}
	}
}
void input(string & m_year, string & m_month, string & m_day) {
	cout << "[year] [month] [day]" << endl;
	cout << "[year]: ";
	getline(cin, m_year);
	cout << "[month]: ";
	getline(cin, m_month);
	cout << "[day]: ";
	getline(cin, m_day);
}
void query_week() {
    string m_year, m_month, m_day;
    input(m_year, m_month, m_day);
	int week = calculate_week(atoi(m_year.c_str()), atoi(m_month.c_str()), atoi(m_day.c_str()));
	switch(week)
	{
	    case 0: cout << "[week]: Monday" << endl; break;
		case 1: cout << "[week]: Tuesday" << endl; break;
		case 2: cout << "[week]: Wednesday" << endl; break;
		case 3: cout << "[week]: Thursday" << endl; break;
		case 4: cout << "[week]: Friday" << endl; break;
		case 5: cout << "[week]: Saturday" << endl; break;
		case 6: cout << "[week]: Sunday" << endl; break;
	}
}
int sum(int y, int m, int d) {
	int num = 0;
	for (int i = 1; i < y; ++i) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) num++;
	}
	int all_year = num * 366 + (y - num) * 365;
	int all_month = 0;
	int all_day = d;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		for (int j = 0; j < m - 1; ++j) {
			all_month += leap_year[j];
		}
    }
	else
	{
		for (int j = 0; j < m - 1; ++j) {
			all_month += common_year[j];
		}
	}
	return all_year + all_month + all_day;
}
void query_timeTotime() {
	string m1_year, m1_month, m1_day;
	input(m1_year, m1_month, m1_day);
	string m2_year, m2_month, m2_day;
	input(m2_year, m2_month, m2_day);
	int number = sum(atoi(m1_year.c_str()), atoi(m1_month.c_str()), atoi(m1_day.c_str())) - sum(atoi(m2_year.c_str()), atoi(m2_month.c_str()), atoi(m2_day.c_str()));
	if (number < 0) cout << -number;
	else cout << number;
	cout << endl;
}
void query_13_Friday() {
	double all = 0;
	double num = 0;
	for (int i = 1600; i < 2000; ++i) {
		for (int j = 0; j < 12; ++j) {
			all++;
			if (calculate_week(i, j + 1, 13) == 4) num++;
		}
	}
	double gailv = num / all * 100;
	cout << gailv << "%" << endl;
	cout << "[Century]: " << endl;
	string cen_str;
	getline(cin, cen_str);
	int cen = (atoi(cen_str.c_str()) - 1) * 100;
	int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
	for (int i = cen; i < cen + 100; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (calculate_week(i, j + 1, 13) == 0) count0++;
			if (calculate_week(i, j + 1, 13) == 1) count1++;
			if (calculate_week(i, j + 1, 13) == 2) count2++;
			if (calculate_week(i, j + 1, 13) == 3) count3++;
			if (calculate_week(i, j + 1, 13) == 4) count4++;
			if (calculate_week(i, j + 1, 13) == 5) count5++;
			if (calculate_week(i, j + 1, 13) == 6) count6++;
		}
	}
	
	cout << "13 is Monday: " << count0 << endl;
	cout << "13 is Tuesday: " << count1 << endl;
	cout << "13 is Wednesday: " << count2 << endl;
	cout << "13 is Thursday: " << count3 << endl;
	cout << "13 is Friday: " << count4 << endl;
	cout << "13 is Saturday: " << count5 << endl;
	cout << "13 is Sunday: " << count6 << endl;

	
}
int main() {
	query_calander();
	/* query_week();
	query_timeTotime();
	query_13_Friday(); */
	return 0;
}