function solution(video_len, pos, op_start, op_end, commands) {
    var answer = '';
    let [video_len_min,video_len_sec] = video_len.split(":").map(Number);
    let video_len_total_sec = video_len_min*60+video_len_sec;
    
    let [min,sec] = pos.split(":").map(Number);
    let pos_total_sec = min*60+sec;
    
    let [op_start_min,op_start_sec] = op_start.split(":").map(Number);
    const op_start_total_sec = op_start_min*60 + op_start_sec;
    
    let [op_end_min,op_end_sec] = op_end.split(":").map(Number);
    const op_end_total_sec = op_end_min*60 + op_end_sec;
    
    if(op_start_total_sec<=pos_total_sec && op_end_total_sec>=pos_total_sec) {
        pos_total_sec = op_end_total_sec;
        min = Math.floor(pos_total_sec / 60);
        sec = pos_total_sec % 60;
    }
    
    commands.map((command)=>{
       if(command==="next"){
           sec+=10;
           if(sec>59){
               min+=1;
               sec %=60;
           }
       } 
        else if(command==="prev"){
            sec-=10;
           if(sec<0){
               min-=1;
               sec +=60;
           }
        }
        pos_total_sec = min * 60 + sec;
        if(pos_total_sec > video_len_total_sec) {
            pos_total_sec = video_len_total_sec;
            min = Math.floor(pos_total_sec / 60);
            sec = pos_total_sec % 60;
        }
        else if(pos_total_sec < 0) {
            pos_total_sec = 0;
            min = Math.floor(pos_total_sec / 60);
            sec = pos_total_sec % 60;
        }

        if(op_start_total_sec<=pos_total_sec && op_end_total_sec>=pos_total_sec) {
            pos_total_sec = op_end_total_sec;
            min = Math.floor(pos_total_sec / 60);
            sec = pos_total_sec % 60;
        }
        
    });
    
    const addZero =(num)=>{
            return ((num < 10)? '0':'')+num;
    }
    answer = addZero(min)+':'+addZero(sec);
    return answer;
}