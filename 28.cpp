// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
static int num = INT_MAX;
class Solution {
public:
    int rand10() {
        num = num-7;
        return(num+ rand7())%10 + 1;
    }
};
