// Idea :
//  There are many ways C to place cows in N stalls
// We can try all possible arrangements of cows and then take out minimum distance between two adjacent cows from each of these arrangements
// Then we will find out the maximum  of all these minimals and that will be our answer
// Instead of doing this we can take a range of our minimum distance and then try to maximise it =>Binary search.
// like by taking minimum distance between two adjacen cows = 1 can we place C cows if yes
// then md = 2 can C cows can be placed ? if yes
//  then md = 3 can C cows can be placed ? if yes
// then md = 4 can C cows can be placed ==> if no
// then 3 is the maximum minimal distance at which the cows must be placed.

// bool canPlacecows(vector<int> &stalls ,int n,int totCowsToBePlaced , int miniumDistanceBetweenCows)
// {
//     int cowCoordinate = stalls[0];
//     int cowsPlaced = 1;
//     for(int i =1; i<n; i++)
//     {
//         if(stalls[i] - cowCoordinate >= miniumDistanceBetweenCows)
//         {
//             cowsPlaced++;
//             cowCoordinate= stalls[i];
//         }
//         if(totCowsToBePlaced==cowsPlaced)
//             return true;
//     }
//     return false;
// }
// int aggressiveCows(vector<int> &stalls, int k)
// {
//     sort(begin(stalls) ,end(stalls));
//     int n =stalls.size();
//     int low = 1 ,high = stalls[n-1]-stalls[0],ans;
//     while(low<=high)
//     {
//         int mid = low + (high - low)/2;
//         if(canPlacecows(stalls, n ,k ,mid))
//         {
//             ans = mid;
//             low = mid +1;
//         }
//         else
//         {
//             high = mid -1;
//         }
//     }
//     return ans;
// }