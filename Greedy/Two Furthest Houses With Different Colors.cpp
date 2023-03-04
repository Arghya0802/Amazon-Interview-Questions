// Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/

// Brute Force: As constraints are small, we can use any 2-pairs of house and get the absoulte max difference in Quadratic Time Complexity
// Optimal Solution: Use colors[0] and traverse from the end to find out the first house with different color, simiarly use colors[n - 1] and check for the first house with different color and return the maxDistance between them

class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n = colors.size() ;

        if(n == 2)
            return 1 ;

        int firstColor = colors[0] ;
        int ans = 0 ;

        for(int i = n - 1 ; i > 0 ; i--)
        {
            if(colors[i] != firstColor)
            {
                ans = max(ans , i) ;

                break ;
            }
        }

        int lastColor = colors[n - 1] ;

        for(int i = 0 ; i < n - 1 ; i++)
        {
            if(colors[i] != lastColor)
            {
                int dist = n - 1 - i ;

                ans = max(ans , dist) ;

                break ;
            }
        }
         
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
