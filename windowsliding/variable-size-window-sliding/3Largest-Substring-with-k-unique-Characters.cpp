//  int longestKSubstr(string s, int k) {
//     // your code here
//     int i =0,j=0;
//     map<char , int> mpp;  
//     int maxi = -1;
//     while(j<  s.size())
//     {
//         mpp[s[j]]++;
        
//         if(mpp.size()<k) //mapsize gives no of uniw=que character in the array
//         j++;
        
//         else if(mpp.size() == k)
//         {
//             maxi = max(maxi,j-i+1);
//             j++;
//         }
//         else if(mpp.size() > k) 
//         {
//            while(mpp.size()>k) when no of unique characters become > k remove elements until no of unique character in the map ==k
//            {
//                mpp[s[i]]--;
//                if(mpp[s[i]]==0) // agar kisi charcter ki freq map me 0 ho gayi to to use map se remove kardenge  
//                                 //kynki mana ki mpp[s[i]]==0 hai par ye exist to karta hai map me to count of unique character me ye bhi count ho jaega
//               {
//                   mpp.erase(s[i]);
//               }
//                i++;
//            }
//            j++;
            
//         }
        
        
       
//     }
//     return maxi;
//     }