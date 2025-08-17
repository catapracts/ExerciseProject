from PIL import Image, ImageTk
import tkinter as tk
import os
import tkinter.messagebox as box

file_path = "/Users/macbook/Desktop/git/basic_code/Python/NotePad/FA18F.png"

img = Image.open(file_path)

# command : event발생 시 실행 정의
def click() :
    print("Click activate")

# config = widget속성 값 변경
def click1() :
    button.config(text="Click success")

# text에 쓴 글자로 label변경
def click2() :
    label.config(text=text.get("1.0", tk.END))

# Entry에 쓴 글자로 label변경
def click3() :
    label.config(text=entry.get())

# message창 띄우기
def click4() :
    box.showinfo("Alarm", "Click Complete")


def resize_image(event) :

    label_width = event.width
    label_height = event.height
    
    if hasattr(resize_image, "prev_width") and hasattr(resize_image, "prev_height") :
        if label_width == resize_image.prev_width and label_height == resize_image.prev_height :
            return
    
    img_copy = img.copy()
    img_copy.thumbnail((label_width, label_height))
    resized_photo = ImageTk.PhotoImage(img_copy)
    
    Label1.config(image=resized_photo)
    Label1.image = resized_photo
    
    canvas.create_window(label_width / 2, label_height / 2, window=Label1, anchor='center')


window = tk.Tk()
window.title("NotePad Example")
window.geometry("900x600+200+50")

canvas = tk.Canvas(window)
canvas.pack(fill=tk.BOTH, expand = True, pady=10)
Label1 = tk.Label(canvas)
canvas.bind("<Configure>", resize_image)

frame = tk.Frame(window)
frame.pack(fill=tk.BOTH, expand=False)

label = tk.Label(window, text="F/A-18F Super Hornet", width = 20, height = 5)
label.pack()

button = tk.Button(window, text="Button1", fg = "Blue", bg = "black", width = 10, height = 5, command = click)
button.pack(side="left")

button = tk.Button(window, text="Button2", fg = "Blue", bg = "black", width = 10, height = 5, command = click1)
button.pack(side="left")

button = tk.Button(window, text="Button3", fg = "Blue", bg = "black", width = 10, height = 5, command = click2)
button.pack(side="left")

button = tk.Button(window, text="Button4", fg = "Blue", bg = "black", width = 10, height = 5, command = click3)
button.pack(side="left")

button = tk.Button(window, text="Button5", fg = "Blue", bg = "black", width = 10, height = 5, command = click4)
button.pack(side="left")

entry = tk.Entry(window)
entry.pack()

# Text : 여러 줄 입력 가능
""" 
Text객체.insert(tk.END, "글자") : Text widget에 표시할 글자 표시
Entry객체.insert(0, "글자") : Entry widget에 표시할 글자 표시

Text객체.get("1.0", tk.END) : Text widget에 있는 첫 문장부터 끝까지 가져오기
Entry객체.get() : Entry widget에 있는 문장 가져오기

Text객체.delete("1.0", tk.END) : Text widget에 있는 글 지우기
Entry객체.delete(0, tk.END) : Entry widget에 있는 글 지우기
"""

text = tk.Text(window, width = 100, height = 3)
text.insert(tk.END, "input text")
text.pack()

window.mainloop()

