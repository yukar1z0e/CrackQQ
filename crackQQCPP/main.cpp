#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

void writeReslutToLog(){
    string command = R"(adb logcat crackQQ:D *:S *:W *:E *:F *:S -f /data/local/tmp/qq.txt)";
    WinExec(command.c_str(),0);
}

void pullReslut() {
    string command = R"(adb pull /data/local/tmp/qq.txt C:\Users\yukar\Desktop)";
    system(command.c_str());
}

void getResult() {
    FILE *fid = fopen("C:\\Users\\yukar\\Desktop\\qq.txt", "r");
    char line[0000];
    memset(line, 0, 0000);
    while (!feof(fid)) {
        fgets(line, 0000, fid);
        cout << line << endl;
    }
}

void pullReslutVerison0(){
    string command = R"(adb logcat -d crackQQ:D *:S *:W *:E *:F> E:/qq.txt)";
    system(command.c_str());
}

void getResultVersion0(){
    FILE *fid = fopen("E:/qq.txt", "r");
    char line[0000];
    memset(line, 0, 0000);
    while (!feof(fid)) {
        fgets(line, 0000, fid);
        cout << line << endl;
    }
}

string getPicPath(){
    FILE *fid = fopen("E:/qq.txt", "r");
    char line[0000];
    memset(line, 0, 0000);
    while (!feof(fid)) {
        fgets(line, 0000, fid);
        string str=line;
        regex reg("/storage(.*?)png");
        smatch m;
        bool found=regex_search(str, m, reg);
        cout<<line;
        cout<<found;
        if(found){
            return m.str(0);
        }
    }
}

void pullPic(string phonenumber){
    string command;
    command="mkdir "+phonenumber;
    system(command.c_str());
    string path=getPicPath();
    command="adb pull "+path+" C:\\Code\\MoblieSecurity\\QQ\\crackQQCPP\\cmake-build-debug\\" + phonenumber;
    cout<<command<<endl;
    system(command.c_str());
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
    command="adb shell input tap 000 000";
    system(command.c_str());
    //Tap Add Friend Icon
    command="adb shell input tap 00 0000";
    system(command.c_str());
    //add phone number
    command="adb shell input text "+phoneNumber;
    system(command.c_str());
    //search
    command="adb shell input tap 000 000";
    system(command.c_str());
    //tap pic
    command="adb shell input tap 00 000";
    system(command.c_str());
    cout<<"继续查询"<<endl;
}

void kill(){
    //kill
    string command="adb shell am force-stop com.tencent.mobileqqi";
    system(command.c_str());
}

void readFile() {
    FILE *fid = fopen("C:/Users/yukar/Desktop/phonenumber.txt", "r");
    char line[0000];
    memset(line, 0, 0000);
    while (!feof(fid)) {
        fgets(line, 0000, fid);
        cout << line << endl;
    }
}

/*int main() {
    FILE *fid = fopen("C:/Users/yukar/Desktop/0.txt", "r");
    char line[0000];
    memset(line, 0, 0000);
    writeReslutToLog();
    while (!feof(fid)) {
        fgets(line, 0000, fid);
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
        if(phoneNumber=="0"){
            break;
        }
        search(phoneNumber);
        Sleep(0000);
        pullReslutVerison0();
        getResultVersion0();
        getPicPath();
        pullPic(phoneNumber);
    }
    cout<<"查询结束"<<endl;
    return 0;
}