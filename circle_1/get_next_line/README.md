# get_next_line

```
int *get_next_line(int fd, char **line);
```

본 과제의 목표는 

* 첫 번째 파라미터로 받아온 fd(파일 디스크립터)의 파일 내에 있는 한 줄을 읽어와,
* 두 번째 파라미터 line에 할당하는 함수를 만드는 것입니다.

이를 위해 필요한 지식은 다음과 같습니다.
* #### 버퍼란?
  * 참고 : https://dololak.tistory.com/84
* #### 정적변수
  * 참고 : https://dojang.io/mod/page/view.php?id=690
* #### 프로세스의 메모리 레이아웃
  * 참고 : https://bigpel66.oopy.io/library/c/chewing-c/5
* #### 파일 디스크립터(File descriptor)
  * 참고 : https://code4human.tistory.com/123
* #### gcc의 -D 옵션 사용법
  * 참고 : https://jangpd007.tistory.com/220
