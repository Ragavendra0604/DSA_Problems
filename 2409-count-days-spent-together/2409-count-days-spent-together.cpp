class Solution {
public:
    int getDays(string date){
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;
        for(int i = 0 ; i < month - 1 ; i++){
            total += days[i];
        }

        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = getDays(arriveAlice);
        int endAlice = getDays(leaveAlice);

        int startBob = getDays(arriveBob);
        int endBob = getDays(leaveBob);

        int start = max(startAlice, startBob);
        int end = min(endAlice, endBob);

        if(start > end){
            return 0;
        }

        return end - start + 1;
    }
};