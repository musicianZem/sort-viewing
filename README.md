## sort-viewing

### SDL

based on SDL2


### Run Code

```
mkdir build
cd build
cmake ..
make # if error, check #include <SDL2/SDL.h> for each PC environment
./a.out
```

### Speed Control

on my pc, SDL Render is too fast to draw all.  
so, i add `SDL_Delay(1)` at main loop.

if the project is too slow to show all, change that point.


### INSTALL SDL2 Guide

#### LINUX
```
sudo apt install libsdl2-image-dev
sudo apt install libsdl2-dev 
```

#### WINDOWS

[SDL Wiki](https://www.libsdl.org/download-2.0.php)  

위 링크에서 Development Libraries 의 Window Visual C++ 버전을 받는다.

압축을 풀면, docs, include, lib  세 폴더가 있는 폴더 위치를 기억해둔다.

Visual Studio에서, 프로젝트 속성에 들어간다.

1) 구성 속성 - C/C++ - 일반 - 추가 포함디렉터리 에 아까 기억해둔 **include** 폴더 경로를 추가한다.  
2) 구성 속성 - 링커 - 일반 - 추가 라이브러리 디렉터리에 기억해둔 **lib/x86** 또는 **lib/x64**중 본인 PC에 맞는 폴더를 설정한다.  
3) 방금 설정한 lib/x86 또는 lib/x64 폴더에 들어가면, SDL2.dll 이라는 파일이 있다. 해당 파일을 복사하여 프로젝트의 소스가 들어있는 폴더로 이동시킨다.  
(이 작업이 어렵다면, 임시 소스 test.cpp 등을 추가한 후, 해당 코드가 들어있는 폴더에 이동시키면 된다)  
4) 구성 속성 - 링커 - 입력 - 추가 종속성에 sdl2.lib;sdl2main.lib;를 입력하여 추가한다.

SDL2_Image 또한 위 방법과 같이 설치한 후, 기억해둔 경로의 include와 lib 파일만 복사하면 동작한다.

#### 참고사항

윈도우즈에서 특히 발생하는 문제 중 하나로, SDL.h 헤더를 추가하면 main을 인식하지 못하는 문제가 있다.  
이 문제는 int main() {} 형식을 int main(int argc, char\*\* argv) 로 변경하면 해결되며,  
반드시 main의 리턴문(return 0, return EXIT_SUCCESS) 등을 기입해주어야 한다.

