function solution(want, number, discount) {
    let result = 0
    discount.forEach((v,i)=>{

     let temp=[...discount].slice(i,i+10)
     if(temp.length<10)return result

     let flag=0
     for(let j=0;j<want.length;j++){
      if([...temp].filter(el=>el==want[j]).length==number[j]) 
       flag++

      else break
     }

     if(flag==want.length)result++

  })

    return result
}