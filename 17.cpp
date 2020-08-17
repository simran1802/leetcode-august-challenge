class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> distribute(num_people);
        int candy = 1,i=0;
        while(candies>0){
            if(i>=num_people)
                i=0;
            distribute[i++] += min(candy,candies);
            candies -= candy++;
        }
        return distribute;
    }
};
