from PIL import Image, ImageTk
import tkinter as tk
import os

file_path = "/Users/macbook/Desktop/git/basic_code/Python/NotePad/FA18F.png"

img = Image.open(file_path)


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
window.geometry("600x600+500+150")

canvas = tk.Canvas(window)
canvas.pack(fill=tk.BOTH, expand = True, pady=20)
Label1 = tk.Label(canvas)
canvas.bind("<Configure>", resize_image)

frame = tk.Frame(window)
frame.pack(fill=tk.BOTH, expand=False, padx=10, pady=10)

label = tk.Label(window, text="Label", width = 10, height = 5)
label.pack(pady=10)

button = tk.Button(window, text="Button", padx = 30, pady = 15, fg = "Blue", bg = "black")
button.pack(pady=10)

entry = tk.Entry(window,)
entry.pack(pady=10)

window.mainloop()

