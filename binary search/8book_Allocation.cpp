//Idea : 
//There can be multiple ways to assign N books to N students
//We can try out every way take the maximum no of pages from each of these ways
//then we take the minimal of all these and we get our answer
//but instead of doing so we will take the range of maximum no of pages
//then we will se by keeping a particular value of max no of pages can we allocate book to each student 
//then we minimise our maximum no of pages

// bool isAllocationPossible(int A[] ,int N,int M,int pagestobealloacted)
//     {
//         int allocatedStudents = 1,pagesallocatedtoastudent=0;
//         for(int i =0;i<N;i++)
//         {
//             if(pagesallocatedtoastudent + A[i] <=pagestobealloacted)
//             {
//                 pagesallocatedtoastudent += A[i];
//             }
//             else
//             {
//                 allocatedStudents++;
//                 if(A[i] > pagestobealloacted || allocatedStudents >M)
//                 return false;
//                 pagesallocatedtoastudent =A[i];
//             }
//         }       
//         return true;
//     }
//     int findPages(int A[], int N, int M) 
//     {
//        //loop for getting maxvalue and sum;
//        int maxi = INT_MIN,sum=0;
//        for(int i =0; i<N; i++)
//        {
//            sum+=A[i];
//            maxi = max(maxi ,A[i]);
//        }
//        int l=maxi,h=sum,ans;
//        while(l<=h)
//        {
//            int mid = l + (h-l)/2;
           
//            if(isAllocationPossible(A,N,M,mid))
//            {
//                ans = mid;
//                h = mid-1;
//            }
//            else
//            {
//                l= mid+1;
               
//            }
//        }
//        return ans;
//     }