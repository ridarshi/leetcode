
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        // Number of days in each month (non-leap year)
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Convert a date like "08-15" into a day number of the year
        auto convert = [&](string date) {
            // substr is a C++ builtin Function that takes the parameters as
            // substr(starting_position, length)
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            // Add the days from all previous months
            for (int i = 0; i < month - 1; i++) {
                day += daysInMonth[i];
            }

            return day;
        };

        // Convert all four dates into day numbers
        int aliceStart = convert(arriveAlice);
        int aliceEnd = convert(leaveAlice);
        int bobStart = convert(arriveBob);
        int bobEnd = convert(leaveBob);

        // The common period starts with the later arrival
        int start = max(aliceStart, bobStart);

        // The common period ends with the earlier departure
        int end = min(aliceEnd, bobEnd);

        // If the common period is valid, count both endpoints
        if (start <= end) {
            return end - start + 1;
        }

        // No overlapping days
        return 0;
    }
};
