#include <iostream>
#include <fstream>
#include <cstdio>
#include "UserController.h"
#include "JobInfoController.h"
#include "ApplyInfoController.h"
#include "StatisticController.h"

using namespace std;

ifstream in;
ofstream out;

void doTask();
void programExit();

int main() {
    in.open("input.txt");
    out.open("output.txt");

    doTask();

    return 0;
}

void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    UserController* uc = new UserController(&in, &out);
    JobInfoController* jc = new JobInfoController(&in, &out, uc);
    ApplyInfoController* ac = new ApplyInfoController(&in, &out, uc, jc);
    StatisticController* sc = new StatisticController(&in, &out, uc, jc, ac);

    while (!is_program_exit) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in >> menu_level_1 >> menu_level_2;
        // cout << menu_level_1 << " " << menu_level_2 << "\n";

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1: {   // 1.1. 회원가입
                        int type;
                        in >> type;
                        // cout << "1.1 회원가입" << "\n";
                        uc->join(type);
                        break;
                    }
                    case 2: { // 1.2. 회원탈퇴
                        // cout << "1.2 회원탈퇴" << "\n";
                        uc->deleteUser();
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch (menu_level_2) {
                    case 1: { // 2.1. 로그인
                        uc->login();
                        break;
                    }
                    case 2: { // 2.2. 로그아웃
                        uc->logout();
                        break;
                    }
                }
                break;
            }
            case 3: {
                switch (menu_level_2) {
                    case 1: { // 3.1. 채용정보 등록
                        jc->registerJobInfo();
                        break;
                    }
                    case 2: { // 3.2. 등록된 채용정보 조회
                        jc->inquiryJobInfo();
                        break;
                    }
                }
                break;
            }
            case 4: {
                switch (menu_level_2) {
                    case 1: { // 4.1. 채용 정보 검색
                        ac->searchJob();
                        break;
                    }
                    case 2: { // 4.2. 채용 지원
                        ac->applyJob();
                        break;
                    }
                    case 3: { // 4.3. 지원 정보 조회
                        ac->inquiryApplyInfo();
                        break;
                    }
                    case 4: { // 4.4. 지원 취소
                        ac->cancelApplyJob();
                        break;
                    }
                }
                break;
            }
            case 5: {
                switch (menu_level_2) {
                    case 1: { // 5.1. 지원 정보 통계
                        sc->showStatistic();
                        break;
                    }
                }
                break;
            }
            case 6: {
                switch (menu_level_2) {
                    case 1: { // 6.1. 종료
                        programExit();
                        is_program_exit = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
}

void programExit() {
    out << "6.1 종료" << "\n";
}