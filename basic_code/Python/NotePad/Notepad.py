import tkinter as tk

# 창 생성
root = tk.Tk()
root.title("메모장 1단계")
root.geometry("600x400")  # 창 크기 설정 (가로 x 세로)

# 텍스트 입력창 생성
text_area = tk.Text(root, wrap="word")
text_area.pack(expand=1, fill="both")

# 창 실행
root.mainloop()
