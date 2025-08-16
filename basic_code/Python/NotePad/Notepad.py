# Pillow
from PIL import Image, ImageTk

#tkinter의 이름이 길어서 tk라고 설정
import tkinter as tk

#
import os

# 현재 작업 디렉토리 확인
print(os.getcwd())
# "/Users/macbook/Desktop/git/basic_code/Python/NotePad/FA18F.png"
# image_path = os.path.join(os.path.dirname(__file__), "FA18F.png")
file_path = "/Users/macbook/Desktop/git/basic_code/Python/NotePad/FA18F.png"
print("파일 존재 여부:", os.path.exists(file_path))  # True이면 파일이 존재

# img
img = Image.open(file_path)


# Label 크기 자동 조정
def resize_image(event) :
    # Label 크기 구하기
    label_width = event.width
    label_height = event.height
    
    if hasattr(resize_image, "prev_width") and hasattr(resize_image, "prev_height") :
        if label_width == resize_image.prev_width and label_height == resize_image.prev_height :
            return
    
    img_copy = img.copy()
    img_copy.thumbnail((label_width, label_height))
    # image Resizing
    # Label 크기에 맞게 resize
    # resized_img = img.resize((label_width, label_height))
    # resized_photo = ImageTk.PhotoImage(resized_img)
    resized_photo = ImageTk.PhotoImage(img_copy)
    
    # Label에 이미지 업데이트
    Label1.config(image=resized_photo)
    Label1.image = resized_photo
    
    canvas.create_window(label_width / 2, label_height / 2, window=Label1, anchor='center')

# window 객체에 tkinter의 Tk함수 사용시작, 정의
window = tk.Tk()
# window 객체 띄울 때, 제목 설정
window.title("NotePad Example")
# window 객체의 크기 설정 및 시작 위치 설정
# 가로x세로 -> *은 x로 인식을 안 함
# 창 시작 x좌표+창 시작 y좌표
window.geometry("600x600+500+150")
# window 객체 크기 변경 불가능하게 설정(X축, Y축)
#window.resizable(False, False)

# Canvas
canvas = tk.Canvas(window)
canvas.pack(fill=tk.BOTH, expand = True, pady=20)
#photo = ImageTk.PhotoImage(img)
Label1 = tk.Label(canvas)
# canvas.create_window(0, 0, window=Label1, anchor='center')
# sLabel1.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
canvas.bind("<Configure>", resize_image)
# button = tk.Button(window, image=img)
# button.pack()

#
frame = tk.Frame(window)
frame.pack(fill=tk.BOTH, expand=False, padx=10, pady=10)

# Label = 글자 띄우기
# width : 넓이, height = 높이
label = tk.Label(window, text="Label", width = 10, height = 5)
# 화면에 띄우기
label.pack(pady=10)

# Button = 버튼
# padx = 30, pady = 15 : 여백 설정
# fg : 글자색, bg : 배경색
button = tk.Button(window, text="Button", padx = 30, pady = 15, fg = "Blue", bg = "black")

# 화면에 띄우기
button.pack(pady=10)

# entry = 값을 입력할 수 있는 칸
entry = tk.Entry(window,)

# 화면에 띄우기
entry.pack(pady=10)

# window 객체 동작 시작
window.mainloop()

