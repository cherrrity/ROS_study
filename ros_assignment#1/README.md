# ROS publish-subscribe 구조 설계 실습

2022 국제 대학생 자율차 대회 숙명여대 FROZEN _ 2022/01

아래 조건을 만족하고 메세지의 흐름이 다음과 같은 ROS 구조를 설계해 보아라.

[조건]
* 같은 패키지에 여러개의 노드를 생성할 때는 launch 파일을 작성할 것.
* 패키지의 이름은 ros_node노드번호 ex) ros_node0, ros_node1...
* 커스텀 메시지 파일 이름은 message메세지번호 ex) message0, message1...
	* 단 메세지 패키지를 따로 만들어 참조하는 .msg 파일이 같도록 할 것.
	* message queue = 10, loop late = 10
* message header의 sequence는 0 부터 시작하며, stamp는 now()를 사용


### message format
- Node0’s publish message
~~~cpp
header 
	uint32 seq
	time stamp 
	string frame_id 
uint32 random (10 이상의 아무정수나 넣으시오)
~~~
- Node1's publish message
~~~cpp
header 
	uint32 seq 
	time stamp 
	string frame_id 
uint32 random (아무정수나 넣으시오) 
uint32 from0 (node0의 메시지 random에 3을 더하여 출력하시오) 
uint32 from3 (node3의 메시지에서 frandom3 에 10을 나누어 출력하시오)
~~~
- Node2's publish message
~~~cpp
header 
	uint32 seq 
	time stamp 
	string frame_id 
float64 frandom2 (Node1에서 받은 메시지의 from0 에 0.1을 곱하여 출력)
~~~
- Node3~5's publish message
~~~cpp
header 
	uint32 seq 
	time stamp 
	string frame_id 
float64 frandom3 (Node2에서 받은 실수 frandom2에 1000을 곱하여 출력)
~~~
---
문제 출저_ 숙명여자대학교 정보인 @정보인