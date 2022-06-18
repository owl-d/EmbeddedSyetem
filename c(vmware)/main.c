//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern void init_client();
extern void init_key();
extern void init_door();
extern void init_lcd();
extern void init_lock();
extern void init_led();
extern unsigned char readKey();
extern unsigned char readDoor();
extern void writeLCD(char* );
extern void writeLED(char* );
extern void writeLock(char* );
extern int readStr();

// only to use simulate
unsigned char read_key(){
    unsigned char buf;
    do{
    	buf = readKey();
    }while(buf=='O'||buf=='N'||buf=='K');
    if(buf=='d'){
    	return buf;
    } else if(buf=='a'){
        return buf;
    } else if(0x2F<buf&&buf<0x3A){
      return buf;
    } else
    return -1;
}
// only to use simulate
unsigned char door_c(int sel){
    if(sel==1){
    	return 'o';
    } else if (sel==2){
        return 'k';
    } else if (sel==3){
        return 'n';
    }
    else return -1;
}

struct Locker {   // 구조체 정의
    int lock_num;        // locker number
    bool is_lock;        // lock(true) or lock(false)
    bool is_open;        // open(true) or close(false)
    bool is_full;        // full(true) or empty(empty)
    int key;         // key code
};

struct Locker Locker1;
struct Locker Locker2;
struct Locker Locker3;

void init_locker() {

    Locker1.lock_num = 1;
    Locker1.is_lock = true;
    Locker1.is_open = false;
    Locker1.is_full = false;

    Locker2.lock_num = 2;
    Locker2.is_lock = true;
    Locker2.is_open = false;
    Locker2.is_full = false;

    Locker3.lock_num = 3;
    Locker3.is_lock = true;
    Locker3.is_open = false;
    Locker3.is_full = false;
}

void print_state() {
    char buf[64];

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "Full : true    Empty : false\n%d : %s\n%d : %s\n%d : %s", Locker1.lock_num,(Locker1.is_full ? "true" : "false"), Locker2.lock_num,(Locker2.is_full ? "true" : "false"), Locker3.lock_num,(Locker3.is_full ? "true" : "false"));
    writeLCD(buf);
}

void print_state_lock() {
    char buf[64];

    memset(buf,0, sizeof(buf));
    sprintf(buf, "Lock : true   Unlock : false\n%d : %s\n%d : %s\n%d : %s", Locker1.lock_num, (Locker1.is_lock ? "true" : "false"), Locker2.lock_num, (Locker2.is_lock ? "true" : "false"), Locker3.lock_num, (Locker3.is_lock ? "true" : "false"));
    writeLock(buf);
}

int keep_user_select_locker() {

    int locker;
    locker = read_key()-0x30;

    if (locker == 1) {
        if(Locker1.is_full == true) {
            return 0;
        };
    }
    else if (locker == 2) {
        if(Locker2.is_full == true) {
            return 0;
        }
    }
    else if (locker == 3) {
        if(Locker3.is_full == true) {
            return 0;
        }
    }

    return locker;
}

int get_user_select_locker() {

    int locker;

    writeLCD("Enter the locker number that has your box");
    locker = read_key()-0x30;

    if (locker == 1) {
        if(Locker1.is_full == false) {
            return 0;
        };
    }
    else if (locker == 2) {
        if(Locker2.is_full == false) {
            return 0;
        }
    }
    else if (locker == 3) {
        if(Locker3.is_full == false) {
            return 0;
        }
    }

    return locker;

}

void change_lock(int locker) {

    if (locker == 1) {
        if(Locker1.is_lock == true) {
            Locker1.is_lock = false;
            writeLock("Unlock Locker1");
        }
        else {
            Locker1.is_lock = true;
            writeLock("Lock Locker1");

            if (Locker1.is_full == false) {  //empty
                Locker1.is_full = true;     //full
                writeLock("Now Locker1 Is Full");
            }
            else {                          //full
                Locker1.is_full = false;    //empty
                writeLock("Now Locker1 Is Empty");
            }
        }
    }

    else if (locker == 2) {
        if(Locker2.is_lock == true) {
            Locker2.is_lock = false;
            writeLock("Unlock Locker2");
        }
        else {
            Locker2.is_lock = true;
            writeLock("Lock Locker2");

            if (Locker2.is_full == false) {
                Locker2.is_full = true;
                writeLock("Now Locker2 Is Full");
            }
            else {
                Locker2.is_full = false;
                writeLock("Now Locker2 Is Empty");
            }
        }
    }

    else if (locker == 3) {
        if(Locker3.is_lock == true) {
            Locker3.is_lock = false;
            writeLock("Unlock Locker3");
        }
        else {
            Locker3.is_lock = true;
            writeLock("Lock Locker3");

            if (Locker3.is_full == false) {
                Locker3.is_full = true;
                writeLock("Now Locker3 Is Full");
            }
            else {
                Locker3.is_full = false;
                writeLock("Now Locker3 Is Empty");
            }
        }
    }
}

