#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, const string& Delim)
{
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (!sWord.empty())
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (!S1.empty())
    {
        vString.push_back(S1);
    }

    return vString;
}

string DateToString(const stDate& Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate StringToDate(const string& DateString)
{
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string ReadStringDate(const string& Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    string DateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(DateString);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou Entered: " << DateToString(Date) << "\n";

    system("pause>0");
    return 0;
}