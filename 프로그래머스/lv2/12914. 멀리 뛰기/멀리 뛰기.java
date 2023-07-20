class Solution {
    public long solution(int n) {
        long answer = 0;
        int[] arr=new int [2001];
        arr[1]=1;
        arr[2]=2;
        arr[3]=3;
        for(int i=4;i<=n;i++){
            arr[i]=(arr[i-1]+arr[i-2])%1234567;     
        }
        answer=arr[n];
        return answer;
    }
}