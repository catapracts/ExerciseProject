import tkinter as tk
from tkinter import filedialog, messagebox

def new_file():
    text_area.delete("1.0", tk.END)

def open_file():
    file_path = filedialog.askopenfilename(
        filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")]
    )
    if file_path:
        with open(file_path, "r", encoding="utf-8") as file:
            content = file.read()
            text_area.delete("1.0", tk.END)
            text_area.insert(tk.END, content)

def save_file():
    file_path = filedialog.asksaveasfilename(
        defaultextension=".txt",
        filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")]
    )
    if file_path:
        with open(file_path, "w", encoding="utf-8") as file:
            file.write(text_area.get("1.0", tk.END))
            messagebox.showinfo("저장 완료", "파일이 저장되었습니다.")

# 창 생성
root = tk.Tk()
root.title("메모장 2단계")
root.geometry("600x400")

# 메뉴바 생성
menu_bar = tk.Menu(root)
file_menu = tk.Menu(menu_bar, tearoff=0)
file_menu.add_command(label="새 파일", command=new_file)
file_menu.add_command(label="열기", command=open_file)
file_menu.add_command(label="저장", command=save_file)
file_menu.add_separator()
file_menu.add_command(label="종료", command=root.quit)

menu_bar.add_cascade(label="파일", menu=file_menu)
root.config(menu=menu_bar)

# 텍스트 입력창 생성
text_area = tk.Text(root, wrap="word")
text_area.pack(expand=True, fill="both")

# 창 실행
root.mainloop()
