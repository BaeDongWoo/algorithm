function solution(a, b) {
    var answer = '';
    const dayList = ['SUN','MON','TUE','WED','THU','FRI','SAT']
    const day = new Date(2016,a-1,b).getDay()
    console.log(dayList[day]);
    return dayList[day];
}