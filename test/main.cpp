#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

void getPicPath(){
    FILE *fid = fopen("E:/qq.txt", "r");
    char line[2048];
    memset(line, 0, 2048);
    while (!feof(fid)) {
        fgets(line, 2048, fid);
        string str=line;
        regex reg("/storage(.*?)png");
        smatch m;
        bool found=regex_search(str, m, reg);
        if(found){
            cout<<m.str(0);
            break;
        }
        }

}


int main() {
    getPicPath();
}