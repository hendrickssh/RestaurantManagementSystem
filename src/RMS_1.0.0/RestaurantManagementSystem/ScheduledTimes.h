#pragma once
#include <string>

using namespace std;

class ScheduledTimes
{
private:
   string calanderDate;
   string start;
   string stop;

public:
   /// <summary>
   ///
   /// <summary>
   ScheduledTimes();
   ScheduledTimes(string s, string e, string d);
   ~ScheduledTimes() {}
   string getSchedule();
};