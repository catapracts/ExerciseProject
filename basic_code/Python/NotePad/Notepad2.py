import tkinter as tk

window = tk.Tk() # tk.Tk() = 최상위 윈도우(root 창) 생성
window.title("grid, frame")
window.geometry("500x500+200+150")
window.resizable(False, False)

# grid : widget 배치 가능
"""
0부터 시작
columnspan(가로), rowspan(세로) : 차지 칸수 설정
sticky=tk.N+tk.E+tk.W+tk.S : +로 방향 추가 & 크기 늘리기 가능
(N = North, E = East, W = West, S = South)
sticky="news" : 모든 방향으로 늘어남


_tkinter.TclError: cannot use geometry manager pack inside . which already has slaves managed by grid
-> 같은 부모 위젯(window)에 grid()와 pack()을 동시에 사용시 나오는 에러
-> window 안에서는 grid()만 쓰거나, pack()만 써야 합니다. 혼용하려면 frame을 만들어서 분리

"""

divide_frame = tk.Frame(window)
divide_frame.pack(side="top", fill="both", expand=True)

button = tk.Button(divide_frame, text="Button")
button.grid(row=0, column=0)

button1 = tk.Button(divide_frame, text="Button1")
button1.grid(row=1, column=0)

button2 = tk.Button(divide_frame, text="Button2")
button2.grid(row=0, column=1)

button3 = tk.Button(divide_frame, text="Button3")
button3.grid(row=1, column=1)

# frame
frame = tk.Frame(window, relief="solid", bd = 3, padx = 15, pady = 15)
frame.pack(side="bottom", fill="x", expand=True)
button4 = tk.Button(frame, text="frame")
button4.pack()
button5 = tk.Button(frame, text="frame")
button5.pack()

frame1 = tk.Frame(window, relief="solid", bd = 3, padx = 15, pady = 15)
frame1.pack(side="bottom", fill="x", expand=True)
button6 = tk.Button(frame1, text="frame1")
button6.pack()
button7 = tk.Button(frame1, text="frame1")
button7.pack()

"""
place()
절대 위치나 상대 위치를 지정해서 배치할 수 있는 방식

언제 place()를 쓰는 게 좋을까?
- 디자인 배치가 고정되어 있고, 창 크기가 변하지 않을 때
- 게임 GUI, 계산기 등 정해진 위치에 요소를 배치해야 할 때

항목	                설명
x, y	        창의 왼쪽 위(0, 0) 기준으로 좌표 지정
relx, rely	    상대 위치 (0.0 ~ 1.0) 사용 가능
절대 vs 상대	x, y는 픽셀 단위. relx, rely는 비율 단위
정밀 배치	    다른 방식보다 픽셀 단위로 정밀하게 배치 가능
단점	       창 크기 조절 시 자동 배치가 어려움 (반응형 레이아웃에 부적합)
"""

frame2 = tk.Frame(window, relief="solid", bd = 3, padx = 15, pady = 15)
frame2.place(x=50, y=300)
button8 = tk.Button(frame2, text="frame2")
button8.pack()
button9 = tk.Button(frame2, text="frame2")
button9.pack()


window.mainloop()

"""
Tkinter 위젯 배치 규칙 요약
1. 하나의 부모 위젯(Frame, root 등) 안에서는 pack() / grid() / place() 중 하나만 사용해야 합니다. - 혼용 금지 / 같은 방식끼리는 OK

2. 혼용하고 싶을 때는 Frame을 사용해서 분리 - 각 Frame 안에서는 자유롭게 pack / grid / place 중 하나 사용 가능 / 루트 창(tk.Tk() 또는 window)에서 직접 혼용하지 마세요

3. Frame마다 다른 방식 사용을 권장
"""