# Bingo Game 🎉

**Bingo Game**은 C++로 개발된 숫자 빙고 게임입니다. 간단한 인터페이스로 새로운 게임을 시작하거나, 중단한 게임을 불러와서 다시 즐길 수 있습니다. 자동 백업 기능도 있어 언제든 게임을 이어서 플레이할 수 있습니다.

## 🖥️ 게임 기능
- **첫 화면**: `새 게임`, `게임 불러오기`, `게임 나가기` 중 하나를 선택할 수 있습니다. 
- **방향키**로 항목을 선택하고, `Enter` 키로 실행합니다.

### ⚠️ 파일 불러오기 시 백업 파일이 없을 경우
- 백업 파일이 없으면 "파일이 비어있습니다"라는 알림과 함께 메인 화면으로 돌아갑니다.

### 🆕 새 게임
- **빙고판 크기**를 3x3 ~ 9x9 사이에서 선택할 수 있습니다. 
- **방향키**로 크기를 조정하고, `Enter` 키로 시작합니다.
- 랜덤한 숫자가 생성된 빙고판에서 게임을 진행할 수 있습니다.

### 🎮 게임 플레이
- **방향키**로 원하는 숫자를 선택하고, 이미 선택한 숫자는 재선택할 수 없습니다.
- 언제든 `나가기`를 선택해 게임을 종료할 수 있으며, 게임은 **자동 백업**됩니다.
- 나간 후 `게임 불러오기`를 통해 중단한 게임을 이어서 할 수 있습니다.

### 🏆 게임 결과
- 게임이 끝나면 **5초 동안** 플레이어와 컴퓨터의 빙고판을 출력합니다.
- 이후 **리플레이**를 통해 게임 결과를 확인할 수 있습니다.

### 🧠 컴퓨터 AI 알고리즘
- 컴퓨터는 **기대값**을 계산해 최적의 수를 선택합니다.
- 대각선, 가로, 세로 방향에서 열린 칸을 세어 기대값을 평가하며, 기대값이 가장 높은 칸을 선택합니다.

### 🤝 무승부 판정
- 드물게 발생하는 무승부는 빙고가 동시에 완성된 경우, 그 후 추가 빙고가 나오면 비긴 것으로 판정됩니다.

## 💾 게임 저장 및 불러오기
- 게임은 **매 턴 자동으로 백업**되며, 중단된 게임을 `게임 불러오기`를 통해 이어서 할 수 있습니다.

---

## 📚 설치 및 실행 방법 (Visual Studio)

1. 이 레포지토리를 클론합니다:
   ```bash
   git clone https://github.com/leemsh/Bingo.git
   ```

2. Bingo.sln 파일을 Visual Studio에서 엽니다:
  - 레포지토리 내에서 Bingo.sln 파일을 더블 클릭하여 프로젝트를 실행합니다.

3. 상단 메뉴에서 Build > Build Solution을 선택하여 빌드합니다.

4. 빌드가 완료되면 Local Windows Debugger 버튼을 클릭하여 프로그램을 실행합니다.

## 🛠️ 기술 스택
C++
Visual Studio
터미널 기반 UI
