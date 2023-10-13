//  int lengthOfLongestSubstring(string s) {
//         map<char, bool> mpp;
//         int i =0,j=0,maxi= 0;
//         while(j<s.size())
//         {        
//             if(mpp[s[j]]==false)
//              {
                  
//                    mpp[s[j]]= true;
//                    maxi = max(maxi ,j-i+1);
//                    j++;
                 
//               }
              
//              else {
        
//                  char ch  = s[j];
//                  while(s[i]!=ch)
//                  {
                  
//                         mpp[s[i]]=false;
//                         i++;

//                  }  
//                  mpp[s[j]] =  true;
//                  i++;
                
//                  j++;
                 
//              }
            
//         }
//         return maxi;
//     }

//THIS IS THE STRANDARISED APPROACH

//   int lengthOfLongestSubstring(string s) {
        
//         map<char ,int> mp;
 //         int i=0,j=0;
//         int maxi = 0;
//         while(j<s.size()){
//             mp[s[j]]++;        
//             if(mp.size()==j-i+1)             //map size shows no of unique characters , here map size == window size means all elements in window are unique--(1)
//             {
//                 maxi = max(maxi ,j-i+1);
//                 j++;
//             }
//             else if(mp.size() < j-i+1)     // if there is some repition of any character in window then map size will always be less than window size 
//             {                              // also note map size can never be greater than window size;
//                 while(mp.size() <  j-i+1)  // remove elements from window until our  condition 1 is satified
//                 {
//                     mp[s[i]]--;           
//                     if(mp[s[i]]==0)  
//                     {
//                         mp.erase(s[i]);     //this is done to ensure that map size always give the no of unique characters beacuse even the s[i]==0  but it will be counted in map size

//                                            //but it should not be counted because 0 specifies that there is no existence of s[i] in window
                        
//                     }
                    
//                     i++;
//                 }
//                 j++;
//             }
//         }
//         return maxi;
//     }