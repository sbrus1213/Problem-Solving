# 파일 정리

| 시간 | 메모리 | 알고리즘 |
|---|---|---|
| 1초 | 64MB | 정렬 |

---

## 문제

친구로부터 노트북을 중고로 산 스브러스는 노트북을 켜자마자 경악할 수밖에 없었다. 바탕화면에 온갖 파일들이 정리도 안 된 채 가득했기 때문이다. 그리고 화면의 구석에서 친구의 메시지를 확인할 수 있었다.

바탕화면의 파일들에는 값진 보물에 대한 정보가 들어있어. 하나라도 지우게 된다면 보물은 물론이고 다시는 노트북을 쓸 수 없게 될거야. 파일들을 잘 분석해서 보물의 주인공이 될 수 있길 바랄게. 힌트는 "확장자"야.

화가 났던 스브러스는 보물 이야기에 금세 화가 풀렸고 보물의 정보를 알아내려고 애썼다. 하지만 파일이 너무 많은 탓에 이내 포기를 했고 보물의 절반을 보상으로 파일의 정리를 요청해왔다. 스브러스의 요청은 다음과 같다.

1. 파일을 확장자 별로 정리해서 몇 개씩 있는지 알려줘

2. 보기 편하게 확장자들을 사전 순으로 정렬해줘

그럼 보물의 절반을 얻어내기 위해 얼른 스브러스의 노트북 파일 정리를 해줄 프로그램을 만들자!!

## 입력

첫 째줄에 양의 정수 N이 주어진다. $(1 \leq N \leq 50,000)$ N은 바탕화면에 있는 파일의 개수이다.

두 번째 줄부터 N 개의 줄에 바탕화면에 있는 파일의 이름이 주어진다. 파일의 이름은 [알파벳 소문자].[알파벳 소문자] 로 구성되어 있고, 각 파일의 이름의 길이는 최소 3, 최대 100이다.

## 출력

확장자의 이름과 그 확장자 파일의 개수를 한 줄에 하나씩 출력한다. 확장자가 여러개 있을 때, 확장자 이름 순으로 출력한다.

## 예제 입력

```
8
sbrus.txt
spc.spc
acm.icpc
korea.icpc
sample.txt
hello.world
sogang.spc
example.txt

```

## 예제 출력

```
icpc 2
spc 2
txt 3
world 1

```

## 노트

엄청난 보물의 정체는 바탕화면을 정리했다는 뿌듯함이라고 알려진다.