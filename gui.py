from tkinter import *
import serial

ser = serial.Serial('COM6', 9600)
class Window(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)               
        self.master = master
        self.init_window()
    def init_window(self):
        self.master.title("GUI")
        self.pack(fill=BOTH, expand=1)
        self.inputString = StringVar()
        self.inputBox = Entry(self, textvariable = self.inputString)
        self.inputBox.pack(fill=X)
        self.quitButton = Button(self, text="Send string to Arduino", command=self.callback)
        self.quitButton.pack(fill=X)
    def callback(self):
        textInput = self.inputBox.get()[:50]
        print(textInput)
        print(str(ser.name))
        ser.write(bytes(textInput, 'utf-8'))
        ser.close
root = Tk()
root.geometry("400x50")

app = Window(root)
root.mainloop()
