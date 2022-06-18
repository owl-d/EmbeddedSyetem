import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QDesktopWidget, QHBoxLayout, QVBoxLayout, QRadioButton, QGroupBox, QLabel
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt, QCoreApplication
from QLed import QLed

import threading
import time

class Simulator(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()
        self.main_label
        self.label_locker1
        self.label_locker2
        self.label_locker3
        self.led_locekr1
        self.led_locekr2
        self.led_locekr3

    def initUI(self):
        
        #groupbox_locker
        gbox_locker1 = self.create_gbox_locker1()
        gbox_locker2 = self.create_gbox_locker2()
        gbox_locker3 = self.create_gbox_locker3()

        #user variable
        gbox_display = self.create_gbox_display()
        gbox_keypad = self.create_gbox_keypad()

        ### gbox_lockers ###############################
        vbox_lockers = QVBoxLayout()
        vbox_lockers.addStretch(1)
        vbox_lockers.addWidget(gbox_locker1)
        vbox_lockers.addStretch(1)
        vbox_lockers.addWidget(gbox_locker2)
        vbox_lockers.addStretch(1)
        vbox_lockers.addWidget(gbox_locker3)
        vbox_lockers.addStretch(1)

        gbox_lockers = QGroupBox('Locker Control')
        gbox_lockers.setLayout(vbox_lockers)
        ################################################

        ### gbox_user ###################################
        vbox_user = QVBoxLayout()
        vbox_user.addStretch(1)
        vbox_user.addWidget(gbox_display)
        vbox_user.addStretch(1)
        vbox_user.addWidget(gbox_keypad)
        vbox_user.addStretch(1)

        gbox_users = QGroupBox('User Input')
        gbox_users.setLayout(vbox_user)
        ##################################################

        ### out_box : out box ############################
        out_box = QHBoxLayout()
        out_box.addStretch(1)
        out_box.addWidget(gbox_lockers)
        out_box.addStretch(1)
        out_box.addWidget(gbox_users)
        out_box.addStretch(1)

        self.setLayout(out_box)
        ##################################################

        self.setWindowTitle('Delivery System Simulator')
        self.setWindowIcon(QIcon('box.png'))
        self.resize(600, 400)
        self.center()
        self.show()

    def send_click(self, msg):
        print(msg)

    def set_main_text(self, msg):
        self.main_label.setText(msg)

    def set_locker1_text(self, msg):
        self.label_locker1.setText(msg)

    def set_locker2_text(self, msg):
        self.label_locker2.setText(msg)

    def set_locker3_text(self, msg):
        self.label_locker3.setText(msg)

    def set_locker1_led(self, i):
        if (i==0):
            self.led_locekr1.value=True
        else: self.led_locekr1.value=False

    def set_locker2_led(self, i):
        if (i==0):
            self.led_locekr2.value=True
        else: self.led_locekr2.value=False

    def set_locker3_led(self, i):
        if (i==0):
            self.led_locekr3.value=True
        else: self.led_locekr3.value=False

    def create_gbox_locker1(self):

        self.led_locekr1 = QLed(self, onColour=QLed.Blue, shape=QLed.Circle)
        self.led_locekr1.value=True
        btn_open_locker = QRadioButton('open')
        btn_close_locker = QRadioButton('close')
        btn_close_locker.setChecked(True)

        self.label_locker1 = QLabel('Lock', self)
        self.label_locker1.setAlignment(Qt.AlignCenter)
        font = self.label_locker1.font()
        font.setPointSize(15)
        self.label_locker1.setFont(font)
    
        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addWidget(self.led_locekr1)
        vbox.addWidget(btn_open_locker)
        vbox.addWidget(btn_close_locker)
        vbox.addStretch(1)

        hbox = QHBoxLayout()
        hbox.addStretch(1)
        hbox.addWidget(self.label_locker1)
        hbox.addStretch(1)
        hbox.addLayout(vbox)
        hbox.addStretch(1)

        gbox_locker = QGroupBox('Locker1')
        gbox_locker.setLayout(hbox)

        ### make event handler #################################################################

        btn_open_locker.clicked.connect(lambda: self.send_click("open locker"+str(1)))
        btn_close_locker.clicked.connect(lambda: self.send_click("close locker"+str(1)))

        #######################################################################################

        return gbox_locker

    def create_gbox_locker2(self):

        self.led_locekr2 = QLed(self, onColour=QLed.Blue, shape=QLed.Circle)
        self.led_locekr2.value=True
        btn_open_locker = QRadioButton('open')
        btn_close_locker = QRadioButton('close')
        btn_close_locker.setChecked(True)

        self.label_locker2 = QLabel('Lock', self)
        self.label_locker2.setAlignment(Qt.AlignCenter)
        font = self.label_locker2.font()
        font.setPointSize(15)
        self.label_locker2.setFont(font)
    
        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addWidget(self.led_locekr2)
        vbox.addWidget(btn_open_locker)
        vbox.addWidget(btn_close_locker)
        vbox.addStretch(1)

        hbox = QHBoxLayout()
        hbox.addStretch(1)
        hbox.addWidget(self.label_locker2)
        hbox.addStretch(1)
        hbox.addLayout(vbox)
        hbox.addStretch(1)

        gbox_locker = QGroupBox('Locker2')
        gbox_locker.setLayout(hbox)

        ### make event handler #################################################################

        btn_open_locker.clicked.connect(lambda: self.send_click("open locker"+str(2)))
        btn_close_locker.clicked.connect(lambda: self.send_click("close locker"+str(2)))

        #######################################################################################3

        return gbox_locker

    def create_gbox_locker3(self):

        self.led_locekr3 = QLed(self, onColour=QLed.Blue, shape=QLed.Circle)
        self.led_locekr3.value=True
        btn_open_locker = QRadioButton('open')
        btn_close_locker = QRadioButton('close')
        btn_close_locker.setChecked(True)

        self.label_locker3 = QLabel('Lock', self)
        self.label_locker3.setAlignment(Qt.AlignCenter)
        font = self.label_locker3.font()
        font.setPointSize(15)
        self.label_locker3.setFont(font)
    
        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addWidget(self.led_locekr3)
        vbox.addWidget(btn_open_locker)
        vbox.addWidget(btn_close_locker)
        vbox.addStretch(1)

        hbox = QHBoxLayout()
        hbox.addStretch(1)
        hbox.addWidget(self.label_locker3)
        hbox.addStretch(1)
        hbox.addLayout(vbox)
        hbox.addStretch(1)

        gbox_locker = QGroupBox('Locker3')
        gbox_locker.setLayout(hbox)

        ### make event handler #################################################################

        btn_open_locker.clicked.connect(lambda: self.send_click("open locker"+str(3)))
        btn_close_locker.clicked.connect(lambda: self.send_click("close locker"+str(3)))

        #######################################################################################3

        return gbox_locker

    

    def create_gbox_display(self):

        self.main_label = QLabel('LED On - empty\nLED Off - full', self)
        self.main_label.setAlignment(Qt.AlignCenter)

        font1 = self.main_label.font()
        font1.setPointSize(15)

        self.main_label.setFont(font1)

        layout = QVBoxLayout()
        layout.addWidget(self.main_label)

        gbox_display = QGroupBox('Display')
        gbox_display.setLayout(layout)
        
        return gbox_display

    def create_gbox_keypad(self):

        btn_keypad_0 = QPushButton('0')
        btn_keypad_1 = QPushButton('1')
        btn_keypad_2 = QPushButton('2')
        btn_keypad_3 = QPushButton('3')
        btn_keypad_4 = QPushButton('4')
        btn_keypad_5 = QPushButton('5')
        btn_keypad_6 = QPushButton('6')
        btn_keypad_7 = QPushButton('7')
        btn_keypad_8 = QPushButton('8')
        btn_keypad_9 = QPushButton('9')
        btn_keypad_ok = QPushButton('확인')
        btn_keypad_cc = QPushButton('취소')


        hbox1 = QHBoxLayout()
        hbox1.addStretch(1)
        hbox1.addWidget(btn_keypad_1)
        hbox1.addStretch(1)
        hbox1.addWidget(btn_keypad_2)
        hbox1.addStretch(1)
        hbox1.addWidget(btn_keypad_3)
        hbox1.addStretch(1)

        hbox2 = QHBoxLayout()
        hbox2.addStretch(1)
        hbox2.addWidget(btn_keypad_4)
        hbox2.addStretch(1)
        hbox2.addWidget(btn_keypad_5)
        hbox2.addStretch(1)
        hbox2.addWidget(btn_keypad_6)
        hbox2.addStretch(1)

        hbox3 = QHBoxLayout()
        hbox3.addStretch(1)
        hbox3.addWidget(btn_keypad_7)
        hbox3.addStretch(1)
        hbox3.addWidget(btn_keypad_8)
        hbox3.addStretch(1)
        hbox3.addWidget(btn_keypad_9)
        hbox3.addStretch(1)

        hbox4 = QHBoxLayout()
        hbox4.addStretch(1)
        hbox4.addWidget(btn_keypad_cc)
        hbox4.addStretch(1)
        hbox4.addWidget(btn_keypad_0)
        hbox4.addStretch(1)
        hbox4.addWidget(btn_keypad_ok)
        hbox4.addStretch(1)

        vbox = QVBoxLayout()
        vbox.addStretch(1)
        vbox.addLayout(hbox1)
        vbox.addStretch(1)
        vbox.addLayout(hbox2)
        vbox.addStretch(1)
        vbox.addLayout(hbox3)
        vbox.addStretch(1)
        vbox.addLayout(hbox4)
        vbox.addStretch(1)

        gbox_keypad = QGroupBox('keypad')
        gbox_keypad.setLayout(vbox)


        ### make event handler #######################################

        btn_keypad_0.clicked.connect(lambda: self.send_click("0"))
        btn_keypad_1.clicked.connect(lambda: self.send_click("1"))
        btn_keypad_2.clicked.connect(lambda: self.send_click("2"))
        btn_keypad_3.clicked.connect(lambda: self.send_click("3"))
        btn_keypad_4.clicked.connect(lambda: self.send_click("4"))
        btn_keypad_5.clicked.connect(lambda: self.send_click("5"))
        btn_keypad_6.clicked.connect(lambda: self.send_click("6"))
        btn_keypad_7.clicked.connect(lambda: self.send_click("7"))
        btn_keypad_8.clicked.connect(lambda: self.send_click("8"))
        btn_keypad_9.clicked.connect(lambda: self.send_click("9"))
        btn_keypad_cc.clicked.connect(lambda: self.send_click("cc"))
        btn_keypad_ok.clicked.connect(lambda: self.send_click("ok"))

        ##############################################################

        return gbox_keypad

    def center(self):
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())


if __name__ == '__main__':
   app = QApplication(sys.argv)
   ex = Simulator()
   ex.set_main_text("Main") # set main label
   ex.set_locker1_text("Hi") # set locker label
   ex.set_locker1_led(1) # set locker led
   sys.exit(app.exec_())