function solution(n, w, num) {
    var answer = 0;
    const num_height = Math.ceil(num / w);// 높이
    const max_height = Math.ceil(n / w); // 최대 높이
    const dir = num_height % 2; // 방향 0 = 우 -> 좌 , 1 = 좌 -> 우
    const max_dir = max_height % 2; // 방향 0 = 우 -> 좌 , 1 = 좌 -> 우
    let num_index = 0;
    let max_index = 0;
    if(dir === 0 ){// 짝수 높이
        num_index = w-(((num - 1) % w));
    }
    else if (dir === 1){//홀수 높이
        num_index = ((num - 1) % w)+1;
    }
    
    if(max_dir === 0 ){// 짝수 높이
        max_index = w-(((n - 1) % w));
    }
    else if (max_dir === 1){//홀수 높이
        max_index = ((n - 1) % w)+1;
    }
    answer = max_height - num_height;
    if(max_dir===0) {
        if(num_index >= max_index) answer+=1;
    }
    else if (max_dir === 1){
        if(num_index <= max_index) answer+=1;
    }
    console.log(max_height,num_height,max_index,num_index);
    return answer;
}
/*
num / w 올림했을때 홀수면 좌 -> 우 , 짝수면 우 -> 좌 방향
홀수 높이일 경우 인덱스는 (num - 1 % w)+1 / 짝수일 경우 인덱스는 w-((num - 1 % w)+1)

총 층수 = n/w

찾고자하는 박스의 높이와 인덱스를 찾고 
해당 인덱스의 최대 박스 높이를 찾음

최대 높이 - 박스 높이

*/