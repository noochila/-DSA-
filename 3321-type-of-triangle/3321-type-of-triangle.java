class Solution {
    public String triangleType(int[] nums) {



        Arrays.sort(nums);


        int a=nums[0];
        int b=nums[1];
        int c=nums[2];




        if(a+b<=c)
        return "none";

        if(a==b && b==c)
        {
            return "equilateral";
        }else if(a!= b && b!=c && c!=a)
        {
            return "scalene";
        }else if((a==b && b!=c) || (b==c && c!=a) || (a==c && c!=b))
        {
            return "isosceles";
        }else
        {
            return "none";
        }
        
    }
}