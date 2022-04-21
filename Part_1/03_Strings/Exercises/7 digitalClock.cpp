#include<string>
using namespace std;

string convert_to_digital_time(int mins){
    int hours = mins/60;
	int minutes = mins%60;
	string hrs_s = to_string(hours);
	string min_s = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
	return hrs_s + ":" + min_s;
}

string Myconvert_to_digital_time(int minutes){
    
    string res{};

    int hour = minutes / 60;
    int minu = minutes % 60;

    res += to_string(hour);
    res += ":";

    res += (minu < 10) ? ("0" + to_string(minu)) : to_string(minu);

    return res;
}