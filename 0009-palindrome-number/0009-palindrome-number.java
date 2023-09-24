class Solution 
{
    public boolean isPalindrome(int x) 
    {
        long rev=0 , temp=x;
        int digit=0;
        if(x<0)
        {
            return false;
        }
        else
        {
            while(temp!=0)
            {
                digit= (int)temp%10;
                rev= rev*10 + digit;
                temp/=10;
            }
        }

        return(rev == x);
    }
}