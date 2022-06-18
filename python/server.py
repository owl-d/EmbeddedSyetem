from socket import *
import threading
import time
import ctypes

from simulator import Simulator
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QDesktopWidget, QHBoxLayout, QVBoxLayout, QRadioButton, QGroupBox, QLabel
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt, QCoreApplication
from QLed import QLed

STD_INPUT_HANDLE   = -10
STD_OUTPUT_HANDLE  = -11
STD_ERROR_HANDLE   = -12

std_out_handle = ctypes.windll.kernel32.GetStdHandle(STD_OUTPUT_HANDLE)

HOST = '192.168.244.1'      # 서버
PORT = 8888                 # 포트

app = QApplication(sys.argv)
hw = Simulator()

def set_color(color, handle=std_out_handle):
    bool = ctypes.windll.kernel32.SetConsoleTextAttribute(handle,color)
    return bool
    
class Cserver(threading.Thread):
    def __init__(self):
        super().__init__()
        self.bListen = False
        self.clients = []
        self.threads = []
        
    def run(self):
        self.s_socket = socket(AF_INET,SOCK_STREAM)
        try:
            self.s_socket.bind((HOST,PORT))
        except Exception as e:
            print('Bind Error: ',e)
            return False
        else:
            self.bListen=True
            self.t = threading.Thread(target=self.listen, args=(self.s_socket,))
            self.t.start()
            print('Server Listening...')
        return True
        
    def listen(self, socket):
        while self.bListen:
            socket.listen(5)
            try:
                client, addr = socket.accept()
            except Exception as e:
                print('Accept() Error: ',e)
                break;
            else:
                self.clients.append(client)
                print(addr[0],addr[1],"이 연결되었습니다.")
                t = threading.Thread(target=self.receive, args=(addr, client))
                self.threads.append(t)
                t.start()
        self.removeAllClients()
        self.s_socket.close()
        
    def send(self, msg):
        try:
            for c in self.clients:
                c.send(msg.encode())
        except Exception as e:
            print('Send() Error : ', e)
    
    def receive(self, addr, client):
        while True:
            try:
                recv = client.recv(64)
            except Exception as e:
                print('Recv() Error: ',e)
                break
            else:
                msg = recv.decode()
                tt = msg.split('|',2)
                print('['+tt[0]+'] ', end='')
                if tt[0]=='LCD':
                    set_color(11)
                    print(tt[1])

                    hw.set_main_text(tt[1])

                    #if tt[1] == 'Select Option':
                    #    hw.set_main_text("Select Option\nPut : 1  Get : 2")

                    set_color(7)
                else:
                    print(tt[1])

                    if tt[1] == 'Unlock Locker1':
                        hw.set_locker1_text("Unlock")
                    elif tt[1] == 'Lock Locker1':
                        hw.set_locker1_text("Lock")
                    
                    elif tt[1] == 'Unlock Locker2':
                        hw.set_locker2_text("Unlock")
                    elif tt[1] == 'Lock Locker2':
                        hw.set_locker2_text("Lock")

                    elif tt[1] == 'Unlock Locker3':
                        hw.set_locker3_text("Unlock")
                    elif tt[1] == 'Lock Locker3':
                        hw.set_locker3_text("Lock")

                    elif tt[1] == 'Now Locker1 Is Full':
                        hw.set_locker1_led(1)
                    elif tt[1] == 'Now Locker1 Is Empty':
                        hw.set_locker1_led(0)

                    elif tt[1] == 'Now Locker2 Is Full':
                        hw.set_locker2_led(1)
                    elif tt[1] == 'Now Locker2 Is Empty':
                        hw.set_locker2_led(0)

                    elif tt[1] == 'Now Locker3 Is Full':
                        hw.set_locker3_led(1)
                    elif tt[1] == 'Now Locker3 Is Empty':
                        hw.set_locker3_led(0)
                
    def stop(self):
        self.bListen = False
        if hasattr(self, 'server'):
            self.server.close()
            print('server closed')
            
    def removeClient(self, addr, client):
        idx = -1
        for k, v in enumerate(self.clients):
            if v==client:
                idx = key
                break
        client.close()
        self.clients.remove(client)
        
        delf(self.threads[idx])
        self.resourceInfo()
                
    def removeAllClients(self):
        for c in self.clients:
            c.close()
        self.clients.clear()
        self.threads.clear()
        self.resourceInfo()
        
    def resourceInfo(self):
        print('Number of Client socket\t: ', len(self.clients) )
        print('Number of Client thread\t: ', len(self.threads) )


server = Cserver()
server.start()
        
while True:
        # 임시로 만든 메뉴 입니다.
    key = input()
    if key[0] == 'o' :
        wbuf = 'O'          # box 1번 닫기 시도
    elif key[0] == 'p' :
        wbuf = 'P'          # box 1번 열림 시도
    elif key[0] == 'k' :
        wbuf = 'K'          # box 2번 닫기 시도
    elif key[0] == 'l' :
        wbuf = 'L'          # box 2번 열기 시도
    elif key[0] == 'n' :
        wbuf = 'N'          # box 3번 닫기 시도
    elif key[0] == 'm' :
        wbuf = 'M'          # box 3번 열기 시도
    elif key[0] == 'd' :
        wbuf = key          # confirm
    # only string input allowed
    else :
        wbuf = key
        print('Input : ', key, '\n')
        hw.set_main_text("Input:"+key)
        
    server.send(wbuf)