void make_code(int locker) {

    int code = rand()%1000000;
    char buf[30];	// only for simulation to know passwd

    if (locker == 1) {
        Locker1.key = code;
        sprintf(buf, "Locker1's code : %d", code);
        writeLock(buf);	// only for simulation to know passwd - reused
    }
    else if (locker == 2) {
        Locker2.key = code;
        sprintf(buf, "Locker2's code : %d", code);
        writeLock(buf);	// only for simulation to know passwd - reused
    }
    else if (locker == 3) {
        Locker3.key = code;
        sprintf(buf, "Locker3's code : %d", code);
        writeLock(buf);	// only for simulation to know passwd - reused
    }
}

int check_code(int locker) {

    int code;

    writeLCD("Enter 6 Digit Key Code");
    code = readStr();

    if (locker == 1) {
        if (code == Locker1.key) {return 1;}
    }
    else if (locker == 2) {
        if (code == Locker2.key) {return 1;}
    }
    else if (locker == 3) {
        if (code == Locker3.key) {return 1;}
    }
    return 0;
}

void run() {

    int mode;
    int selected_locker;
    int ok;
    int temp;
    char phone_number[20];
    char buf[64]={0,};

    //select mode
    writeLCD("Select Option\nPut : 1    Get : 2");
    mode = read_key()-0x30;
    printf("%c",mode);
    memset(buf, 0, sizeof(buf));

    if (mode == 1) { //put
        //Display the state of lockers
        writeLCD("Select Box - Put Mode");
        print_state();

        //Select empty locker
        selected_locker = keep_user_select_locker();
        while (selected_locker == 0) {
            writeLCD("Selected Locker Is Full ! Try Aagin !\n");
            selected_locker = keep_user_select_locker();
        }

        //Enter the phone number of receiver
        writeLCD("Enter the phone number of receiver");

        int nbuf = readStr();
        sprintf(phone_number, "0%d",nbuf);

        //Display the information of selected locker and reveriver's phone number
        sprintf(buf, "\nLocker : %d\nPhone Number : %s\nEnter 'd'", selected_locker, phone_number);
	writeLCD(buf);

        //If OK, unlock the selected locker
        ok = read_key();
        if (ok == 'd') {
            change_lock(selected_locker);
        }
        print_state_lock();

        //If selected locker is closed, lock the locker
        memset(buf,0,sizeof(buf));
        writeLCD("Enter 'd' after you close the locker");
        ok = read_key();
        if (ok == 'd') {
            change_lock(selected_locker);
        }
        print_state_lock();

        //Send 6 digit code to receiver
        make_code(selected_locker);

    }

    else if (mode == 2) { //get

        writeLCD("Select Box - Put Mode");

        print_state();

        //Select full locker
        selected_locker = get_user_select_locker();
        while (selected_locker == 0) {
            writeLCD("Selected Locker Is Empty ! Try Aagin !");
            selected_locker = get_user_select_locker();
        }

        //If key code is right, unlock the locker
        temp = check_code(selected_locker);
        while (temp == 0) {
            writeLCD("Key Code is Wrong ! Try Again !");
            temp = check_code(selected_locker);
        }
        writeLCD("Code is Right!\nGet Your Box !");
        change_lock(selected_locker);
        print_state_lock();

        //If selected locker is closed, lock the locker
        memset(buf,0,sizeof(buf));
        writeLCD("Enter 'd' after you close the locker");
        ok = read_key();
        if (ok == 'd') {
            change_lock(selected_locker);
        }
        print_state_lock();

    }
    else if (mode == 3){

    }
    else {
        writeLCD("Wrong Input !");
    }

    run();

}


void main() {

    init_locker();
    init_client();
    init_key();
    init_door();
    init_lock();
    init_led();
    init_lcd();

    run();
}
