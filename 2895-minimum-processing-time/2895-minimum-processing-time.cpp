class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        sort(tasks.begin(),tasks.end());
        
        sort(processorTime.begin(),processorTime.end(),greater<int>());
        
        int j=0;
        
        int ans=0;
        
        for(int i=0;i<tasks.size();i+=4)
        {
               if(i!=0 && i%4==0)
                j++;
            int task1=tasks[i];
             int task2=tasks[i+1];
             int task3=tasks[i+2];
             int task4=tasks[i+3];
        
            
            ans=max(ans,processorTime[j]+max(max(task1,task2),max(task3,task4)));
        cout<<processorTime[j]<<" "<<ans<<endl;
            
         
            
        }
        
        return ans;
        
        
        
        
        
    }
};