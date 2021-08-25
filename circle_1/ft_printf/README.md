# ft_printf

```
int ft_printf(const char *, ...);
```

안타깝게도 42 Seoul에서는 표준 입출력 라이브러리에 속한 강력한 함수 printf를 사용할 수 없습니다. <br/>
따라서 앞으로 사용할 자신만의 ft_printf를 만드는 것이 본 과제의 목표입니다. <br/>

본 과제에서 필수적으로 구현해야 하는 내용은 다음과 같습니다
* 서식지정자 `c` `s` `i` `d` `u` `p` `x` `X` `%`

본 과제의 보너스 과제로 구현할 수 있는 내용은 다음과 같습니다.
* 너비 옵션
* 플래그 `-` `0` `.`
* 플래그 `#` ` ` `+`

과제를 진행하기 위해서는 다음과 같은 지식들이 필요합니다.
* 가변인자
	* 참고 : `man 3 stdarg` & https://jhnyang.tistory.com/293
* printf의 사용법
	* 참고 : `man 3 printf` & https://m.blog.naver.com/jamespiggy/221499808227 
