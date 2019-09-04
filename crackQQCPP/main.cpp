#include <iostream>
#include <windows.h>

using namespace std;

void writeReslutToLog(){
    string command = R"(adb logcat crackQQ:D *:S *:W *:E *:F *:S -f /data/local/tmp/qq.txt)";
    WinExec(command.c_str(),1);
}

void pullReslut() {
    string command = R"(adb pull /data/local/tmp/qq.txt C:\Users\yukar\Desktop)";
    system(command.c_str());
}

void getResult() {
    FILE *fid = fopen("C:\\Users\\yukar\\Desktop\\qq.txt", "r");
    char line[2048];
    memset(line, 0, 2048);
    while (!feof(fid)) {
        fgets(line, 2048, fid);
        cout << line << endl;
    }
}

void search(string phoneNumber) {
    string command;
    //kill
    command="adb shell am force-stop com.tencent.mobileqqi";
    system(command.c_str());

    //Start QQ
    command="adb shell am start -n com.tencent.mobileqqi/com.tencent.mobileqq.activity.SplashActivity";
    system(command.c_str());
    //Tap Contact Icon
    command="adb shell input tap 390 100";
    system(command.c_str());
    //Tap Add Friend Icon
    command="adb shell input tap 60 1130";
    system(command.c_str());
    //add phone number
    command="adb shell input text "+phoneNumber;
    system(command.c_str());
    //search
    command="adb shell input tap 690 290";
    system(command.c_str());

    cout<<"继续查询"<<endl;
}

void readFile() {
    FILE *fid = fopen("C:/Users/yukar/Desktop/phonenumber.txt", "r");
    char line[2048];
    memset(line, 0, 2048);
    while (!feof(fid)) {
        fgets(line, 2048, fid);
        cout << line << endl;
    }
}

/*int main() {
    FILE *fid = fopen("C:/Users/yukar/Desktop/1.txt", "r");
    char line[2048];
    memset(line, 0, 2048);
    writeReslutToLog();
    while (!feof(fid)) {
        fgets(line, 2048, fid);
        string phoneNumber = line;
        if (phoneNumber == "0") {
            break;
        }
        search(phoneNumber);
    }
    pullReslut();
    getResult();
    cout << "查询结束" << endl;
    return 0;
}*/

int main() {
    while (true)
    {
        string phoneNumber;
        cout << "输入手机号" << endl;
        cin >> phoneNumber;
        writeReslutToLog();
        if(phoneNumber=="0"){
            break;
        }
        search(phoneNumber);
        pullReslut();
        getResult();
    }
    cout<<"查询结束"<<endl;
    return 0;
}