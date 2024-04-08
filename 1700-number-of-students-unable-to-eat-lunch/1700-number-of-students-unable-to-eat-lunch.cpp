class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int zerocount=0;
        int onecount=0;


      for(int i=0;i<students.size();i++)
      {
        if(students[i]==0)
        zerocount++;
        else
        onecount++;

      }

      for(auto it:sandwiches)
      {
        if(it==0 && zerocount==0)
        return onecount;
        else if(it==1 && onecount==0)
        return zerocount;
        if(it==0)
        zerocount--;
        else
        onecount--;

      }

    return 0; 
    }
};