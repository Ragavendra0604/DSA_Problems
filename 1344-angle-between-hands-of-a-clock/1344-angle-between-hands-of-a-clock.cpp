class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6;

        double hourAngle = (hour  % 12) * 30 + minutes * 0.5;

        double angle = min(abs(hourAngle - minAngle), 360 - abs(hourAngle - minAngle));

        return angle;
    }
};