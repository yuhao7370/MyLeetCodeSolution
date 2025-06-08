#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start
class Solution {
public:
    int isRun(int y){
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getDays(int y, int m, int d) {
        int years = y - 1971;
        int leapYears = (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 - (1970 / 4 - 1970 / 100 + 1970 / 400);
        int days = leapYears * 366 + (years - leapYears) * 365;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int i = 1; i < m; ++i) {
            days += months[i];
        }
        days += d;

        if (isRun(y) && m > 2) days += 1;

        return days;
    }

    int daysBetweenDates(string date1, string date2) {
        int y1, m1, d1, y2, m2, d2;
        sscanf(date1.c_str(), "%d-%d-%d", &y1, &m1, &d1);
        sscanf(date2.c_str(), "%d-%d-%d", &y2, &m2, &d2);
        return abs(getDays(y1, m1, d1) - getDays(y2, m2, d2));
    }
};
// @lc code=end

