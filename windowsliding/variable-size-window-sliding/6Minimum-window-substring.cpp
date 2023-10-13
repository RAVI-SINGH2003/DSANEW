// string minWindow(string s, string t)
// {
//     map<char, int> mpp;
//     if (s.size() < t.size()) 
//         return {};
//     for (char c : t)
//     {
//         mpp[c]++;
//     }
//     int count = mpp.size();
//     int mini = INT_MAX;
//     string ans = "";
//     int i = 0, j = 0;
//     while (j < s.size())
//     {
//         if (mpp.find(s[j]) != mpp.end())  // jo character map me hai uska count 1 se ghato taki ye pata rahe ki ye character of string t aagaya apni window me
//         {
//             mpp[s[j]]--;
//             if (mpp[s[j]] == 0)
//                 count--;
//         }
//         if (count > 0) //count>0 matlab sare characters of string t nahi aaye hai window me
//         {
//             j++;
//         }
//         else if (count == 0)  // sare characters of string t aagaye window me par hume to smallest size ki window chhaiye such that sare characters of string t usme aaye to hum ab apni window ko minimize
//                               //karne ki koshih karenge agar minimize ho jaegi to matlab ha isse chhoti window aisi thi jisme sare characters of  string t aarahe hai
//         { 
//             while (count == 0)     //mimimize the candidate string to obtain minimum window such that all characters od string t are still present in the window
//             {
//                 if (mpp.find(s[i]) != mpp.end())   //agar minmize karte waqt hum asia characterremove kar rahe hai jo map me bhi hai to uske frequency map me badhao
//                 {
//                     mpp[s[i]]++;                  
//                     if (mpp[s[i]] == 1)
//                     count++;
//                 }
//                 if (j - i + 1 < mini)   // hum loop ke andar matlab abhi bhi string t ke sarre characters hai apni window me window chhoti hone ke bad bhi to matlab ye bhi answer ke liye qualify hogayi
//                 {
//                     mini = j - i + 1;
//                     ans = s.substr(i, j - i + 1);
//                 }
//                 i++; // window ko aur chhota karne ka prayas 
//             } // loop se bahar matlab ab sare characters of string t is not present in window 
//             j++; // to ab window ki size badhao aur phir se aisi window dhundo jisme string t ke sare characters aaye aur phir hum us window ko dubara minimize karenge aur answer store karate jaenege jab tak phir se  count >0 naho jaye (matlab atleast ek character of string t missing from window)
//         }
//     }
//     return ans;
// }