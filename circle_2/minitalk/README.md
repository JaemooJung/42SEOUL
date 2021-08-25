# minitalk

본 과제의 목표는 UNIX signal을 이용해 문자열을 주고받는 client와 server를 제작하는 것입니다. <br/>
* SIGUSR1 과 SIGUSR2를 제외한 다른 시그널은 사용할 수 없습니다. <br/>
* 1000자의 문자열을 전송하는데 2초 이상의 시간이 소요되어서는 안됩니다.
___
### 본 과제를 수행하기 위해 필요한 지식
* 프로세스와 pid
  * 참고 : https://bowbowbow.tistory.com/16
* UNIX Signal
  * 참고 : `man 3 signal` & https://www.joinc.co.kr/w/Site/system_programing/Book_LSP/ch06_Signal
* 2진수를 이용해 데이터를 처리하는 법
  * 참고 : https://all-young.tistory.com/6
___
### 고민해봐야 할 점
* 서버와 클라이언트 간의 통신이 중간에 방해받지 않도록 하는 방법이 있을까?
* 있다면 전송속도의 지연을 최소하 하는 방법은 무엇일까?
