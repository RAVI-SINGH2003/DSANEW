	// int search(string pat, string txt) {
	   
	//    map<char ,int> mpp;
	//    for(char c :pat)
	//    {
	//        mpp[c]++;
	//    }
	//    int count =mpp.size(); // this is used so that we need not to traverse array to see if occournce of all element has become zero in map shows how many element have count> 0 in map
	//    int i=0,j=0;
	//    int n = txt.size();
	//    int k = pat.size();
	//    int c=0;
	//    while(j<n)
	//    {
	//        if(mpp.find(txt[j])!=mpp.end())  //if the number is present in map decrease its count by 1
	//        {
	//            mpp[txt[j]]--;
	//            if(mpp[txt[j]]==0) count--;  // if the count of a element becomes 0 in map then dec count
	//        }
	//        if(j-i+1<k) j++;
	//       
	//        else if(j-i+1==k)
	//        {
	//            if(count==0) // ifcount become zero means occoursnce odf all characters in map is 0 means anagram exists in window
	//            c++;
	//            if(mpp.find(txt[i])!=mpp.end()) // undo changes on A[i] ,if it exists inn map then we must increase the count of this charater in map 
   //            kynki hum is element ko remove karne wale hai apni window se to iska matlab next window ke hisab se  ye hai ki ye element encounter nahi hua hai nayi window me to ye ensure karne ke liye hume is element ke count ko badhana hoga
   //             
	//            {
	//                mpp[txt[i]]++;
	//                if(mpp[txt[i]]==1) // now agar kisi elemnent ka count badhane ke bad uska count 1 ho gaya hai to iska matlab ki count variable ko bhi badhana padega kyunki count dikhta ahai ki kitne element map me aise hai jiska count > 0 hai 
	//                count++;
	//            }
	//            i++; //slide window
	//            j++;
	//        }
	       
	//    }
	//    return c;
	// }
