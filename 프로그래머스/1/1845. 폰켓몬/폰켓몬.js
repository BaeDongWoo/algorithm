function solution(nums) {
    var answer = nums.length/2;
    let table = new Set(nums);
    if(table.size < answer) answer = table.size;
    return answer;
}