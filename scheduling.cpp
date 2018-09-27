/* At an airport you have a timetable for arrivals and departures.
 * You need to determine the minimum number of gates you*d need to provide so that all the planes can be placed at a gate as per their schedule.
 * The arrival and departure times for each plane are presented in two arrays, sorted by arrival time, and you're told the total number of flights for the
 * day. Assume that no planes remain overnight at the airport; all fly in and back out on the same day. Assume that if a plane departs in the same minute as another plane arrives, the arriving plane takes priority (i.e. you'll still need the gate for the departing plane). Write a function that returns
 * the minimum number of gates needed for the schedules you're given.
 */
#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

class scheduling{
public:
	int findMinGates(vector<int> arr, vector<int>dep, int flight){
		sort(arr.begin(), arr.end());
		sort(dep.begin(), dep.end());
		int count = 0;
		int depcount = 0;
		for(int i = 0; i < flight; i++){
			if (arr[i] > dep[depcount])
				depcount++;
			else
				count++;
		}
		return count;
	}
};

int main(){
	scheduling sch;
	vector<int> a = {900, 940, 950, 1100,1500,1800};
	vector<int> d = {910,1200,1120, 1130,1900, 2000};
	int f = 6;
	cout<< "Min Gates" << sch.findMinGates(a, d, f);
	return 0;
}